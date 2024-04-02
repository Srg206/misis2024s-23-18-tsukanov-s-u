#include"queuelst.hpp"


QueueLst::QueueLst(const QueueLst& q) noexcept{
	Node* it = q.head_;
	while (it != nullptr) {
		Push(it->data);
		it = it->next;
	}
}

QueueLst::QueueLst(QueueLst&& q) noexcept
{
	std::swap(head_, q.head_);
	std::swap(tail_, q.tail_);
}

QueueLst::~QueueLst() noexcept
{
	Clear();

}

QueueLst& QueueLst::operator=(const QueueLst& q) noexcept
{
	Clear();
	Node* it = q.head_;
	while (it != nullptr) {
		Push(it->data);
		it = it->next;
	}
	return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& q) noexcept
{
	std::swap(head_,q.head_);
	std::swap(tail_,q.tail_);
	return *this;
}

void QueueLst::Push(const Complex& c)
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

void QueueLst::Pop() noexcept
{
	if (!IsEmpty()) {
		Node* n = head_->next;
		delete head_;
		head_ = n;
	}
}

Complex& QueueLst::Top()
{
	if (IsEmpty()) {
		throw std::out_of_range("There are no elements in queue");
	}
	return head_->data;
}

bool QueueLst::IsEmpty()
{
	return head_==nullptr;
}

void QueueLst::Clear() noexcept
{
	while (!IsEmpty()) {
		Pop();
	}
	head_ = nullptr;
}
//
//void QueueLst::print()
//{
//	Node* it = head_;
//	while (it != nullptr) {
//		std::cout << it->data<<" <- ";
//		it = it->next;
//	}
//	std::cout<<std::endl;
//}
