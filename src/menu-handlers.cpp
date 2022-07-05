#include <iostream>
#include <iomanip>
#include <ctime>
#include "files/file-operations.h"
#include "utils.cpp"
#include "models/Location.h"
#include "models/Disease.h"

using namespace std;

#define COLOR_RED "\033[1;31m"
#define COLOR_GRAY "\e[90m"
#define COLOR_RESET "\033[0m"


void printHeader() {
    cout << "=========================================================" << endl;
    cout << "*\tWelcome to Disease Cases Reporting System!\t*" << endl;
    cout << "*  ***************************************************  *" << endl;
    cout << "*\t\t\t\t\t\t\t*" << endl;
    cout << "* It is developed by 'Divin Irakiza' as practical\t*" << endl;
    cout << "* evaluation for the end of Year 3.\t\t\t*" << endl;
    cout << "=========================================================" << endl;
}



void handleHelpCommand() {
    cout << "===============================================================================" << endl;
    cout << "*\t\t\t\tH E L P   M E N U " << endl;
    cout << "===============================================================================" << endl;

    cout << "add <Location>" << setw(44) <<": Add a new location" << endl;
    cout << "delete <Location>"  << setw(50)  <<  ": Delete an existing location" << endl;
    cout << "record <Location> <disease> <cases>"  << setw(34)  <<  ": Record a disease and its case" << endl;
    cout << "list locations"  << setw(53)  <<  ": List all existing locations" << endl;
    cout << "list diseases"  << setw(62)   <<  ": List existing Diseases in locations" << endl;
    cout << "where <disease>"  << setw(50)  <<  ": Find where disease exists" << endl;
    cout << "case <Location><disease>"  << setw(51)  <<  ": Find cases of a disease in location" << endl;
    cout << "cases <disease>"  << setw(60)  <<  ": Find total cases of a given disease" << endl;
    cout << "help"  << setw(54)  <<  ": Prints user manual" << endl;
    cout << "Exit"  << setw(52) <<  ": Exit the program" << endl;
}

bool sortByLocations( Location & left,  Location & right) {
    return left.getId() < right.getId();
}

void handleExitCommand() {
    cout << "Closing the system" << endl;
    exit(0);
}

void handleAddLocationCommand(string* args) {
    Location location = Location(args[1]);
    location.save();
    cout << "Location " << location.getName() << " is succcessfully added!" << endl;
}

void handleDeleteLocationCommand(string* args) {
    Location location = Location::findByName(args[1]);
    if (compare(location.getName(), "")) {
        cout << COLOR_RED << "Location was not found" << COLOR_RESET << endl;
    } else {
        vector<int> districtIds = Disease::findByLocation(location);
        cout << districtIds.size() << endl;
        if (districtIds.size() > 0) {
            for (int i = 0; i < districtIds.size(); i++) {
                Disease disease = Disease::findByID(districtIds[i]);
                disease.remove();
            }
        }
        location.remove();
    }
}

void handleRecordDiseaseAndCasesCommand(string* args) {
     Location location = Location::findByName(args[1]);
    if (!compare(location.getName(), "")) {
        Disease disease = Disease(location.getId(), args[2], stoi(args[3]));
        disease.save();
    } else {
        cout << COLOR_RED << "Location doesn't exist" << COLOR_RESET << endl;
    }
}

void handleListLocationsCommand(string* args) {
    vector<Location> locations = Location::getAll();

    sort(locations.begin(), locations.end(), [] (Location &s1, Location &s2) {return s1.getName() < s2.getName(); });

    for (Location location : locations) {
        cout << location.getName() << endl;
    }
}



void handleListDiseasesCommand(string* args) {
    vector<Disease> diseases = Disease::getAll();

    sort(diseases.begin(), diseases.end(), [] (Disease &s1, Disease &s2) {return s1.getName() < s2.getName(); });

    for (Disease disease : diseases) {
        cout << disease.getName() << endl;
    }
}


void handleWhereDiseaseCommand(string* args) {
    Disease disease = Disease::findByName(args[1]);
    if (!compare(disease.getName(), "")) {
        for (int locationId: Disease::findLocationsByDisease(disease)) {
            cout << locationId << endl;
    
            Location location = Location::findByID(locationId);
            cout << "[" << toLower(location.getName()) << "]" << endl;
        }
    } else {
        cout << COLOR_RED << "Disease was not found" << COLOR_RESET << endl;
    }
}

void handleCasesOfDiseaseInLocationCommand(string* args) {
    Location location = Location::findByName(args[1]);
    if (!compare(location.getName(), "")) {
        Disease disease = Disease::findByName(args[2]);

        if (!compare(disease.getName(), "")) {
            Disease diseaseInLocation = Disease::findByDiseaseAndLocation(disease, location);
            if (!compare(diseaseInLocation.getName(), "")) {
                cout << "Cases of " << diseaseInLocation.getName() << " at " << location.getName() << " are: " << diseaseInLocation.getCases() << endl;
            } else {
                cout << COLOR_RED << "No location with this disease" <<  COLOR_RESET<< endl;
            }
        } else {
            cout << COLOR_RED << "Disease was not found" << COLOR_RESET << endl;
        }
    } else {
        cout << COLOR_RED << "Location was not found" << COLOR_RESET << endl;
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


