#pragma once

#include <cmath>
#include <stdexcept>
#include <iostream>
#include <cstdint>

#define FROM_FLOAT_PREC 1000000000

namespace Betternumbers {

class Number {
public:
	int64_t den, num;
	Number() {
		den = 1; 
		num = 0;
	}
	Number(int64_t num, int64_t den): num(num), den(den) {}
	Number(int64_t number): num(number), den(1) {}
	Number(int32_t num, int32_t den): num(num), den(den) {}
	Number(int32_t number): num(number), den(1) {}
	Number(const Number& other): num(other.num), den(other.den) {}
	Number(const float number): num(number * FROM_FLOAT_PREC), den(FROM_FLOAT_PREC) {
		normalize();
	}
	Number(const double number): num(number * FROM_FLOAT_PREC), den(FROM_FLOAT_PREC) {
		normalize();
	}

	Number operator+(const Number rhs) const;
	Number operator-(const Number rhs) const;
	Number operator*(const Number rhs) const;
	Number operator/(const Number rhs) const;

	Number operator=(const Number rhs) noexcept;

	Number operator+=(const Number rhs);
	Number operator-=(const Number rhs);
	Number operator*=(const Number rhs);
	Number operator/=(const Number rhs);
	
	operator int64_t() const noexcept {
		return num / den;
	}

	operator float() const noexcept {
		return (float) num / (float) den;
	}

	operator double() const noexcept {
		return (double) num / (double) den;
	}

	friend std::ostream& operator<<(std::ostream& os, const Number& numb) {
		os << (double) numb;
		return os;
	}

	void normalize() noexcept;

private:
	Number add(const Number lhs, const Number rhs) const;
	Number mul(const Number lhs, const Number rhs) const;
	void check(const Number& numb) const;
};

void Number::check(const Number& numb) const {
	if (numb.den == 0) throw std::runtime_error("Invalid denominator");
}

Number Number::add(const Number lhs, const Number rhs) const {
	check(lhs);
	check(rhs);
	Number t;
	if (lhs.den == rhs.den)
		t.num = lhs.num + rhs.num;
	else
		t.num = lhs.num * rhs.den + rhs.num + lhs.den;
	return t;
}

Number Number::mul(const Number lhs, const Number rhs) const {
	check(lhs);
	check(rhs);
	Number t = lhs;
	t.num *= rhs.num;
	t.den *= rhs.den;
	return t;
}

Number Number::operator+(Number rhs) const {
	return add(*this, rhs);
}

Number Number::operator-(Number rhs) const {
	rhs.num *= -1;
	return add(*this, rhs);
}

Number Number::operator*(Number rhs) const {
	return mul(*this, rhs);
}

Number Number::operator/(Number rhs) const {
	auto t = rhs.den;
	rhs.den = rhs.num;
	rhs.num = t;
	return mul(*this, rhs);
}

void Number::normalize() noexcept {
	auto a = std::abs(num);
	auto b = std::abs(den);
	if (a == 1 || b == 1) return;
	if (a == 0) {
		num = 0;
		den = 1;
		return;
	}
	if (b == 0) {
		num = 0;
		den = 0;
		return;
	}

	auto t = b;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	if (a == 1) return;
	num /= a;
	den /= a;
	return;
}

Number Number::operator=(const Number rhs) noexcept {
	num = rhs.num;
	den = rhs.den;
	return *this;
}

Number Number::operator+=(const Number rhs) {
	Number t = *this + rhs;
	this->num = t.num;
	this->den = t.den;
	return *this;
}

Number Number::operator-=(const Number rhs) {
	Number t = *this - rhs;
	this->num = t.num;
	this->den = t.den;
	return *this;
}

Number Number::operator*=(const Number rhs) {
	Number t = *this * rhs;
	this->num = t.num;
	this->den = t.den;
	return *this;
}

Number Number::operator/=(const Number rhs) {
	Number t = *this / rhs;
	this->num = t.num;
	this->den = t.den;
	return *this;
}


}