#ifndef KINDAMENU_H
#define KINDAMENU_H

#include "vector.hpp"
#include "file.hpp"
#include <string>
#include "Hash.hpp"
#include "queueStack.hpp"
#include "lists.hpp"
#include "help.hpp"
#include "AVLtree.hpp"
const string ARRAY_SECTION = "Array";
const string AVL_SECTION = "AvlTree";
const string DLIST_SECTION = "Dlist";
const string MAP_SECTION = "Map";
const string QUEUE_SECTION = "Queue";
const string SLIST_SECTION = "Slist";
const string STACK_SECTION = "Stack";

void vectorMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "MPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Vector<string> array = readArray(name);
        array.pushBack(element);
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    }
    else if (command == "MLEN") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);

        Vector<string> array = readArray(name);
        cout << array.size() << endl;
    }
    else if (command == "MSET") {
        if (arguments.size() != 4) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }
        string value = arguments.get(3);

        Vector<string> array = readArray(name);
        try {
            array.set(index, value);
        }
        catch (invalid_argument& e) {
            throw runtime_error("invalid index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    }
    else if (command == "MDEL") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        Vector<string> array = readArray(name);
        try {
            array.remove(index);
        }
        catch (invalid_argument& e) {
            throw runtime_error("incorrect index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    }
    else if (command == "MGET") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        Vector<string> array = readArray(name);
        cout << array.get(index) << endl;
    }
}


void avlTreeMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "TPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int number;
        try {
            number = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        AVLTree tree = readTree(name);
        tree.insertNum(number);
        save(AVL_SECTION, name, name + " " + tree.serialize());
    }
    else if (command == "TDEL") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int number;
        try {
            number = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        AVLTree tree = readTree(name);
        tree.removeNum(number);
        save(AVL_SECTION, name, name + " " + tree.serialize());
    }
    else if (command == "TGET") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);

        AVLTree tree = readTree(name);
        cout << tree << endl;
    }
    else if (command == "TFIND") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int elem;
        elem = stoi(arguments.get(2));

        AVLTree tree = readTree(name);

        if (tree.find(elem)) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}
void dlistMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "DLPUSHBACK") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Dlist<string> dlist = readDlist(nameArr);
        dlist.pushBack(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    }
    else if (command == "DLPUSHFORWARD") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Dlist<string> dlist = readDlist(nameArr);
        dlist.pushForward(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    }
    else if (command == "DLDELBACK") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeBack();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    }
    else if (command == "DLDELFORWARD") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeForward();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    }
    else if (command == "DLDELVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeValue(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    }
    else if (command == "DLGET") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        Dlist<string> dlist = readDlist(nameArr);
        cout << dlist.get(index) << endl;
    }
    else if (command == "DLFINDBYVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        Dlist<string> dlist = readDlist(nameArr);
        int index = dlist.findByValue(element);

        if (index != -1) {
            cout << index << endl;
        }
        else {
            throw runtime_error("Element not found");
        }
    }
    else if (command == "DLPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        cout << dlist << endl;
    }
}
void mapMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "HPUSH") {
        if (arguments.size() != 4) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);
        string value = arguments.get(3);

        if (key.find(",") != string::npos || value.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed key or value");
        }
        else if (key.find(",") != string::npos || value.find(",") != string::npos) {
            throw runtime_error("; shouldn't be in pushed key or value");
        }

        Map<string> map = readMap(name);
        map.put(key, value);
        save(MAP_SECTION, name, name + " " + map.join());
    }
    else if (command == "HDEL") {
        if (arguments.size() != 3) {
            throw invalid_argument("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        Map<string> map = readMap(name);
        map.remove(key);
        save(MAP_SECTION, name, name + " " + map.join());
    }
    else if (command == "HGET") {
        if (arguments.size() != 3) {
            throw invalid_argument("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        string key = arguments.get(2);

        Map<string> map = readMap(name);
        cout << map.get(key) << endl;
        save(MAP_SECTION, name, name + " " + map.join());
    }
    else if (command == "HPRINT") {
        if (arguments.size() != 2) {
            throw invalid_argument("incorrect count of arguments");
        }
        string name = arguments.get(1);

        Map<string> map = readMap(name);
        cout << map << endl;
    }
}
void queueMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "QPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Queue<string> queue = readQueue(nameArr);
        queue.enqueue(element);
        save(QUEUE_SECTION, nameArr, nameArr + " " + queue.data().join(','));
    }
    else if (command == "QPOP") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Queue<string> queue = readQueue(nameArr);
        cout << "Popped: " << queue.dequeue() << endl;
        save(QUEUE_SECTION, nameArr, nameArr + " " + queue.data().join(','));
    }
    else if (command == "QPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Queue<string> queue = readQueue(nameArr);
        cout << queue << endl;
    }
}
void slistMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "SLPUSHBACK") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        SList<string> Slist = readSlist(nameArr);
        Slist.pushBack(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    }
    else if (command == "SLPUSHFORWARD") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        SList<string> Slist = readSlist(nameArr);
        Slist.pushForward(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    }
    else if (command == "SLDELBACK") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> Slist = readSlist(nameArr);
        Slist.removeBack();
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    }
    else if (command == "SLDELFORWARD") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> Slist = readSlist(nameArr);
        Slist.removeForward();
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    }
    else if (command == "SLDELVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        SList<string> Slist = readSlist(nameArr);
        Slist.removeValue(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + Slist.join(','));
    }
    else if (command == "SLGET") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        }
        catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        SList<string> Slist = readSlist(nameArr);
        cout << Slist.get(index) << endl;
    }
    else if (command == "SLFINDBYVALUE") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        SList<string> Slist = readSlist(nameArr);
        int index = Slist.findByValue(element);

        if (index != -1) {
            cout << index << endl;
        }
        else {
            throw runtime_error("Element not found");
        }
    }
    else if (command == "SLPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> Slist = readSlist(nameArr);
        cout << Slist << endl;
    }
}
void stackMenu(Vector<string> arguments) {
    string command = arguments.get(0);

    if (command == "SPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Stack<string> stack = readStack(nameArr);
        stack.push(element);
        save(STACK_SECTION, nameArr, nameArr + " " + stack.data().join(','));
    }
    else if (command == "SPOP") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Stack<string> stack = readStack(nameArr);
        cout << "Popped: " << stack.pop() << endl;
        save(STACK_SECTION, nameArr, nameArr + " " + stack.data().join(','));
    }
    else if (command == "SPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Stack<string> stack = readStack(nameArr);
        cout << stack << endl;
    }
}
#endif