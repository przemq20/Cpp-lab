#include "vector.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

Vector::Vector(int number) : vecSize(0), vecCapacity(number) {
	this->data = new Fraction[number];
}

Vector::~Vector() {
	delete[] this->data;
	this->vecSize = 0;
	this->vecCapacity = 0;
}

Vector::Vector(const Vector& other) : vecSize(other.size()), vecCapacity(other.capacity()) {
	this->data = new Fraction[other.size()];
	std::memcpy(data, other.data, sizeof(Fraction) * other.size());
}

Vector::Vector(Vector&& other) : data(other.data), vecSize(other.size()), vecCapacity(other.capacity()) {
	other.data = nullptr;
	other.vecSize = 0;
	other.vecCapacity = 0;
}

Vector& Vector::operator=(const Vector& other) {
	this->data = other.data;
	this->vecSize = other.vecSize;
	this->vecCapacity = other.vecCapacity;
	return *this;
}

Vector& Vector::operator=(Vector&& other) {
	this->data = other.data;
	this->vecSize = other.vecSize;
	this->vecCapacity = other.vecCapacity;
	other.data = NULL;
	other.vecSize = 0;
	other.vecCapacity = 0;
	return *this;
}

void Vector::push_back(const Fraction& frac) {
	if (this->vecSize == this->vecCapacity) {
		this->data = (Fraction*)realloc(this->data, this->capacity() + 1);
		this->vecCapacity++;
	}
	this->data[this->vecSize] = frac;
	this->vecSize++;
}

const Fraction& Vector::operator[](size_t index) const {
	if (index >= this->vecSize) {
		throw std::out_of_range("Index is bigger than vector size");
	}
	else {
		return this->data[index];
	}
}


