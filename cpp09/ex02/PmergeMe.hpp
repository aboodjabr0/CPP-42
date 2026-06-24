#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parseInput(int argc, char* argv[]);

	void sortVector();
	void sortDeque();

	void printBefore() const;
	void printAfterVector() const;
	void printAfterDeque() const;

	std::size_t size() const;

private:
	std::vector<int> _vec;
	std::deque<int>  _deq;

	void fjSortVec(std::vector<int>& arr);
	void fjSortDeq(std::deque<int>& arr);

	std::vector<int> jacobsthal(int n) const;
};

#endif
