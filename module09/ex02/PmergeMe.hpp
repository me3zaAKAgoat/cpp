#pragma once

#include <deque>
#include <list>
#include <ctime>
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

/** class will initiliawe one of either contaienrs and one will be null*/
class PmergeMe
{
	public:
		PmergeMe(std::string const &container, std::vector<int> &unsorted);
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		void sort();
		void print();

	private:
		std::list<int> l;
		std::deque<int> d;
		clock_t timestamp;
		bool stragglerExists;
		int straggler;
		std::deque<std::deque<int> > merge(std::deque<std::deque<int> > &l, std::deque<std::deque<int> > &r);
		std::deque<std::deque<int> > mergeSort(std::deque<std::deque<int> > &l);
		void insert(std::deque<int> &main_chain, int const &value);
		std::deque<int> sort(std::deque<int> &d);
		std::list<std::list<int> > merge(std::list<std::list<int> > &l, std::list<std::list<int> > &r);
		std::list<std::list<int> > mergeSort(std::list<std::list<int> > &l);
		void insert(std::list<int> &main_chain, int const &value);
		std::list<int> sort(std::list<int> &d);
};