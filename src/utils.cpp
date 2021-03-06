#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cctype>
#include <cstring>  

using namespace std;

void getTime() {
    time_t curr_time;
	tm * curr_tm;
	char date_time_string[150];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_time_string, 50, "%a %b %d %H:%M:%S CAT %Y", curr_tm);

    cout << "Starting Time: " << date_time_string  << endl;
}


string toLower(string str) {
	for (int i = 0; i < str.length(); i++){
  		str[i] = tolower(str[i]);
  	}
  	return str;
}

string toUpper(string str) {
	for (int i = 0; i < str.length(); i++){
  		str[i] = toupper(str[i]);
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


bool startsWith(string str, string prefix) {
    str = toLower(str);
    prefix = toLower(prefix);
    return str.rfind(prefix, 0) == 0;
}

string* split(string str, char seperator)  
{  
    string *strings = new string[8];

    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= (str.length()))  
    {  
        if (str[i] == seperator || i == str.length())  
        {  
            endIndex = i;  
            string subStr = "";  
            subStr.append(str, startIndex, endIndex - startIndex);  
            strings[currIndex] = subStr;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
    }

    return strings;     
}  



int getStringArrayLen(string* strArr) {
    int i = 0;
    while (strArr[i] != "") {
        i++;
    }
    return i;
}

bool validateCommandInput(string* splits, string command) {
    if (command == "ADD") {
       return getStringArrayLen(splits) == 2;
    } else if (command == "DELETE") {
        return getStringArrayLen(splits) == 2;
    }  else if (command == "RECORD") {
        return getStringArrayLen(splits) == 4;
    } else if (command == "LIST") {
        return getStringArrayLen(splits) == 2;
    } else if (command == "WHERE") {
        return getStringArrayLen(splits) == 2;
    } else if (command == "CASES") {
        return getStringArrayLen(splits) == 2 || getStringArrayLen(splits) == 3;
    }
    else if (command == "HELP") {
        return getStringArrayLen(splits) == 1;
    } else if (command == "EXIT") {
        return getStringArrayLen(splits) == 1;
    } else {
        return false;
    }
}


