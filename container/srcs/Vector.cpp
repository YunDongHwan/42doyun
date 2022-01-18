#include "../includes/Vector.hpp"
#include <vector>

int	main()
{
	//std::vector<int> test(3, 3);
	//std::vector<int>::iterator it;
	ft::Vector<int> test(5, 3);
	ft::Vector<int> test2(3, 1);
	ft::Vector<int>::iterator it;
	//ft::Vector<int>::const_iterator cit;
	it = test.begin();


	for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << "constructor" << *it << std::endl;
	}
	it--;

	test.insert(it, 5);

	std::cout << "it : " << *it << std::endl;
	for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << "insert" << *it << std::endl;
	}
	it = test.begin();
	it = 3 + it;
	std::cout << "it + 3 : " << *it << std::endl;
	std::cout << "size : " << test.size() << " / max : " << test.max_size() << " / capa : " << test.capacity() << std::endl;
	test.erase(it);
	std::cout << "erase" << *it << std::endl;
	std::cout << "2size : " << test.size() << " / max : " << test.max_size() << " / capa : " << test.capacity() << std::endl;

	test[1] = 10;
	//test[3] = 12;
	test[4] = 0;
	test2.pop_back();
	test2.push_back(-1);
	it = test2.begin();
	++it;
	//test2.insert(it, 77);
	test2.swap(test);

	for (ft::Vector<int>::iterator iter = test2.begin(); iter != test2.end(); iter++)
	{
		std::cout << "test2 : " << *iter << std::endl;
	}

	for (ft::Vector<int>::iterator iter = test.begin(); iter != test.end(); iter++)
	{
		std::cout << "test : " << *iter << std::endl;
	}

	test.clear();

	for (ft::Vector<int>::iterator iter = test.begin(); iter != test.end(); iter++)
	{
		std::cout << "clear test : " << *iter << std::endl;
	}
	std::cout << "front : " << test2.front() << std::endl;


	return (0);
}
