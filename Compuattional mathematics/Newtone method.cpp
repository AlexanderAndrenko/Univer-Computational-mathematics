#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double valueOfFunction(double x)//функция расчёта значения функции в точке
{
	double result = tan(1.5773 * x) - 2.3041 * x;

	return result;
}

double calcDerivative(double x)//функция расчёта значения первой производной
{
	double valueDerivative = 1.5773 * tan(pow(1.5773 * x, 2)) - 0.7268;

	return valueDerivative;
}

double calcSecondDerivative(double x)//функция расчёта значения второй производной
{
	double valueDerivative = 3.1546 * tan(1.5773 * x) * (1.5773 * tan(pow(1.5773 * x, 2)) + 1.5773);

	return valueDerivative;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double x0; //Начальное приближение корня
	double epsilon;//точность вычислений    
	double x1;//Значение следующего приближения
	double delta;//Разность значений между предыдущим и следующим корнями

	cout << "Введите начальное приближение: ";
	cin >> x0;
	cout << "Введите точность вычислений: ";
	cin >> epsilon;

	if (fabs((valueOfFunction(x0) * calcSecondDerivative(x0)) / pow(calcDerivative(x0), 2)) < 1)//Проверка условия сходимости
	{
		//Цикл поиска корня
		do
		{
			x1 = x0 - (valueOfFunction(x0) / calcDerivative(x0));//Расчёт следующего приближения
			cout << "х0: " << x0 << "\t" << "x1:" << x1 << endl;
			delta = x1 - x0;//Разница между следующим и предыдущим корнями
			x0 = x1;

		} while (fabs(delta) > epsilon);

		cout << "Корень уравнения: " << x1 << endl;
		cout << "Значение функции в данной точке: " << tan(1.5773 * x1) - 2.3041 * x1 << endl;
	}
	else
	{
		cout << "К сожалению приближенное значение не удовлетворяет условию сходимости!\n";
	}

	system("pause");

	return 0;
}