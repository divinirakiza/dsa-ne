#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "../files/file-operations.h"

using namespace std;

class Location {
    private:
        int id;
        const string FILENAME = "src/data/locations.txt";
        string name;
        int generateID() {
            return countRecords(this->FILENAME) + 1;
        }

    public:
        Location(){};
        
        Location(string name) {
            this->id = this->generateID();
            this->name = name;
        }

        int getId() { return this->id; }
        void setId(int id) { this->id = id; }
        string getName() { return this->name; }
        void setName(string name) { this->name = name; }

        void save() {
            ofstream fout(this->FILENAME, fstream::in | fstream::out | fstream::app);
            fout << "id:" << this->id << "|" << "name:" << this->name << "|" << endl;
        }
        void remove(string name) {

        }
};
