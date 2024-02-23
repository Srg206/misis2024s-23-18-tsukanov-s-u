#include<iostream>

class Rational {
public:
	Rational() = default;
	Rational(const int64_t n, const int64_t d);
	explicit Rational(const int64_t n);
	Rational(const Rational& R) = default;
	~Rational() = default;
	Rational& operator=(const Rational& R) = default;


	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	bool operator==(const Rational& b);
	bool operator!=(const Rational& b);
	bool operator<(const Rational& b);
	bool operator>(const Rational& b);
	bool operator<=(const Rational& b);
	bool operator>=(const Rational& b);

	int64_t get_num() const ; 
	int64_t get_den() const;


	std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	std::istream& ReadFrom(std::istream& istrm);

	//static const char div = '/';

private:
	void shorten_the_fraction();
	int64_t num = 0; //сверху
	int64_t den = 1; //снизу 

};

int64_t greatest_common_divisor(int64_t a, int64_t b);
int64_t least_common_multiple(int64_t a, int64_t b);
std::ostream& operator<<(std::ostream& out, const Rational& r);
std::istream& operator>>(std::istream& in, Rational& r);

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);


Rational operator+(const Rational& a, const int64_t b);
Rational operator-(const Rational& a, const int64_t b);
Rational operator*(const Rational& a, const int64_t b);
Rational operator/(const Rational& a, const int64_t b);

Rational operator+(const int64_t b, const Rational& a);
Rational operator-(const int64_t b, const Rational& a);
Rational operator*(const int64_t b, const Rational& a);
Rational operator/(const int64_t b, const Rational& a);

