#include <iostream>

#include "matrix.h"

// TODO:
TwoDimensionMatrix::TwoDimensionMatrix() {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->matrix[i][j] = 0;
		}
	}
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& matrix) {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix[size][size]) {
	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size; j++)
			this->matrix[i][j] = matrix[i][j];
}


std::ostream& operator<<(std::ostream& o, TwoDimensionMatrix const& twoDimensionMatrix) {
	o << "Size: " << twoDimensionMatrix.size << "\n";
	for (int i = 0; i < twoDimensionMatrix.getSize(); i++) {
		for (int j = 0; j < twoDimensionMatrix.getSize(); j++) {
			o << twoDimensionMatrix.get(i, j) << " ";
		}
		o << "\n";
	}
	return o;
}


TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
	TwoDimensionMatrix result;
	for (int i = 0; i < matrix1.getSize(); i++) {
		for (int j = 0; j < matrix1.getSize(); j++) {
			result.set(i, j, matrix1[i][j] + matrix2[i][j]);
		}
	}
	return result;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->matrix[i][j] *= number;
		}
	}
	return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const {
	TwoDimensionMatrix result;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			result.matrix[i][j] = this->matrix[i][j] && matrix.matrix[i][j];
		}
	}
	return result;
}