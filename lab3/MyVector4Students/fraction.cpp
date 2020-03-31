#include "fraction.h"
#include <iostream>
#include<math.h>

Fraction::Fraction(int n, int d) {
	this->numerator = n;
	if (d == 0) {
		throw std::invalid_argument("Denominator can not equal 0");
	}
	else {
		this->denominator = d;
	}
}

int Fraction::getNumerator() const {
	return this->numerator;
}

int Fraction::getDenominator() const {
	return this->denominator;
}

void Fraction::setNumerator(int x) {
	this->numerator = x;
}
void Fraction::setDenominator(int x) {
	if (x == 0) {
		throw std::invalid_argument("Denominator can not equal 0");
	}
	else {
		this->denominator = x;
	}
}

int NWD(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


Fraction fracNWD(Fraction frac) {

	if (frac.getDenominator() < 1 || frac.getNumerator() < 0) {
		return frac;
	}
	else {
		Fraction result;
		result.setNumerator(frac.getNumerator() / NWD(frac.getDenominator(), frac.getNumerator()));
		result.setDenominator(frac.getDenominator() / NWD(frac.getDenominator(), frac.getNumerator()));
		return result;
	}
}

Fraction Fraction::operator+ (const Fraction frac) {
	if (this->getDenominator() == frac.getDenominator()) {
		Fraction result;
		result.setNumerator(this->getNumerator() + frac.getNumerator());
		result.setDenominator(this->getDenominator());
		return fracNWD(result);
	}
	else {
		Fraction result;
		result.setNumerator(this->getNumerator() * frac.getDenominator() + frac.getNumerator() * this->getDenominator());
		result.setDenominator(this->getDenominator() * frac.getDenominator());
		return fracNWD(result);
	}
}

Fraction Fraction::operator* (const Fraction frac) {
	Fraction result;
	result.setNumerator(this->getNumerator() *  frac.getNumerator() );
	result.setDenominator(this->getDenominator() * frac.getDenominator());
	return fracNWD(result);
}