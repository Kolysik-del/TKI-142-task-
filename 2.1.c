#include <stdio.h>

 /**
  * @brief Перечисление для выбора способа обмена значениями
  * with:    обмен с использованием третьей переменной
  * without: обмен без использования третьей переменной
  */
enum {with = 1,without};

/**
 * @brief Меняет местами значения двух переменных с использованием третьей
 * @param a — указатель на первую переменную
 * @param b — указатель на вторую переменную
 * @param c — указатель на вспомогательную переменную
  */
void swapWith(int* a, int* b, int* c);

/**
 * @brief Меняет местами значения двух переменных без использованием третьей
 * @param a — указатель на первую переменную
 * @param b — указатель на вторую переменную
  */
void swapWithout(int* a, int* b);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main() {
    system("chcp 1251");
    int a = 0, b = 0, c = 0, choice = 0;
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
