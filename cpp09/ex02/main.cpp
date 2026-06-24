#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error: no input provided." << std::endl;
		return 1;
	}

	PmergeMe pm;
	try {
		pm.parseInput(argc, argv);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	pm.printBefore();

	// Sort with vector and measure time
	PmergeMe pmVec(pm);
	struct timespec t0, t1;
	clock_gettime(CLOCK_MONOTONIC, &t0);
	pmVec.sortVector();
	clock_gettime(CLOCK_MONOTONIC, &t1);
	double vecTime = (t1.tv_sec - t0.tv_sec) * 1e6 +
	                 (t1.tv_nsec - t0.tv_nsec) / 1e3;

	// Sort with deque and measure time
	PmergeMe pmDeq(pm);
	clock_gettime(CLOCK_MONOTONIC, &t0);
	pmDeq.sortDeque();
	clock_gettime(CLOCK_MONOTONIC, &t1);
	double deqTime = (t1.tv_sec - t0.tv_sec) * 1e6 +
	                 (t1.tv_nsec - t0.tv_nsec) / 1e3;

	pmVec.printAfterVector();

	std::cout << "Time to process a range of " << pm.size()
	          << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << pm.size()
	          << " elements with std::deque  : " << deqTime << " us" << std::endl;

	return 0;
}
