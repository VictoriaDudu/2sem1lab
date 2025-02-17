
#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include "lists.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct Queue {
    Dlist<T> list; // Список для хранения элементов очереди

    // Конструктор
    Queue() {}

    // Метод для получения данных
    Dlist<T> data() const {
        return list;
    }

    // Метод для получения размера очереди
    int size() const {
        return list.size();
    }

    // Метод для добавления элемента в конец очереди
    void enqueue(const T& val) {
        list.pushBack(val);
    }

    // Метод для удаления элемента из начала очереди
    T dequeue() {
        if (size() == 0) {
            throw runtime_error("Queue is empty");
        }

        T dequeued = list.head->value; // Сохраняем значение для возвращения
        list.removeForward(); // Удаляем элемент из начала списка
        return dequeued; // Возвращаем удаленный элемент
    }

    // Метод для печати содержимого очереди
    void print() const {
        for (int i = 0; i < size(); i++) {
            cout << list.get(i) << " "; // Предполагается, что в Dlist есть метод get
        }
        cout << endl;
    }
};

// Оператор для вывода содержимого очереди
template <typename T>
ostream& operator<<(ostream& os, const Queue<T>& queue) {
    queue.print(); // Используем метод print для вывода
    return os;
}
//***************************************STACK******************************** */
template <typename T>
struct Stack {
    SList<T> list; // Список для хранения элементов стека

    // Конструктор
    Stack() {}

    // Метод для получения размера стека
    int size() const {
        return list.size();
    }

    // Метод для получения данных стека
    SList<T> data() const {
        return list;
    }

    // Метод для добавления элемента на вершину стека
    void push(const T& value) {
        list.pushForward(value);
    }

    // Метод для удаления элемента с вершины стека
    T pop() {
        if (list.head == nullptr) {
            throw runtime_error("Stack is empty");
        }
        T popped = list.head->value; // Сохраняем значение для возвращения
        list.removeForward(); // Удаляем элемент с вершины стека
        return popped; // Возвращаем удаленный элемент
    }

    // Метод для печати содержимого стека
    void print() const {
        for (int i = 0; i < size(); i++) {
            cout << list.get(i) << " "; // Предполагается, что в SList есть метод get
        }
        cout << endl;
    }
};

// Оператор для вывода содержимого стека
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack) {
    stack.print(); // Используем метод print для вывода
    return os;
}
#endif
