#ifndef STACKARR_HPP_20231113
#define STACKARR_HPP_20231113

#include"../prj.lab/complex/complex.hpp"

#include <cstddef>

class StackList {
private:
	struct Node{
		Complex data = (0, 0);
		Node* next = nullptr;
		Node(Complex c);
		Node(Complex c, Node* n);
		Node(const Node& n);
	};
	Node* head = nullptr;

public:
	StackList() = default;
	StackList(const StackList& s) noexcept;
	~StackList() noexcept;
	StackList& operator=(const StackList& s) noexcept;

	void Push(const Complex& c);
	void Pop() noexcept;
	const Complex& Top() const;
	Complex& Top();
	bool IsEmpty() const noexcept;

	void Clear() noexcept;

	//size_t size() const noexcept;
	//size_t capacity() const noexcept;

};







#endif