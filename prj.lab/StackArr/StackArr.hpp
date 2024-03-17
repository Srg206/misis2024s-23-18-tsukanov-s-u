#ifndef STACKARR_HPP_20231113
#define STACKARR_HPP_20231113

#include"../prj.lab/complex/complex.hpp"

#include <cstddef>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& s) noexcept;
	StackArr(StackArr&& s) noexcept;
	~StackArr() noexcept;
	StackArr& operator=(const StackArr& s) noexcept;
	StackArr& operator=(StackArr&& s) noexcept;

	void Push(const Complex& c);
	void Pop() noexcept;
	const Complex& Top() const;
	Complex& Top();
	bool IsEmpty() const noexcept;

	void Clear() noexcept;

	//size_t size() const noexcept;
	//size_t capacity() const noexcept;
private:
	Complex* data = nullptr;
	std::ptrdiff_t _size=0;
	std::ptrdiff_t _capacity = 0;

};







#endif