#include"rational.hpp"


Rational::Rational(int64_t n) {
	num = n;
	den = 1;
}


int64_t greatest_common_divisor(int64_t a, int64_t b) {
	a = abs(a);
	b = abs(b);
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return greatest_common_divisor(a % b, b);
	return greatest_common_divisor(a, b % a);
}

int64_t least_common_multiple(int64_t a, int64_t b) {
	return (a * b) / greatest_common_divisor(a, b);
}
void Rational::shorten_the_fraction() {
	int64_t tmp_div = greatest_common_divisor(num, den);
	num /= tmp_div;
	den /= tmp_div;

}
Rational::Rational(const int64_t n, const int64_t d) {
	if (d == 0) {
		throw  std::exception("   ERORR: DENOMINATOR CAN`T BE EQUAL ZERO !!!!  ");
	}
	num = n;
	den = d;
	shorten_the_fraction();

}

Rational& Rational::operator+=(const Rational& rhs) {
	int64_t tmp_den= least_common_multiple(den, rhs.get_den());
	num = num*(tmp_den/den) + rhs.get_num()*(tmp_den/rhs.get_den());
	den = tmp_den;
	shorten_the_fraction();
	return *this;
}


Rational& Rational::operator-=(const Rational& rhs) {
	int64_t tmp_den= least_common_multiple(den, rhs.get_den());
	num = num*(tmp_den/den) - rhs.get_num()*(tmp_den/rhs.get_den());
	den = tmp_den;
	shorten_the_fraction();
	return *this;
}


Rational& Rational::operator*=(const Rational& rhs) {
	num = num * rhs.get_num();
	den = den * rhs.get_den();
	shorten_the_fraction();
	return *this;
}


Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.get_num() == 0) {
		throw std::exception("Erorr division by zero !!!");
	}
	num = num * rhs.get_den();
	den = den * rhs.get_num();
	shorten_the_fraction();
	return *this;
}

int64_t Rational::get_num() const
{
	return num;
}

int64_t Rational::get_den() const
{
	return den;
}

std::ostream& Rational::WriteTo(std::ostream& out) const noexcept
{
	out << num << '/' << den;
	return out;
	// TODO: вставьте здесь оператор return
}

std::istream& Rational::ReadFrom(std::istream& in)
{
	int64_t n = 0;
	int64_t d = 0;
	char bar = ' ';
	in >> n >> bar >> d;
	if (bar == '/') {
		num = n;
		den = d;
		shorten_the_fraction();
	}
	else {
		throw(std::exception("Format is incorrect"));
	}
	return in;
}

std::istream& operator>>(std::istream& in, Rational& r) {
	
	r.ReadFrom(in);
	return in;

}


std::ostream& operator<<(std::ostream& out, const Rational& r) {
	r.WriteTo(out);
	return out;
}
bool Rational::operator==(const Rational& a) {
	if (den == a.get_den() && get_num() == a.get_num()) {
		return true;
	}
	else{
		return false;
	}
}
bool Rational::operator!=( const Rational& a) {
	return !(*(this)==a);
}
bool Rational::operator<(const Rational& a) {
	int64_t tmp_den = least_common_multiple(get_den(),a.get_den());
	int64_t a_num((tmp_den / get_den()) * get_num());
	int64_t b_num((tmp_den / a.get_den()) * a.get_num());

	if (a_num < b_num) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator<=( const Rational& a) {
	int64_t tmp_den = least_common_multiple(get_den(),a.get_den());
	int64_t a_num((tmp_den / get_den()) * get_num());
	int64_t b_num((tmp_den / a.get_den()) * a.get_num());

	if (a_num <= b_num) {
		return true;
	}
	else {
		return false;
	}
}


bool Rational::operator>(const Rational& a) {
	int64_t tmp_den = least_common_multiple(a.get_den(),get_den());
	int64_t a_num((tmp_den / get_den()) * get_num());
	int64_t b_num((tmp_den / a.get_den()) * a.get_num());

	if (a_num > b_num) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator>=( const Rational& a) {
	int64_t tmp_den = least_common_multiple(get_den(),a.get_den());
	int64_t a_num((tmp_den / get_den()) * get_num());
	int64_t b_num((tmp_den / a.get_den()) * a.get_num());

	if (a_num >= b_num) {
		return true;
	}
	else {
		return false;
	}
}





Rational operator+(const Rational& a, const  Rational& b) {
	return Rational(a) += b;
}
Rational operator-(const Rational& a, const Rational& b) {
	return Rational(a) -= b;
}
Rational operator*(const Rational& a, const Rational& b) {
	return Rational(a) *= b;
}
Rational operator/(const Rational& a, const Rational& b) {
	return Rational(a) /= b;
}



Rational operator+(const Rational& a, const int64_t b) {
	Rational c(a);
	Rational d(b);
	c += d;
	return c;
}
Rational operator-(const Rational& a, const int64_t b) {
	Rational c(a);
	Rational d(b);

	c -= d;
	return c;
}
Rational operator*(const Rational& a, const int64_t b) {
	Rational c(a);
	Rational d(b);

	c *= d;
	return c;
}
Rational operator/(const Rational& a, const int64_t b) {
	Rational c(a);
	Rational d(b);

	c /= d;
	return c;
}



Rational operator+(const int64_t b , const Rational &a) {
	Rational c(a);
	Rational d(b);
	c += d;
	return c;
}
Rational operator-(const int64_t b, const Rational& a) {
	Rational c(a);
	Rational d(b);

	c -= d;
	return c;
}
Rational operator*(const int64_t b, const  Rational& a) {
	Rational c(a);
	Rational d(b);

	c *= d;
	return c;
}
Rational operator/(const int64_t b, const Rational& a) {
	Rational c(a);
	Rational d(b);

	c /= d;
	return c;
}










