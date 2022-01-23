#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "Vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
    {
        public:
            typedef T value_type;
			typedef Container container_type;
            typedef typename Container::size_type size_type;

        private:
			container_type s_ctnr;

        public:
			stack(const container_type& ctnr = container_type())
			{
				s_ctnr = ctnr;
			}
			stack(const stack& other)
			{
				s_ctnr = other.s_ctnr;
			}
			bool empty() const
			{
				return (s_ctnr.empty());
			}
			size_type size() const
			{
				return (s_ctnr.size());
			}
			value_type& top()
			{
				return (s_ctnr.back());
			}
			const value_type& top() const
			{
				return (s_ctnr.back());
			}
			void push (const value_type& val)
			{
				s_ctnr.push_back(val);
			}
			void pop()
			{
				s_ctnr.pop_back();
			}
			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.s_ctnr == rhs.s_ctnr);
			}
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.s_ctnr != rhs.s_ctnr);
			}
			friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.s_ctnr < rhs.s_ctnr);
			}
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.s_ctnr <= rhs.s_ctnr);
			}
			friend bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.s_ctnr > rhs.s_ctnr);
			}
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.s_ctnr >= rhs.s_ctnr);
			}
	};
	// template <class T, class Container>
	// bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (lhs.s_ctnr == rhs.s_ctnr);
	// }
	// template <class T, class Container>
	// bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (lhs.s_ctnr != rhs.s_ctnr);
	// }
	// template <class T, class Container>
	// bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (lhs.s_ctnr < rhs.s_ctnr);
	// }
	// template <class T, class Container>
	// bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (lhs.s_ctnr <= rhs.s_ctnr);
	// }
	// template <class T, class Container>
	// bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (lhs.s_ctnr > rhs.s_ctnr);
	// }
	// template <class T, class Container>
	// bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (lhs.s_ctnr >= rhs.s_ctnr);
	// }
};
#endif
