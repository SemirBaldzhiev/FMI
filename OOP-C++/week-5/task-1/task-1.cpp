#include <iostream>

class Rational {

	int numerator;
	int denominator;

public:
	void initialize(int numer, int denom) {

		numerator = numer;
		denominator = denom;

		int gcdNum = gcd(numerator, denominator);

		numerator /= gcdNum;
		denominator /= gcdNum;
	}

	Rational negate() const {
		Rational rational;
		rational.numerator = (-1) * numerator;
		rational.denominator = denominator;

		return rational;
	}

	Rational reciprocal() const {
		Rational rational;

		rational.numerator = denominator;
		rational.denominator = numerator;

		return rational;
	}

	Rational add(const Rational& num) const {

		Rational result;

		int gcdNum = gcd(denominator, num.denominator);

		result.numerator = numerator * (denominator / gcdNum) + num.numerator * (num.denominator / gcdNum);
		result.denominator = num.denominator * denominator;

		return result;

	}

	Rational subtract(const Rational& num) const {
		Rational result;

		int gcdNum = gcd(denominator, num.denominator);

		result.numerator = numerator * (denominator / gcdNum) - num.numerator * (num.denominator / gcdNum);
		result.denominator = num.denominator * denominator;

		return result;
	}

	Rational divide(const Rational& num) const {

		Rational result;

		Rational recip = num.reciprocal();

		result.numerator = numerator * recip.numerator;
		result.denominator = denominator * recip.denominator;

		return result;
	}

	Rational multiply(const Rational& num) const {

		Rational result;

		result.numerator = numerator * num.numerator;
		result.denominator = denominator * num.denominator;

		return result;
	}

	void print() {
		std::cout << this->numerator << "/" << this->denominator << std::endl;
	}

private:
	int gcd(int a, int b) const {

		while (a != b) {
			if (a > b) a -= b;
			else b -= a;
		}

		return a;
	}
};


int main()
{
	Rational rat;

	rat.initialize(1, 2);

	Rational addR;
	addR.initialize(1, 2);

	Rational result = rat.add(addR);

	Rational subR;
	subR.initialize(1, 3);

	//Rational result = rat.subtract(subR);


	result.print();

	return 0;
}