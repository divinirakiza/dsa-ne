#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>



using namespace std;

class Disease {
    private:
        int id;
        string name;
        int cases;
        int locationId;

        int generateID() {
            return countRecords(Disease::FILENAME) + 1;
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
            ifstream inFile(Disease::FILENAME);
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

        Disease(){};
        
        Disease(int locationId, string name, int cases) {
            this->id = this->generateID();
            this->locationId = locationId;
            this->name = name;
            this->cases = cases;
        }
        Disease (string line, int readFile) {
            this->id = stoi(this->extractor(line, "id"));
            this->name = this->extractor(line, "name");
        }
        
        void save() {
            ofstream outFile(Disease::FILENAME, ios::app);
            outFile << "id:" << this->id << "|" << "locationId:" << this->locationId << "|" << "name:" << this->name << "|" << "cases:" << this-> cases << endl;
            outFile.close();
        }

        int getId() { return this->id; }
        void setId(int id) { this->id = id; }
        string getName() { return this->name; }
        void setName(string name) { this->name = name; }

        static vector<Disease> getAll() {
            vector<Disease> diseases;
            ifstream inFile(Disease::FILENAME);
            string line;
            while (inFile >> line) {
                Disease disease = Disease(line, 1);
                diseases.push_back(disease);
            }
            return diseases;
        }
   

        static Disease findByName(string value) {
            ifstream inFile(Disease::FILENAME);
            Disease disease;
            string line;
            value = toUpper(value);

            Disease _static_disease;
            while (inFile >> line) {
                string name = _static_disease.extractor(line, "name");
                if (compare(name, value)) {
                    disease.setId(stoi(_static_disease.extractor(line, "id")));
                    disease.setName(_static_disease.extractor(line, "name"));
                }
            }

            return disease;
        }

        static vector<int> findLocationsByDisease(Disease disease) {
            ifstream inFile(Disease::FILENAME);

            vector<int> locationIds;
            string line;

            Disease _static_disease;
            while (inFile >> line) {
                int locationId = stoi(_static_disease.extractor(line, "locationId"));
                locationIds.push_back(locationId);
            }

            return locationIds;
        }

        void remove() {
            int line = findPositionByName(this->name);
            cout << "On line " << line << endl;

            ofstream outFile(Disease::FILENAME);
            vector<Disease> diseases = Disease::getAll();
            for (int i = 0; i < diseases.size(); i++) {
                if (i != line) {
                    outFile << "id:" << diseases[i].getId() << "|" << "name:" << diseases[i].getName() << "|" <<  endl;
                }
            }
        }


        
};

const string Disease::FILENAME = "src/data/diseases.txt";