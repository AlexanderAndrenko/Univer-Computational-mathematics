#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>

using namespace std;

/*Программа расчёта определённого интеграла методом Симпсона*/

typedef long double value;//Тип данных используемый для результатов вычислений

value ValueOfIntegrand(value x)//Вычисление значения подынтегральной функции в заданной точке
{
    return ((x / 2) * log((x * x) / 2));
}

value ValueFourthDerivative(value x)
{
    return 2 / (x * x * x);
}

/*ATTENTION*/
/*Доработать динамический размер массива или пересмотреть структуру данных*/
value MaxDeltaFunc(value step, value low)//Функция поиска максимальной разницы чертвертого порядка подынтегральной функции
{
    value max;
    value array[21][5];

    for (int i = 0; i < 21; i++)
    {
        array[i][0] = ValueOfIntegrand(low + (step * i));//Заполнение массива значениями функций в точках
    }

    for (int i = 0; i < 20; i++)
    {
        array[i][1] = array[i + 1][0] - array[i][0];//Разность первого порядка
    }

    for (int i = 0; i < 19; i++)
    {
        array[i][2] = array[i + 1][1] - array[i][1];//Разность второго порядка
    }

    for (int i = 0; i < 18; i++)
    {
        array[i][3] = array[i + 1][2] - array[i][2];//Разность третьего порядка
    }

    for (int i = 0; i < 17; i++)
    {
        array[i][4] = array[i + 1][3] - array[i][3];//Разность четвертого порядка
    }

    max = array[0][4];

    for (int  i = 0; i < 17; i++)
    {
        if (max < array[i][4])
        {
            max = array[i][4];
        }
    }
    
    return max;
}

value SimpsonsRule(value lowerIntervalValue, value upperIntervalValue, int quantityOfIntervals)//Параметры: Нижнее значение интервала, Верхнее значение интервала, Количество интервалов
{
    if (quantityOfIntervals % 2 != 0)
    {
        quantityOfIntervals++;
    }

    value step = (upperIntervalValue - lowerIntervalValue) / quantityOfIntervals;//Вычисление длинны шага разбиения

    value sumOfOddValue = 0;// сумма значений функций в нечетных узлах
    for (int i = 1; i < quantityOfIntervals; i += 2)//Вычисление суммы значений функции в нечетных узлах
    {
        sumOfOddValue += ValueOfIntegrand(lowerIntervalValue + (i * step));
    }

    value sumOfEvenValue = 0;// сумма значений функций в четных узлах
    for (int i = 2; i < quantityOfIntervals; i += 2)//Вычисление суммы значений функции в четных узлах
    {
        sumOfEvenValue += ValueOfIntegrand(lowerIntervalValue + (i * step));
    }

    value remain = ((upperIntervalValue - lowerIntervalValue) * MaxDeltaFunc(step, lowerIntervalValue)) / 180;

    cout << "Остаточный член: ";
    cout << fixed;
    cout << setprecision(12) << remain << endl;

    return ((step / 3) * (ValueOfIntegrand(lowerIntervalValue) + ValueOfIntegrand(upperIntervalValue) + (4 * sumOfOddValue) + (2 * sumOfEvenValue)));

}

int main()
{
    setlocale(LC_ALL, "Russian");

    value low;
    value high;
    int intervals;

    cout << "Пожалуйста введите нижнию границу интервала: ";
    cin >> low;
    cout << "Пожалуйста введите верхнию границу интервала: ";
    cin >> high;
    cout << "Пожалуйста введите количество интервалов разбиения: ";
    cin >> intervals;

    double result = SimpsonsRule(low, high, intervals);

    cout << "Результат вычисления: ";
    cout << setprecision(12) << result << endl;

    system("pause");

    return 0;
}
