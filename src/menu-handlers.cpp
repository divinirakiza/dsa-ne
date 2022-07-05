#include <iostream>
#include <iomanip>
#include <ctime>
#include "models/Location.h"
using namespace std;


void printHeader() {
    cout << "================================================================" << endl;
    cout << "*\tWelcome to Disease Casese Reporting System!\t*" << endl;
    cout << "************************************************" << endl;
    cout << "*\t\t\t\t*" << endl;
    cout << "It is developed by 'Divin Irakiza' as practical *" << endl;
    cout << "evaluation for the end of Year 3. *" << endl;
    cout << "================================================================" << endl;
}



void handleHelpCommand() {
    cout << "================================================================" << endl;
    cout << "*\t\t\tHELP MENU " << endl;
    cout << "================================================================" << endl;

    cout << "add <Location> \t\t :Add a new location" << endl;
    cout << "delete <Location> \t\t :Delete an existing location" << endl;
    cout << "record <Location> <disease> <cases> \t\t :Record a disease and its case" << endl;
    cout << "list locations \t\t :List all existing locations" << endl;
    cout << "list diseases \t\t :List existing Diseases in locations" << endl;
    cout << "where <disease> \t\t :Find where disease exists" << endl;
    cout << "case <Location><disease> \t\t: Find cases of a disease in location" << endl;
    cout << "cases <disease> \t\t :Find total cases of a given disease" << endl;
    cout << "help \t\t :Prints user manual" << endl;
    cout << "Exit \t\t :Exit the program" << endl;
}


void handleExitCommand() {
    cout << "Closing the system" << endl;
}

void handleAddLocationCommand(string* args) {
    Location location = Location(args[1]);
    cout << "Location " << location.getName() << " is succcessfully added" << endl;
}


void handleDeleteLocationCommand() {
    cout << "Closing the system" << endl;
}

void handleRecordDiseaseAndCasesCommand() {
    cout << "Closing the system" << endl;
}

void handleListLocationsCommand() {
    cout << "Closing the system" << endl;
}

void handleWhereDiseaseCommand() {
    cout << "Closing the system" << endl;
}

void handleDiseaseCasesCommand() {

}

void handleTotalDiseaseCasesCommand() {

}
