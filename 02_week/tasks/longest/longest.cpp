#include <stdexcept> // Остался для определения size_t

char* FindLongestSubsequence(const char* begin, const char* end, size_t& count) {

    // Указатель на начало самой большой последовательности
    char* LongestStartChar = nullptr;
    count = 0; // Зануляем счётчик

    // Проверяем на действительные указатели
    if (begin == nullptr || end == nullptr)
        return LongestStartChar;

    // Указатель на начало массива не должен быть больше указателя на конец массива
    if (end < begin)
        return LongestStartChar;

    // Сбрасываем константность с указателя begin 
    //  и работаем дальше с неконстантной копией указателя (копией же?)
    char* noConstBegin = const_cast<char*>(begin);

    // Указатель на символ начала последовательности
    char* currChar = noConstBegin;

    // Счетчик текущей последовательности символов
    size_t currCount = 0;

    // Цикл для перебора элементов массива
    while (noConstBegin != end) {
        char* symb = noConstBegin++; // Оставляем указатель на текущий begin и переходим у следующему символу

        // Если символы в указателях равны, то увеличиваем счётчик последователньости
        if (*currChar == *symb) {
            currCount++;

            // Проверяем, не закончилась ли последовательность символов
            if (noConstBegin != end)
                continue; // Если не закончилась, то повотряем цикл
        }

        // Если попали сюда, то непрерывная последовательность прервана
        //  или достигли конца массива

        // Если текущая последовательность символов больше предыдущей, то заменяем значения
        if (currCount > count) {
            count = currCount;
            LongestStartChar = currChar;
        }
        currChar = symb;
        currCount = 1;
    }

    return LongestStartChar;
}
