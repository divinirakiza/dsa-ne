#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

void getTime() {
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    cout << put_time(&tm, "%d-%m-%Y %H-%M-%S") << endl;
}


string toLower(string str) {
	for (int i = 0; i < str.length(); i++){
  		str[i] = tolower(str[i]);
  	}
  	return str;
}

bool compare(string str1, string str2) {
    str1 = toLower(str1);
    str2 = toLower(str2);
    int comparison = str1.compare(str2);
    if (comparison != 0)
        return false;
    return true;    
}
