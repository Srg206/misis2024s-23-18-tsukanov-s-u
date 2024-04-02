#include"bitset.hpp"
#include <bitset> 
#include <iostream> 

BitSet::BitSet(const std::uint32_t s)
{
	Resize(s);
}

BitSet::BitSet(const BitSet& rhs) noexcept{
	n = rhs.n;
	bits = rhs.bits;
}

BitSet::BitSet(BitSet&& rhs) noexcept{
	std::swap(n, rhs.n);
	std::swap(bits, std::move(rhs.bits));

}

BitSet& BitSet::operator=(const BitSet& rhs) noexcept
{
	n = rhs.n;
	bits = rhs.bits;
	return *this;
}

BitSet& BitSet::operator=(BitSet&& rhs) noexcept
{
	std::swap(n, rhs.n);
	std::swap(bits, std::move(rhs.bits));
	return *this;
}

void BitSet::Resize(int s){
	if (s <= 0) {
		throw( std::exception( "could not resize to 0 or lower size"));
	}
	if (n >= s) {
		bits.resize(ceil(static_cast<float>(s) / 32));
	}
	else {

		int start = ceil(static_cast<float>(n) / 32);
		int finish = ceil(static_cast<float>(s) / 32);
		for (int i = start; i < finish; i++) {
			bits.push_back(0);
		}
	}
	n = s;
}

uint32_t BitSet::Size() const noexcept{
	return n;
}

bool BitSet::Get(const uint32_t ind) const
{
	if (ind > n) {
		throw std::exception("index is out of range of bitset!");
	}
	int num_of_el = (ind-1) / 32;
	int num_of_bit = ((ind-1) % 32);
	uint32_t tmp = bits[num_of_el];
	return (tmp>>num_of_bit)%2;
}

void BitSet::Set(const uint32_t ind, bool val)
{
	if (ind > n) {
		throw std::exception("index is out of range of bitset!");
	}
	if (Get(ind)==val) {
		return;
	}
	int num_of_el = (ind - 1) / 32;
	int num_of_bit = ((ind - 1) % 32);
	if (val) {
		bits[num_of_el] += (pow(2, num_of_bit));
	}
	else {
		bits[num_of_el] -= (pow(2, num_of_bit));

	}
}

void BitSet::fill(const bool val) noexcept
{
	if (val) {
		for (int i = 0; i < ceil(static_cast<float>(n)/32); i++) {
			bits[i] = UINT32_MAX;
		}
	}
	else {
		for (int i = 0; i < ceil(static_cast<float>(n) / 32); i++) {
			bits[i] = 0;
		}
	}
}

void BitSet::print(){
	for (auto x : bits) {
		std::cout << std::bitset<sizeof(x) * 8>(x);
	}
	std::cout << std::endl;
}

bool BitSet::operator==(const BitSet& rhs) const noexcept
{
	bool equal = true;
	if (rhs.Size() != n) {
		equal = false;
		return equal;
	}
	else {
		for (size_t i = 1; i < n; i++) {
			if (Get(i) != rhs.Get(i)) {
				equal = false;
				break;
			}
		}
	}
	return equal;
}

bool BitSet::operator!=(const BitSet& rhs) const noexcept
{
	return !(*this==rhs);
}

BitSet& BitSet::operator&=(const BitSet& rhs)
{
	*this = (*this) & rhs;
	return *this;
}

BitSet& BitSet::operator|=(const BitSet& rhs)
{
	*this = (*this) | rhs;
	return *this;
}

BitSet& BitSet::operator^=(const BitSet& rhs)
{
	*this = (*this) ^ rhs;
	return *this;
}

BitSet& BitSet::operator~()
{
	//BitSet res(lhs);
	for (size_t i = 1; i < Size(); i++) {
		Set(i, !Get(i));
	}
	return *this;
}

BitSet::BiA& BitSet::operator[](const uint32_t ind){
	BiA res(*this, ind);
	return res;
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs)
{
	int s = (lhs.Size() > rhs.Size()) ? rhs.Size() : lhs.Size();
	BitSet res;
	res.Resize(s);
	res.fill(0);


	for (size_t i = 1; i <= s; i++){
		bool l = lhs.Get(i);
		bool r = rhs.Get(i);
		res.Set(i, l && r);
	}
	return res;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs)
{
	BitSet res;
	if (lhs.Size() >= rhs.Size()) {
		res = lhs;
	}
	else {
		res = rhs;
	}
	int s = (lhs.Size() > rhs.Size()) ? rhs.Size() : lhs.Size();

	for (size_t i = 1; i <= s; i++) {
		bool l = lhs.Get(i);
		bool r = rhs.Get(i);
		res.Set(i, l || r);
	}
	return res;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs)
{
	BitSet res;
	if (lhs.Size() >= rhs.Size()) {
		res = lhs;
	}
	else {
		res = rhs;
	}
	int s = (lhs.Size() > rhs.Size()) ? rhs.Size() : lhs.Size();

	for (size_t i = 1; i <= s; i++) {
		bool l = lhs.Get(i);
		bool r = rhs.Get(i);
		res.Set(i, l ^r);
	}
	for (size_t i = s+1; i <= res.Size(); i++){
		res.Set(i, res.Get(i) ^0);

	}
	return res;
}

BitSet operator~(const BitSet& lhs)
{
	BitSet res(lhs);
	for (size_t i = 1; i < res.Size(); i++) {
		res.Set(i, !lhs.Get(i));
	}
	return res;
}

BitSet::BiA::BiA(BitSet& b_, uint32_t ind_):
b(b_), ind(ind_)
{
}

BitSet::BiA& BitSet::BiA::operator=(const bool bit)
{
	b.Set(ind, bit);
	return *this;
}

BitSet::BiA::operator bool() const
{
	return b.Get(ind);
}



//bool BitSet::BiA::opeartor() const{
//
//	return b.Get(ind);
//}
