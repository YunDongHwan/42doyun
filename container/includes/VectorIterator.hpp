#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP
# include "IteratorTraits.hpp"
namespace ft
{
	template<class T>
	class VectorIterator
	{
		protected:
			typedef iterator_traits<T*>                               traits_type;
		public:
			typedef T                                               iterator_type;
			typedef typename traits_type::iterator_category         iterator_category;
			typedef typename traits_type::value_type                value_type;
			typedef typename traits_type::difference_type           difference_type;
			typedef typename traits_type::reference                 reference;
			typedef typename traits_type::pointer                   pointer;
		private:
			pointer ptr;
		public:
			VectorIterator() : ptr(0) {};
			VectorIterator(pointer p) : ptr(p) {};
			VectorIterator &operator=(VectorIterator const &tmp);
			~VectorIterator() {};
			VectorIterator &operator++();
			VectorIterator operator++(int);
			bool operator==(VectorIterator<const T> const &tmp) const;
			bool operator!=(VectorIterator<const T> const &tmp) const;
			reference operator*();
			pointer operator->();
			VectorIterator &operator--();
			VectorIterator operator--(int);
			VectorIterator operator+(int n) const;
			VectorIterator operator-(int n) const;
			difference_type operator-(VectorIterator const &tmp) const;
			bool operator<(VectorIterator<const T> const &tmp) const;
			bool operator>(VectorIterator<const T> const &tmp) const;
			bool operator<=(VectorIterator<const T> const &tmp) const;
			bool operator>=(VectorIterator<const T> const &tmp) const;
			VectorIterator &operator+=(int n);
			VectorIterator &operator-=(int n);
			reference operator[](int n);
			pointer get_ptr() const;
			operator VectorIterator<const T>() const;
	};
	template<class T>
	VectorIterator<T>::operator VectorIterator<const T>() const
	{
		return (VectorIterator<const T>(ptr));
	}
	template<class T>
	VectorIterator<T> &VectorIterator<T>::operator=(VectorIterator const &tmp)
	{
		if (this != &tmp)
		{
			ptr = tmp.ptr;
		}
		return (*this);
	}
	template<class T>
	VectorIterator<T> &VectorIterator<T>::operator++()
	{
		ptr = ptr + 1;
		return (*this);
	}
	template<class T>
	VectorIterator<T> VectorIterator<T>::operator++(int)
	{
		VectorIterator tmp;

		tmp.ptr = this->ptr;
		ptr = ptr + 1;
		return (tmp);
	}
	template<class T>
	bool VectorIterator<T>::operator==(VectorIterator<const T> const &tmp) const
	{
		return (ptr == tmp.get_ptr());
	}
	template<class T>
	bool VectorIterator<T>::operator!=(VectorIterator<const T> const &tmp) const
	{
		return (ptr != tmp.get_ptr());
	}
	template<class T>
	typename VectorIterator<T>::reference VectorIterator<T>::operator*()
	{
		return (*ptr);
	}
	template<class T>
	typename VectorIterator<T>::pointer VectorIterator<T>::operator->()
	{
		return (ptr);
	}
	template<class T>
	VectorIterator<T> &VectorIterator<T>::operator--()
	{
		ptr = ptr - 1;
		return (*this);
	}
	template<class T>
	VectorIterator<T> VectorIterator<T>::operator--(int)
	{
		VectorIterator tmp;

		tmp.ptr = this->ptr;
		ptr = ptr - 1;
		return (tmp);
	}
	template<class T>
	VectorIterator<T> VectorIterator<T>::operator+(int n) const
	{
		return (VectorIterator(this->ptr + n));
	}
	template<class T>
	VectorIterator<T> operator+(long long int n, VectorIterator<T> iter) //no member
	{
		return (VectorIterator<T>(iter.get_ptr() + n));
	}
	template<class T>
	VectorIterator<T> VectorIterator<T>::operator-(int n) const
	{
		return (VectorIterator(this->ptr - n));
	}
	template<class T>
	typename VectorIterator<T>::difference_type VectorIterator<T>::operator-(VectorIterator const &tmp) const
	{
		return (this->ptr - tmp.get_ptr());
	}
	template<class T>
	bool VectorIterator<T>::operator<(VectorIterator<const T> const &tmp) const
	{
		return (ptr < tmp.get_ptr());
	}
	template<class T>
	bool VectorIterator<T>::operator>(VectorIterator<const T> const &tmp) const
	{
		return (ptr > tmp.get_ptr());
	}
	template<class T>
	bool VectorIterator<T>::operator<=(VectorIterator<const T> const &tmp) const
	{
		return (ptr <= tmp.get_ptr());
	}
	template<class T>
	bool VectorIterator<T>::operator>=(VectorIterator<const T> const &tmp) const
	{
		return (ptr >= tmp.get_ptr());
	}
	template<class T>
	VectorIterator<T> &VectorIterator<T>::operator+=(int n)
	{
		this->ptr = this->ptr + n;
		return (*this);
	}
	template<class T>
	VectorIterator<T> &VectorIterator<T>::operator-=(int n)
	{
		this->ptr = this->ptr - n;
		return (*this);
	}
	template<class T>
	typename VectorIterator<T>::reference VectorIterator<T>::operator[](int n)
	{
		return (*(this->ptr + n));
	}
	template<class T>
	typename VectorIterator<T>::pointer VectorIterator<T>::get_ptr() const
	{
		return (ptr);
	}
}
#endif
