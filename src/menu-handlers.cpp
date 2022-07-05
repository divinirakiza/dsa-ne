#include <iostream>
#include <iomanip>
#include <ctime>
#include "files/file-operations.h"
#include "utils.cpp"
#include "models/Location.h"
#include "models/Disease.h"

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
    location.save();
    cout << "Location " << location.getName() << " is succcessfully added" << endl;
}

void handleDeleteLocationCommand(string* args) {
    Location location = Location::findByName(args[1]);
    if (compare(location.getName(), "")) {
        cout << "Location was not found" << endl;
    } else {
        location.remove();
    }
}

void handleRecordDiseaseAndCasesCommand(string* args) {
     Location location = Location::findByName(args[1]);
    if (!compare(location.getName(), "")) {
        Disease disease = Disease(location.getId(), args[2], stoi(args[3]));
        disease.save();
    } else {
        cout << "Location doesn't exist" << endl;
    }
}

void handleListLocationsCommand(string* args) {
    for (Location location : Location::getAll()) {
        cout << location.getName() << endl;
    }
}



void handleListDiseasesCommand(string* args) {
    for (Disease disease : Disease::getAll()) {
        cout << disease.getName() << endl;
    }
}


void handleWhereDiseaseCommand(string* args) {
    Disease disease = Disease::findByName(args[1]);
    if (!compare(disease.getName(), "")) {
        for (int locationId: Disease::findLocationsByDisease(disease)) {
            Location location = Location::findByID(locationId);
            cout << "[" << toLower(location.getName()) << "]" << endl;
        }
    } else {
        cout << "Disease was not found" << endl;
    }
}

void handleCasesOfDiseaseInLocationCommand(string* args) {
    Location location = Location::findByName(args[1]);
    if (!compare(location.getName(), "")) {
        Disease disease = Disease::findByName(args[2]);

        if (!compare(disease.getName(), "")) {
            Disease diseaseInLocation = Disease::findByDiseaseAndLocation(disease, location);
            if (!compare(diseaseInLocation.getName(), "")) {
                cout << "Cases of " << diseaseInLocation.getName() << " at " << location.getName() << " are " << diseaseInLocation.getCases() << endl;
            } else {
                cout << "Disease was not found in location" << endl;
            }
        } else {
            cout << "Disease was not found" << endl;
        }
    } else {
        cout << "Location was not found" << endl;
    }
}


void handleTotalCasesOfDiseaseCommand(string* args) {
    Disease disease = Disease::findByName(args[1]);
    if (!compare(disease.getName(), "")) {
        cout << "Total cases of '" << disease.getName() << "' = " << disease.getCases() << endl;
    } else {
        cout << "Disease was not found" << endl;
    }
}
