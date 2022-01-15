#ifndef REBERSEITERATOR_HPP
# define REBERSEITERATOR_HPP

# include "Identifies.hpp"
# include "IteratorTraits.hpp"

namespace ft
{
	template<class T>
	class ReverseIterator
	{
		protected:
   			typedef iterator_traits<T*>						traits_type;

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
			ReverseIterator() : ptr(0) {};
			ReverseIterator(pointer p) : ptr(p) {};
			ReverseIterator(ReverseIterator const &tmp) : ptr(tmp.ptr) {};
			ReverseIterator &operator=(ReverseIterator const &tmp);
			~ReverseIterator() {};

			iterator_type base() const;
			reference operator*() const;
			ReverseIterator operator+ (difference_type n) const;
			ReverseIterator& operator++();
			ReverseIterator  operator++(int);
			ReverseIterator& operator+= (difference_type n);
			ReverseIterator operator- (difference_type n) const;
			ReverseIterator& operator--();
			ReverseIterator  operator--(int);
			ReverseIterator& operator-= (difference_type n);
			pointer operator->() const;
			reference operator[] (difference_type n) const;
	};

	template<class T>
	ReverseIterator<T>::iterator_type ReverseIterator<T>::base() const
	{
		return (this - 1);
	}

	template<class T>
	ReverseIterator<T> &ReverseIterator<T>::operator=(ReverseIterator const &tmp)
	{
		if (this != &tmp)
		{
			ptr = tmp.ptr;
		}
		return (*this);
	}

	template<class T>
	ReverseIterator<T> &ReverseIterator<T>::operator++()
	{
		ptr = ptr - 1;
		return (*this);
	}

	template<class T>
	ReverseIterator<T> ReverseIterator<T>::operator++(int)
	{
		ReverseIterator tmp;

		tmp = *this;
		ptr = ptr - 1;
		return (tmp);
	}



	template<class T>
	typename ReverseIterator<T>::reference ReverseIterator<T>::operator*() const
	{
		return (*(ptr - 1));
	}

	template<class T>
	typename ReverseIterator<T>::pointer ReverseIterator<T>::operator->() const
	{
		return (ptr - 1);
	}

	template<class T>
	ReverseIterator<T> &ReverseIterator<T>::operator--()
	{
		ptr = ptr + 1;
		return (*this);
	}

	template<class T>
	ReverseIterator<T> ReverseIterator<T>::operator--(int)
	{
		ReverseIterator tmp;

		tmp = *this;
		ptr = ptr + 1;
		return (tmp);
	}

	template<class T>
	ReverseIterator<T> ReverseIterator<T>::operator+ (difference_type n) const
	{
		ReverseIterator tmp;

		tmp = this - n;
		return (tmp);
	}

	template<class T>
	ReverseIterator<T> ReverseIterator<T>::operator-(difference_type n) const
	{
		ReverseIterator tmp;

		tmp = this + n;
		return (tmp);
	}

	template <class Iterator>
  	bool operator== (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (ptr == tmp.ptr);
	}

	template <class Iterator>
	bool operator!= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (ptr != tmp.ptr);
	}

	template <class Iterator>
	bool operator< (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (ptr > tmp.ptr);
	}

	template <class Iterator>
	bool operator> (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (ptr < tmp.ptr);
	}

	template <class Iterator>
	bool operator> (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (ptr >= tmp.ptr);
	}

	template <class Iterator>
	bool operator> (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (ptr <= tmp.ptr);
	}

	template<class T>
	ReverseIterator<T> &ReverseIterator<T>::operator+=(difference_type n)
	{
		this = this - n;
		return (*this);
	}

	template<class T>
	ReverseIterator<T> &ReverseIterator<T>::operator-=(difference_type n)
	{
		this = this + n;
		return (*this);
	}

	template<class T>
	typename ReverseIterator<T>::reference ReverseIterator<T>::operator[](difference_type n) const
	{
		return (*(this + n - 1));
	}
}

#endif
