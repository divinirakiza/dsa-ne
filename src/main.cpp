#include <iostream>
#include <string>
#include "utils.cpp"
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

        if (compare(command, "HELP")) {
            handleHelpCommand();
        } else if (compare(command, "EXIT")) {
            handleExitCommand();
        }
        else if (startsWith(command, "ADD")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "ADD")) {
                cout << "Invalid command arguments provided. Type 'help' for more information." << endl;
            } else {
                handleAddLocationCommand(args);
            }
            cout << "Saved" << endl;
        }
        else if (compare(command, "ADD")) {

        }
        else if (compare(command, "ADD")) {

        }
        else if (compare(command, "ADD")) {

        }
        else if (compare(command, "ADD")) {

        }

        else if (compare(command, "ADD")) {

        } else {
            cout << "Command doesn't exist, Trying >help, for help." << endl;
        }
    }
     
    return 0;
}


