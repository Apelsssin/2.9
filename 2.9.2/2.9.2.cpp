#include <iostream>
class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	int get_num() { return numerator_; };
	int get_den() { return denominator_; }
	void simplification() {
		int min;
		(numerator_ <= denominator_) ? min = numerator_ : min = denominator_;
		if (min < 0) { min = -min; }
			for (int i = min; i >= 2; i--) {
				if ((numerator_ % i) == 0 && (denominator_ % i) == 0) {
					numerator_ = numerator_ / i;
					denominator_ = denominator_ / i;
					
				}
			}
			
	}
	Fraction operator+(Fraction& x) { return  Fraction(((numerator_ * x.denominator_) + (denominator_ * x.numerator_)), (denominator_ * x.denominator_)); }
	Fraction operator-(Fraction& x) { return Fraction((numerator_ * x.denominator_) - (denominator_ * x.numerator_), (denominator_ * x.denominator_));}
	Fraction operator*(Fraction& x) { return Fraction(numerator_ * x.numerator_, denominator_ * x.denominator_); }
	Fraction operator/(Fraction& x) { return Fraction (numerator_ * x.denominator_, denominator_ * x.numerator_); }
	Fraction operator++() {
		numerator_ = (numerator_ + denominator_);
		return Fraction(numerator_, denominator_); }
	Fraction operator--() { 
		numerator_ = numerator_ - denominator_;
		return Fraction(numerator_, denominator_); }
	Fraction operator++(int) { 
		int num = numerator_;
		numerator_ = numerator_ + denominator_;
		return Fraction(num, denominator_); }
	Fraction operator--(int) { 
		int num = numerator_;
		numerator_ = numerator_ - denominator_;
		return Fraction(num, denominator_); }
	Fraction operator-() { return Fraction(-numerator_, denominator_); }
};
int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		int n;
		int m;
		std::cout << "Введите числитель дроби 1: ";
		std::cin >> n;
		std::cout << "Введите знаменатель дроби 1: ";
		std::cin >> m;
		if (m == 0) { throw std::exception("Деление на 0!"); }
		Fraction f1(n, m);
		std::cout << "Введите числитель дроби 2: ";
		std::cin >> n;
		std::cout << "Введите знаменатель дроби 2: ";
		std::cin >> m;
		if (m == 0) { throw std::exception("Деление на 0!"); }
		Fraction f2(n, m);

		Fraction f3 = f1 + f2;
		f3.simplification();
		std::cout << f1.get_num() << "/" << f1.get_den() << " + " << f2.get_num() << "/" << f2.get_den() << " = " << f3.get_num() << "/" << f3.get_den() << std::endl;
		Fraction f4 = f1 - f2;
		f4.simplification();
		std::cout << f1.get_num() << "/" << f1.get_den() << " - " << f2.get_num() << "/" << f2.get_den() << " = " << f4.get_num() << "/" << f4.get_den() << std::endl;
		Fraction f5 = f1 * f2;
		f5.simplification();
		std::cout << f1.get_num() << "/" << f1.get_den() << " * " << f2.get_num() << "/" << f2.get_den() << " = " << f5.get_num() << "/" << f5.get_den() << std::endl;
		Fraction f6 = f1 / f2;
		f6.simplification();
		std::cout << f1.get_num() << "/" << f1.get_den() << " / " << f2.get_num() << "/" << f2.get_den() << " = " << f6.get_num() << "/" << f6.get_den() << std::endl;
		std::cout << "++" << f1.get_num() << "/" << f1.get_den();
		Fraction f7 = (++f1) * f2;
		f7.simplification();
		std::cout << " * " << f2.get_num() << "/" << f2.get_den() << " = " << f7.get_num() << "/" << f7.get_den() << std::endl;
		std::cout << "Значение дроби 1 = " << f1.get_num() << "/" << f1.get_den() << std::endl;
		Fraction f8 = (f1--) * f2;
		f8.simplification();
		std::cout << f1.get_num() << "/" << f1.get_den() << "-- * " << f2.get_num() << "/" << f2.get_den() << " = " << f8.get_num() << "/" << f8.get_den() << std::endl;
		std::cout << "Значение дроби 1 = " << f1.get_num() << "/" << f1.get_den() << std::endl;
	}
	catch (std::exception str) {
		std::cout << str.what() << std::endl;
	}
}
