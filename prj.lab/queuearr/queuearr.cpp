#include"queuearr.hpp"

QueueArr::QueueArr(){
	data_= std::make_unique<Complex[]>(capacity_);
}

QueueArr::QueueArr(const QueueArr& rhs)
{
	data_ = std::make_unique<Complex[]>(rhs.capacity_);
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	tail_ = rhs.tail_;
	head_ = rhs.head_;
	if (rhs.head_ <= rhs.tail_) {
		for (int i = rhs.head_; i <= rhs.tail_; i++) {
			data_[i] = rhs.data_[i];
		}
	}
}

QueueArr::~QueueArr()
{
	Clear();
}

QueueArr& QueueArr::operator=(const QueueArr& rhs)
{
	data_ = std::make_unique<Complex[]>(rhs.capacity_);
	tail_ = rhs.tail_;
	head_ = rhs.head_;
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	if (rhs.head_ <= rhs.tail_) {
		for (int i = rhs.head_; i <= rhs.tail_; i++) {
			data_[i] = rhs.data_[i];
		}
	}
	return *this;
}

bool QueueArr::IsEmpty() const noexcept
{
	return size_==0;
}

void QueueArr::Pop() noexcept
{
	if (size_>0) {
		head_ = (head_ + 1) % capacity_;
		size_--;
	}
}

void QueueArr::Push(const Complex& val){
	if (size_ == capacity_) {
		QueueArr tmp(*this);
		data_= std::make_unique<Complex[]>(capacity_*2);
		capacity_ *= 2;
		for (int i = 0, j = head_; i < size_; i++, j++) {
			data_[i] = tmp.data_[j % tmp.capacity_];
		}
		data_[size_] = val;
		head_ = 0;
		tail_ = size_;
		size_++;
	}
	else {
		tail_ = (tail_ + 1) % capacity_;
		head_ = head_ > 0 ? head_ : 0;
		data_[tail_] = val;
		size_++;
	}

}

Complex& QueueArr::Top(){
	if (size_ == 0) {
		throw std::exception("There are no elements in queue");
	}
	else {
		return data_[head_];
	}
}

const Complex& QueueArr::Top() const
{
	if (size_ == 0) {
		throw std::exception("There are no elements in queue");
	}
	else {
		return data_[head_];
	}
}

void QueueArr::Clear() noexcept
{
	data_.reset();
	data_ = nullptr;
	size_ = 0;
	capacity_ = 8;
	data_ = std::make_unique<Complex[]>(capacity_);
	head_ = 0;
	tail_ = -1;
}

void QueueArr::print()
{
	for (int i = head_; i - head_ < size_; i++) {
		std::cout << data_[i];
	}
	std::cout << std::endl;
}

std::ptrdiff_t QueueArr::Count() const
{
	return size_;
}
