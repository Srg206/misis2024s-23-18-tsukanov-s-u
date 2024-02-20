#include "stacklist.hpp"

StackList::StackList(const StackList& s) noexcept
{
	Node* iter_s = s.head;
	Push(s.head->data);
	Node* iter = head;
	while (iter_s->next != nullptr) {

		Node* tmpNode = new Node (*iter_s->next);
		iter->next = tmpNode;
		tmpNode->next = nullptr;
		iter = iter->next;
		iter_s = iter_s->next;
	}
}

StackList::~StackList() noexcept
{
	Clear();
	head = nullptr;
}

StackList& StackList::operator=(const StackList& s) noexcept
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

void StackList::Push(const Complex& c)
{

	Node* newNode = new Node(c);
	newNode->next = head;
	head = newNode;
}

void StackList::Pop() noexcept
{

	if (!IsEmpty()) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

const Complex& StackList::Top() const
{
	if (IsEmpty()) {
		throw(std::exception("The stack is empty"));
	}
	return head->data;
}

Complex& StackList::Top()
{
	if (IsEmpty()) {
		throw(std::exception("The stack is empty"));
	}
	return head->data;
}

bool StackList::IsEmpty() const noexcept
{
	return head==nullptr;
}

void StackList::Clear() noexcept
{
	while (head != nullptr) {
		Pop();
	}
}

StackList::Node::Node(Complex c)
{
	data = c;
	next = nullptr;
}

StackList::Node::Node(Complex c, Node* n)
{
	data = c;
	next = n;
}

StackList::Node::Node(const Node& n)
{
	data = n.data;
	next = n.next;
}
