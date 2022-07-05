#include <iostream>
#include <string>
#include "utils.cpp"
#include "operations.h"
#include "menu-handlers.cpp"

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
            handleHelpCommand();
        } else if (compare(command, EXIT)) {
            handleExitCommand();
        }
        else if (compare(command, EXIT)) {
            
        }
        else if (compare(command, EXIT)) {

        }
        else if (compare(command, EXIT)) {

        }
        else if (compare(command, EXIT)) {

        }
        else if (compare(command, EXIT)) {

        }

        else if (compare(command, EXIT)) {

        }
    }
     
    return 0;
}


