#include <iostream>
#include <string>
#include "utils.cpp"
#include "operations.h"

using namespace std;



int main() {
    printHeader();
    getTime();

    string command;
    cout << "Need a help ? Type 'help' then press Enter key." << endl;
    while (true) {
        cout << "> ";
        getline(cin, command);
        cout << "You wrote " << command << endl;

        if (compare(command, HELP)) {
            printMenu();
        }
    }
     
    return 0;
}


