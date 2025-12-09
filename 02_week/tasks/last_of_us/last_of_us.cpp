using Predicate = bool (*)(int); // Используем using чтобы подставить как параметр функции

const int* FindLastElement(const int* begin, const int* end, Predicate predicate) {

    // Проверяем на корректно переданные указатели
    if (begin == nullptr
        || end == nullptr
        || begin > end)
        return end;

    // Создаем указатель c результатом функции
    int* res = nullptr;

    // Отменяем константность, чтобы иметь возможность итерироваться по указателю
    auto noConstBegin = const_cast<int*>(begin);

    // Проходимся поэлементно по массиву чисел
    while (noConstBegin != end) {

        // Получаем по текущему указателю значение и передаем в функцию для проверки
        if (predicate(*noConstBegin))
            res = noConstBegin; // Записываем значение указателя, если проверка была пройдена

        // Перемещаемся по массиву чисел дальше
        noConstBegin++;
    }

    // Если ни одно число не удовлетворяло переданному условию,
    //  возвращаем указатель конца массива
    if (res == nullptr)
        return end;

    return res;
}