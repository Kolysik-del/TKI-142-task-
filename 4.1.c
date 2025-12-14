#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <stdbool.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
int getValid();

/**
* @brief Считывает положительное целое число (>=1) и возвращает его как size_t
* @return Корректный размер массива (>= 1)
*/
size_t positiveInput(void);

/**
* @brief Проверяет, лежит ли число в указанном диапазоне
* @param input - значение проверяемой переменной
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Считает сумму согласно условию №1 (отрицательные, кратные 10)
* @param arr - массив
* @param size - размер массива
* @return Посчитанное значение
*/
int defForTask1(const int* arr, const size_t size);

/**
* @brief Заменяет первые k элементов на те же в обратном порядке (условие №2)
* @param arr - массив
* @param size - размер массива
* @param k - количество первых элементов для замены
*/
void defForTask2(int* arr, const size_t size, const size_t k);

/**
* @brief Проверяет наличие пары соседних элементов с произведением, равным заданному числу (условие №3)
* @param arr - массив
* @param size - размер массива
* @param target - заданное число для сравнения произведения
*/
void defForTask3(const int* arr, const size_t size, const int target);

/**
* @brief Находит минимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращaет минимальный элемент массива
*/
int defMINN(const int* arr, const size_t size);

/**
* @brief Находит максимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращaет максимальный элемент массива
*/
int defMAXX(const int* arr, const size_t size);

/**
@brief CHOISE_ONE - первый выбор (Ручное заполнение массива)
@brief  CHOISE_TWO - второй выбор (Автоматическое заполнение массива)
@brief  TASK_ONE - выполнение первого задания
@brief  TASK_TWO - выполнение второго задания
@brief  TASK_THREE - выполнение третьего задания
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief Проверяет диапазон на корректность ввода
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void defCheckMinMax(const int min, const int max);

/**
* @brief Заполняет массив элементами, который пользователь вводит с клавиатуры, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getManual(int* arr, const size_t size, const int min, const int max);

/**
* @brief Заполняет массив случайными элементами, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getRandom(int* arr, const size_t size, const int min, const int max);

/**
* @brief Выводит все элементы массива на экран
* @param arr - массив
* @param size - размер массива
*/
void defPrintArr(const int* arr, const size_t size);

/**
* @brief Копирует все элементы массива в новый
* @param arr - массив
* @param size - размер массива
* @return Новый массив, идентичный старому
*/
int* defcopyArr(const int* arr, const size_t size);

/**
* @brief Проверяет корректно ли выделена память под массив
* @param arr - массив
*/
void check_pointer(const int* arr);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
    system("chcp 1251");

    printf("Введите размер массива: ");
    size_t size = positiveInput();

    int* A = calloc(size, sizeof(int));
    check_pointer(A);

    printf("Введите диапазон, в котором будут задаваться числа массива: \n");
    const int min = getValid();
    const int max = getValid();
    defCheckMinMax(min, max);
    printf("Числа массива будут задаваться в диапазоне [%d,%d]\n", min, max);

    printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n", CHOISE_ONE, CHOISE_TWO);
    int choise = getValid();

    switch (choise)
    {
    case CHOISE_ONE:
        getManual(A, size, min, max);
        break;

    case CHOISE_TWO:
        getRandom(A, size, min, max);
        break;

    default:
        fprintf(stderr, "Error: неверный выбор!\n");
        free(A);
        exit(1);
    }

    defPrintArr(A, size);
    int* copyA = defcopyArr(A, size);
    check_pointer(copyA);

    printf("\nКакие будут преобразования?\n%d - Найти сумму отрицательных элементов, кратных 10\n%d - Заменить первые k элементов на те же в обратном порядке\n%d - Определить, есть ли пара соседних элементов с произведением, равным заданному числу\n",
        TASK_ONE, TASK_TWO, TASK_THREE);
    int second_choise = getValid();

    switch (second_choise)
    {
    case TASK_ONE:
    {
        int sum = defForTask1(copyA, size);
        printf("\nСумма отрицательных элементов, кратных 10 = %d\n", sum);
        break;
    }

    case TASK_TWO:
    {
        printf("Введите k (количество первых элементов для замены): ");
        size_t k = (size_t)getValid();
        if (k > size || k == 0)
        {
            fprintf(stderr, "Error: k должно быть в пределах [1, %zu]\n", size);
            free(A);
            free(copyA);
            exit(1);
        }
        defForTask2(copyA, size, k);
        printf("\nМассив после замены первых %zu элементов в обратном порядке:\n", k);
        defPrintArr(copyA, size);
        break;
    }

    case TASK_THREE:
    {
        printf("Введите число, с которым сравнивать произведение пар: ");
        int target = getValid();
        defForTask3(copyA, size, target);
        break;
    }

    default:
        fprintf(stderr, "Error: неверный выбор!\n");
        free(A);
        free(copyA);
        exit(1);
    }

    free(A);
    free(copyA);

    return 0;
}

int getValid()
{
    int valid = 0;
    if (scanf_s("%d", &valid) != 1)
    {
        fprintf(stderr, "Error: некорректный ввод!\n");
        exit(1);
    }
    return valid;
}

void checkValue(const int input, const int min, const int max)
{
    if (input > max || input < min)
    {
        fprintf(stderr, "Error: Число должно лежать в промежутке [%d;%d]\n", min, max);
        exit(1);
    }
}

void getManual(int* arr, const size_t size, const int min, const int max)
{
    check_pointer(arr);

    printf("\nВведи %zu элемент-а(ов) массива:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        int num = getValid();
        checkValue(num, min, max);
        printf("A[%zu] = %d\n", i, num);
        arr[i] = num;
    }
}

void defCheckMinMax(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr, "Error: Неправильно указан диапазон (min должен быть меньше max)\n");
        exit(1);
    }
}

void getRandom(int* arr, const size_t size, const int min, const int max)
{
    check_pointer(arr);
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < size; i++)
    {
        int num = (rand() % (max - min + 1)) + min;
        arr[i] = num;
    }
}

void defPrintArr(const int* arr, const size_t size)
{
    check_pointer(arr);

    printf("\nМассив: \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

size_t positiveInput(void)
{
    int input = getValid();
    if (input < 1)
    {
        fprintf(stderr, "Error: Размер массива должен быть не меньше 1\n");
        exit(1);
    }
    return (size_t)input;
}

int defForTask1(const int* arr, const size_t size)
{
    check_pointer(arr);

    int summ = 0;
    for (size_t i = 0; i < size; i++)
    {
        if ((arr[i] < 0) && (abs(arr[i]) % 10 == 0))
        {
            summ += arr[i];
        }
    }
    return summ;
}

void defForTask2(int* arr, const size_t size, const size_t k)
{
    check_pointer(arr);

    for (size_t i = 0; i < k / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[k - 1 - i];
        arr[k - 1 - i] = temp;
    }
}

void defForTask3(const int* arr, const size_t size, const int target)
{
    check_pointer(arr);

    bool found = false;
    printf("\nПары соседних элементов с произведением %d:\n", target);

    for (size_t i = 0; i < size - 1; i++)
    {
        int product = arr[i] * arr[i + 1];
        if (product == target)
        {
            printf("Элементы A[%zu] = %d и A[%zu] = %d (произведение = %d)\n",
                i, arr[i], i + 1, arr[i + 1], product);
            found = true;
        }
    }

    if (!found)
    {
        printf("Таких пар в массиве нет.\n");
    }
}

int* defcopyArr(const int* arr, const size_t size)
{
    check_pointer(arr);

    int* copyArr = calloc(size, sizeof(int));
    check_pointer(copyArr);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void check_pointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Memory Error: не удалось выделить память!\n");
        exit(1);
    }
}
