#include"queuelstpr/queuelstpr.hpp"

QueueLstPr::~QueueLstPr()
{
	Clear();
}

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) noexcept
{
	for (auto it = rhs.head; it != nullptr; it = it->next) {
		Push(it->data);
	}
}

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept
{
	std::swap(head, rhs.head);
	std::swap(tail, rhs.tail);
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& s) noexcept
{
	Clear();
	for (auto it = s.head; it != nullptr; it = it->next) {
		Push(it->data);
	}
	return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& s) noexcept
{
	std::swap(head, s.head);
	std::swap(tail, s.tail);
	return *this;
}

void QueueLstPr::Push(float a)
{
	if (IsEmpty()) {
		head = new Node{nullptr,a};
		tail = head;
	}
	else {
		if (a <= head->data) {
			Node* lasthead = head;
			head = new Node{ lasthead,a };
			lasthead = nullptr;
		}
		else {
			Node* lastel = head;
			bool Added = false;

			for (Node* it = head; it != nullptr; it = it->next) {
				if (it->data > a) {
					Node* newNode = new Node{ it,a };
					lastel->next = newNode;
					Added = true;
					break;
				}
				lastel = it;
			}
			if (!Added) {
				Node* newNode = new Node{ nullptr,a };
				tail->next = newNode;
				tail = newNode;

			}
		}
	}
}

void QueueLstPr::Pop() noexcept
{
	if (!IsEmpty()) {
		if (head->next != nullptr) {
			Node* newhead = head->next;
			delete head;
			head = newhead;
		}
		else {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
	}
}

bool QueueLstPr::IsEmpty() noexcept
{
	return head==nullptr;
}

float QueueLstPr::Top() 
{
	if (IsEmpty()) {
		throw std::exception("There are no elements in queue");
	}
	else {
		return head->data;
	}
}

void QueueLstPr::Clear() noexcept
{
	if (!IsEmpty()) {
		while (head != tail) {
			Pop();

		}
		Pop();
	}
	head = nullptr;
	tail = nullptr;
}
