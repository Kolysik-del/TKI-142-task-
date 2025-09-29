#include <stdio.h>
#include <math.h>
/*
 * @brief рассчитывает значение функции A
 * @param x значение параметра x
 * @param y значение параметра y
 * @param z значение параметра z
 * @return рассчитанное значения
 */
double defA(const double x, const double y, const double z);
/*
 * @brief рассчитывает значение функции B
 * @param x значение параметра x
 * @param y значение параметра y
 * @param z значение параметра z
 * @return рассчитанное значения
 */
double defB(const double x, const double y, const double z);
/*
 * @brief Точка входа программы
 * @return Вернет 0, если программа выполнена корректно. Иначе 1
 */
int main(void)
{
    const double x = 0.61;
    const double y = 3.4;
    const double z = 16.5;
    printf("A = %.6f\n", defA(x, y, z));
    printf("B = %.6f\n", defB(x, y, z));
    return 0;
}
double defA(const double x, const double y, const double z)
{
    return pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + z / pow(x + y, .5);
}
double defB(const double x, const double y, const double z)
{
    return (y * pow(x, 2) - z) / (exp(z * x) - 1);
}
