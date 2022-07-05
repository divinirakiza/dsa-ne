#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void getTime() {
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    cout << put_time(&tm, "%d-%m-%Y %H-%M-%S") << endl;
}