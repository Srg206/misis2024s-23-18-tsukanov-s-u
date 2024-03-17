#pragma once
#include"../complex/complex.hpp"
#include<iostream>
class QueueLst {

private:
	struct Node {
		Node* next;
		Complex data = { 0,0 };
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;

public:
	QueueLst() = default;
	QueueLst(const QueueLst& q) noexcept;
	QueueLst(QueueLst&& q) noexcept;
	~QueueLst() noexcept;

	QueueLst& operator=(const QueueLst& q) noexcept;
	QueueLst& operator=(QueueLst&& q) noexcept;

	void Push(const Complex& c);
	void Pop() noexcept;
	Complex& Top();
	bool IsEmpty();
	void Clear() noexcept;
	//void print();






};