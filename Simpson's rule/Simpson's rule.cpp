#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>

using namespace std;

/*Программа расчёта определённого интеграла методом Симпсона*/

typedef long double value;//Тип данных используемый для результатов вычислений

value GetValueOfIntegrand(value x)//Вычисление значения подынтегральной функции в заданной точке
{
    return ((x / 2) * log((x * x) / 2));
}

/*ATTENTION*/
/*Доработать динамический размер массива или пересмотреть структуру данных*/
value MaxDeltaFunc(value step, value low, int quantity)//Функция поиска максимальной разницы чертвертого порядка подынтегральной функции
{
    value max;//Максимальное значение разности четвёртого порядка

    //Создание массива для расчета разности четвертого порядка
    value** array = new value * [quantity];
    for (int index = 0; index < quantity; index++)
    {
        array[index] = new value[5];
    }
    
    //Расчёт значений функций в узлах
    for (int i = 0; i < quantity; i++)
    {
        array[i][0] = GetValueOfIntegrand(low + (step * i));//Заполнение массива значениями функций в точках
    }

    //Расчёт разностей первого порядка
    for (int i = 0; i < quantity - 1; i++)
    {
        array[i][1] = array[i + 1][0] - array[i][0];//Разность первого порядка
    }

    //Расчёт разностей второго порядка
    for (int i = 0; i < quantity - 2; i++)
    {
        array[i][2] = array[i + 1][1] - array[i][1];//Разность второго порядка
    }

    //Расчёт разностей третьего порядка
    for (int i = 0; i < quantity - 3; i++)
    {
        array[i][3] = array[i + 1][2] - array[i][2];//Разность третьего порядка
    }

    //Расчёт разностей четвертого порядка
    for (int i = 0; i < quantity - 4; i++)
    {
        array[i][4] = array[i + 1][3] - array[i][3];//Разность четвертого порядка
    }

    max = array[0][4];//Присваиваем первое значение разности четвертого порядка как максимальное


    for (int  i = 0; i < 17; i++)//Поиск максимального значения разности 4 порядка
    {
        if (max < array[i][4])
        {
            max = array[i][4];
        }
    }
    
    for (int i = 0; i < quantity; i++)
        delete []array[i];

    return max;
}

value SimpsonsRule(value lowerIntervalValue, value upperIntervalValue, int quantityOfIntervals)//Параметры: Нижнее значение интервала, Верхнее значение интервала, Количество интервалов
{
    if (quantityOfIntervals % 2 != 0)//Если количество интервалов нечётное, то увеличиваем значение на единицу
    {
        quantityOfIntervals++;
    }

    value step = (upperIntervalValue - lowerIntervalValue) / quantityOfIntervals;//Вычисление длинны шага разбиения

    value sumOfOddValue = 0;// сумма значений функций в нечетных узлах
    for (int i = 1; i < quantityOfIntervals; i += 2)//Вычисление суммы значений функции в нечетных узлах
    {
        sumOfOddValue += GetValueOfIntegrand(lowerIntervalValue + (i * step));
    }

    value sumOfEvenValue = 0;// сумма значений функций в четных узлах
    for (int i = 2; i < quantityOfIntervals; i += 2)//Вычисление суммы значений функции в четных узлах
    {
        sumOfEvenValue += GetValueOfIntegrand(lowerIntervalValue + (i * step));
    }

    value remain = ((upperIntervalValue - lowerIntervalValue) * MaxDeltaFunc(step, lowerIntervalValue, quantityOfIntervals + 1)) / 180;

    cout << "Остаточный член: ";
    cout << fixed;
    cout << setprecision(12) << remain << endl;

    return ((step / 3) * (GetValueOfIntegrand(lowerIntervalValue) + GetValueOfIntegrand(upperIntervalValue) + (4 * sumOfOddValue) + (2 * sumOfEvenValue)));

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
