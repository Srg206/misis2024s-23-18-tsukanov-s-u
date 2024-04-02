#include"../prj.lab/dynarr/dynarr.hpp"

DynArr::DynArr(const DynArr& arr) {
	size_ = arr.size_;
	capacity_ = arr.capacity_;
	data_.reset();
	data_ = std::unique_ptr<float>(new float[capacity_]);
	for (size_t i = 0; i < capacity_; i++)
	{
		data_.get()[i] = arr.data_.get()[i];
	}
}

DynArr::DynArr(DynArr&& arr)
{
	std::swap(data_, arr.data_);
	std::swap(size_, arr.size_);
	std::swap(capacity_, arr.capacity_);
}

DynArr::DynArr(std::ptrdiff_t s) {
	if (s < 0) {
		throw std::invalid_argument("Size is less than 0 !!!");
	}
	size_ = s;
	capacity_ = s;
	data_ = std::unique_ptr<float>(new float[s]);
	for (size_t i = 0; i < s; i++) {
		data_.get()[i] = 0;
	}
}

DynArr::~DynArr() {
	data_.reset();
	//data_.get() = nullptr;
}

DynArr& DynArr::operator=(const DynArr& arr) {
	size_ = arr.size_;
	capacity_ = arr.capacity_;
	data_ = nullptr;
	data_ = std::unique_ptr<float>(new float[capacity_]);
	for (size_t i = 0; i < capacity_; i++)
	{
		data_.get()[i] = arr.data_.get()[i];
	}
	return *this;
}

DynArr& DynArr::operator=(DynArr&& arr)
{
	std::swap(data_, arr.data_);
	std::swap(size_, arr.size_);
	std::swap(capacity_, arr.capacity_);

	return *this;
}

ptrdiff_t DynArr::Size() {
	return size_;
}
//
//ptrdiff_t DynArr::capacity() {
//	return capacity_;
//}

void DynArr::Resize(ptrdiff_t s) {
	if (s < 0) {
		throw std::invalid_argument("Size is less than 0 !!!");
	}
	if (s < size_) {
		for (size_t i = s; i < size_; i++) {
			data_.get()[i] = 0;
		}
		size_ = s;
	}
	else if (s <= capacity_) {
		for (size_t i = size_; i < s; i++) {
			data_.get()[i] = 0;
		}
		size_ = s;
	}
	else if (s > capacity_) {
		float* tmp = new float[size_];
		for (size_t i = 0; i < size_; i++) {
			tmp[i] = data_.get()[i];
		}
		data_ = std::unique_ptr<float>(new float[s]);
		for (size_t i = 0; i < s; i++) {
			if (i < size_) {
				data_.get()[i] = tmp[i];
			}
			else {
				data_.get()[i] = 0;
			}
		}
		delete[] tmp;
		tmp = nullptr;
		size_ = s;
		capacity_ = s;
	}

}

const float& DynArr::operator[](ptrdiff_t idx)const {
	if (idx >= size_) {
		throw std::invalid_argument("Index is out of Array !!!");
	}
	else if (idx < 0) {
		throw std::invalid_argument("Index is less than 0 !!!");
	}
	else {
		return data_.get()[idx];
	}
}
float& DynArr::operator[](ptrdiff_t idx) {
	if (idx >= size_) {
		throw std::invalid_argument("Index is out of Array !!!");
	}
	else if (idx < 0) {
		throw std::invalid_argument("Index is less than 0 !!!");
	}
	else {
		return data_.get()[idx];
	}
}

bool operator==(DynArr& a, DynArr& b) {
	bool flag = true;
	if (a.Size() != b.Size()) {
		flag = false;
	}
	for (size_t i = 0; i < a.Size(); i++) {
		if (a[i] != b[i]) {
			flag = false;
		}
	}

	return flag;
}