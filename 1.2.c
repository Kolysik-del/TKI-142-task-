#include <stdio.h>
#include <math.h>
/**
 * @brief Вычисляет расстояние между двумя точками на плоскости.
 * @param x1 Координата x первой точки
 * @param y1 Координата y первой точки
 * @param x2 Координата x второй точки
 * @param y2 Координата y второй точки
 * @return Расстояние между точками
 */
double distance(const double x1, const double y1, const double x2, const double y2);
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void) 
{
    system("chcp 1251");
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    printf("Введите координаты первой точки (x1, y1): ");
    scanf_s("%lf %lf", &x1, &y1);
    printf("Введите координаты второй точки (x2, y2): ");
    scanf_s("%lf %lf", &x2, &y2);
    printf("Расстояние равно %.2f\n", distance(x1, y1, x2, y2));
    return 0;
}
double distance(const double x1, const double y1, const double x2, const double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}
