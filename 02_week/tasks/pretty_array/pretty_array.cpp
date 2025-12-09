#include <iostream> // Для std::cout

void PrintArray(const int* begin, const int* end, int limiter = 0) {

    std::cout << "[";

    // Проверка на существование указателей
    if (begin == nullptr || end == nullptr) {
        std::cout << "]\n";
        return;
    }

    // флаг, указывающий, в какую сторону следует итерироваться в массиве
    //  true - вперед
    //  false - назад
    bool isInc = begin < end;

    // Счетчик для текущего элемента
    int counter = 0;
    while (begin != end) {
        ++counter;

        // Выводим символ
        std::cout << *begin;

        // Проверяем, есть ли следующий элемент в массиве
        auto futureElement = isInc ? begin + 1 : begin - 1;
        if (futureElement != end) {
            std::cout << ", ";

            // Проверяем, следует ли переносить печать на новую строку
            if (limiter != 0
                && counter == limiter) {
                std::cout << "...\n ";
                counter = 0; // Сбрасываем счётчик
            }
        }

        // Переходим к следующему элементу массива
        if (isInc)
            ++begin;
        else
            --begin;
    }
    std::cout << "]\n";
}
