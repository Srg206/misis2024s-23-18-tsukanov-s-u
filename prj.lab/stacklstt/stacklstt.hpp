#ifndef STACKLSTT_HPP_20231113
#define STACKLSTT_HPP_20231113

#include"../prj.lab/complex/complex.hpp"

#include <cstddef>
template <typename T>
class StackLstT {
private:
	struct Node {
		T data;
		Node* next = nullptr;
		Node(T c);
		Node(T c, Node* n);
		Node(const Node& n);
	};
	Node* head = nullptr;

public:
	StackLstT() = default;
	StackLstT(const StackLstT& s) noexcept;
	StackLstT(StackLstT&& s) noexcept;
	~StackLstT() noexcept;
	StackLstT& operator=(const StackLstT& s) noexcept;
	StackLstT& operator=(StackLstT&& s) noexcept;

	void Push(const T& c);
	void Pop() noexcept;
	const T& Top() const;
	T& Top();
	bool IsEmpty() const noexcept;

	void Clear() noexcept;

	//size_t size() const noexcept;
	//size_t capacity() const noexcept;

};


template <typename T>
StackLstT<T>::StackLstT(const StackLstT<T>& s) noexcept
{
	Node* iter_s = s.head;
	Push(s.head->data);
	Node* iter = head;
	while (iter_s->next != nullptr) {

		Node* tmpNode = new Node(*iter_s->next);
		iter->next = tmpNode;
		tmpNode->next = nullptr;
		iter = iter->next;
		iter_s = iter_s->next;
	}
}

template <typename T>
StackLstT<T>::StackLstT(StackLstT<T>&& s) noexcept
{
	std::swap(head, s.head);
}

template <typename T>
StackLstT<T>::~StackLstT() noexcept
{
	Clear();
	head = nullptr;
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& s) noexcept
{
	Clear();
	Node* iter_s = s.head;
	Push(s.head->data);
	Node* iter = head;
	while (iter_s->next != nullptr) {
		Node* tmpNode = new Node(*iter_s->next);
		iter->next = tmpNode;
		tmpNode->next = nullptr;
		iter = iter->next;
		iter_s = iter_s->next;
	}

	return *this;
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& s) noexcept
{
	std::swap(head, s.head);
	return *this;
}
template <typename T>

void StackLstT<T>::Push(const T& c)
{

	Node* newNode = new Node(c);
	newNode->next = head;
	head = newNode;
}

template <typename T>
void StackLstT<T>::Pop() noexcept
{

	if (!IsEmpty()) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

template <typename T>
const T& StackLstT<T>::Top() const
{
	if (IsEmpty()) {
		throw(std::runtime_error("The stack is empty"));
	}
	return head->data;
}

template <typename T>
T& StackLstT<T>::Top()
{
	if (IsEmpty()) {
		throw(std::runtime_error("The stack is empty"));
	}
	return head->data;
}

template <typename T>
bool StackLstT<T>::IsEmpty() const noexcept
{
	return head == nullptr;
}

template <typename T>
void StackLstT<T>::Clear() noexcept
{
	while (head != nullptr) {
		Pop();
	}
}

template <typename T>
StackLstT<T>::Node::Node(T c)
{
	data = c;
	next = nullptr;
}

template <typename T>
StackLstT<T>::Node::Node(T c, Node* n)
{
	data = c;
	next = n;
}

template <typename T>
StackLstT<T>::Node::Node(const Node& n)
{
	data = n.data;
	next = n.next;
}

#endif