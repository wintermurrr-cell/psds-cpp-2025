#include <stack>
#include <vector>

class Queue {
public:
    Queue() = default;
    Queue(const std::vector<int>& queue);
    Queue(std::stack<int> stack);
    Queue(const std::initializer_list<int>& list);
    Queue(const int size);

    void Push(const int val);     // добавляет элемент в конец очереди
    bool Pop();                   // убирает элемент из начала очереди
    int& Front();                 // обеспечивает доступ на запись и чтение к элементу в начале очереди
    const int& Front() const;     // обеспечивает доступ на запись и чтение к элементу в начале очереди без изменений
    int& Back();                  // обеспечивает доступ на запись и чтение к элементу в конце очереди
    const int& Back() const;      // обеспечивает доступ на запись и чтение к элементу в конце очереди без изменений
    bool Empty() const;           // возвращает результат проверки очереди на отсутствие элементов
    size_t Size() const;          // возвращает количество элементов в очереди
    void Clear();                 // очищает очередь
    void Swap(Queue& otherQueue); // меняется элементами с другой очередью (без копирования)

    bool operator==(const Queue& otherQueue) const;
    bool operator!=(const Queue& otherQueue) const;

private:
    std::vector<int> queue;
};

Queue::Queue(const std::vector<int>& queue) :
    queue(queue) {}

Queue::Queue(std::stack<int> stack) {

    const auto stackSize = stack.size();
    queue.reserve(stackSize);
    for (size_t i = 0; i < stackSize; i++) {
        queue.push_back(stack.top());
        stack.pop();
    }

    // Разворачиваем элементы очереди, ведь после заполнения из стека, они в обратном порядке
    std::reverse(queue.begin(), queue.end());
}

Queue::Queue(const std::initializer_list<int>& list) {
    queue.reserve(list.size());

    // Копируем из листа в очередь данные
    std::copy(list.begin(), list.end(), std::back_inserter(queue));
}

Queue::Queue(const int size) {
    queue.reserve(size);
}

void Queue::Push(const int val) {
    queue.push_back(val);
}

bool Queue::Pop() {
    if (queue.empty())
        return false;

    queue.erase(queue.begin());
    return true;
}

int& Queue::Front() {
    return queue.front();
}

const int& Queue::Front() const {
    return queue.front();
}

int& Queue::Back() {
    return queue.back();
}

const int& Queue::Back() const {
    return queue.back();
}

bool Queue::Empty() const {
    return queue.empty();
}

size_t Queue::Size() const {
    return queue.size();
}

void Queue::Clear() {
    queue.clear();
}

void Queue::Swap(Queue& otherQueue) {
    std::swap(*this, otherQueue);
}

bool Queue::operator==(const Queue& otherQueue) const {
    return queue == otherQueue.queue;
}

bool Queue::operator!=(const Queue& otherQueue) const {
    return queue != otherQueue.queue;
}
