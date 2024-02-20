#include"queuelist.hpp"


QueueList::QueueList(const QueueList& q) noexcept{
	Node* it = q.head_;
	while (it != nullptr) {
		Push(it->data);
		it = it->next;
	}
}

QueueList::~QueueList() noexcept
{
	Clear();

}

QueueList& QueueList::operator=(const QueueList& q) noexcept
{
	Clear();
	Node* it = q.head_;
	while (it != nullptr) {
		Push(it->data);
		it = it->next;
	}
	return *this;
}

void QueueList::Push(const Complex& c)
{

	Node* n = new Node;
	n->data = c;
	n->next = nullptr;
	if (IsEmpty()) {
		tail_ = n;
		head_ = n;

	}
	else {
		tail_->next = n;
		tail_ = n;
	}
}

void QueueList::Pop() noexcept
{
	if (!IsEmpty()) {
		Node* n = head_->next;
		delete head_;
		head_ = n;
	}
}

Complex& QueueList::Top()
{
	if (IsEmpty()) {
		throw std::exception("There are no elements in queue");
	}
	return head_->data;
}

bool QueueList::IsEmpty()
{
	return head_==nullptr;
}

void QueueList::Clear() noexcept
{
	while (!IsEmpty()) {
		Pop();
	}
	head_ = nullptr;
}

void QueueList::print()
{
	Node* it = head_;
	while (it != nullptr) {
		std::cout << it->data<<" <- ";
		it = it->next;
	}
	std::cout<<std::endl;
}
