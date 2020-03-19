#ifndef MATRIX_H
#define MATRIX_H

/** Tresc zadania:
Ćw2 [16pkt] Przeciążanie operatorów w C++
Plan zajęć:
    Proszę uzupełnić dane w pliku programmerDetails.h

    Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
           - tablice typu MatrixElement (tzn. int), oraz size (=2)
           - konstruktory:
             - bezargumentowy - zerujący wszystkie elementy
             - kopiujący
             - przyjmujący jako argument tablicę (const MatrixElement matrix[size][size]) i kopiujący z niej wartości
           - funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
           - funkcja zwracająca size o nazwie (getSize()), proponuję aby była static constexpr
    Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
        - operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
        - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
            TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna
            TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy
        - zadany operator logiczny (metoda klasy),
            TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), proszę pamiętać o wersji const
            MatrixElement* operator[](size_t i);
        - operator konwersji do size_t, zwracający to co getSize() (metoda klasy),
    Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"

Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

Punktacja zdalna: (jak ktoś się nie zgadza proszę o informacje, wtedy ocenimy wg punktacji z treści zadania):
- do 9p: przejście wszystkich testów automatycznych
- 1p: wszystkie atrybuty powinny być prywatne
- 1p: konstruktory i metody - publiczne
- 1p: metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane poza klasą
- 1p: obiekty typów klasowych powinny być w miarę możliwości przekazywane w argumentach funkcji przez referencję
- 1p: proszę też stosować słówko "const" w odpowiednich miejscach
- 1p: ogólna estetyka/czytelność kodu
- 1p: podział na pliki matrix.h i matrix.cpp
**/

#include <iosfwd>

#include "matrixElement.h"


class TwoDimensionMatrix
{
private:

	constexpr static int size = 2;
	MatrixElement matrix[size][size];

public:

	TwoDimensionMatrix();

	TwoDimensionMatrix(const TwoDimensionMatrix& matrix);

	TwoDimensionMatrix(const MatrixElement matrix[size][size]);

	MatrixElement get(int i, int j) const {
		return matrix[i][j];
	}

	int static constexpr getSize() {
		return size;
	}

	void TwoDimensionMatrix::set(int i, int j, int value) {
		this->matrix[i][j] = value;
	}

	friend std::ostream& operator<<(std::ostream& o, const TwoDimensionMatrix& twoDimensionMatrix);

	friend TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2);

	TwoDimensionMatrix& operator*=(MatrixElement number);

	TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;

	const MatrixElement* operator[](size_t i) const {
		return matrix[i];
	}

	MatrixElement* operator[](size_t i) {
		return matrix[i];
	}

	operator size_t () const {
		return (size_t)size;
	}
};

#endif // MATRIX_H