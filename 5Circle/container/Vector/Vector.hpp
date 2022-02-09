#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <memory>
# include "../includes/Iterator.hpp"
# include "../includes/VectorIterator.hpp"
# include "../includes/Identifies.hpp"
# include "../includes/VReverseIterator.hpp"
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef typename allocator_type::size_type 			size_type;
			typedef typename allocator_type::difference_type 	difference_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef ft::vector_iterator<T> 						iterator;
			typedef ft::vector_iterator<const T> 				const_iterator;
			typedef ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;

		private:
			pointer v_arr;
			allocator_type v_alloc;
			size_type v_size;
			size_type v_capacity;

		public:
			vector();
			vector(size_type count, value_type value = value_type());
			template <class InputIterator>
			vector( InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0 );
			vector (const vector& other);
			vector& 		operator= (const vector& other);
			void 			assign (size_type count, const value_type& value);
			template <class InputIterator>
			void 			assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
			allocator_type 	get_allocator ( ) const;
			~vector();

			reference 		at(size_type pos);
			const_reference at( size_type pos ) const;
			reference 		operator[]( size_type pos );
			const_reference operator[]( size_type pos ) const;
			reference 		front();
			const_reference front() const;
			reference 		back();
			const_reference back() const;
			T* 				data();
			const T* 		data() const;

			iterator 				begin();
			const_iterator 			begin() const;
			iterator 				end();
			const_iterator 			end() const;
			reverse_iterator 		rbegin();
			const_reverse_iterator 	rbegin() const;
			reverse_iterator 		rend();
			const_reverse_iterator 	rend() const;

			bool 		empty() const;
			size_type 	size() const;
			size_type 	max_size() const;
			void 		reserve( size_type new_cap );
			size_type 	capacity() const;

			void		clear();
			iterator	insert( iterator pos, const T& value );
			void		insert( iterator pos, size_type count, const T& value );
			template <class InputIterator>
			void 		insert( iterator pos, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0 );
			iterator 	erase( iterator pos );
			iterator 	erase (iterator first, iterator last);
			void 		push_back( const T& value );
			void 		pop_back();
			void 		resize( size_type count, value_type value = value_type() );
			void 		swap( vector& other );

			pointer 	&get_arr() {return (v_arr);};
			size_type	&get_size() {return (v_size);};
			size_type	&get_capacity() {return (v_capacity);};
	};
	// constructor, destructor
	template < class T, class Alloc >
	vector<T, Alloc>::vector()
	{
		v_arr = v_alloc.allocate(4);
		v_size = 0;
		v_capacity = 4;
	}

	template < class T, class Alloc >
	vector<T, Alloc>::vector(size_type count, value_type value)
	{
		v_arr = v_alloc.allocate(count);
		v_size = 0;
		v_capacity = v_size + 4;
		while (count--)
		{
			push_back(value);
		}
	}
	template<class T, class Alloc>
	template <class InputIterator>
	vector<T, Alloc>::vector( InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* )
	{
		v_arr = v_alloc.allocate(4);
		v_size = 0;
		v_capacity = 4;
		while (first != last)
		{
			push_back(*first++);
		}
	}

	template < class T, class Alloc >
	vector<T, Alloc>::vector (const vector& other) : v_alloc(other.v_alloc), v_size(other.v_size), v_capacity(other.v_capacity)
	{
		v_arr = v_alloc.allocate(other.v_capacity);

		for (size_type idx = 0; idx < v_size; idx++)
		{
			v_arr[idx] = other.v_arr[idx];
		}
	}

	template < class T, class Alloc >
	vector<T, Alloc>& vector<T, Alloc>::operator=(const vector& other)
	{
		v_arr = other.v_arr;
		v_size = other.v_size;
		v_capacity = other.v_capacity;
		return (*this);
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::assign (size_type count, const value_type& value)
	{
		clear();
		v_arr = v_alloc.allocate(count + 4);
		v_size = count;
		v_capacity = v_size + 4;
		 for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = value;
		}
	}
	template<class T, class Alloc>
	template <class InputIterator>
	void vector<T, Alloc>::assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* )
	{
		clear();
		v_arr = v_alloc.allocate(1);
		while (first != last)
		{
			push_back(*first++);
		}
		v_capacity = v_size + 4;
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator ( ) const
	{
		return (v_alloc);
	}
	template < class T, class Alloc >
	vector<T, Alloc>::~vector()
	{
		// this->v_alloc.destroy();
		// this->v_alloc.deallocate();
	}
	//Element access
	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type pos)
	{
		if (pos >= v_size || pos < 0)
		{
			throw (std::out_of_range("vector 의 index 가 범위를 초과하였습니다."));
		}
		return (v_arr[pos]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at( size_type pos ) const
	{
		if (pos >= v_size || pos < 0)
		{
			throw (std::out_of_range("vector 의 index 가 범위를 초과하였습니다."));
		}
		return (v_arr[pos]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::operator[]( size_type pos )
	{
		return (v_arr[pos]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[]( size_type pos ) const
	{
		return (v_arr[pos]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::front()
	{
		return (v_arr[0]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
	{
		return (v_arr[0]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::back()
	{
		return (v_arr[v_size - 1]);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
	{
		return (v_arr[v_size - 1]);
	}
	template < class T, class Alloc >
	T* vector<T, Alloc>::data()
	{
		return (v_arr);
	}
	template < class T, class Alloc >
	const T* vector<T, Alloc>::data() const
	{
		return (v_arr);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
	{
		return (iterator(&v_arr[0]));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
	{
		return (iterator(&v_arr[0]));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
	{
		return (iterator(&v_arr[v_size]));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
	{
		return (iterator(&v_arr[v_size]));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
	{
		return (reverse_iterator(this->end()));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
	{
		return (const_reverse_iterator(this->end()));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
	{
		return (reverse_iterator(this->begin()));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
	{
		return (const_reverse_iterator(this->begin()));
	}
	template < class T, class Alloc >
	bool vector<T, Alloc>::empty() const
	{
		if (v_size == 0)
			return (1);
		else
			return (0);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
	{
		return (v_size);
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
	{
		return (v_alloc.max_size());
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::reserve( size_type new_cap )
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
	//  v_alloc.destroy(v_arr);
		v_alloc.deallocate(v_arr);
		v_arr = tmp;
		v_capacity = new_cap;
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
	{
		return (v_capacity);
	}
	template < class T, class Alloc >//////////
	void vector<T, Alloc>::clear()
	{
		v_alloc.destroy(this->v_arr);
		v_size = 0;
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert( iterator pos, const T& value )
	{
		iterator    tmp;
		iterator    tmp_begin;
		size_type   idx;
		iterator    pos2;

		idx = 0;
		tmp = v_alloc.allocate(v_size + 1);
		tmp_begin = tmp;
		for (iterator i = this->begin(); i != pos; i++)
		{
			*tmp++ = v_arr[idx++];
		}
		pos2 = tmp;
		*tmp++ = value;
		while(v_size - idx > 0)
		{
			*tmp = v_arr[idx++];
			tmp++;
		}
		if (v_capacity == v_size)
			reserve(v_capacity * 2);
		v_size++;
		for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = *tmp_begin++;
		}
		return (pos2);
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::insert( iterator pos, size_type count, const T& value )
	{
		iterator    tmp;
		iterator    tmp_begin;
		size_type   idx;

		idx = 0;
		tmp = v_alloc.allocate(v_size + count);
		tmp_begin = tmp;
		for (iterator i = this->begin(); i != pos; i++)
		{
			*tmp++ = v_arr[idx++];
		}
		for (size_type i = 0; i < count; i++)
		{
			*tmp++ = value;
		}
		while(v_size - idx > 0)
		{
			*tmp = v_arr[idx++];
			tmp++;
		}
		if (v_capacity - v_size < count)
			reserve(v_capacity + count);
		v_size = v_size + count;
		for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = *tmp_begin++;
		}
	}
	template< class T, class  Alloc>
	template <class InputIterator>
	void vector<T, Alloc>::insert( iterator pos, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*  )
	{
		iterator    tmp;
		iterator    tmp_begin;
		InputIterator    tmp2;
		size_type   count;
		size_type   idx;

		count = 0;
		idx = 0;
		tmp2 = first;
		while (tmp2++ != last)
			count++;
		tmp = v_alloc.allocate(v_size + count);
		tmp_begin = tmp;
		for (iterator i = this->begin(); i != pos; i++)
		{
			*tmp++ = v_arr[idx++];
		}
		while (first != last)
		{
			*tmp++ = *first++;
		}
		while(v_size - idx > 0)
		{
			*tmp = v_arr[idx++];
			tmp++;
		}
		if (v_capacity - v_size < count)
			reserve(v_capacity + count);
		v_size = v_size + count;
		for (size_type i = 0; i < v_size; i++)
		{
			v_arr[i] = *tmp_begin++;
		}
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase( iterator pos )
	{
		iterator iter;
		iter = pos;

		if (iter == end())
			return (pos);
		while (iter != end())
		{
			*iter = *(iter + 1);
			iter++;
		}
		v_size = v_size - 1;
		return (iterator(pos));
	}
	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase (iterator first, iterator last)
	{
		while (first != last)
		{
			erase(first);
			last--;
		}
		return (iterator(last));
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::push_back( const T& value )
	{
		iterator iter;
		if (v_size == v_capacity)
			reserve(v_capacity * 2);
		iter = this->end();
		*iter = value;
		v_size = v_size + 1;
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::pop_back()
	{
		v_size = v_size - 1;
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::resize( size_type count, value_type value)
	{
		size_type idx;

		idx = v_size;
		if (v_size > count)
			v_size = count;
		else if (count > v_size)
		{
			if (count > v_capacity)
				reserve(count + 4);
			while (idx < count)
			{
				v_arr[idx++] = value;
			}
		}
		v_size = count;
	}
	template < class T, class Alloc >
	void vector<T, Alloc>::swap( vector& other )
	{
		std::swap(v_arr, other.v_arr);
		std::swap(v_size, other.v_size);
		std::swap(v_capacity, other.v_capacity);
	}


	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t i;

		if (lhs.size() != rhs.size())
			return (0);
		else
		{
			for (i = 0; i < lhs.size() && i < rhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return (0);
			}
			if (i < lhs.size() || i < rhs.size())
				return (0);
		}
		return (1);
	}

	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t i;

		if (lhs.size() != rhs.size())
			return (1);
		else
		{
			for (i = 0; i < lhs.size() && i < rhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return (1);
			}
			if (i < lhs.size() || i < rhs.size())
				return (1);
		}
		return (0);
	}

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t i;

		for (i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (1);
			else if (lhs[i] > rhs[i])
				return (0);
		}
		if (i == lhs.size() && i < rhs.size())
			return (1);
		return (0);
	}

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t i;

		for (i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (1);
			else if (lhs[i] < rhs[i])
				return (0);
		}
		if (i == rhs.size() && i < lhs.size())
			return (1);
		return (0);
	}

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template < class T, class Alloc >
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs )
	{
		std::swap(lhs.get_arr(), rhs.get_arr());
		std::swap(lhs.get_size(), rhs.get_size());
		std::swap(lhs.get_capacity(), rhs.get_capacity());
	}
};
#endif
