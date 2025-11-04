#include <stdio.h>
/**
 * @brief меняет между собой значения переменных a и b с использованием 3 переменной c и без неё
 * @param a - первая переменная
 * @param b - вторая переменная
 * @param c - третья переменная
 * @param choice - переменная для выбора варианта
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main() {
    int a, b, c, choice;
    printf("Введите значение a:");
    scanf_s("%d", &a);
    printf("Введите значение b:");
    scanf_s("%d", &b);
    printf("1. С использованием третьей переменной\n");
    printf("2. Без использования третьей переменной\n");
    printf("Введите номер варианта:");
    scanf_s("%d", &choice);
    if (choice == 1)
    {
        c = a;
        a = b;
        b = c;
    }
    else if (choice == 2)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    else
    {
        return 0;
    }
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}
