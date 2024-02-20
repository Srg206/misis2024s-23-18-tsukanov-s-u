#pragma once
#include"../complex/complex.hpp"
class QueueList {

private:
	struct Node {
		Node* next;
		Complex data = { 0,0 };
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;

public:
	QueueList() = default;
	QueueList(const QueueList& q) noexcept;
	~QueueList() noexcept;

	QueueList& operator=(const QueueList& q) noexcept;

	void Push(const Complex& c);
	void Pop() noexcept;
	Complex& Top();
	bool IsEmpty();
	void Clear() noexcept;
	void print();






};