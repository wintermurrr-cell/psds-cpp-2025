#include <vector>

using Pred = bool (*)(int);

void Filter(std::vector<int>& v, Pred func) {
    if (func == nullptr)
        return;

    int rewrite_indx = 0; // Индекс для перезписи устаревшего элемента

    // Проходимся по всему массиву
    for (auto itr = v.begin(); itr != v.end(); ++itr) {
        // Если элемент удовлетворяет условию
        if (func(*itr)) {
            v[rewrite_indx] = *itr; // Перепимываем элемент на новое значение, которое нужно оставить
            ++rewrite_indx;         // Увеличиваем счетчик элемента
        }
    }

    v.resize(rewrite_indx); // Удаляем оставшийся массив
}
