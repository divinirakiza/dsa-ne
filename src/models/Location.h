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
            return countRecords(Location::FILENAME) + 1;
        }
        string extractor(string line, string prop) {
            size_t found = line.find(prop);

            string value;
            if (found != string::npos)
            {
                string substring = line.substr((found + prop.length()));
                unsigned first = substring.find(":");
                unsigned last = substring.find("|");
                value = substring.substr(first + 1, (last - first) - 1);
            }
            return value;
        }

        int findPositionByName(string value) {
            ifstream inFile(Location::FILENAME);
            string line;
            value = toUpper(value);
            int i =  0;
            while (inFile >> line) {
                string name = this->extractor(line, "name");
                if (compare(name, value)) {
                    break;
                }
                i++;
            }
            return i;
        }

    public:
        static const string FILENAME;

        Location(){};
        
        Location(string name) {
            this->id = this->generateID();
            this->name = toUpper(name);
        }
        Location (string line, int readFile) {
            this->id = stoi(this->extractor(line, "id"));
            this->name = this->extractor(line, "name");
        }
        
        void save() {
            ofstream outFile(Location::FILENAME, ios::app);
            outFile << "id:" << this->id << "|" << "name:" << this->name << "|" <<  endl;
            outFile.close();
        }

        int getId() { return this->id; }
        void setId(int id) { this->id = id; }
        string getName() { return toUpper(this->name); }
        void setName(string name) { this->name = name; }

        static vector<Location> getAll() {
            vector<Location> locations;
            ifstream inFile(Location::FILENAME);
            string line;
            while (inFile >> line) {
                Location location = Location(line, 1);
                locations.push_back(location);
            }
            return locations;
        }
   

        static Location findByID(int value) {
            ifstream inFile(Location::FILENAME);
            Location location;
            string line;
            Location _static_location;
            while (inFile >> line) {
                int id = stoi(_static_location.extractor(line, "id"));
                if (value == id) {
                    location = Location(line, 1);
                }
            }

            return location;
        }

        static Location findByName(string value) {
            ifstream inFile(Location::FILENAME);
            Location location;
            string line;
            value = toUpper(value);


            Location _static_location;
            while (inFile >> line) {
                string name = _static_location.extractor(line, "name");
                if (compare(name, value)) {
                    location.setId(stoi(_static_location.extractor(line, "id")));
                    location.setName(_static_location.extractor(line, "name"));
                }
            }

            return location;
        }

        void remove() {
            int line = findPositionByName(this->name);
   
            vector<Location> locations = Location::getAll();

            ofstream outFile(Location::FILENAME);

            for (int i = 0; i < locations.size(); i++) {
                if (i != line) {
                    outFile << "id:" << locations[i].getId() << "|" << "name:" << locations[i].getName() << "|" <<  endl;
                }
            }
        }


        
};

const string Location::FILENAME = "src/data/locations.txt";