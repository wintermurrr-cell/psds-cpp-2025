#include <cstdint>   // Подключаем библиотеку для работы с целыми числами фиксированного размера
#include <iostream>  // Для вывода данных

enum class CheckFlags : uint8_t {
    NONE = 0,
    TIME = (1 << 0),
    DATE = (1 << 1),
    USER = (1 << 2),
    CERT = (1 << 3),
    KEYS = (1 << 4),
    DEST = (1 << 5),
    ALL = TIME | DATE | USER | CERT | KEYS | DEST
};

// Если бит стоит, то выводим текст stringIsTrue.
// Если не стоит - выводим пустую строку
std::string enumToString(uint8_t flagsInt, CheckFlags checkFlag, std::string stringIsTrue) {

  // Проверяем на то, выставлен ли бит
    if (flagsInt & static_cast<uint8_t>(checkFlag)) {
      return stringIsTrue + ',';
    }
    return {};
}

// Функция для вывода в консоль проверок, которые соответствуют флагам переданного енума
void PrintCheckFlags(CheckFlags flags) {

    uint8_t flagsInt = static_cast<uint8_t>(flags);

// Проверка выхода за пределы енума
    if (flagsInt > static_cast<uint8_t>(CheckFlags::ALL)) {
        return;
    }

    std::string res; // Строка для текстовых эквивалентов
    res += enumToString(flagsInt, CheckFlags::TIME, "TIME");
    res += enumToString(flagsInt, CheckFlags::DATE, "DATE");
    res += enumToString(flagsInt, CheckFlags::USER, "USER");
    res += enumToString(flagsInt, CheckFlags::CERT, "CERT");
    res += enumToString(flagsInt, CheckFlags::KEYS, "KEYS");
    res += enumToString(flagsInt, CheckFlags::DEST, "DEST");

// Если строка не пустая, то последний символ точно запятая - убираем
    if (!res.empty())
        res.pop_back();

     std::cout << "[" << res << "]";
}
