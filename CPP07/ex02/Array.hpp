#pragma once
#include <cstddef>
#include <stdexcept>

template< typename T > class Array
{
private:
	size_t	_size;
	T*		_array;
public:
	Array( void ) : _size(0), _array(NULL) {}
	Array( unsigned int n ) : _size(n)
	{
		_array = new T[n];
	}
	Array( const Array& other ) : _size(other._size)
	{
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	Array&	operator=( const Array& other )
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return (*this);
	}
	~Array()
	{
		delete[] _array;
	}
	size_t	size() const
	{
		return (_size);
	}
	T&	operator[]( size_t index )
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return (_array[index]);
	}
	const T&	operator[]( size_t index ) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return (_array[index]);
	}
};

