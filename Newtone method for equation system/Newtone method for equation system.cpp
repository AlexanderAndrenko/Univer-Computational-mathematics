/*
Решение не доработано

Solving isn't completed
*/
#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

typedef long double root;

root valueOfFirstFunc(root x, root y)
{
	root result = x + tan(x * y);

	return result;
}

root valueOfSecondFunc(root x, root y)
{
	root result = (y * y - 7.5 * 7.5) + log(x);

	return result;
}

root partialDerFirstFuncX(root x, root y)
{
	root result = y * (pow(tan(x * y),2) + 1) + 1;

	return result;
}

root partialDerFirstFuncY(root x, root y)
{
	root result = x * (pow(tan(x * y), 2) + 1);

	return result;
}

root partialDerSecondFuncX(root x, root y)
{
	root result = 1 / x;

	return result;
}

root partialDerSecondFuncY(root x, root y)
{
	root result = 2 * y;

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	root x0[2];//Начальное приближение корня
	root x1[2];//Последующее приближение корня
	root epsilon;//точность вычислений
	root delta[2];//Разность между следующим и предыдущим корнями
	
	cout << "Введите начальное приближение корня.";
	cout << "x0: ";
	cin >> x0[0];
	cout << "y0: ";
	cin >> x0[1];

	cout << "Введите точность вычислений: ";
	cin >> epsilon;

	int iteration = 1;

	//Цикл поиска корня
	do
	{
		x1[0] = x0[0] -
			((valueOfFirstFunc(x0[0], x0[1]) * partialDerSecondFuncY(x0[0], x0[1]) - partialDerFirstFuncY(x0[0], x0[1]) * valueOfSecondFunc(x0[0], x0[1]))
				/
				(partialDerFirstFuncX(x0[0], x0[1]) * partialDerSecondFuncY(x0[0], x0[1]) - partialDerFirstFuncY(x0[0], x0[1]) * partialDerSecondFuncX(x0[0], x0[1])));
		//Расчёт следующего приближения
		x1[1] = x0[1] -
			((partialDerFirstFuncX(x0[0], x0[1]) * valueOfSecondFunc(x0[0], x0[1]) - valueOfFirstFunc(x0[0], x0[1]) * partialDerSecondFuncX(x0[0], x0[1]))
				/
				(partialDerFirstFuncX(x0[0], x0[1]) * partialDerSecondFuncY(x0[0], x0[1]) - partialDerFirstFuncY(x0[0], x0[1]) * partialDerSecondFuncX(x0[0], x0[1])));//Расчёт следующего приближения

		delta[0] = x1[0] - x0[0];//Разница между следующим и предыдущим корнями
		delta[1] = x1[1] - x0[1];//Разница между следующим и предыдущим корнями

		cout << "№ " << left << setw(2) << iteration << "\t"
			<< "х0: " << left << setw(8) << x0[0] << "\t"
			<< "y0: " << left << setw(8) << x0[1] << "\t"
			<< "x1:" << left << setw(8) << x1[0] << "\t"
			<< "y1: " << left << setw(8) << x1[1] << "\t"
			<< "|x1 - x0|" << left << setw(8) << fabs(delta[0]) << "\t" << fabs(delta[1]) << endl;

		x0[0] = x1[0];
		x0[1] = x1[1];

		iteration++;

	} while (fabs(delta[0]) > epsilon || fabs(delta[1]) > epsilon);

	cout << "Корень уравнения. x: " << x1[1] << "\t y: " << x1[0] << endl;
	cout << "Значения функций в данных точках.\n";
	//cout << "x: " << valueOfFirstFunc(x1[1]) << "\t" << "y: " << valueOfSecondFunc(x1[0]) << endl;

	system("pause");

	return 0;
}