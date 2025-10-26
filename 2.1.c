#include <stdio.h>
/**
 * @brief меняет между собой значения переменных a и b с использованием 3 переменной c и без неё
 * @param a - первая переменная
 * @param b - вторая переменная
 * @param c - третья переменная
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main()
{
    double a, b;
    printf("Введите два числа a и b:");
    scanf("%lf %lf", &a, &b);
    printf("До обмена: a = %.2lf, b = %.2lf\n", a, b);
    double c = a;
    a = b;
    b = c;
    printf("После обмена с переменной c: a = %.2lf, b = %.2lf\n", a, b);
    printf("Введите два числа a и b:");
    scanf("%lf %lf", &a, &b);
    printf("До обмена: a = %.2lf, b = %.2lf\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("После обмена без переменной c: a = %.2lf, b = %.2lf\n", a, b);
    return 0;
}
