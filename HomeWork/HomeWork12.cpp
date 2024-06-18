#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

	int gcd(int a, int b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	void reduce() {
		int div = gcd(abs(numerator), abs(denominator));
		numerator /= div;
		denominator /= div;
		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}

public:
	Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
		if (den == 0)
		{
			numerator = 0;
			denominator = 1;
		}
		reduce();
	}

	void setNum(int num) {
		numerator = num;
		reduce();
	}

	void setDen(int den) {
		if (den == 0) { return; }
		denominator = den;
		reduce();
	}

	int getNum() { return numerator; }
	int getDen() { return denominator; }

	Fraction operator+(const Fraction& other) const {
		int new_numerator = numerator * other.denominator + denominator * other.numerator;
		int new_denomitator = denominator * other.denominator;
		return(Fraction(new_numerator, new_denomitator));
	}

	Fraction operator-(const Fraction& other) const {
		int new_numerator = numerator * other.denominator - denominator * other.numerator;
		int new_denomitator = denominator * other.denominator;
		return(Fraction(new_numerator, new_denomitator));
	}

	Fraction operator*(const Fraction& other) const {
		int new_numerator = numerator * other.numerator;
		int new_denomitator = denominator * other.denominator;
		return(Fraction(new_numerator, new_denomitator));
	}

	Fraction operator/(const Fraction& other) const {
		if (other.numerator == 0)
		{
			return(Fraction(0, 1));
		}
		int new_numerator = numerator * other.denominator;
		int new_denominator = denominator * other.numerator;
		return(Fraction(new_numerator, new_denominator));
	}

	void print() {
		cout << numerator << "/" << denominator << endl;
	}
};


int main() {
	Fraction drob1(3, 5);
	Fraction drob2(8, 15);

	Fraction sum = drob1 + drob2;
	sum.print();
	Fraction dif = drob1 - drob2;
	dif.print();
	Fraction mul = drob1 * drob2;
	mul.print();
	Fraction div = drob1 / drob2;
	div.print();
}