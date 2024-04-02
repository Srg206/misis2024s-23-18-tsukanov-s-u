#ifndef BITSET_HPP
#define BITSET_HPP
#include <vector>
#include <cstdint>

class BitSet {
private:
	std::vector<uint32_t> bits;
	int n = 0;
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
	bool Get(const uint32_t) const;
	void Set(const uint32_t, bool);
	void fill(const bool) noexcept;
	void print();

	[[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
	[[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

	[[nodiscard]] BitSet& operator&=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator|=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator^=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator~();

};

BitSet operator& (const BitSet& lhs, const BitSet& rhs);
BitSet operator| (const BitSet& lhs, const BitSet& rhs);
BitSet operator^ (const BitSet& lhs, const BitSet& rhs);
BitSet operator~ (const BitSet& lhs);


#endif