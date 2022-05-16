#ifndef VREBERSEITERATOR_HPP
# define VREBERSEITERATOR_HPP

# include "VectorIterator.hpp"
namespace ft
{
    template<class Iterator>
    class reverse_iterator
    {
		public:
			typedef	Iterator														iterator_type;
			typedef	typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<Iterator>::value_type			value_type;
			typedef	typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<Iterator>::pointer				pointer;
			typedef	typename	ft::iterator_traits<Iterator>::reference			reference;
        private:
            pointer ptr;
        public:
            reverse_iterator() : ptr() {};
            reverse_iterator(pointer p) : ptr(p) {};
            explicit reverse_iterator (iterator_type it) : ptr(it.get_ptr()) {};      
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter> &tmp)
            {
                pointer ptr2 = 0;
                ptr2 = tmp.get_ptr();
                ptr = ptr2;
            }
			template <class Iter>
            reverse_iterator &operator=(const reverse_iterator<Iter>& tmp);

            iterator_type base() const;
            reference operator*() const;
            
			bool operator==(const reverse_iterator<Iterator> &tmp) const;		
            bool operator!=(const reverse_iterator<Iterator> &tmp) const;            
			bool operator<(const reverse_iterator<Iterator> &tmp) const;            
			bool operator>(const reverse_iterator<Iterator> &tmp) const;            
			bool operator<=(const reverse_iterator<Iterator> &tmp) const;            
			bool operator>=(const reverse_iterator<Iterator> &tmp) const;

            template <class Iter>
			bool operator==(const reverse_iterator<Iter> &tmp) const;
			template <class Iter>
            bool operator!=(const reverse_iterator<Iter> &tmp) const;
            template <class Iter>
			bool operator<(const reverse_iterator<Iter> &tmp) const;
            template <class Iter>
			bool operator>(const reverse_iterator<Iter> &tmp) const;
            template <class Iter>
			bool operator<=(const reverse_iterator<Iter> &tmp) const;
            template <class Iter>
			bool operator>=(const reverse_iterator<Iter> &tmp) const;
            reverse_iterator operator+ (difference_type n) const;
            reverse_iterator& operator++();
            reverse_iterator  operator++(int);
            reverse_iterator& operator+= (difference_type n);
            reverse_iterator operator- (difference_type n) const;
			difference_type operator-(reverse_iterator const &tmp) const;
            reverse_iterator& operator--();
            reverse_iterator  operator--(int);
            reverse_iterator& operator-= (difference_type n);
            pointer operator->() const;
            reference operator[] (difference_type n) const;
            pointer get_ptr() const;
    };


    template<class Iterator>
    typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const
    {
        return (iterator_type(this->ptr));
    }


	template<class Iterator>
	template<class Iter>
	reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter>& tmp)
	{
		ptr = tmp.get_ptr();
		return (*this);
	}

    template<class Iterator>
    reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator++()
    {
        ptr = ptr - 1;
        return (*this);
    }
    template<class Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int)
    {
        reverse_iterator tmp;

        tmp.ptr = this->ptr;
        ptr = ptr - 1;
        return (tmp);
    }
    template<class Iterator>
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const
    {
        return (*(ptr - 1));
    }
    template<class Iterator>
    typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const
    {
        return (&(*(ptr - 1)));
    }
    template<class Iterator>
    reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator--()
    {
        ptr = ptr + 1;
        return (*this);
    }
    template<class Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int)
    {
        reverse_iterator tmp;

        tmp.ptr = this->ptr;
        this->ptr = this->ptr + 1;
        return (tmp);
    }
    template<class Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+ (difference_type n) const
    {
        return (reverse_iterator(this->ptr - n));
    }
    template<class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> iter)
    {
        return (reverse_iterator<Iterator>(iter.get_ptr() - n));
    }
    template<class Iterator>
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const
    {
        return (reverse_iterator(this->ptr + n));
    }

	template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type reverse_iterator<Iterator>::operator-(reverse_iterator const &tmp) const
    {
        return (tmp.get_ptr() - this->ptr);
    }

    template <class Iterator>    
	bool reverse_iterator<Iterator>::operator==(const reverse_iterator<Iterator> &tmp) const
	{
		return (ptr == tmp.get_ptr());
	}
	template <class Iterator>    
	bool reverse_iterator<Iterator>::operator!=(const reverse_iterator<Iterator> &tmp) const
	{
		return (ptr != tmp.get_ptr());
	}
	template <class Iterator>    
	bool reverse_iterator<Iterator>::operator<(const reverse_iterator<Iterator> &tmp) const
	{
		return (ptr > tmp.get_ptr());
	}
	template <class Iterator>    
	bool reverse_iterator<Iterator>::operator<=(const reverse_iterator<Iterator> &tmp) const
	{
		return (ptr >= tmp.get_ptr());
	}
	template <class Iterator>    
	bool reverse_iterator<Iterator>::operator>(const reverse_iterator<Iterator> &tmp) const
	{
		return (ptr < tmp.get_ptr());
	}
	template <class Iterator>    
	bool reverse_iterator<Iterator>::operator>=(const reverse_iterator<Iterator> &tmp) const
	{
		return (ptr <= tmp.get_ptr());
	}

    template <class Iterator>
    template <class Iter>
	bool reverse_iterator<Iterator>::operator==(const reverse_iterator<Iter> &tmp) const
	{
		return (ptr == tmp.get_ptr());
	}
	template <class Iterator>
    template <class Iter>
	bool reverse_iterator<Iterator>::operator!=(const reverse_iterator<Iter> &tmp) const
	{
		return (ptr != tmp.get_ptr());
	}
	template <class Iterator>
    template <class Iter>
	bool reverse_iterator<Iterator>::operator<(const reverse_iterator<Iter> &tmp) const
	{
		return (ptr > tmp.get_ptr());
	}
	template <class Iterator>
    template <class Iter>
	bool reverse_iterator<Iterator>::operator<=(const reverse_iterator<Iter> &tmp) const
	{
		return (ptr >= tmp.get_ptr());
	}
	template <class Iterator>
    template <class Iter>
	bool reverse_iterator<Iterator>::operator>(const reverse_iterator<Iter> &tmp) const
	{
		return (ptr < tmp.get_ptr());
	}
	template <class Iterator>
    template <class Iter>
	bool reverse_iterator<Iterator>::operator>=(const reverse_iterator<Iter> &tmp) const
	{
		return (ptr <= tmp.get_ptr());
	}

    template<class Iterator>
    reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator+=(difference_type n)
    {
        this->ptr = this->ptr - n;
        return (*this);
    }
    template<class Iterator>
    reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator-=(difference_type n)
    {

        this->ptr = this->ptr + n;
        return (*this);
    }
    template<class Iterator>
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const
    {
        return (*(this->ptr - n - 1));
    }


    template<class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_ptr() == rhs.get_ptr());
    }

    template<class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_ptr() != rhs.get_ptr());
    }

    template<class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_ptr() > rhs.get_ptr());
    }
    
    template<class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_ptr() >= rhs.get_ptr());
    }

    template<class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_ptr() < rhs.get_ptr());
    }

    template<class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_ptr() <= rhs.get_ptr());
    }

    template<class Iterator>
    typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::get_ptr() const
    {
        return (this->ptr);
    }
}
#endif
