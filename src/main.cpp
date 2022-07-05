#include <iostream>
#include <string>
#include "menu-handlers.cpp"

using namespace std;

#define COLOR_RED "\033[1;31m"
#define COLOR_GRAY "\e[90m"
#define COLOR_RESET "\033[0m"

int main() {
    printHeader();
    getTime();

    string command;
    cout << "Need a help? Type 'help' then press Enter key." << endl;
    while (true) {
        cout << "> ";
        cout << COLOR_GRAY;
        getline(cin, command);
        cout << COLOR_RESET;
        if (compare(command, "HELP")) {
            handleHelpCommand();
        }
        else if (startsWith(command, "ADD")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "ADD")) {
                cout << COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
            } else {
                handleAddLocationCommand(args);
            }
        }
        else if (startsWith(command, "DELETE")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "DELETE")) {
                cout << COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
            } else {
                handleDeleteLocationCommand(args);
            }
        }
         else if (startsWith(command, "RECORD")) {
            string* args = split(command, ' ');

            if (!validateCommandInput(args, "RECORD")) {
                cout << COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
            } else {
                handleRecordDiseaseAndCasesCommand(args);
            }
        }
        else if (startsWith(command, "LIST")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "LIST")) {
                cout << COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
            } else {
                if (compare(args[1], "LOCATIONS")) {
                    handleListLocationsCommand(args);
                } else if (compare(args[1], "DISEASES")) {
                    handleListDiseasesCommand(args);
                } else {
                    cout << COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
                }
                
            }
        }
   
        else if (startsWith(command, "WHERE")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "WHERE")) {
                cout << COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
            } else {
                handleWhereDiseaseCommand(args);
            }
        }
   
        else if (startsWith(command, "CASES")) {
            string* args = split(command, ' ');
            if (!validateCommandInput(args, "CASES")) {
                cout <<  COLOR_RED << "Invalid command arguments provided. Type 'help' for more information." << COLOR_RESET << endl;
            } else {
                if (getStringArrayLen(args) == 2) {
                    handleTotalCasesOfDiseaseCommand(args);
                } else if (getStringArrayLen(args) == 3) {
                    handleCasesOfDiseaseInLocationCommand(args);
                }
            }
        }

        else if (compare(command, "EXIT")) {
            handleExitCommand();
        }
         else {

            cout << COLOR_RED << "Command doesn't exist, Trying >help, for help." << COLOR_RESET << endl;
        }
    }
     
    return 0;
}


