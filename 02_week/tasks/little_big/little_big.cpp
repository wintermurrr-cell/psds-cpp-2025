#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

// функция выводит символ по индексу
void printSymbol(unsigned char* numbers, int printIndex) {
    // Используем битовую маску, чтобы вывести лишь 2 последних символа
    const auto value = (static_cast<int>(numbers[printIndex]));

    // Выводить не меньеше двух символов
    // Если вывод меньше двух символов, то дополняем вывод нулями
    // и выводим получившееся число
    std::cout << std::setw(2) << std::setfill('0') << value;
}

// Функция проверяем как выводить последовательность символов
//  и исходя из этого - выбирает нужный цикл
void checkIsInvert(unsigned char* numbers, int size, bool isInvert) {

    if (isInvert) {
        // Если нужно инвертирование, то получаем символы в обратном порядке
        for (int i = size - 1; 0 <= i; --i) {
            printSymbol(numbers, i);
        }
    } else {
        for (int i = 0; i < size; ++i) {
            printSymbol(numbers, i);
        }
    }
}

// вывод представления для int
void PrintMemory(int number, bool isInvert = false) {

    // Получаем представление числа в символах
    // unsigned - позволяет выводить только два символа
    unsigned char* ptr_char = reinterpret_cast<unsigned char*>(&number);

    // Выводим первый символ строки
    // Устанавливаем вывод в шестнадцатиричной системе счисления
    // Все буквенные символы заглавными буквами
    std::cout << "0x" << std::hex << std::uppercase;

    // Делаем проверку на инвертированный вывод и выводим последовательность
    checkIsInvert(ptr_char, sizeof(int), isInvert);

    // Выводим конец строки
    std::cout << std::endl;
}

// вывод представления для double
void PrintMemory(double number, bool isInvert = false) {

    // Получаем представление числа в символах
    unsigned char* ptr_char = reinterpret_cast<unsigned char*>(&number);

    // Выводим первый символ строки
    // Устанавливаем вывод в шестнадцатиричной системе счисления
    // Все буквенные символы заглавными буквами
    std::cout << "0x" << std::hex << std::uppercase;

    // Делаем проверку на инвертированный вывод и выводим последовательность
    checkIsInvert(ptr_char, sizeof(double), isInvert);

    // Выводим конец строки
    std::cout << std::endl;
}
