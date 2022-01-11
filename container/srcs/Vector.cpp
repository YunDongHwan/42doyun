#include "../includes/container.hpp"

int	main()
{
	ft::Vector<int> test(3, 3);

	for (typename ft::Vector<int>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
