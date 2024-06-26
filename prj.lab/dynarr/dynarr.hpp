#ifndef DYNARR_HPP
#define DYNARR_HPP
#include<iostream>
#include<memory>


class DynArr {
public:
	DynArr()=default;
	DynArr( const DynArr &arr);
	DynArr( DynArr &&arr);
	DynArr(std::ptrdiff_t s);
	~DynArr();

	DynArr& operator=(const DynArr& arr);
	DynArr& operator=(DynArr&& arr);
	
	std::ptrdiff_t Size();
	void Resize(std::ptrdiff_t s);
	const float& operator[](std::ptrdiff_t idx) const;
	float& operator[](std::ptrdiff_t idx);

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t capacity_ = 0;
	std::unique_ptr<float> data_ = nullptr;

};

bool operator==(DynArr& a, DynArr& b);


#endif // !DYNARR_HPP
