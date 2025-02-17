#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <regex>
#include "vector.hpp"
#include "queueStack.hpp"
#include "help.hpp"
#include "lists.hpp"
#include "Hash.hpp"
#include "AVLtree.hpp"


using namespace std;

const string FILENAME = "file.data";

Vector<string> readArray(string name) {
    Vector<string> array;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Array") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                array = split(splittedLine.get(1), ','); // делим по запятым второй аргумент
                if (array.size() == 1 && array.get(0) == "") { // при пустой строке создаётся массив с пустой строкой, надо удалить эту строку, чтоб сделать пустой массив
                    array.remove(0);
                }
                return array;
            }
        }
    }

    file.close();

    return array;
}

Queue<string> readQueue(string name) {
    Queue<string> queue;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Queue") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Vector<string> array = split(splittedLine.get(1), ','); // делим по запятым второй аргумент
                if (array.size() == 1 && array.get(0) == "") { // при пустой строке создаётся массив с пустой строкой, надо удалить эту строку, чтоб сделать пустой массив
                    array.remove(0);
                }
                for (int i = 0; i < array.size(); i++) {
                    queue.enqueue(array.get(i));
                }
                return queue;
            }
        }
    }

    file.close();

    return queue;
}

Stack<string> readStack(string name) {
    Stack<string> stack;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Stack") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Vector<string> array = split(splittedLine.get(1), ','); // делим по запятым второй аргумент
                array.reverse();
                if (array.size() == 1 && array.get(0) == "") { // при пустой строке создаётся массив с пустой строкой, надо удалить эту строку, чтоб сделать пустой массив
                    array.remove(0);
                }
                for (int i = 0; i < array.size(); i++) {
                    stack.push(array.get(i));
                }
                return stack;
            }
        }
    }

    file.close();

    return stack;
}

Dlist<string> readDlist(string name) {
    Dlist<string> dlist;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Dlist") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Vector<string> array = split(splittedLine.get(1), ','); // делим по запятым второй аргумент
                if (array.size() == 1 && array.get(0) == "") { // при пустой строке создаётся массив с пустой строкой, надо удалить эту строку, чтоб сделать пустой массив
                    array.remove(0);
                }
                for (int i = 0; i < array.size(); i++) {
                    dlist.pushBack(array.get(i));
                }
                return dlist;
            }
        }
    }

    file.close();

    return dlist;
}

SList<string> readSlist(string name) {
    SList<string> slist;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Slist") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Vector<string> array = split(splittedLine.get(1), ','); // делим по запятым второй аргумент
                if (array.size() == 1 && array.get(0) == "") { // при пустой строке создаётся массив с пустой строкой, надо удалить эту строку, чтоб сделать пустой массив
                    array.remove(0);
                }
                for (int i = 0; i < array.size(); i++) {
                    slist.pushBack(array.get(i));
                }
                return slist;
            }
        }
    }

    file.close();

    return slist;
}

Map<string> readMap(string name) {
    Map<string> map;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Map") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Vector<string> array = split(splittedLine.get(1), ';'); // делим по точке-запятой второй аргумент
                if (array.size() == 1 && array.get(0) == "") { // при пустой строке создаётся массив с пустой строкой, надо удалить эту строку, чтоб сделать пустой массив
                    array.remove(0);
                }
                else {
                    for (int i = 0; i < array.size(); i++) {
                        Vector<string> keyval = split(array.get(i), ',');
                        if (keyval.size() != 2) {
                            throw runtime_error("invalid map format");
                        }
                        string key = keyval.get(0);
                        string value = keyval.get(1);
                        map.put(key, value);
                    }
                }

                return map;
            }
        }
    }

    file.close();

    return map;
}

AVLTree readTree(string name) {
    AVLTree tree;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;

    bool isArray = false;
    while (getline(file, line)) {
        if (line == "AvlTree") {
            isArray = true;
        }
        else if (line == "" && isArray) {
            break;
        }
        else if (isArray) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                tree.unserialize(splittedLine.get(1));
                return tree;
            }
        }
    }

    file.close();

    return tree;
}

// сохраняет в file.data. Работает для list,array,queue,stack
void save(string section, string name, string writeline) {
    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("error opening file");
    }

    Vector<string> fileLines;  // Вектор для хранения строк файла
    string line; //переменная для хранения текущей строки файла при чтении
    bool isArraySection = false; // флаг для отслеживания, находимся ли мы в нужной секции
    bool foundArray = false;

    while (getline(file, line)) {
        if (line == section) {
            isArraySection = true;
        }
        else if (isArraySection && line == "") {
            isArraySection = false;
            if (!foundArray) {
                fileLines.pushBack(writeline);
            }
        }

        if (isArraySection) {
            Vector<string> splittedLine = split(line, ' ');

            if (splittedLine.size() == 2 && splittedLine.get(0) == name) {
                // Нашли нужный массив, заменяем его на новый
                line = writeline;
                foundArray = true;
            }
        }

        fileLines.pushBack(line);  // Сохраняем строку
    }

    file.close();  // Закрываем файл после чтения

    // Открываем файл для записи (перезаписываем содержимое файла)
    ofstream outFile(FILENAME);
    if (!outFile.is_open()) {
        throw runtime_error("Error opening file for writing");
    }

    // Записываем все строки обратно в файл
    for (int i = 0; i < fileLines.size(); i++) {
        outFile << fileLines.get(i) << endl;
    }

    outFile.close();  // Закрываем файл после записи
}


#endif
