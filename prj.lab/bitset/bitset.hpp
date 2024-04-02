#ifndef BITSET_HPP
#define BITSET_HPP
#include<vector>

class BitSet {
private:
	std::vector<uint32_t> bits;
	int n = 0;
	class BiA {
	private:
		BitSet& b;
		uint32_t ind = 0;
	public:
		BiA()= delete;
		BiA(BitSet& _b, uint32_t ind);
		BiA& operator=(const BiA& other) = default;
		BiA& operator=(const bool bit);
		operator bool() const;

	};
public:
	BitSet() = default;
	BitSet(const uint32_t s);;
	~BitSet() = default;
	BitSet(const BitSet& rhs) noexcept;
	BitSet(BitSet&& rhs) noexcept;

	BitSet& operator=(const BitSet& rhs)  noexcept;
	BitSet& operator=(BitSet&& rhs) noexcept;

	void Resize(int s);
	uint32_t Size() const noexcept;
	bool Get(const uint32_t ind) const;
	void Set(const uint32_t ind, bool val);
	void fill(const bool) noexcept;
	void print();

	[[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
	[[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

	[[nodiscard]] BitSet& operator&=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator|=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator^=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator~();
	
	BiA& operator[](const uint32_t ind);


};

BitSet operator& (const BitSet& lhs, const BitSet& rhs);
BitSet operator| (const BitSet& lhs, const BitSet& rhs);
BitSet operator^ (const BitSet& lhs, const BitSet& rhs);


#endif