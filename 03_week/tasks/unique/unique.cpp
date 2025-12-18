#include <vector>

std::vector<int> Unique(std::vector<int> vec) {

    std::vector<int> result;    // Вектор с результатами
    result.reserve(vec.size()); // указание для вектора, сколько максимально элементов он будет в себе содержать

    // Если вектор не пустой
    if (!vec.empty())
        // то помещаем его первый элемент в начало
        result.push_back(vec.at(0));

    // Перебор всех элементов вектора
    for (const auto& element : vec) {
        // Поскольку изначальный вектор отсортирован,
        //  то считаем, что последний элемент этого вектора 
        //  не должен совпадать c текущим элементом
        if (result.back() != element)
            result.push_back(element); // добавляем в результирующий вектор
    }

    // обрезаем вместимость вектора до его текущего размера
    result.shrink_to_fit();

    return result;
}
