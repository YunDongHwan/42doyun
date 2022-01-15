#include "../includes/container.hpp"
#include <vector>

int	main()
{
	//std::vector<int> test(3, 3);
	//std::vector<int>::iterator it;
	ft::Vector<int> test(3, 3);
	ft::Vector<int>::iterator it;

	for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << "constructor" << *it << std::endl;
	}
	it--;
	test.insert(it, 2);
	for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << "insert" << *it << std::endl;
	}
	return (0);
}
