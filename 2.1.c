#include <stdio.h>
/**
 * @brief Меняет местами значения переменных a и b с использованием 3 переменной c и без неё
 * @param a - первая переменная
 * @param b - вторая переменная
 * @param c - третья переменная
 * @param choice - переменная для выбора варианта
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
typedef enum {
    with = 1,
    without
} swap;
void swapWith(int* a, int* b, int* c) {
    *c = *a;
    *a = *b;
    *b = *c;
}
void swapWithout(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main() {
    int a, b, c, choice;
    printf("Введите значение a: ");
    scanf_s("%d", &a);
    printf("Введите значение b: ");
    scanf_s("%d", &b);
    printf("1. С использованием третьей переменной\n");
    printf("2. Без использования третьей переменной\n");
    printf("Введите номер варианта: ");
    scanf_s("%d", &choice);
    switch (choice) {
    case with:
        swapWith(&a, &b, &c);
        break;
    case without:
        swapWithout(&a, &b);
        break;
    default:
        printf("Ошибка: неверный номер варианта.\n");
        return 1;
    }
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}
