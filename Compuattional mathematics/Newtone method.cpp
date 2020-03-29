#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double valueOfFunction(double x)
{
	double result = tan(1.5773 * x) - 2.3041 * x;

	return result;
}

double calcDerivative(double x)
{
	double valueDerivative = 1.5773 * tan(pow(1.5773 * x, 2)) - 0.7268;

	return valueDerivative;
}

double calcSecondDerivative(double x)
{
	double valueDerivative = 3.1546 * tan(1.5773 * x) * (1.5773 * tan(pow(1.5773 * x, 2)) + 1.5773);

	return valueDerivative;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double x0; //НАчальное приближение корня
	double epsilon;//точность вычислений    
	double x1 = 1;
	double savePreX = 0;



	cout << "Введите начальное приближение: ";
	cin >> x0;
	cout << "Введите точность вычислений: ";
	cin >> epsilon;

	if (abs((valueOfFunction(x0) * calcSecondDerivative(x0)) / pow(calcDerivative(x0), 2)) < 1)
	{
		do
		{
			x1 = x0 - (valueOfFunction(x0) / calcDerivative(x0));
			cout << "х0: " << x0 << "\t" << "x1:" << x1 << endl;
			savePreX = x0;
			x0 = x1;

		} while (abs(x1 - savePreX) > epsilon);
	}
	else
	{
		cout << "К сожалению приближенное значение не удовлетворяет условию сходимости!\n";
	}


	if (abs(x1 - savePreX) < epsilon)
	{
		cout << "Корень уравнения: " << x1 << endl;
		cout << "Значение функции в данной точке: " << tan(1.5773 * x1) - 2.3041 * x1 << endl;
	}

	system("pause");

	return 0;
}