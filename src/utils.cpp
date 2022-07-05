#include <iostream>
#include <iomanip>
#include <ctime>

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

void getTime() {
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    cout << put_time(&tm, "%d-%m-%Y %H-%M-%S") << endl;
}

void printMenu() {
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



bool compare(string s1, string s2) {
    int comparison = s1.compare(s2);
 
    if (comparison != 0)
        return false;
    return true;    
}