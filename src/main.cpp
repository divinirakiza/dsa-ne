#include <iostream>
#include <string>
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
        }
        else if (startsWith(command, "ADD")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "ADD")) {
                cout << "Invalid command arguments provided. Type 'help' for more information." << endl;
            } else {
                handleAddLocationCommand(args);
            }
        }
        else if (startsWith(command, "DELETE")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "DELETE")) {
                cout << "Invalid command arguments provided. Type 'help' for more information." << endl;
            } else {
                handleDeleteLocationCommand(args);
            }
        }
         else if (startsWith(command, "RECORD")) {
            string* args = split(command, ' ');

            if (!validateCommandInput(args, "RECORD")) {
                cout << "Invalid command arguments provided. Type 'help' for more information." << endl;
            } else {
                handleRecordDiseaseAndCasesCommand(args);
            }
        }
        else if (startsWith(command, "LIST")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "LIST")) {
                cout << "Invalid command arguments provided. Type 'help' for more information." << endl;
            } else {
                handleListLocationsCommand(args);
            }
        }
   
        else if (compare(command, "ADD")) {

        }
        else if (compare(command, "ADD")) {

        }

        else if (compare(command, "ADD")) {
        }

        else if (compare(command, "EXIT")) {
            handleExitCommand();
        }
         else {
            cout << "Command doesn't exist, Trying >help, for help." << endl;
        }
    }
     
    return 0;
}


