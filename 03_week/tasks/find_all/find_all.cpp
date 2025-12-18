#include <vector>

// Используем using чтобы подставить как параметр функции
using FuncType = bool (*)(int);

std::vector<unsigned long> FindAll(const std::vector<int>& v, FuncType func) {

    // Результирующий вектор
    std::vector<unsigned long> resVec;

    if (func == nullptr)
        return resVec;

    // Резервируем максимальное возможное место
    resVec.reserve(v.size());

    // Цикл с проверками
    for (size_t i = 0; i < v.size(); ++i) {
        if (func(v[i]))
            resVec.push_back(i);
    }

    // Обрезаем лишние ячейки вектора после выделения места
    resVec.shrink_to_fit();

    return resVec;
}
