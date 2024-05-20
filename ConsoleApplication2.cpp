#include <iostream>

template <class T>
class ListNode {
public:
    T data;
    ListNode<T>* next;

    // Конструктор для создания узла списка с заданным значением
    ListNode(const T& value) : data(value), next(nullptr) {}
};

template <class T>
class LinkedList {
private:
    ListNode<T>* head; // Указатель на начало списка

public:
    // Конструктор по умолчанию
    LinkedList() : head(nullptr) {}

    // Деструктор для освобождения памяти, занятой узлами списка
    ~LinkedList() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Метод для добавления элемента в начало списка
    void insert(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Метод для удаления первого элемента списка
    void remove() {
        if (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Метод для вывода содержимого списка
    void display() {
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);

    std::cout << "List: ";
    myList.display();

    myList.remove();

    std::cout << "List after removal: ";
    myList.display();

    return 0;
}