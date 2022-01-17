#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include "IteratorTraits.hpp"

namespace ft
{
	template<class T>
	class Iterator
	{
		protected:
   			typedef iterator_traits<T*>								traits_type;

		public:
			typedef T												iterator_type;
			typedef typename traits_type::iterator_category			iterator_category;
			typedef typename traits_type::value_type				value_type;
			typedef typename traits_type::difference_type			difference_type;
			typedef typename traits_type::reference					reference;
			typedef typename traits_type::pointer					pointer;

		private:
			pointer	ptr;

		public:
			Iterator() : ptr(0) {};
			Iterator(pointer p) : ptr(p) {};
			Iterator(Iterator const &tmp) : ptr(tmp.ptr) {};
			Iterator &operator=(Iterator const &tmp);
			~Iterator() {};
			Iterator &operator++();
			Iterator operator++(int);
			bool operator==(Iterator const &tmp);
			bool operator!=(Iterator const &tmp);
			reference operator*();
			pointer operator->();
			Iterator &operator--();
			Iterator operator--(int);
			Iterator operator+(int n) const;
			Iterator operator-(int n) const;
			bool operator<(Iterator const &tmp);
			bool operator>(Iterator const &tmp);
			bool operator<=(Iterator const &tmp);
			bool operator>=(Iterator const &tmp);
			Iterator &operator+=(int n);
			Iterator &operator-=(int n);
			reference operator[](int n);
			pointer get_ptr();
	};

	template<class T>
	Iterator<T> &Iterator<T>::operator=(Iterator const &tmp)
	{
		if (this != &tmp)
		{
			ptr = tmp.ptr;
		}
		return (*this);
	}

	template<class T>
	Iterator<T> &Iterator<T>::operator++()
	{
		ptr = ptr + 1;
		return (*this);
	}

	template<class T>
	Iterator<T> Iterator<T>::operator++(int)
	{
		Iterator tmp;

		tmp.ptr = this->ptr;
		ptr = ptr + 1;
		return (tmp);
	}

	template<class T>
	bool Iterator<T>::operator==(Iterator const &tmp)
	{
		return (ptr == tmp.ptr);
	}

	template<class T>
	bool Iterator<T>::operator!=(Iterator const &tmp)
	{
		return (ptr != tmp.ptr);
	}

	template<class T>
	typename Iterator<T>::reference Iterator<T>::operator*()
	{
		return (*ptr);
	}

	template<class T>
	typename Iterator<T>::pointer Iterator<T>::operator->()
	{
		return (ptr);
	}

	template<class T>
	Iterator<T> &Iterator<T>::operator--()
	{
		ptr = ptr - 1;
		return (*this);
	}

	template<class T>
	Iterator<T> Iterator<T>::operator--(int)
	{
		Iterator tmp;

		tmp.ptr = this->ptr;
		ptr = ptr - 1;
		return (tmp);
	}

	template<class T>
	Iterator<T> Iterator<T>::operator+(int n) const
	{
		return (Iterator(this->ptr + n));
	}

	template<class T>
	Iterator<T> operator+(long long int n, Iterator<T> iter)
	{
		return (Iterator<T>(iter.get_ptr() + n));
	}

	template<class T>
	Iterator<T> Iterator<T>::operator-(int n) const
	{
		Iterator tmp;

		tmp = this - n;
		return (*tmp);
	}

	template<class T>
	bool Iterator<T>::operator<(Iterator const &tmp)
	{
		return (ptr < tmp.ptr);
	}

	template<class T>
	bool Iterator<T>::operator>(Iterator const &tmp)
	{
		return (ptr > tmp.ptr);
	}

	template<class T>
	bool Iterator<T>::operator<=(Iterator const &tmp)
	{
		return (ptr <= tmp.ptr);
	}

	template<class T>
	bool Iterator<T>::operator>=(Iterator const &tmp)
	{
		return (ptr >= tmp.ptr);
	}

	template<class T>
	Iterator<T> &Iterator<T>::operator+=(int n)
	{
		this = this + n;
		return (*this);
	}

	template<class T>
	Iterator<T> &Iterator<T>::operator-=(int n)
	{
		this = this - n;
		return (*this);
	}

	template<class T>
	typename Iterator<T>::reference Iterator<T>::operator[](int n)
	{
		return (*(this + n));
	}

	template<class T>
	typename Iterator<T>::pointer Iterator<T>::get_ptr()
	{
		return (ptr);
	}
}

#endif
