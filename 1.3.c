#include <stdio.h>
/**
 * @brief Рассчитывает давление, производимое бетонной плитой
 * @param weight масса тела
 * @param square площадь поверхности тела
 * @param g ускорение свободного падения
 * @return возвращает рассчитанное давление, производимое бетонной плитой
 */
double davka(const double weight, const double square, const double g);
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void)
{
    system("chcp 1251");
    double weight = 0, square = 0;
    const double g = 9.8;
    printf("Введите значение массы тела (кг): ");
    scanf_s("%lf", &weight);
    printf("Введите значение площади опоры (м²): ");
    scanf_s("%lf", &square);
    printf("Давление тела на поверхность равно: %.4lf Па\n", davka(weight, square, g));
    return 0;
}
double davka(const double weight, const double square, const double g)
{
    return (weight * g) / square;
}
