#include "../includes/container.hpp"

int	main()
{
	ft::Vector<int> test(3, 3);
	ft::Vector<int>::iterator it;

	for (it = test.end(); it != test.begin(); it--)
	{
		std::cout << *it << std::endl;
	}

	test.insert(it, 2);
	std::cout << "1" << *it << std::endl;
	for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return (0);
}
