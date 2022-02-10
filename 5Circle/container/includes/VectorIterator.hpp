#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include "Iterator.hpp"

namespace ft
{
	template<class T>
	class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			//typedef T                                               iterator_type;
			typedef random_access_iterator_tag      		iterator_category;
			typedef T						                value_type;
			typedef std::ptrdiff_t         					difference_type;
			typedef value_type&   			                reference;
			typedef value_type*			      		        pointer;
		private:
			pointer ptr;
		public:
			vector_iterator() : ptr(0) {};
			vector_iterator(pointer p) : ptr(p) {};
			vector_iterator &operator=(const vector_iterator &tmp);
			~vector_iterator() {};
			vector_iterator &operator++();
			vector_iterator operator++(int);
			bool operator==(const vector_iterator<const T> &tmp) const;
			bool operator!=(const vector_iterator<const T> &tmp) const;
			reference operator*();
			pointer operator->();
			vector_iterator &operator--();
			vector_iterator operator--(int);
			vector_iterator operator+(int n) const;
			vector_iterator operator-(int n) const;
			difference_type operator-(const vector_iterator &tmp) const;
			bool operator<(const vector_iterator<const T> &tmp) const;
			bool operator>(const vector_iterator<const T> &tmp) const;
			bool operator<=(const vector_iterator<const T> &tmp) const;
			bool operator>=(const vector_iterator<const T> &tmp) const;
			vector_iterator &operator+=(int n);
			vector_iterator &operator-=(int n);
			reference operator[](int n);
			pointer get_ptr() const;
			operator vector_iterator<const T>() const;
	};
	template<class T>
	vector_iterator<T>::operator vector_iterator<const T>() const
	{
		return (vector_iterator<const T>(ptr));
	}
	template<class T>
	vector_iterator<T> &vector_iterator<T>::operator=(vector_iterator const &tmp)
	{
		ptr = tmp.get_ptr();
		return (*this);
	}
	template<class T>
	vector_iterator<T> &vector_iterator<T>::operator++()
	{
		ptr = ptr + 1;
		return (*this);
	}
	template<class T>
	vector_iterator<T> vector_iterator<T>::operator++(int)
	{
		vector_iterator tmp;

		tmp.ptr = this->ptr;
		ptr = ptr + 1;
		return (tmp);
	}
	template<class T>
	bool vector_iterator<T>::operator==(const vector_iterator<const T> &tmp) const
	{
		return (ptr == tmp.get_ptr());
	}
	template<class T>
	bool vector_iterator<T>::operator!=(const vector_iterator<const T> &tmp) const
	{
		return (ptr != tmp.get_ptr());
	}
	template<class T>
	typename vector_iterator<T>::reference vector_iterator<T>::operator*()
	{
		return (*ptr);
	}
	template<class T>
	typename vector_iterator<T>::pointer vector_iterator<T>::operator->()
	{
		return (ptr);
	}
	template<class T>
	vector_iterator<T> &vector_iterator<T>::operator--()
	{
		ptr = ptr - 1;
		return (*this);
	}
	template<class T>
	vector_iterator<T> vector_iterator<T>::operator--(int)
	{
		vector_iterator tmp;

		tmp.ptr = this->ptr;
		ptr = ptr - 1;
		return (tmp);
	}
	template<class T>
	vector_iterator<T> vector_iterator<T>::operator+(int n) const
	{
		return (vector_iterator(this->ptr + n));
	}
	template<class T>
	vector_iterator<T> operator+(long long int n, vector_iterator<T> iter) //no member
	{
		return (vector_iterator<T>(iter.get_ptr() + n));
	}
	template<class T>
	vector_iterator<T> vector_iterator<T>::operator-(int n) const
	{
		return (vector_iterator(this->ptr - n));
	}
	template<class T>
	typename vector_iterator<T>::difference_type vector_iterator<T>::operator-(vector_iterator const &tmp) const
	{
		return (this->ptr - tmp.get_ptr());
	}
	template<class T>
	bool vector_iterator<T>::operator<(const vector_iterator<const T> &tmp) const
	{
		return (ptr < tmp.get_ptr());
	}
	template<class T>
	bool vector_iterator<T>::operator>(const vector_iterator<const T> &tmp) const
	{
		return (ptr > tmp.get_ptr());
	}
	template<class T>
	bool vector_iterator<T>::operator<=(const vector_iterator<const T> &tmp) const
	{
		return (ptr <= tmp.get_ptr());
	}
	template<class T>
	bool vector_iterator<T>::operator>=(const vector_iterator<const T> &tmp) const
	{
		return (ptr >= tmp.get_ptr());
	}
	template<class T>
	vector_iterator<T> &vector_iterator<T>::operator+=(int n)
	{
		this->ptr = this->ptr + n;
		return (*this);
	}
	template<class T>
	vector_iterator<T> &vector_iterator<T>::operator-=(int n)
	{
		this->ptr = this->ptr - n;
		return (*this);
	}
	template<class T>
	typename vector_iterator<T>::reference vector_iterator<T>::operator[](int n)
	{
		return (*(this->ptr + n));
	}
	template<class T>
	typename vector_iterator<T>::pointer vector_iterator<T>::get_ptr() const
	{
		return (ptr);
	}

	// template<class T>
	// class const_vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	// {
	// 	public:
	// 		//typedef T                                               iterator_type;
	// 		typedef random_access_iterator_tag      		iterator_category;
	// 		typedef T						                value_type;
	// 		typedef std::ptrdiff_t         					difference_type;
	// 		typedef const value_type&   			                reference;
	// 		typedef const value_type*			      		        pointer;
	// 	private:
	// 		pointer ptr;
	// 	public:
	// 		const_vector_iterator() : ptr(0) {};
	// 		const_vector_iterator(pointer p) : ptr(p) {};
	// 		const_vector_iterator &operator=(const const_vector_iterator &tmp);
	// 		~const_vector_iterator() {};
	// 		const_vector_iterator &operator++();
	// 		const_vector_iterator operator++(int);
	// 		bool operator==(const const_vector_iterator<const T> &tmp) const;
	// 		bool operator!=(const const_vector_iterator<const T> &tmp) const;
	// 		reference operator*();
	// 		pointer operator->();
	// 		const_vector_iterator &operator--();
	// 		const_vector_iterator operator--(int);
	// 		const_vector_iterator operator+(int n) const;
	// 		const_vector_iterator operator-(int n) const;
	// 		difference_type operator-(const const_vector_iterator &tmp) const;
	// 		bool operator<(const const_vector_iterator<const T> &tmp) const;
	// 		bool operator>(const const_vector_iterator<const T> &tmp) const;
	// 		bool operator<=(const const_vector_iterator<const T> &tmp) const;
	// 		bool operator>=(const const_vector_iterator<const T> &tmp) const;
	// 		const_vector_iterator &operator+=(int n);
	// 		const_vector_iterator &operator-=(int n);
	// 		reference operator[](int n);
	// 		pointer get_ptr() const;
	// 		//operator const_vector_iterator<const T>() const;
	// };
	// // template<class T>
	// // const_vector_iterator<T>::operator const_vector_iterator<const T>() const
	// // {
	// // 	return (const_vector_iterator<const T>(ptr));
	// // }
	// template<class T>
	// const_vector_iterator<T> &const_vector_iterator<T>::operator=(const_vector_iterator const &tmp)
	// {
	// 	ptr = tmp.get_ptr();
	// 	return (*this);
	// }
	// template<class T>
	// const_vector_iterator<T> &const_vector_iterator<T>::operator++()
	// {
	// 	ptr = ptr + 1;
	// 	return (*this);
	// }
	// template<class T>
	// const_vector_iterator<T> const_vector_iterator<T>::operator++(int)
	// {
	// 	const_vector_iterator tmp;

	// 	tmp.ptr = this->ptr;
	// 	ptr = ptr + 1;
	// 	return (tmp);
	// }
	// template<class T>
	// bool const_vector_iterator<T>::operator==(const const_vector_iterator<const T> &tmp) const
	// {
	// 	return (ptr == tmp.get_ptr());
	// }
	// template<class T>
	// bool const_vector_iterator<T>::operator!=(const const_vector_iterator<const T> &tmp) const
	// {
	// 	return (ptr != tmp.get_ptr());
	// }
	// template<class T>
	// typename const_vector_iterator<T>::reference const_vector_iterator<T>::operator*()
	// {
	// 	return (*ptr);
	// }
	// template<class T>
	// typename const_vector_iterator<T>::pointer const_vector_iterator<T>::operator->()
	// {
	// 	return (ptr);
	// }
	// template<class T>
	// const_vector_iterator<T>& const_vector_iterator<T>::operator--()
	// {
	// 	ptr = ptr - 1;
	// 	return (*this);
	// }
	// template<class T>
	// const_vector_iterator<T> const_vector_iterator<T>::operator--(int)
	// {
	// 	const_vector_iterator tmp;

	// 	tmp.ptr = this->ptr;
	// 	ptr = ptr - 1;
	// 	return (tmp);
	// }
	// template<class T>
	// const_vector_iterator<T> const_vector_iterator<T>::operator+(int n) const
	// {
	// 	return (const_vector_iterator(this->ptr + n));
	// }
	// template<class T>
	// const_vector_iterator<T> operator+(long long int n, const_vector_iterator<T> iter) //no member
	// {
	// 	return (const_vector_iterator<T>(iter.get_ptr() + n));
	// }
	// template<class T>
	// const_vector_iterator<T> const_vector_iterator<T>::operator-(int n) const
	// {
	// 	return (const_vector_iterator(this->ptr - n));
	// }
	// template<class T>
	// typename const_vector_iterator<T>::difference_type const_vector_iterator<T>::operator-(const_vector_iterator const &tmp) const
	// {
	// 	return (this->ptr - tmp.get_ptr());
	// }
	// template<class T>
	// bool const_vector_iterator<T>::operator<(const const_vector_iterator<const T> &tmp) const
	// {
	// 	return (ptr < tmp.get_ptr());
	// }
	// template<class T>
	// bool const_vector_iterator<T>::operator>(const const_vector_iterator<const T> &tmp) const
	// {
	// 	return (ptr > tmp.get_ptr());
	// }
	// template<class T>
	// bool const_vector_iterator<T>::operator<=(const const_vector_iterator<const T> &tmp) const
	// {
	// 	return (ptr <= tmp.get_ptr());
	// }
	// template<class T>
	// bool const_vector_iterator<T>::operator>=(const const_vector_iterator<const T> &tmp) const
	// {
	// 	return (ptr >= tmp.get_ptr());
	// }
	// template<class T>
	// const_vector_iterator<T> &const_vector_iterator<T>::operator+=(int n)
	// {
	// 	this->ptr = this->ptr + n;
	// 	return (*this);
	// }
	// template<class T>
	// const_vector_iterator<T> &const_vector_iterator<T>::operator-=(int n)
	// {
	// 	this->ptr = this->ptr - n;
	// 	return (*this);
	// }
	// template<class T>
	// typename const_vector_iterator<T>::reference const_vector_iterator<T>::operator[](int n)
	// {
	// 	return (*(this->ptr + n));
	// }
	// template<class T>
	// typename const_vector_iterator<T>::pointer const_vector_iterator<T>::get_ptr() const
	// {
	// 	return (ptr);
	// }
}
#endif
