#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "../includes/IteratorTraits.hpp"

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
			typedef typename value_type iterator;
			typedef typename const value_type const_iterator;
		//	typedef reverse_iterator<iterator> reverse_iterator;
		//	typedef reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			pointer *arr;
			allocator_type alloc;
			size_type size;
			size_type capacity;


		public:
			// constructor, destructor
			Vector();
			Vector(size_type count);
			Vector(size_type count, value_type value);
			Vector( iterator first, iterator last);
			Vector (const Vector& other);
			Vector& operator= (const Vector& other);
			void assign( size_type count, const_pointer hint=0 );
			void assign (size_type count, const value_type& value);
			void assign (iterator first, iterator last);
			allocator_type get_allocator ( ) const ;
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
			iterator erase( iterator pos );
			void push_back( const T& value );
			void pop_back();
			void resize( size_type count );
			void resize( size_type count, T value = T() );
			void swap( Vector& other );

			//Non-member functions
			//template< class T, class Alloc >
			//bool operator==( const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs );
	};

	// constructor, destructor
	template < class T, class Alloc >
	Vector<T, Alloc>::Vector()
	{
		arr = NULL;
		size = 0;
		capacity = 0;
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::Vector(size_type count)
	{
		size = count;
		capacity = size + 4;
		assign(capacity);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::Vector(size_type count, value_type value)
	{
		size = count;
		capacity = size + 4;
		assign(capacity, value);

	}

	template<class iterator, class Alloc>
    Vector<iterator, Alloc>::Vector (iterator first, iterator last)
	{
		size = last - first;
		capacity = size + 4;
		assign(first, last);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::Vector (const Vector& other)
	{
		size = other.size;
		capacity = other.capacity;
		assign(capacity);
		for (int i = 0; i < size; i++)
		{
			arr[i] = other[i];
		}
	}

	template < class T, class Alloc >
	Vector<T, Alloc>& Vector<T, Alloc>::operator=(const Vector& other)
	{
		Vector<T> vec;

		this->alloc.destroy();
		this->alloc.deallocate();
		vec.assign(other.capacity);
		vec.arr = other.arr;
		return (vec);
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::assign( size_type count, const_pointer hint=0 )
	{
		arr = alloc.allocate(count);
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	template<class iterator, class Alloc>
 	void Vector<iterator, Alloc>::assign (iterator first, iterator last)
	{
		arr = alloc.allocate(capacity);
		for (int i = 0; first != last; first++)
		{
			arr[i++] = first;
		}
	}

	template<class iterator, class Alloc>
 	void Vector<iterator, Alloc>::assign (iterator first, iterator last)
	{
		arr = alloc.allocate(capacity);
		for (int i = 0; first != last; first++)
		{
			arr[i++] = first;
		}
	}

	template<class T, class Alloc>
	void assign (size_type count, const value_type& value)
	{
		arr = alloc.allocate(count);
		for (int i = 0; i < size; i++)
		{
			arr[i] = value;
		}
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::allocator_type Vector<T, Alloc>::get_allocator ( ) const
	{
		return (alloc)
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::~Vector()
	{
		this->alloc.destroy();
		this->alloc.deallocate();
	}

	//Element access
	template < class T, class Alloc >
	Vector<T, Alloc>::reference Vector<T, Alloc>::at(size_type pos)
	{
		reference ref = arr[pos]; //참조자 선언시 초기화

		if (!(pos < size()))
		{
			throw (std::out_of_range("vector 의 index 가 범위를 초과하였습니다."));
		}
		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::const_reference Vector<T, Alloc>::at( size_type pos ) const
	{
		const_reference ref = arr[pos]; //참조자 선언시 초기화

		if (!(pos < size()))
		{
			throw (std::out_of_range("vector 의 index 가 범위를 초과하였습니다."));
		}
		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::reference Vector<T, Alloc>::operator[]( size_type pos )
	{
		reference ref = arr[pos]; //참조자 선언시 초기화

		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::const_reference Vector<T, Alloc>::operator[]( size_type pos ) const
	{
		const_reference ref = arr[pos]; //참조자 선언시 초기화

		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::reference Vector<T, Alloc>::front()
	{
		reference ref = arr[0];

		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::const_reference Vector<T, Alloc>::front() const
	{
		const_reference ref = arr[0];

		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::reference Vector<T, Alloc>::back()
	{
		reference ref = arr[size - 1];

		return (ref);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::const_reference Vector<T, Alloc>::back() const
	{
		const_reference ref = arr[size - 1];

		return (ref);
	}

	template < class T, class Alloc >
	T* data()
	{
		return (arr);
	}

	template < class T, class Alloc >
	const T* data() const
	{
		return (arr);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::iterator Vector<T, Alloc>::begin()
	{
		return (this);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::const_iterator Vector<T, Alloc>::begin() const
	[
		return (iterator(ptr));
	]

	template < class T, class Alloc >
	Vector<T, Alloc>::iterator Vector<T, Alloc>::end()
	{
		return (this + size - 1);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::const_iterator Vector<T, Alloc>::end() const
	{
		return (this + size - 1);
	}

	template < class T, class Alloc >
	bool empty() const;

	template < class T, class Alloc >
	Vector<T, Alloc>::size_type Vector<T, Alloc>::size() const
	{
		return (size);
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::size_type Vector<T, Alloc>::max_size() const
	{
		return (alloc.max_size());
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::reserve( size_type new_cap )
	{
		if (new_cap > alloc.max_size())
			throw (std::length_error("std::length_error"));
		arr.allocate(new_cap);
 	}

	template < class T, class Alloc >
	Vector<T, Alloc>::size_type Vector<T, Alloc>::capacity() const
	{
		return (capacity);
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::clear()
	{
		for (; size > 0; size--)
		{
			arr[size] = 0;
		}
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::iterator Vector<T, Alloc>::insert( iterator pos, const T& value )
	{
		if ()
	}

	template < class T, class Alloc >
	void Vector<T, Alloc>::insert( iterator pos, size_type count, const T& value )
	{
		Iterator it;

		if (pos > it.end)
		{
			throw (std::out_of_range("std::insert_error"));
		}
	}

	template < class T, class Alloc >
	Vector<T, Alloc>::iterator Vector<T, Alloc>::erase( iterator pos )
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

};

#endif
