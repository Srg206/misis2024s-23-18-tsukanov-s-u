#include <cstddef>
#include<iostream>
#include"../complex/complex.hpp"

class QueueLstPr {

private:
	struct Node {
		Node* next=nullptr;
		float data = 0;

	};

	Node* head=nullptr;
	Node* tail=nullptr;

public:
	QueueLstPr() = default;
	~QueueLstPr();

	QueueLstPr(const QueueLstPr& rhs) noexcept;
	QueueLstPr(QueueLstPr&& rhs) noexcept;

	QueueLstPr& operator=(const QueueLstPr& s) noexcept;
	QueueLstPr& operator=(QueueLstPr&& s) noexcept;

	void Push(float a);
	void Pop() noexcept;
	bool IsEmpty() noexcept;

	float Top();
	void Clear() noexcept;

};