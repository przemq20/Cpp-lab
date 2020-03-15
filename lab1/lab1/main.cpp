#include <iostream>
#include <string>

using namespace std;


class Cone {

	int height;
	int radius;
	static int ilosc;
	const string nazwa;
	const static int defHeight;
	constexpr static int comp = 1;

public:
	Cone() : Cone(1, 1) {}

	Cone(int r, int h = defHeight) {
		height = h;
		radius = r;
		ilosc++;
	}

	~Cone() {
		ilosc--;
	}


	int getHeight() const { return height; }

	int getRadius() const { return this->radius; }

	void setHeight(int h) {
		height = h;
	}

	void setRadius(int r) {
		radius = r;
	}

	void wypisz() {
		cout << "Wysokosc: " + to_string(height) + ", Promien: " + to_string(radius);
	}

	static int getIlosc() {
		return ilosc;
	}

	friend ostream& operator<< (ostream& o, const Cone& cone);
	friend istream& operator>> (istream& i, Cone& cone);

	const string getName() const { return nazwa; };
	const int getDefHeight() const { return defHeight; };
	constexpr int getComp() const { return comp; };
};

ostream& operator<< (ostream& o, const Cone& cone) {
	return o << "Promien: " << cone.radius << " Wysokosc: " << cone.height;
}

istream& operator>> (istream& i, Cone& cone) {
	return i >> cone.radius >> cone.height;
}


int Cone::ilosc = 0;
const int  Cone::defHeight = 1;


int main()
{
	Cone cone1;
	cout << cone1.getIlosc() << endl;
	Cone cone2(2, 2);
	Cone cone3(3, 3);
	cout << cone1.getIlosc() << endl;
	cout << cone1.getHeight();
	cone1.setHeight(2);
	cout << cone1.getHeight() << endl;;
	cout << cone2.getRadius() << endl;
	cone2.setRadius(122);
	cout << cone2.getRadius() << endl;
	cone3.wypisz();
	cout << "\n";

	cout << (cout, cone1);
}

