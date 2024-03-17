// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUEARR_QUEUEARR_HPP_20240227
#define QUEUEARR_QUEUEARR_HPP_20240227

#include <complex/complex.hpp>
#include<iostream>
#include <cstddef>

class QueueArr {
public:
	QueueArr();

	QueueArr(const QueueArr& rhs);
	QueueArr(QueueArr&& rhs);

	~QueueArr();

	[[nodiscard]] QueueArr& operator=(const QueueArr& rhs);
	QueueArr& operator=(QueueArr&& rhs);

	[[nodiscard]] bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	[[nodiscard]] Complex& Top();

	[[nodiscard]] const Complex& Top() const;

	void Clear() noexcept;
	void print();

private:
	std::ptrdiff_t size_ = 0;  //!< 
	std::ptrdiff_t capacity_ = 8; 
	std::unique_ptr<Complex[]> data_{};
	std::ptrdiff_t head_ = 0; //!< 
	std::ptrdiff_t tail_ = -1; //!< 
private:
	std::ptrdiff_t Count() const;
};

#endif