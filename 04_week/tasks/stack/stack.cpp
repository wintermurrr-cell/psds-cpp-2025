#include <algorithm>
#include <vector>

class Stack {
public:
    void Push(const int val);     // добавляет элемент на верхушку стека
    bool Pop();                   // убирает элемент с верхушки стека
    int& Top();                   // обеспечивает доступ к элементу на верхушке стека
    const int& Top() const;       // обеспечивает доступ к элементу на верхушке стека без изменений
    bool Empty() const;           // возвращает результат проверки стека на отсутствие элементов
    size_t Size() const;          // возвращает количество элементов в стеке
    void Clear();                 // очищает стек
    void Swap(Stack& otherStack); // меняется элементами с другим стеком (без копирования)

    bool operator==(const Stack& otherStack) const;
    bool operator!=(const Stack& otherStack) const;

private:
    std::vector<int> stack; // Структура хранения данных
};

void Stack::Push(const int val) {
    stack.push_back(val);
}

bool Stack::Pop() {
    if (Size() == 0)
        return false;

    stack.pop_back();
    return true;
}

int& Stack::Top() {
    return stack.back();
}

const int& Stack::Top() const {
    return stack.back();
}

bool Stack::Empty() const {
    return stack.empty();
}

size_t Stack::Size() const {
    return stack.size();
}

void Stack::Clear() {
    stack.clear();
}

void Stack::Swap(Stack& otherStack) {
    std::swap(*this, otherStack);
}

bool Stack::operator==(const Stack& otherStack) const {
    return stack == otherStack.stack;
}

bool Stack::operator!=(const Stack& otherStack) const {
    return stack != otherStack.stack;
}
