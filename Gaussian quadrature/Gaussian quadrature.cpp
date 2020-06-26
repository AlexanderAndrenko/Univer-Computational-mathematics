/*Программа расчёта определённого интеграла методом Гаусса*/

#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

typedef long double value;//Тип данных используемый для результатов вычислений

/*Вычисление значения подынтегральной функции в заданной точке*/
value GetValueOfIntegrand(value x)
{
	return ((x / 2) * log((x * x) / 2));
}

int main()
{
	setlocale(LC_ALL, "Russian");

	value coordinate4node[4] = { -0.861136311594053 , -0.339981043584856, 0.339981043584856, 0.861136311594053 };//Координаты узлов для метода Гаусса с числом узлов 4 
	value weightCoefficient4[4] = { 0.347854845137454, 0.652145154862546, 0.652145154862546, 0.347854845137454 };//Весовые коэффициенты для метода Гаусса с числом узлов 4

	value coordinate5node[5] = { -0.906179845938664, -0.538469310105683, 0.0, 0.538469310105683, 0.906179845938664 };//Координаты узлов для метода Гаусса с числом узлов 5 
	value weightCoefficient5[5] = { 0.236926885056189, 0.478628670499366, 0.568888888888889, 0.478628670499366, 0.236926885056189 };//Весовые коэффициенты для метода Гаусса с числом узлов 5

	value lowerIntervalValue;
	value upperIntervalValue;

	cout << "Введите левую границу интеграла: ";
	cin >> lowerIntervalValue;
	cout << "Введите правую границу интеграла: ";
	cin >> upperIntervalValue;

	value x4[4];

	for (int index = 0; index < 4; index++)//Расчёт x для метода с количеством узлов 4
	{
		x4[index] = ((upperIntervalValue + lowerIntervalValue) / 2) + (((upperIntervalValue - lowerIntervalValue) / 2) * coordinate4node[index]);
	}

	value x5[5];

	for (int index = 0; index < 5; index++)//Расчёт x для метода с количеством узлов 4
	{
		x5[index] = ((upperIntervalValue + lowerIntervalValue) / 2) + (((upperIntervalValue - lowerIntervalValue) / 2) * coordinate5node[index]);
	}

	value valueIntegral4;//Результат вычисления интеграла для метода с 4 узлами
	value sum = 0;

	for (int index = 0; index < 4; index++)
	{
		sum += weightCoefficient4[index] * GetValueOfIntegrand(x4[index]);
	}

	valueIntegral4 = ((upperIntervalValue - lowerIntervalValue) / 2) * sum;

	cout << "Значение интеграла расчитанного методом с 4 узлами: ";
	cout << setprecision(12) << valueIntegral4 << endl;

	sum = 0;
	value valueIntegral5;//Результат вычисления интеграла для метода с 5 узлами

	for (int index = 0; index < 5; index++)
	{
		sum += weightCoefficient5[index] * GetValueOfIntegrand(x5[index]);
	}

	valueIntegral5 = ((upperIntervalValue - lowerIntervalValue) / 2) * sum;

	cout << "Значение интеграла расчитанного методом с 5 узлами: ";
	cout << setprecision(12) << valueIntegral5 << endl;

	system("pause");

	return 0;
}