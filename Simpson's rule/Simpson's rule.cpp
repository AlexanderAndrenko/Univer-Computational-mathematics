#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

/*Программа расчёта определённого интеграла методом Симпсона*/

typedef double value;//Тип данных используемый для результатов вычислений

value ValueOfIntegrand(value x)//Вычисление значения подынтегральной функции в заданной точке
{
    return ((x / 2) * log((x * x) / 2));
}

value SimpsonsRule(value lowerIntervalValue, value upperIntervalValue, int quantityOfIntervals)//Параметры: Нижнее значение интервала, Верхнее значение интервала, Количество интервалов
{
    value step = (upperIntervalValue - lowerIntervalValue) / quantityOfIntervals;//Вычисление длинны шага разбиения

}

int main()
{
    setlocale(LC_ALL, "Russian");

    

    return 0;
}
