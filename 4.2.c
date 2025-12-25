#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <time.h>
/**
 * @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();
/**
 * @brief выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива
 */
size_t getSize(const char* message);
/**
 * @brief считывает каждое из значений элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);
/**
 * @brief выводит элементы массива в стилизованном виде
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);
/**
 * @brief заполняет массив случайными числами, выбранными из введенного интервала чисел
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);
/**
 * @brief создает копию массива
 * @param arr массив
 * @param size размер массива
 * @return копия исходного массива
 */
int* copyArray(const int* arr, const size_t size);
/**
 * @brief выделяет память для массива целых чисел заданного размера с проверкой успешности выделения
 * @param size размер массива (количество элементов)
 * @return указатель на выделенную память для массива
 * @note в случае ошибки выделения памяти выводит сообщение об ошибке и завершает программу
 */
int* allocateArray(const size_t size);
/**
 * @brief находит индекс минимального элемента массива
 * @param arr массив
 * @param size размер массива
 * @return индекс минимального элемента
 */
int findMinEl(const int* arr, const size_t size);
/**
 * @brief находит средний элемент массива (при нечетном размере)
 * @param arr массив
 * @param size размер массива
 * @return значение среднего элемента
 */
int findMiddleEl(const int* arr, const size_t size);
/**
 * @brief заменяет минимальный элемент массива на средний
 * @param arr массив
 * @param size размер массива
 */
void replaceMinWithMiddle(int* arr, const size_t size);
/**
 * @brief проверяет, содержит ли число цифру 5
 * @param num число для проверки
 * @return 1 если содержит цифру 5, иначе 0
 */
bool containsDigit5(const int num);
/**
 * @brief подсчитывает количество элементов, не содержащих цифру 5
 * @param arr исходный массив
 * @param size размер исходного массива
 * @return количество элементов без цифры 5
 */
size_t getCountWithoutDigit5(const int* arr, const size_t size);
/**
 * @brief создает новый массив без элементов, содержащих цифру 5
 * @param arr исходный массив
 * @param size размер исходного массива
 * @param newarr новый массив (уже выделенная память)
 * @param newSize размер нового массива
 */
void removeElementsWithDigit5(const int* arr, const size_t size, int* newarr, const size_t newSize);
/**
 * @brief формирует новый массив A из массива C по правилу
 * @param C исходный массив
 * @param size размер массива
 * @return новый массив A
 */
int* formArrayFromC(const int* C, const size_t size);
/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введенного интервала чисел
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    system("chcp 1251");
    size_t size = getSize("Введите размер массива C: ");
    int* C = allocateArray(size);
    printf("Выберите способ заполнения массива:\n%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = getValue();
    switch (choice)
    {
    case RANDOM:
        fillRandom(C, size);
        break;
    case MANUAL:
        fillArray(C, size);
        break;
    default:
        printf("Неверный выбор!\n");
        free(C);
        exit(1);
    }
    printf("Исходный массив C: ");
    printArray(C, size);
    printf("\nВыберите задачу для выполнения:\n");
    printf("1 - Заменить минимальный элемент на средний\n");
    printf("2 - Удалить элементы, содержащие цифру 5\n");
    printf("3 - Сформировать массив A по правилу\n");
    printf("4 - Выполнить все задачи\n");
    printf("Ваш выбор: ");
    int task = getValue();

    switch (task)
    {
    case 1:
        if (size % 2 == 0) {
            printf("\nОшибка: для задачи 1 размер массива должен быть нечётным!\n");
            free(C);
            exit(1);
        }
        {
            printf("\nЗадача 1:\n");
            int* C_copy1 = copyArray(C, size);
            replaceMinWithMiddle(C_copy1, size);
            printf("Массив после замены: ");
            printArray(C_copy1, size);
            free(C_copy1);
        }
        break;

    case 2:
    {
        printf("\nЗадача 2:\n");
        size_t newSize = getCountWithoutDigit5(C, size);
        if (newSize == 0)
        {
            printf("Все элементы содержат цифру 5. Массив пуст!\n");
        }
        else
        {
            int* newC = allocateArray(newSize);
            removeElementsWithDigit5(C, size, newC, newSize);
            printf("Массив без элементов с цифрой 5: ", newSize);
            printArray(newC, newSize);
            free(newC);
        }
    }
    break;

    case 3:
    {
        printf("\nЗадача 3:\n");
        int* A = formArrayFromC(C, size);
        printf("Сформированный массив A: ");
        printArray(A, size);
        free(A);
    }
    break;

    case 4:
        if (size % 2 == 0) 
        {
            printf("\nОшибка: для выполнения всех задач размер должен быть нечётным!\n");
            free(C);
            exit(1);
        }
        {
            printf("\nЗадача 1:\n");
            int* C_copy1 = copyArray(C, size);
            replaceMinWithMiddle(C_copy1, size);
            printf("Массив после замены: ");
            printArray(C_copy1, size);
            free(C_copy1);
            printf("\nЗадача 2:\n");
            size_t newSize = getCountWithoutDigit5(C, size);
            if (newSize == 0)
            {
                printf("Все элементы содержат цифру 5. Массив пуст!\n");
            }
            else
            {
                int* newC = allocateArray(newSize);
                removeElementsWithDigit5(C, size, newC, newSize);
                printf("Массив без элементов с цифрой 5: ", newSize);
                printArray(newC, newSize);
                free(newC);
            }
            printf("\nЗадача 3:\n");
            int* A = formArrayFromC(C, size);
            printf("Сформированный массив A: ");
            printArray(A, size);
            free(A);
        }
        break;
    default:
        printf("Неверный выбор задачи!\n");
        free(C);
        exit(1);
    }
    free(C);
    return 0;
}
int getValue()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    return value;
}
size_t getSize(const char* message)
{
    printf("%s", message);
    int value = getValue();
    if (value <= 0)
    {
        printf("Размер должен быть положительным числом!\n");
        exit(1);
    }
    return (size_t)value;
}
void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент arr[%zu]: ", i);
        arr[i] = getValue();
    }
}
void printArray(const int* arr, const size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]");
    printf("\n");
}
void fillRandom(int* arr, const size_t size)
{
    printf("Введите начало диапазона: ");
    int start = getValue();
    printf("Введите конец диапазона: ");
    int end = getValue();
    if (start >= end)
    {
        printf("Ошибка! Конечное значение должно быть больше начального\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}
int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = allocateArray(size);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
int* allocateArray(const size_t size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти для массива размера %zu!\n", size);
        exit(1);
    }
    return arr;
}
int findMinEl(const int* arr, const size_t size)
{
    int minElIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < arr[minElIndex])
        {
            minElIndex = i;
        }
    }
    return minElIndex;
}
int findMiddleEl(const int* arr, const size_t size)
{
    return arr[size / 2];
}
void replaceMinWithMiddle(int* arr, const size_t size)
{
    int minElIndex = findMinEl(arr, size);
    int middleEl = findMiddleEl(arr, size);
    arr[minElIndex] = middleEl;
}
bool containsDigit5(int el)
{
    if (el < 0) el = -el;
    for (; el > 0; el /= 10)
    {
        if (el % 10 == 5)
        {
            return true;
        }
    }
    return false;
}
size_t getCountWithoutDigit5(const int* arr, const size_t size)
{
    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (!containsDigit5(arr[i]))
        {
            count++;
        }
    }
    return count;
}
void removeElementsWithDigit5(const int* arr, const size_t size, int* newarr, const size_t newSize)
{
    size_t newIndex = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (!containsDigit5(arr[i]))
        {
            newarr[newIndex++] = arr[i];
        }
    }
}
int* formArrayFromC(const int* C, const size_t size)
{
    int* A = allocateArray(size);
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            A[i] = (int)pow(C[i], 2);
        }
        else
        {
            A[i] = 2 * C[i];
        }
    }
    return A;
}
