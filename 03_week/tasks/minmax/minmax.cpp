#include <vector>

using Itr = std::vector<int>::const_iterator; // Для константного итератора используем псевдоним Itr
using PairItr = std::pair<Itr, Itr>;          // Для пары итераторов используем псевдоним PairItr

PairItr MinMax(const std::vector<int>& v) {

    // Создаем пару итераторов, указывающую на начало вектора
    //  а так же, в случае пустого векотра - и на его конец одновременно
    PairItr p { v.begin(), v.begin() };

    // Проходимся по всему вектору
    for (auto it = v.begin(); it != v.end(); ++it) {

        // Если значение first (оно же min) больше текущего значения
        if (*p.first > *it) {
            p.first = it; // то заменяем итератор на текущее минимальное
        }

        // Если значение second (оно же max) меньше или равно текущего значения
        if (*p.second <= *it) {
            p.second = it; // то заменяем итератор на текущее максимальное
        }
    }

    // Возвращаем пару итераторов min и max
    return p;
}
