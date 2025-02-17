
#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include "lists.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct Queue {
    Dlist<T> list; // ������ ��� �������� ��������� �������

    // �����������
    Queue() {}

    // ����� ��� ��������� ������
    Dlist<T> data() const {
        return list;
    }

    // ����� ��� ��������� ������� �������
    int size() const {
        return list.size();
    }

    // ����� ��� ���������� �������� � ����� �������
    void enqueue(const T& val) {
        list.pushBack(val);
    }

    // ����� ��� �������� �������� �� ������ �������
    T dequeue() {
        if (size() == 0) {
            throw runtime_error("Queue is empty");
        }

        T dequeued = list.head->value; // ��������� �������� ��� �����������
        list.removeForward(); // ������� ������� �� ������ ������
        return dequeued; // ���������� ��������� �������
    }

    // ����� ��� ������ ����������� �������
    void print() const {
        for (int i = 0; i < size(); i++) {
            cout << list.get(i) << " "; // ��������������, ��� � Dlist ���� ����� get
        }
        cout << endl;
    }
};

// �������� ��� ������ ����������� �������
template <typename T>
ostream& operator<<(ostream& os, const Queue<T>& queue) {
    queue.print(); // ���������� ����� print ��� ������
    return os;
}
//***************************************STACK******************************** */
template <typename T>
struct Stack {
    SList<T> list; // ������ ��� �������� ��������� �����

    // �����������
    Stack() {}

    // ����� ��� ��������� ������� �����
    int size() const {
        return list.size();
    }

    // ����� ��� ��������� ������ �����
    SList<T> data() const {
        return list;
    }

    // ����� ��� ���������� �������� �� ������� �����
    void push(const T& value) {
        list.pushForward(value);
    }

    // ����� ��� �������� �������� � ������� �����
    T pop() {
        if (list.head == nullptr) {
            throw runtime_error("Stack is empty");
        }
        T popped = list.head->value; // ��������� �������� ��� �����������
        list.removeForward(); // ������� ������� � ������� �����
        return popped; // ���������� ��������� �������
    }

    // ����� ��� ������ ����������� �����
    void print() const {
        for (int i = 0; i < size(); i++) {
            cout << list.get(i) << " "; // ��������������, ��� � SList ���� ����� get
        }
        cout << endl;
    }
};

// �������� ��� ������ ����������� �����
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack) {
    stack.print(); // ���������� ����� print ��� ������
    return os;
}
#endif
