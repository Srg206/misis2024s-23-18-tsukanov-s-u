#include "stacklst.hpp"

StackLst::StackLst(const StackLst& s) noexcept
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

StackLst::StackLst(StackLst&& s) noexcept
{
	std::swap(head,s.head);
}

StackLst::~StackLst() noexcept
{
	Clear();
	head = nullptr;
}

StackLst& StackLst::operator=(const StackLst& s) noexcept
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

StackLst& StackLst::operator=(StackLst&& s) noexcept
{
	std::swap(head, s.head);
	return *this;
}

void StackLst::Push(const Complex& c)
{

	Node* newNode = new Node(c);
	newNode->next = head;
	head = newNode;
}

void StackLst::Pop() noexcept
{

	if (!IsEmpty()) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

const Complex& StackLst::Top() const
{
	if (IsEmpty()) {
		throw(std::exception("The stack is empty"));
	}
	return head->data;
}

Complex& StackLst::Top()
{
	if (IsEmpty()) {
		throw(std::exception("The stack is empty"));
	}
	return head->data;
}

bool StackLst::IsEmpty() const noexcept
{
	return head==nullptr;
}

void StackLst::Clear() noexcept
{
	while (head != nullptr) {
		Pop();
	}
}

StackLst::Node::Node(Complex c)
{
	data = c;
	next = nullptr;
}

StackLst::Node::Node(Complex c, Node* n)
{
	data = c;
	next = n;
}

StackLst::Node::Node(const Node& n)
{
	data = n.data;
	next = n.next;
}

