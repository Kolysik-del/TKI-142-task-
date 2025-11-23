#include <stdio.h>
/**
 * @brief Рассчитывает давление, производимое бетонной плитой
 * @param weight масса тела
 * @param square площадь поверхности тела
 * @param g ускорение свободного падения
 * @return возвращает рассчитанное давление, производимое бетонной плитой
 */
double davka(const double weight, const double square, const double g)
{
    return (weight * g) / square;
}
int main(void)
{
    double weight, square;
    const double g = 9.8;
    printf("Введите значение массы тела (кг): ");
    scanf("%lf", &weight);
    printf("Введите значение площади опоры (м²): ");
    scanf("%lf", &square);
    printf("Давление тела на поверхность равно: %.4lf Па\n", davka(weight, square, g));
    return 0;
}
