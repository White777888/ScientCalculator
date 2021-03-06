#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

long double my_abs(long double val);

long double my_Pi(long double accuracy = 0.000001);

long double my_sqrt(long double x, long double accuracy = 0.000001);
long double my_cbrt(long double x, long double accuracy = 0.000001);

long int my_floor(long double num);
long int my_ceil(long double num);
long int my_round(long double num);

long double my_sin(long double x, long double accuracy = 0.00001);
long double my_cos(long double x, long double accuracy = 0.00001);
long double my_tan(long double x, long double accuracy = 0.00001);

long double my_exp(long double x, long double accuracy = 0.00001);

long double integral(long double a, long double b, long double accuracy = 0.00001);
long double my_ln(long double x, long double accuracy = 0.00001);

long double my_pow(long double a, long int n);
long double my_pow(long double a, long double n, long double accuracy = 0.0000001);

bool check(string str) {

	try {
		for (unsigned long int i = 0; i < str.size(); i++) {
			if (!isdigit(str[i]) && str[i] != '-' &&
				str[i] != '+' && str[i] != '.')
				throw - 1;
		}
	}
	catch (int i) {
		throw;
	}

	return true;
}

int main()
{

	short int choice = 1;
	cout << "Welcome to my Scientific Calculator!\n";

	string buf;

	//You can use two variables of the long double type. 
	//I just improve code readability
	long double x, degree;
	long double num;
	long double rad;

	unsigned long int i = 0;

	do {
		cout << "What do you want?\n";
		cout << "1.Get the PI number\n";
		cout << "2.Get the square root\n";
		cout << "3.Get the cube root\n";
		cout << "4.Use the round function\n";
		cout << "5.Use the ceil function\n";
		cout << "6.Use the floor function\n";
		cout << "7.Calculate the sin(x)\n";
		cout << "8.Calculate the cos(x)\n";
		cout << "9.Calculate the tan(x)\n";
		cout << "10.Calcute the exponent\n";
		cout << "11.Raise the number to a power\n";
		cout << "12.Calcute the natural log\n";
		cout << "13.Exit\n";
		cin >> choice;

		try {
			switch (choice) {
			case 1:
				cout << "\npi = " << my_Pi() << "\n\n";
				break;
			case 2:
				cout << "Enter x: ";
				cin >> buf;
				check(buf);
				x = atof(buf.c_str());
				cout << "\nThe square root of " << x <<
					" is equal to " << my_sqrt(x) << "\n\n";
				break;
			case 3:
				cout << "Enter x: ";
				cin >> buf;
				check(buf);
				x = atof(buf.c_str());
				cout << "\nThe cube root of " << x <<
					" is equal to " << my_cbrt(x) << "\n\n";
				break;
			case 4:
				cout << "Enter number: ";
				cin >> buf;
				check(buf);
				num = atof(buf.c_str());
				cout << "\nMathematical rounding of the number " <<
					num << " is equal to " << my_round(num) << "\n\n";
				break;
			case 5:
				cout << "Enter number: ";
				cin >> buf;
				check(buf);
				num = atof(buf.c_str());
				cout << "\nRounding up the number " << num <<
					" is equal to " << my_ceil(num) << "\n\n";
				break;
			case 6:
				cout << "Enter number: ";
				cin >> buf;
				check(buf);
				num = atof(buf.c_str());
				cout << "\nRounding down the number " << num <<
					" is equal to " << my_floor(num) << "\n\n";
				break;
			case 7:
				cout << "Enter radians: ";
				cin >> buf;

				if (buf == "pi")
					rad = my_Pi();
				else {
					check(buf);
					rad = atof(buf.c_str());
				}
				cout << "\nsin(" << rad << ") = " << my_sin(rad) << "\n\n";
				break;
			case 8:
				cout << "Enter radians: ";

				cin >> buf;

				if (buf == "pi")
					rad = my_Pi();
				else {
					rad = atof(buf.c_str());
					check(buf);
					rad = atof(buf.c_str());
				}
				cout << "\ncos(" << rad << ") = " << my_cos(rad) << "\n\n";
				break;
			case 9:
				cout << "Enter radians: ";

				cin >> buf;

				if (buf == "pi")
					rad = my_Pi();
				else {
					rad = atof(buf.c_str());
					check(buf);
					rad = atof(buf.c_str());
				}
				cout << "\ntan(" << rad << ") = " << my_tan(rad) << "\n\n";
				break;
			case 10:
				cout << "Enter x: ";
				cin >> buf;
				check(buf);
				x = atof(buf.c_str());
				cout << "\nexp(" << x << ") = " <<
					setprecision(10) << my_exp(x) << "\n\n";
				break;
			case 11:

				cout << "Enter x: ";

				cin >> buf;
				check(buf);
				x = atof(buf.c_str());

				cout << "Enter degree: ";
				cin >> buf;
				check(buf);

				for (i = 0; i <= buf.size(); i++) {
					if (buf[i] == '.') {
						break;
					}
				}
				if (i > 0 && i < buf.size()) {
					degree = atof(buf.c_str());

					cout << '\n' << x << "^" << degree << " = " <<
						setprecision(18) <<
						my_pow(x, (long double)degree)
						<< "\n\n";
				}
				else {
					degree = atoi(buf.c_str());

					cout << '\n' << x << "^" << degree << " = " <<
						my_pow(x, (long int)degree)
						<< "\n\n";
				}

				break;
			case 12:
				cout << "Enter x: ";
				cin >> buf;
				check(buf);
				x = atof(buf.c_str());
				cout << "\nln(" << x << ") = " << my_ln(x) << "\n\n";
				break;
			case 13:
				cout << "\nGood bye!\n";
				break;
			default:
				cout << "\nIncorrect input\n\n";
				break;

			}
		}
		catch (int i) {
			cout << "\nError\n\n";
		}

	} while (choice != 13);

	return 0;
}

long double my_abs(long double val) {
	//Analog of the standard abs() function
	if (val >= 0)
		return val;
	else return -val;
}

long double my_Pi(long double accuracy) {
	//The number PI has a Taylor series expansion:
	//pi = 4 * [1 — 1/3 + 1/5 — 1/7 + 1/9 + … + ((-1) ^ n) / (2n + 1)]

	//The accuracy must be positive
	accuracy = my_abs(accuracy);

	long double current_element = 1, previous_element = 0;
	double num_pi = 1.0;
	int sign = -1;

	//Calculating to the specified accuracy
	for (int i = 1; my_abs(current_element - previous_element) >= accuracy; i++) {
		previous_element = current_element;

		//The next element of a series of numbers
		current_element = sign / (2.0 * i + 1.0);

		num_pi += current_element;

		sign = -sign;
	}

	return 4.0 * num_pi;


}

long double my_sqrt(long double x, long double accuracy) {

	//Will be using the next expression: y[i+1] = (y[i] + x/y[i])/2
	//This expression gives a sequence of numbers. 
	//Each number is closer to the square root of x
	if (x < 0)
		return -1;

	accuracy = my_abs(accuracy);

	long double res = x / 2, previous_element = 0;

	while (my_abs(res - previous_element) >= accuracy) {
		previous_element = res;
		res = (previous_element + x / previous_element) / 2;
	}

	return res;

}

long double my_cbrt(long double x, long double accuracy) {

	//Will be using the next expression:y[i+1] = 
	//( y[i] + 3*x / ( 2 y[i]*y[i] + x / y[i] ))/2.
	//This expression gives a sequence of numbers. 
	//Each number is closer to the square root of x
	accuracy = my_abs(accuracy);

	long double res = x, previous_element = 0;

	while (my_abs(res - previous_element) >= accuracy) {
		previous_element = res;
		res = (previous_element + 3 * x /
			(2 * previous_element * previous_element + x / previous_element)) / 2;
	}

	return res;
}

long int my_floor(long double num) {
	if ((long long int)num == num)
		return num;

	if (num > 0)
		return num; //Return a number closer to zero
	else
		return num - 1; //Return a number further from zero
}

long int my_ceil(long double num) {
	if ((long long int)num == num)
		return num;

	if (num > 0)
		return num + 1; //Return a number closer to zero
	else
		return num; //Return a number further from zero
}

long int my_round(long double num) {

	if (my_abs(num) - my_floor(my_abs(num)) >= 0.5) {
		if (num >= 0) return my_ceil(num);
		else return my_floor(num);
	}
	else {
		if (num >= 0) return my_floor(num);
		else return my_ceil(num);
	}
}

long double my_sin(long double x, long double accuracy) {

	//The Taylor series is used: sin(x)=x−x^3/3! + x^5/5! − x^7/7! + ... 

	accuracy = my_abs(accuracy);

	long double sin_val = x, current_element = x, previous_element = 0;

	for (int i = 1; my_abs(current_element - previous_element) >= accuracy; i++) {
		previous_element = current_element;
		//We use an iterative addition to avoid calculating the factorial
		current_element = current_element * -(x * x) / (2 * i*(2 * i + 1));
		sin_val += current_element;
	}

	return my_round(sin_val * (1 / accuracy)) / (1 / accuracy);

}

long double my_cos(const long double x, long double accuracy) {

	//The Taylor series is used: 1 - x^2/2! + x^4/4! - x^6/6! + ...

	accuracy = my_abs(accuracy);

	long double cos_val = 1, current_element = 1, previous_element = 0;

	for (int i = 1; my_abs(current_element - previous_element) >= accuracy; i++) {
		previous_element = current_element;
		//We use an iterative addition to avoid calculating the factorial
		current_element = current_element * -(x * x) / (2 * i*(2 * i - 1));
		cos_val += current_element;
	}

	return my_round(cos_val * (1 / accuracy)) / (1 / accuracy);

}

long double my_tan(long double x, long double accuracy) {

	//tan(x) = sin(x)/cos(x):)

	try {
		if (my_cos(x, accuracy) == 0)
			throw - 1;
	}
	catch (int a) {
		throw;
	}

	return my_sin(x, accuracy) / my_cos(x, accuracy);
}

long double my_exp(long double x, long double accuracy) {

	//The Taylor series is used: e^x = 1 + x^1/1! + x^2/2! + x^3/3! + ...

	long double current_element = x;
	long double exp_sum = 1 + x;
	long int n;

	for (n = 2; my_abs(current_element) >= accuracy; n++) {
		//We use an iterative addition to avoid calculating the factorial
		current_element = current_element * x / n;
		exp_sum += current_element;
	}
	return exp_sum;

}
long double hyperbole(long double x) {

	//The function of a hyperbole is 1/x
	if (!x)
		return 0;

	return 1 / x;
}

long double integral(long double a, long double b, long double accuracy) {
	//The function calculates the hyperbola integral on the specified interval
	//The trapezoid method is used

	long int n = 1;
	long double h = b - a;
	long double s1, s = (hyperbole(a) + hyperbole(b))*(h / 2);

	do {

		n = 2 * n;
		h = (b - a) / n;
		s1 = s;
		s = hyperbole(a) + hyperbole(b);
		for (int i = 1; i <= n - 1; i++)
			s = s + 2 * hyperbole(a + i * h);

		s = s * h / 2;

	} while (my_abs(s - s1) / 3 >= accuracy);

	return s;
}
long double my_ln(long double x, long double accuracy) {
	//ln(x) = Sdx/x is the area of the hyperbola 1/x

	try {
		if (x <= 0)
			throw - 1;
	}
	catch (int a) {
		throw;
	}

	if (x >= 1)
		return integral(1, x, accuracy);
	else
		return -integral(x, 1, accuracy);
}

long double my_pow(long double a, long int n) {
	//Recursive exponentiation

	if (n == 0) return 1;

	if (n == 1) return a;

	if (n % 2 == 0)
		return my_pow(a, n / 2) * my_pow(a, n / 2);
	else
		return a * my_pow(a, n - 1);
}

long double my_pow(long double a, long double n, long double accuracy) {
	//Exponentiation for real numbers
	//a^n = e^(ln(a^n)) = e^(n*ln(a))

	if (n < 0)
		return 0;

	return my_exp(n * my_ln(a, accuracy), accuracy);

}