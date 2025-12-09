#include <stdexcept>

// Для указателей
void SwapPtr(int*& ptr1, int*& ptr2) {
    auto tmpPtr = ptr1;
    ptr1 = ptr2;
    ptr2 = tmpPtr;
}

// Для указателей на указатели
void SwapPtr(int**& ptr1, int**& ptr2) {
    auto tmpPtr = ptr1;
    ptr1 = ptr2;
    ptr2 = tmpPtr;
}

// Для константных указателей
void SwapPtr(const int*& ptr1, const int*& ptr2) {
    auto tmpPtr = ptr1;
    ptr1 = ptr2;
    ptr2 = tmpPtr;
}