#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator tmp;

	tmp = find(container.begin(), container.end(), val);
	if (tmp == container.end())
		throw std::invalid_argument("not found value");
	return (tmp);
}

#endif
