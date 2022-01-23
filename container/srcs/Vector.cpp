#include "../includes/vector.hpp"
#include <vector>

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct[i] = (vct.size() - i) * 7;
		std::cout << "vct[i] : " << vct[i] << std::endl;
	}
	std::cout << "0: " << vct.size() << std::endl;
	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	std::cout << "1: " << vct2.size() << std::endl;
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	std::cout << "2: " << std::endl;
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	std::cout << "3: " << vct2.size() << std::endl;


	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}


	// std::vector<int> vtest;
	// vtest.push_back(1);
	// vtest.push_back(2);
	// vtest.push_back(3);
	// vtest.push_back(4);
	// vtest.push_back(5);
	// std::vector<int>::iterator vit;
	// vit = vtest.end();
	// std::vector<int>::reverse_iterator vrit(vit);
	// std::vector<int>::const_reverse_iterator vcrit(vrit);
	// std::cout << "vn :" << *vcrit << std::endl;
/*

	// std::vector<int>::const_iterator vcit;
	// vcit = vtest.end();

	// std::vector<int>::const_reverse_iterator vcrit2(vcit);
	// std::cout << "vc :" << *vcrit2 << std::endl;

	// std::cout << "----------------------------------------------\n";

	ft::vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);

	ft::vector<int> test2(3, 1);
	//ft::vector<int>::iterator it;

	it = test.end();
	//it++;
	ft::vector<int>::reverse_iterator rit = test.rbegin();

	ft::vector<int>::const_reverse_iterator crit = test.rbegin();
	std::cout << "nomal iterator : " << *crit << std::endl;


	ft::vector<int>::const_iterator cit;
	cit = test.end();

	//ft::vector<int>::reverse_iterator rit(it);
	//ft::vector<int>::const_reverse_iterator crit(rit);
	std::cout << "const iterator : " << *rit << std::endl;




	for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << "constructor" << *it << std::endl;
	}
	test.assign(7,7);
	test.erase(test.begin());
	test.erase(--test.end());
for (it = test.begin(); it != test.end(); it++)
	{
		std::cout << "assign " << *it << std::endl;
	}
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
*/
