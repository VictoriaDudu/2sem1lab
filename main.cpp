#include <iostream>
#include "help.hpp"
#include "vector.hpp"
#include "queueStack.hpp"
#include "lists.hpp"
#include "Hash.hpp"
#include "AVLtree.hpp"
#include "kindaMenu.hpp"
#include "file.hpp"
#include <string>

using namespace std;

int main() {
    string str;

    while (true) {
        cout << ">> ";
        getline(cin, str);
        Vector<string> splitedStr = split(str, ' ');
        string command = splitedStr.get(0);
        if (command.substr(0, 2) == "DL") {
            try {
                dlistMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else if (command.substr(0, 2) == "SL") {
            try {
                slistMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else if (command[0] == 'M') {
            try {
                vectorMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else if (command[0] == 'Q') {
            try {
                queueMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else if (command[0] == 'S') {
            try {
                stackMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else if (command[0] == 'H') {
            try {
                mapMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else if (command[0] == 'T') {
            try {
                avlTreeMenu(splitedStr);
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
        else {
            cerr << "Unknown command" << endl;
        }
    }

    return 0;
}