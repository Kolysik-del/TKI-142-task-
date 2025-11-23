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
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}
int main(void) {
    double x1, y1, x2, y2;
    printf("Введите координаты первой точки (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Введите координаты второй точки (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Расстояние равно %.2f\n", distance(x1, y1, x2, y2));
    return 0;
}
