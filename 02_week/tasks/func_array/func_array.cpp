#include <stdexcept> // Остался для определения size_t

// Используем using чтобы подставить как параметр функции
using FuncType = double (**)(double, double);

double ApplyOperations(double a, double b, FuncType ops, size_t opsSize) {

    // Создаем переменную, куда будет складываться результат
    double res = 0.0;

    // Перебираем все операции
    for (size_t i = 0; i < opsSize; i++) {
        // Проверяем на пустой указатель операции
        if (ops[i] == nullptr)
            continue; // пропускаем цикл, если пустой

        // Производим запуск операции и складываем результат
        res += ops[i](a, b);
    }

    return res;
}