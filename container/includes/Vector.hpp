#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "VectorIterator.hpp"
# include "Identifies.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename Alloc::size_type size_type;
			typedef typename Alloc::difference_type difference_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef Iterator<T> iterator;
			typedef const Iterator<T> const_iterator;
		//	typedef reverse_iterator<iterator> reverse_iterator;
		//	typedef reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			pointer v_arr;
			allocator_type v_alloc;
			size_type v_size;
			size_type v_capacity;


		public:
			// constructor, destructor
			Vector();
			Vector(size_type count);
			Vector(size_type count, value_type value);
			template <class InputIterator>
			Vector( InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* );
			Vector (const Vector& other);
			Vector& operator= (const Vector& other);
			void assign( size_type count, const_pointer hint );
			void assign (size_type count, const value_type& value);
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* );
			allocator_type get_allocator ( ) const;
			~Vector();

			//Element access
			reference at(size_type pos);
			const_reference at( size_type pos ) const;
			reference operator[]( size_type pos );
			const_reference operator[]( size_type pos ) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			T* data();
			const T* data() const;

			//Iterators
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
		//	reverse_iterator rbegin();
		//	reverse_iterator rend();

			//Capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void reserve( size_type new_cap );
			size_type capacity() const;

			//Modifiers
			void clear();
			iterator insert( iterator pos, const T& value );
			void insert( iterator pos, size_type count, const T& value );
			template <class InputIterator>
			void insert( iterator pos, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* );
	/*		iterator erase( iterator pos );
			iterator erase (iterator first, iterator last);
			void push_back( const T& value );
			void pop_back();
			void resize( size_type count );
			void resize( size_type count, T value = T() );
			void swap( Vector& other );
*/
			//Non-member functions
			//template< class T, class Alloc >
			//bool operator==( const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs );
	};

	// constructor, destructor
	template < class T, class Alloc >
	Vector<T, Alloc>::Vector()
	{
		v_arr = NULL;
		v_size = 0;
		v_capacity = 0;
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::Vector(size_type count)
	{
		v_size = count;
		v_capacity = v_size + 4;
		assign(capacity);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::Vector(size_type count, value_type value)
	{
		v_size = count;
		v_capacity = v_size + 4;
		assign(v_capacity, value);

	}

	template<class T, class Alloc>
	template <class InputIterator>
    Vector<T, Alloc>::Vector( InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* )
	{
		v_size = last - first;
		v_capacity = v_size + 4;
		assign(first, last);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::Vector (const Vector& other)
	{
		v_size = other.v_size;
		v_capacity = other.v_capacity;
		assign(v_capacity);
		for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = other[i];
		}
	}

	template < class T, class Alloc >
	Vector<T, Alloc>& Vector<T, Alloc>::operator=(const Vector& other)
	{
		Vector<T> vec;

		this->v_alloc.destroy();
		this->v_alloc.deallocate();
		vec.assign(other.v_capacity);
		vec.v_arr = other.v_arr;
		return (vec);
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::assign( size_type count, const_pointer hint )
	{
		v_arr = v_alloc.allocate(count);
		for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = 0;
		}
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::assign (size_type count, const value_type& value)
	{
		v_arr = v_alloc.allocate(count);
		for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = value;
		}
	}

	template<class T, class Alloc>
	template <class InputIterator>
 	void Vector<T, Alloc>::assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* )
	{
		v_arr = v_alloc.allocate(v_capacity);
		for (size_type i = 0; first != last; first++)
		{
			v_alloc.construct(v_arr[i++], *first);
		}
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::allocator_type Vector<T, Alloc>::get_allocator ( ) const
	{
		return (v_alloc);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::~Vector()
	{
		// this->v_alloc.destroy();
		// this->v_alloc.deallocate();
	}

	//Element access
	template < class T, class Alloc >
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::at(size_type pos)
	{
		if (!(pos < size()))
		{
			throw (std::out_of_range("vector 의 index 가 범위를 초과하였습니다."));
		}
		return (v_arr[pos]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::at( size_type pos ) const
	{
		if (!(pos < size()))
		{
			throw (std::out_of_range("vector 의 index 가 범위를 초과하였습니다."));
		}
		return (v_arr[pos]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::operator[]( size_type pos )
	{
		return (v_arr[pos]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::operator[]( size_type pos ) const
	{
		return (v_arr[pos]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::front()
	{
		return (v_arr[0]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::front() const
	{
		return (v_arr[0]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::back()
	{
		return (v_arr[size - 1]);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::back() const
	{
		return (v_arr[size - 1]);
	}

	template < class T, class Alloc >
	T* Vector<T, Alloc>::data()
	{
		return (v_arr);
	}

	template < class T, class Alloc >
	const T* Vector<T, Alloc>::data() const
	{
		return (v_arr);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::begin()
	{
		return (iterator(&v_arr[0]));
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::begin() const
	{
		return (iterator(&v_arr[0]));
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::end()
	{
		return (iterator(&v_arr[v_size]));
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::end() const
	{
		return (iterator(&v_arr[v_size]));
	}

	template < class T, class Alloc >
 	bool Vector<T, Alloc>::empty() const
	{
		if (v_size == 0)
			return (1);
		else
			return (0);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::size() const
	{
		return (v_size);
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::max_size() const
	{
		return (v_alloc.max_size());
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::reserve( size_type new_cap )
	{
		pointer tmp;

		if (new_cap > v_alloc.max_size())
			throw (std::length_error("std::length_error"));
		if (this->v_capacity > new_cap)
			return ;
		tmp = v_alloc.allocate(new_cap);
		for(size_type i = 0; i < v_size; i++)
		{
			tmp[i] = v_arr[i];
		}
	//	v_alloc.destroy(v_arr);
	//	v_alloc.deallocate(v_arr);
		v_arr = tmp;
		v_capacity = new_cap;
 	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::capacity() const
	{
		return (v_capacity);
	}

	template < class T, class Alloc >//////////
	void Vector<T, Alloc>::clear()
	{
		v_alloc.destroy();
		for (; v_size > 0; v_size--)
		{
			v_arr[v_size] = 0;
		}
	}

	template < class T, class Alloc >
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert( iterator pos, const T& value )
	{
		std::cout << value << std::endl;
		insert(pos, 1, value);

		return (pos);
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::insert( iterator pos, size_type count, const T& value )
	{
		iterator	iter;
		size_type	idx;
		size_type	tmp_idx;
		pointer		tmp;

		idx = 0;
		tmp_idx = 0;
		if (v_capacity - v_size < count)
		{
			reserve(v_capacity + count);    //pos의 위치가 reserve 하고나서도 유효한가?
		}
		tmp = v_alloc.allocate(v_size + count);
		for (size_type i = 0; i < v_size + count; i++)
		{
			tmp[i] = v_arr[i];
		}
		iter = this->begin();
		while (iter++ != pos)
		{
			v_arr[idx++] = tmp[tmp_idx++];
		}
		for (size_type i = 0; i < count; i++)
		{
			v_arr[idx++] = value;
		}
		while (iter++ != this->end())
		{
			v_arr[idx++] = tmp[tmp_idx++];
		}
		v_size = v_size + count;
	}

	template< class T, class  Alloc>
	template <class InputIterator>
	void Vector<T, Alloc>::insert( iterator pos, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*  )
	{
		iterator	iter;
		size_type	idx;
		size_type	tmp_idx;
		pointer		*tmp;

		idx = 0;
		tmp_idx = 0;
		if (v_capacity - v_size < last - first)
		{
			reserve(v_capacity + last - first);
		}
		tmp = v_alloc.allocate(v_size + last - first);
		for (int i = 0; i < v_size + last - first; i++)
		{
			tmp[i] = v_arr[i];
		}
		iter = this->begin();
		while (iter++ != pos)
		{
			v_arr[idx++] = tmp[tmp_idx++];
		}
		while (first != last)
		{
			v_arr[idx++] = *first++;
		}
		while (iter++ != this->end())
		{
			v_arr[idx++] = tmp[tmp_idx++];
		}
		v_size = v_size + first - last;
	}
/*
	template < class T, class Alloc >
	Vector<T, Alloc>::iterator Vector<T, Alloc>::erase( iterator pos )
	{

	}

	template < class T, class Alloc >
	Vector<T, Alloc>::iterator Vector<T, Alloc>::erase (iterator first, iterator last)
	{

	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::push_back( const T& value )
	{

	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::pop_back()
	{

	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::resize( size_type count )
	{
		if (size > count)
		{

		}
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::resize( size_type count, T value = T() )
	{

	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::swap( Vector& other )
	{
		std::swap(arr, other.arr);
		std::swap(size, other.size);
		std::swap(capacity, other.capacity);
	}
*/
};

#endif
