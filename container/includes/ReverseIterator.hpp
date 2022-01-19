#ifndef REBERSEITERATOR_HPP
# define REBERSEITERATOR_HPP
# include "IteratorTraits.hpp"
# include "VectorIterator.hpp"
namespace ft
{
    template<class T>
    class ReverseIterator
    {
         protected:
             typedef iterator_traits<T*>                            traits_type;
        public:
            typedef VectorIterator<T>                               iterator_type;
            typedef typename traits_type::iterator_category         iterator_category;
            typedef typename traits_type::value_type                value_type;
            typedef typename traits_type::difference_type           difference_type;
            typedef typename traits_type::reference                 reference;
            typedef typename traits_type::pointer                   pointer;
        private:
            pointer ptr;
        public:
            ReverseIterator() : ptr(0) {};
          	ReverseIterator(const VectorIterator<T> &it);
          //  template<class Tp>
           // ReverseIterator (VectorIterator<Tp> &it);
            ReverseIterator(const ReverseIterator& tmp);
           // template <class Tp>
           // ReverseIterator(ReverseIterator<Tp> &tmp);
            ReverseIterator(pointer p) : ptr(p) {};
            ReverseIterator &operator=(const ReverseIterator &tmp);

            //~ReverseIterator() {};
            operator ReverseIterator<const T>() const;
            iterator_type base() const;
            reference operator*() const;
			bool operator==(const ReverseIterator<const T> &tmp) const;
			bool operator!=(const ReverseIterator<const T> &tmp) const;
			bool operator<(const ReverseIterator<const T> &tmp) const;
			bool operator>(const ReverseIterator<const T> &tmp) const;
			bool operator<=(const ReverseIterator<const T> &tmp) const;
			bool operator>=(const ReverseIterator<const T> &tmp) const;
            ReverseIterator operator+ (difference_type n) const;
            ReverseIterator& operator++();
            ReverseIterator  operator++(int);
            ReverseIterator& operator+= (difference_type n);
            ReverseIterator operator- (difference_type n) const;
			difference_type operator-(ReverseIterator const &tmp) const;
            ReverseIterator& operator--();
            ReverseIterator  operator--(int);
            ReverseIterator& operator-= (difference_type n);
            pointer operator->() const;
            reference operator[] (difference_type n) const;
            pointer get_ptr() const;
    };
    template<class T>
    ReverseIterator<T>::operator ReverseIterator<const T>() const
    {
        return (ReverseIterator<const T>(ptr));
    }

    template<class T>
    typename ReverseIterator<T>::iterator_type ReverseIterator<T>::base() const
    {
        return (iterator_type(this->ptr));
    }
	template<class T>
	ReverseIterator<T> &ReverseIterator<T>::operator=(const ReverseIterator &tmp)
	{
		ptr = tmp.get_ptr();
		return (*this);
	}

    template<class T>
    ReverseIterator<T>::ReverseIterator (const VectorIterator<T> &it)
    {
        this->ptr = it.get_ptr();
    }
    // template<class T>
    // template<class Tp>
    // ReverseIterator<T>::ReverseIterator (VectorIterator<Tp> &it)
    // {
	// 	std::cout << "ReverseIterator (VectorIterator<Tp> &it)" << std::endl;
    //     this->ptr = it.get_ptr();
    // }
    template<class T>
    ReverseIterator<T>::ReverseIterator (const ReverseIterator& tmp)
    {
        if (this != &tmp)
        {
            ptr = tmp.get_ptr();
        }
    }
    // template <class T>
    // template <class Tp>
    // ReverseIterator<T>::ReverseIterator (ReverseIterator<Tp> &tmp)
    // {
	// 	std::cout << "ReverseIterator (ReverseIterator<Tp> &tmp)" << std::endl;
    //     this->ptr = tmp.get_ptr();
    // }
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
        tmp.ptr = this->ptr;
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
        tmp.ptr = this->ptr;
        ptr = ptr + 1;
        return (tmp);
    }
    template<class T>
    ReverseIterator<T> ReverseIterator<T>::operator+ (difference_type n) const
    {
        return (ReverseIterator(this->ptr - n));
    }
    template<class T>
    ReverseIterator<T> operator+(typename ReverseIterator<T>::difference_type n, ReverseIterator<T> iter) //no member
    {
        return (ReverseIterator<T>(iter.get_ptr() - n));
    }
    template<class T>
    ReverseIterator<T> ReverseIterator<T>::operator-(difference_type n) const
    {
        return (ReverseIterator(this->ptr + n));
    }

	template <class T>
    typename ReverseIterator<T>::difference_type ReverseIterator<T>::operator-(ReverseIterator const &tmp) const
    {
        return (tmp.get_ptr() - this->ptr); //왜 tmp - this 야..
    }
    template <class T>
	bool ReverseIterator<T>::operator==(const ReverseIterator<const T> &tmp) const
	{
		return (ptr == tmp.get_ptr());
	}
	template <class T>
	bool ReverseIterator<T>::operator!=(const ReverseIterator<const T> &tmp) const
	{
		return (ptr == tmp.get_ptr());
	}
	template <class T>
	bool ReverseIterator<T>::operator<(const ReverseIterator<const T> &tmp) const
	{
		return (ptr > tmp.get_ptr());
	}
	template <class T>
	bool ReverseIterator<T>::operator<=(const ReverseIterator<const T> &tmp) const
	{
		return (ptr >= tmp.get_ptr());
	}
	template <class T>
	bool ReverseIterator<T>::operator>(const ReverseIterator<const T> &tmp) const
	{
		return (ptr < tmp.get_ptr());
	}
	template <class T>
	bool ReverseIterator<T>::operator>=(const ReverseIterator<const T> &tmp) const
	{
		return (ptr <= tmp.get_ptr());
	}

    template<class T>
    ReverseIterator<T> &ReverseIterator<T>::operator+=(difference_type n)
    {
        this->ptr = this->ptr - n;
        return (*this);
    }
    template<class T>
    ReverseIterator<T> &ReverseIterator<T>::operator-=(difference_type n)
    {

        this->ptr = this->ptr + n;
        return (*this);
    }
    template<class T>
    typename ReverseIterator<T>::reference ReverseIterator<T>::operator[](difference_type n) const
    {
        return (*(this->ptr - n - 1));
    }
    template<class T>
    typename ReverseIterator<T>::pointer ReverseIterator<T>::get_ptr() const
    {
        return (ptr);
    }
}
#endif
