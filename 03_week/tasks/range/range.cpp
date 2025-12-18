#include <vector>

bool checkContinue(const int i, const int to, const int from) {
    // Если from меньше, чем to, то и i должен быть меньше to
    if (from < to)
        return i < to;
    else // и так же наоборот, если from > to, то перемещаемся в обратную сторону
        return i > to;
}

std::vector<int> Range(int from, int to, int step = 1) {

    std::vector<int> result;

    if (from == to     // Начальное значение не должно совпадать с конечным
        || step == 0)  // Шаг не может быть равен нулю
        return result; // Возвращаем пустой массив

    // Для перемещения вперед ожидается шаг больше нуля
    if (from < to && step < 0)
        return result;

    // Для перемещения назад ожидается шаг меньше нуля
    if (from > to && step > 0)
        return result;

    int count_element = (to - from) / step + 1; // Ожидаемое число элементов
    result.reserve(count_element);              // Заранее резервируем это количество элементов

    // В цикле добавляем в вектор элементы начиная с to и заканчивая from через шаг step
    for (int i = from; checkContinue(i, to, from); i += step) {
        result.push_back(i);
    }

    return result;
}
