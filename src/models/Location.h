#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class Location {
    private:
        int id;
        string name;
        int generateID() {
            return 1;
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
            cout << "saving" << endl;
        }
        void remove(string name) {

        }
};
