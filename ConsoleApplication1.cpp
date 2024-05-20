#include <iostream>
#include <list>

template <typename T>
class Stack {
private:
    std::list<T> data; // Используем List для хранения данных стека

public:
    // Конструктор по умолчанию
    Stack() {}

    // Добавление элемента в вершину стека
    void push(const T& item) {
        data.push_back(item);
    }

    // Удаление элемента из вершины стека
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
        else {
            std::cerr << "Stack is empty. Cannot pop.\n";
        }
    }

    // Получение элемента из вершины стека без его удаления
    T& top() {
        if (!isEmpty()) {
            return data.back();
        }
        else {
            throw std::out_of_range("Stack is empty. Cannot get top element.");
        }
    }

    // Проверка на пустоту стека
    bool isEmpty() const {
        return data.empty();
    }

    // Получение размера стека
    size_t size() const {
        return data.size();
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    return 0;
}