#ifndef STACKARR_HPP_20231113
#define STACKARR_HPP_20231113

#include"../prj.lab/complex/complex.hpp"


class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& s) noexcept;
	~StackArr() noexcept;
	StackArr& operator=(const StackArr& s) noexcept;

	void Push(const Complex& c);
	void Pop() noexcept;
	const Complex& Top() const ;
	bool IsEmpty() const noexcept;

	//size_t size() const noexcept;
	//size_t capacity() const noexcept;
private:
	Complex* data = nullptr;
	size_t _size=0;
	size_t _capacity = 0;

};







#endif