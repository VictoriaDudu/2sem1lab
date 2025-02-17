#ifndef LISTS_H
#define LISTS_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
struct SNode {
    T value;
    SNode<T>* next;

    SNode(const T& val) : value(val), next(nullptr) {}
};

template <typename T>
struct SList {
    SNode<T>* head;
    int len;

    SList() : head(nullptr), len(0) {}

    int size() const {
        return len;
    }

    void pushForward(T value) {
        SNode<T>* node = new SNode<T>(value);
        node->next = head;
        head = node;
        len++;
    }

    void pushBack(T value) {
        SNode<T>* node = new SNode<T>(value);
        if (head == nullptr) {
            head = node;
        }
        else {
            SNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        len++;
    }

    void removeForward() {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }

        SNode<T>* oldHead = head;
        head = head->next;
        delete oldHead;
        len--;
    }

    void removeBack() {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }

        if (head->next == nullptr) { // If there's only one element
            delete head;
            head = nullptr;
        }
        else {
            SNode<T>* current = head;
            while (current->next->next != nullptr) {
                current = current->next; // Find the second last node
            }
            delete current->next; // Delete the last node
            current->next = nullptr; // Nullify the next pointer
        }
        len--;
    }

    void removeValue(const T& value) {
        SNode<T>* prev = nullptr;
        SNode<T>* current = head;

        while (current != nullptr) {
            if (current->value == value) {
                if (prev != nullptr) {
                    prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                SNode<T>* toDelete = current;
                current = current->next;
                delete toDelete;
                len--;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    int findByValue(const T& value) {
        SNode<T>* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Not found
    }

    string join(char delimiter) {
        string result;
        SNode<T>* current = head;

        while (current != nullptr) {
            result += current->value;
            if (current->next != nullptr) {
                result += delimiter;
            }
            current = current->next;
        }

        return result;
    }

    T get(int index) const {
        if (index < 0 || index >= len) {
            throw runtime_error("Index out of bounds");
        }

        SNode<T>* current = head;
        for (int c = 0; c < index; c++) {
            current = current->next;
        }
        return current->value;
    }
};

// Overloaded output operator for printing the list
template <typename T>
ostream& operator<<(ostream& os, const SList<T>& list) {
    SNode<T>* current = list.head;
    while (current != nullptr) {
        os << current->value << endl;
        current = current->next;
    }
    return os;
}

template <typename T>
struct DNode {
    T value;
    DNode<T>* next;
    DNode<T>* prev;

    DNode(const T& val) : value(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
struct Dlist {
    DNode<T>* head;
    DNode<T>* tail;
    int len;

    Dlist() : head(nullptr), tail(nullptr), len(0) {}

    int size() const {
        return len;
    }

    T get(int index) const {
        if (index < 0 || index >= len) {
            throw runtime_error("Index out of bounds");
        }

        DNode<T>* current = head;
        for (int c = 0; c < index; c++) {
            current = current->next;
        }
        return current->value;
    }

    void pushForward(T value) {
        DNode<T>* node = new DNode<T>(value);
        if (head == nullptr) {
            head = node;
            tail = node; // Head and tail are the same
        }
        else {
            DNode<T>* oldHead = head;
            head = node;
            node->next = oldHead;
            oldHead->prev = node;
        }
        len++;
    }

    void pushBack(T value) {
        DNode<T>* node = new DNode<T>(value);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node; // Attach to the tail
            node->prev = tail;
            tail = node; // Update the tail
        }
        len++;
    }

    void removeForward() {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }

        DNode<T>* oldHead = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; // If head is removed, tail is also null
        }
        delete oldHead;
        len--;
    }

    void removeBack() {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }

        if (head->next == nullptr) { // Only one element
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            DNode<T>* current = tail;
            current->prev->next = nullptr;
            tail = current->prev; // Update the tail
            delete current;
        }
        len--;
    }

    void removeValue(const T& value) {
        DNode<T>* current = head;

        while (current != nullptr) {
            if (current->value == value) {
                DNode<T>* toDelete = current;
                if (current->prev != nullptr) { // Node is not the first
                    current->prev->next = current->next;
                }
                else { // First node
                    head = current->next;
                }

                if (current->next != nullptr) { // Node is not the last
                    current->next->prev = current->prev;
                }
                else { // Last node
                    tail = current->prev;
                }

                current = current->next;
                delete toDelete;
                len--;
            }
            else {
                current = current->next;
            }
        }
    }

    int findByValue(const T& value) {
        DNode<T>* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Not found
    }

    string join(char delimiter) {
        string result;
        DNode<string>* current = head;

        while (current != nullptr) {
            result += current->value;
            if (current->next != nullptr) {
                result += delimiter;
            }
            current = current->next;
        }

        return result;
    }
};

// Overloaded output operator for printing the list
template <typename T>
ostream& operator<<(ostream& os, const Dlist<T>& list) {
    DNode<T>* current = list.head;
    while (current != nullptr) {
        os << current->value << " ";
        current = current->next;
    }
    return os;
}
#endif
