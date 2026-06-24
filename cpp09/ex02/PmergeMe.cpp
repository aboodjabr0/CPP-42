#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <map>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		long val;
		if (!(iss >> val))
			throw std::runtime_error("invalid input");
		std::string leftover;
		if (iss >> leftover)
			throw std::runtime_error("invalid input");
		if (val <= 0)
			throw std::runtime_error("only positive integers allowed");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
}

std::size_t PmergeMe::size() const { return _vec.size(); }

void PmergeMe::printBefore() const {
	std::cout << "Before:";
	for (std::size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::printAfterVector() const {
	std::cout << "After:";
	for (std::size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::printAfterDeque() const {
	std::cout << "After:";
	for (std::size_t i = 0; i < _deq.size(); i++)
		std::cout << " " << _deq[i];
	std::cout << std::endl;
}

// Returns Jacobsthal sequence: 1, 3, 5, 11, 21, 43, ...
// up to the first term >= n
std::vector<int> PmergeMe::jacobsthal(int n) const {
	std::vector<int> seq;
	seq.push_back(1);
	seq.push_back(3);
	while (seq.back() < n) {
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		seq.push_back(next);
	}
	return seq;
}

// ─── std::vector version ────────────────────────────────────────────────────

void PmergeMe::fjSortVec(std::vector<int>& arr) {
	int n = static_cast<int>(arr.size());
	if (n <= 1) return;

	bool odd = (n % 2 == 1);
	int straggler = odd ? arr.back() : 0;
	int m = n / 2;

	// Build pairs (loser, winner) where winner >= loser
	std::vector<std::pair<int,int> > pairs(m);
	for (int i = 0; i < m; i++) {
		if (arr[2*i] <= arr[2*i+1])
			pairs[i] = std::make_pair(arr[2*i], arr[2*i+1]);
		else
			pairs[i] = std::make_pair(arr[2*i+1], arr[2*i]);
	}

	// Recursively sort winners
	std::vector<int> winners(m);
	for (int i = 0; i < m; i++)
		winners[i] = pairs[i].second;
	fjSortVec(winners);

	// Reconstruct pairing after recursive sort (handles duplicates)
	std::multimap<int,int> wToL;
	for (int i = 0; i < m; i++)
		wToL.insert(std::make_pair(pairs[i].second, pairs[i].first));

	std::vector<std::pair<int,int> > sp(m); // sorted pairs (loser, winner)
	for (int j = 0; j < m; j++) {
		std::multimap<int,int>::iterator it = wToL.find(winners[j]);
		sp[j] = std::make_pair(it->second, winners[j]);
		wToL.erase(it);
	}

	// Build main chain: [b1, a1, a2, ..., am]
	std::vector<int> chain;
	chain.push_back(sp[0].first);
	for (int i = 0; i < m; i++)
		chain.push_back(sp[i].second);

	// Insert b2..bm using Jacobsthal order
	if (m > 1) {
		std::vector<int> jac = jacobsthal(m);
		std::vector<bool> done(m + 1, false);
		done[1] = true;

		for (std::size_t g = 1; g < jac.size(); g++) {
			int lo = jac[g-1] + 1;
			int hi = std::min(jac[g], m);
			for (int k = hi; k >= lo; k--) {
				if (done[k]) continue;
				done[k] = true;
				int bval = sp[k-1].first;
				int aval = sp[k-1].second;
				std::vector<int>::iterator ub =
					std::upper_bound(chain.begin(), chain.end(), aval);
				std::vector<int>::iterator pos =
					std::lower_bound(chain.begin(), ub, bval);
				chain.insert(pos, bval);
			}
		}
		// Any remaining (shouldn't happen, safety net)
		for (int k = 2; k <= m; k++) {
			if (done[k]) continue;
			int bval = sp[k-1].first;
			int aval = sp[k-1].second;
			std::vector<int>::iterator ub =
				std::upper_bound(chain.begin(), chain.end(), aval);
			std::vector<int>::iterator pos =
				std::lower_bound(chain.begin(), ub, bval);
			chain.insert(pos, bval);
		}
	}

	// Insert straggler
	if (odd) {
		std::vector<int>::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	arr = chain;
}

void PmergeMe::sortVector() {
	fjSortVec(_vec);
}

// ─── std::deque version ─────────────────────────────────────────────────────

void PmergeMe::fjSortDeq(std::deque<int>& arr) {
	int n = static_cast<int>(arr.size());
	if (n <= 1) return;

	bool odd = (n % 2 == 1);
	int straggler = odd ? arr.back() : 0;
	int m = n / 2;

	std::vector<std::pair<int,int> > pairs(m);
	for (int i = 0; i < m; i++) {
		if (arr[2*i] <= arr[2*i+1])
			pairs[i] = std::make_pair(arr[2*i], arr[2*i+1]);
		else
			pairs[i] = std::make_pair(arr[2*i+1], arr[2*i]);
	}

	std::deque<int> winners(m);
	for (int i = 0; i < m; i++)
		winners[i] = pairs[i].second;
	fjSortDeq(winners);

	std::multimap<int,int> wToL;
	for (int i = 0; i < m; i++)
		wToL.insert(std::make_pair(pairs[i].second, pairs[i].first));

	std::vector<std::pair<int,int> > sp(m);
	for (int j = 0; j < m; j++) {
		std::multimap<int,int>::iterator it = wToL.find(winners[j]);
		sp[j] = std::make_pair(it->second, winners[j]);
		wToL.erase(it);
	}

	std::deque<int> chain;
	chain.push_back(sp[0].first);
	for (int i = 0; i < m; i++)
		chain.push_back(sp[i].second);

	if (m > 1) {
		std::vector<int> jac = jacobsthal(m);
		std::vector<bool> done(m + 1, false);
		done[1] = true;

		for (std::size_t g = 1; g < jac.size(); g++) {
			int lo = jac[g-1] + 1;
			int hi = std::min(jac[g], m);
			for (int k = hi; k >= lo; k--) {
				if (done[k]) continue;
				done[k] = true;
				int bval = sp[k-1].first;
				int aval = sp[k-1].second;
				std::deque<int>::iterator ub =
					std::upper_bound(chain.begin(), chain.end(), aval);
				std::deque<int>::iterator pos =
					std::lower_bound(chain.begin(), ub, bval);
				chain.insert(pos, bval);
			}
		}
		for (int k = 2; k <= m; k++) {
			if (done[k]) continue;
			int bval = sp[k-1].first;
			int aval = sp[k-1].second;
			std::deque<int>::iterator ub =
				std::upper_bound(chain.begin(), chain.end(), aval);
			std::deque<int>::iterator pos =
				std::lower_bound(chain.begin(), ub, bval);
			chain.insert(pos, bval);
		}
	}

	if (odd) {
		std::deque<int>::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), straggler);
		chain.insert(pos, straggler);
	}

	arr = chain;
}

void PmergeMe::sortDeque() {
	fjSortDeq(_deq);
}
