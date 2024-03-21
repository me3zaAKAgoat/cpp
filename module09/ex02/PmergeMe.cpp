#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string const &container, std::vector<int> &unsorted) : stragglerExists(false)
{
	if (container == "list")
	{
		this->l = std::list<int>(unsorted.begin(), unsorted.end());
		this->d = std::deque<int>();
	}
	else if (container == "deque")
	{
		this->l = std::list<int>();
		this->d = std::deque<int>(unsorted.begin(), unsorted.end());
	}
	else
		throw std::runtime_error("Invalid container type");
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		l = rhs.l;
		d = rhs.d;
	}
	return *this;
}

void PmergeMe::sort()
{
	this->timestamp = std::clock();
	if (!l.empty())
		l = sort(l);
	else if (!d.empty())
		d = sort(d);
	std ::cout << "Time to sort with " << (l.empty() ? "deque" : "list") << ": " << (std::clock() - this->timestamp) * 1000000 / (double)CLOCKS_PER_SEC  << "μs" << std::endl;
}

void PmergeMe::print()
{
	if (!l.empty())
	{
		for (std::list<int>::iterator i = l.begin(); i != l.end(); i++)
			std::cout << *i << " ";
	}
	else if (!d.empty())
	{
		for (std::deque<int>::iterator i = d.begin(); i != d.end(); i++)
			std::cout << *i << " ";
	}
	std::cout << std::endl;
}

/**
 * 
    Given an unsorted list, group the list into pairs. If the list is straggler, the last element is unpaired.

    Each pair is sorted (using a single comparison each) into what we will call [a b] pairs.

    mergeSort the pairs depending on the bigger number of the pair.

	Create a main-chain and a sub-chain. The main-chain will be the sorted pairs. The sub-chain will be the unsorted pairs.

	Iterate through the sub-chain and insert each element into the main-chain using lower_bound function that uses a binary search algorithm.
*/
std::deque<int> PmergeMe::sort(std::deque<int> &l)
{
	if (l.size() % 2 == 1)
	{
		stragglerExists = true;
		this->straggler = l.back();
		l.pop_back();
	}
	std::deque<std::deque<int> > pairs;
	for (std::deque<int>::iterator i = l.begin(); i != l.end(); i++)
	{
		std::deque<int> pair;
		pair.push_back(*i);
		i++;
		pair.push_back(*i);
		if (pair.front() < pair.back())
		{
			pair.push_front(pair.back());
			pair.pop_back();
		}
		pairs.push_back(pair);
	}
	pairs = mergeSort(pairs);
	std::deque<int> main_chain;
	std::deque<int> sub_chain;
	for (std::deque<std::deque<int> >::iterator i = pairs.begin(); i != pairs.end(); i++)
	{
		main_chain.push_back((*i).front());
		sub_chain.push_back((*i).back());
	}
	while (!sub_chain.empty())
	{
		insert(main_chain, sub_chain.back());
		sub_chain.pop_back();
	}
	if (stragglerExists)
		insert(main_chain, straggler);
	return main_chain;
}

std::deque<std::deque<int> > PmergeMe::mergeSort(std::deque<std::deque<int> > &l)
{
	if (l.size() <= 1)
		return l;
	std::deque<std::deque<int> > left;
	std::deque<std::deque<int> > right;

	std::deque<std::deque<int> >::iterator i = l.begin();
	for (int j = 0; j < static_cast<int>(l.size() / 2); j++)
	{
		left.push_back(*i);
		i++;
	}
	for (; i != l.end(); i++)
	{
		right.push_back(*i);
	}
	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

std::deque<std::deque<int> > PmergeMe::merge(std::deque<std::deque<int> > &l, std::deque<std::deque<int> > &r)
{
	std::deque<std::deque<int> > result;
	while (!l.empty() && !r.empty())
	{
		if (l.front().front() < r.front().front())
		{
			result.push_back(l.front());
			l.pop_front();
		}
		else
		{
			result.push_back(r.front());
			r.pop_front();
		}
	}
	while (!l.empty())
	{
		result.push_back(l.front());
		l.pop_front();
	}
	while (!r.empty())
	{
		result.push_back(r.front());
		r.pop_front();
	}
	return result;
}

void PmergeMe::insert(std::deque<int> &main_chain, int const &value)
{
	std::deque<int>::iterator i = std::lower_bound(main_chain.begin(), main_chain.end(), value);
	main_chain.insert(i, value);
}

std::list<int> PmergeMe::sort(std::list<int> &l)
{
	if (l.size() % 2 == 1)
	{
		stragglerExists = true;
		this->straggler = l.back();
		l.pop_back();
	}
	std::list<std::list<int> > pairs;
	for (std::list<int>::iterator i = l.begin(); i != l.end(); i++)
	{
		std::list<int> pair;
		pair.push_back(*i);
		i++;
		pair.push_back(*i);
		if (pair.front() < pair.back())
			pair.reverse();
		pairs.push_back(pair);
	}
	pairs = mergeSort(pairs);
	std::list<int> main_chain;
	std::list<int> sub_chain;
	for (std::list<std::list<int> >::iterator i = pairs.begin(); i != pairs.end(); i++)
	{
		main_chain.push_back((*i).front());
		sub_chain.push_back((*i).back());
	}
	while (!sub_chain.empty())
	{
		insert(main_chain, sub_chain.back());
		sub_chain.pop_back();
	}
	if (stragglerExists)
		insert(main_chain, straggler);
	return main_chain;
}

std::list<std::list<int> > PmergeMe::mergeSort(std::list<std::list<int> > &l)
{
	if (l.size() <= 1)
		return l;
	std::list<std::list<int> > left;
	std::list<std::list<int> > right;

	std::list<std::list<int> >::iterator i = l.begin();
	for (int j = 0; j < static_cast<int>(l.size() / 2); j++)
	{
		left.push_back(*i);
		i++;
	}
	for (; i != l.end(); i++)
	{
		right.push_back(*i);
	}
	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}

std::list<std::list<int> > PmergeMe::merge(std::list<std::list<int> > &l, std::list<std::list<int> > &r)
{
	std::list<std::list<int> > result;

	while (!l.empty() && !r.empty())
	{
		if (l.front().front() < r.front().front())
		{
			result.push_back(l.front());
			l.pop_front();
		}
		else
		{
			result.push_back(r.front());
			r.pop_front();
		}
	}
	while (!l.empty())
	{
		result.push_back(l.front());
		l.pop_front();
	}
	while (!r.empty())
	{
		result.push_back(r.front());
		r.pop_front();
	}
	return result;
}

void PmergeMe::insert(std::list<int> &main_chain, int const &value)
{
	std::list<int>::iterator i = std::lower_bound(main_chain.begin(), main_chain.end(), value);
	main_chain.insert(i, value);
}