#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

double valueOfFirstFunc(double x)
{
	double result = 1 - 0.5 * cos(x);		

	return result;
}

double valueOfSecondFunc(double x)
{
	double result = sin(x + 1) - 1.2;

	return result;
}

bool checkingConditionForRootConvergence(double x, double y)
{
	bool result = false;

	if ( (fabs(cos(x + 1)) < 1) && (fabs(0.5 * sin(y)) < 1) )
	{
		result = true;
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double x0[2];//Начальное приближение корня
	double x1[2];//Последующее приближение корня
	double epsilon;//точность вычислений
	double delta[2];//Разность между следующим и предыдущим корнями
	
	cout << "Введите начальное приближение корня.\n";
	cout << "x0: ";
	cin >> x0[0];
	cout << "y0: ";
	cin >> x0[1];

	cout << "Введите точность вычислений: ";
	cin >> epsilon;

	if (checkingConditionForRootConvergence(x0[0], x0[1]))//Проверка условия сходимости
	{
		int iteration = 1;
		
		//Цикл поиска корня
		do
		{
			x1[0] = valueOfFirstFunc(x0[1]);//Расчёт следующего приближения
			x1[1] = valueOfSecondFunc(x0[0]);//Расчёт следующего приближения

			delta[0] = x1[0] - x0[0];//Разница между следующим и предыдущим корнями
			delta[1] = x1[1] - x0[1];//Разница между следующим и предыдущим корнями

			cout << "№ " << left << setw(2) << iteration << "\t"
				<< "х0: " << left << setw(8) << x0[0] << "\t"
				<< "y0: " << left << setw(8) << x0[1] << "\t"
				<< "x1:" << left << setw(8) << x1[0] << "\t"
				<< "y1: " << left << setw(8) << x1[1] << "\t"
				<< "|x1 - x0|, |y1 - y0|  " << left << setw(8) << fabs(delta[0]) << ",\t" << setw(8) << fabs(delta[1]) << endl;

			x0[0] = x1[0];
			x0[1] = x1[1];

			iteration++;

		} while (fabs(delta[0]) > epsilon || fabs(delta[1]) > epsilon);

		cout << "Корень уравнения. x: " << x1[0] << "\t y: " << x1[1] << endl;
	}
	else
	{
		cout << "К сожалению приближенное значение не удовлетворяет условию сходимости!\n";
	}

	system("pause");

	return 0;
}