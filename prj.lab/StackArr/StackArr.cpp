#include"stackarr.hpp"

StackArr::StackArr(const StackArr& s) noexcept {
	data = new Complex[s._capacity];
	_capacity = s._capacity;
	_size = s._size;
	for (size_t i = 0; i < _size; i++) {
		data[i] = s.data[i];
	}
}

StackArr::StackArr(StackArr&& s) noexcept
{
	std::swap(data,s.data);
	std::swap(_size,s._size);
	std::swap(_capacity,s._capacity);
}

StackArr::~StackArr() noexcept {
	delete[] data;
	data = nullptr;
}
StackArr& StackArr::operator=(const StackArr& s) noexcept {
	delete[] data;
	data = new Complex[s._capacity];
	_capacity = s._capacity;
	_size = s._size;
	for (size_t i = 0; i < _size; i++) {
		data[i] = s.data[i];
	}
	return *this;
}

StackArr& StackArr::operator=(StackArr&& s) noexcept
{
	std::swap(data, s.data);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
	return *this;
}

void StackArr::Push(const Complex& c) {
	//if (_capacity == 0) {
	//	_capacity = 1;
	//	data = new Complex[_capacity];
	//}
	if (_size == _capacity) {
		_capacity = (_size+1) * 2;
		Complex* newdata = new Complex[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			newdata[i] = data[i];
		}
		data = newdata;
	}
	data[_size] = c;
	_size++;
}

void StackArr::Pop() noexcept {
	if (_size > 0) {
		_size--;
	}
}

const Complex& StackArr::Top() const {
	if (_size == 0) {
		throw std::runtime_error("There are no elements in Stack");
	}
	return data[_size - 1];
}

Complex& StackArr::Top()
{
	if (_size == 0) {
		throw std::runtime_error("There are no elements in Stack");
	}
	return data[_size - 1];
}

bool StackArr::IsEmpty() const noexcept {
	return _size == 0;
}

void StackArr::Clear() noexcept
{
	_size = 0;
}

//size_t StackArr::size() const noexcept
//{
//	return _size;
//}
//
//size_t StackArr::capacity() const noexcept
//{
//	return _capacity;
//}
