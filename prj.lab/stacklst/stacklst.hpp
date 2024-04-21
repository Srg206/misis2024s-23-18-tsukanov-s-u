#ifndef STACKLST_HPP_20231113
#define STACKLST_HPP_20231113

#include"../prj.lab/complex/complex.hpp"

#include <cstddef>

class StackLst {
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
	StackLst() = default;
	StackLst(const StackLst& s) noexcept;
	StackLst(StackLst&& s) noexcept;
	~StackLst() noexcept;
	StackLst& operator=(const StackLst& s) noexcept;
	StackLst& operator=(StackLst&& s) noexcept;

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