#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <locale>
#include <algorithm>
#include <vector>

#include "Header.h"

using namespace std;

string classInfoFile = "ClassInfo.txt";
string savedOutputFile = "Output.txt";

// Function: Check the supported C++ version
void showStandardCppVersion() {
    std::cout << "Standard C++ Version: ";
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else {
        std::cout << "pre-standard C++\n";
        std::cout << "(Exit reason: This program requires at least Standard C++98 with STL C++11 support and above.) " << endl;
        // exit program
        exit(0);
    }
    return;
}

// Function: Convert string to uppper case
std::string toUpperCase(string str) {
    string upperCaseStr = "";
    std::locale loc;
    for (std::string::size_type i = 0; i < str.length(); ++i) {
        char c = std::toupper(str[i], loc);
        upperCaseStr.append(string(1,c));
    }
    return upperCaseStr;
}

// Function: print class information by the given class ID
void SchoolClass::getClassInfoByID(string comment, int id) {
    bool foundTitle = false;
    std::cout << comment << endl;
    
    if (__cplusplus >= 201703L) {
        // C++17 and above
        for (const auto& [key, value] : this->classInfoMap) {
            if (key == id) {
                foundTitle = true;
                // string res = "Class ID: " + to_string(key) + ", Name: " + string(value);
                string res = "Class ID: " + to_string(key) + ", Name: " + string(value) + " tought by " + this->teacherInfoMap[key];
                std::cout << res << endl;
                // Save to output file
                this->saveOutput(res, savedOutputFile);
            }
        }
    } else {
        // For C++14, C++11, C++98
        for (auto iter = this->classInfoMap.begin(); iter != this->classInfoMap.end(); iter++) {
            if (iter->first == id) {
                foundTitle = true;
                // string res = "Class ID: " + to_string(iter->first) + ", Name: " + iter->second;
                string res = "Class ID: " + to_string(iter->first) + ", Name: " + iter->second + " tought by " + this->teacherInfoMap[iter->first];
                std::cout << res << endl;
                // Save to output file
                this->saveOutput(res, savedOutputFile);
            }
        }
    }
    if (! foundTitle) {
        std::cout << "Class not found!" << endl;
    }
    return;
}

// Function: print class information by the given class Title
void SchoolClass::getClassInfoByTitle(string comment, string title) {
    string classTitleStr = toUpperCase(title);
    bool foundID = false;
    std::cout << comment << endl;
    
    if (__cplusplus >= 201703L) {
        // C++17 and above
        for (const auto& [key, value] : this->classInfoMap) {
            if (value == classTitleStr) {
                foundID = true;
                string res = "Class ID: " + to_string(key) + ", Name: " + string(value) + " tought by " + this->teacherInfoMap[key];
                std::cout << res << endl;
                // Save to output file
                this->saveOutput(res, savedOutputFile);
            }
        }
    } else {
        // For C++14, C++11, C++98
        for (auto iter = this->classInfoMap.begin(); iter != this->classInfoMap.end(); iter++) {
            if (iter->second == title) {
                foundID = true;
                string res = "Class ID: " + to_string(iter->first) + ", Name: " + iter->second + " tought by " + this->teacherInfoMap[iter->first];
                std::cout << res << endl;
                // Save to output file
                this->saveOutput(res, savedOutputFile);
                
            }
        }
    }
    
    if (! foundID) {
        std::cout << "Class not found!" << endl;
    }
    return;
}

// Function: print all class information
void SchoolClass::printAllClasses(string comment) {
    std::cout << comment << endl;
    if (__cplusplus >= 201703L) {
        // C++17 and above
        for (const auto& [key, value] : this->classInfoMap) {
            std::cout << "Class ID: " << key << ", Name: " << value << " tought by " << this->teacherInfoMap[key] << endl;
        }
    } else {
        // For C++14, C++11, C++98
        for (auto iter = this->classInfoMap.begin(); iter != this->classInfoMap.end(); iter++) {
            std::cout << "Class ID: " << iter->first << ", Name: " << iter->second << " tought by " << this->teacherInfoMap[iter->first] << endl;
        }
    }
    std::cout << "There are " << this->classInfoMap.size() << " classes tought by " << this->teacherInfoMap.size() << " teachers." << endl;
}

// Function: load class information from the local text file "Output.txt"
int SchoolClass::saveOutput(string comment, string fileName) {
    
    // append to the end of file
    ofstream saveResults(fileName, ios::app);
    
    if (! saveResults) {
        cout << "Error saving file." << endl;
        return -1;
    }
    
    saveResults << comment << endl;
    saveResults.close();
    
    return 0;
}

// Function: read class information from the local text file "ClassInfo.txt"
int SchoolClass::readFile(string comment, string fileName) {
    string line;
    ifstream mapFile(fileName);
    string space = " ";
        
    std::cout << comment << endl;
    // check file's availability
    if (! mapFile) {
        cout << "File " << fileName << " unable to open!" << endl;
        return -1;
    }
    // read file
    while (! mapFile.eof()) {
        getline(mapFile, line, ',');
        // clean non-character line endings
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\f'), line.end());
        
        // skip empty data
        if (line.length() < 1) {
            continue;
        }
        // local variables for storing classID and classTitle strings
        vector<string> words;
        size_t pos = 0;

        while ((pos = line.find(space)) != string::npos) {
            // append the class id string then title next loop
            words.push_back(line.substr(0, pos));
            // remove the class id string and keep class title part
            line.erase(0, pos + space.length());
        }
        // append the teacher name string
        words.push_back(line);

        // convert string to integer with std::stoi() API
        if (words.size() > 2) {
            int classID = std::stoi(words.at(0));
            string classTitle = words.at(1);
            string teacherName = words.at(2);
            // cout << "Teacher Name is " << teacherName << endl;
        
            // insert the class info to the classInfoMap structure
            if (__cplusplus >= 201103L) {
                // C++11 and above
                this->classInfoMap.insert(std::pair<int, string>(classID, classTitle));
                this->teacherInfoMap.insert(std::pair<int, string>(classID, teacherName));
            } else {
                // C++98
                std::map<int, string>::iterator it = this->classInfoMap.begin();
                this->classInfoMap.insert(it, std::pair<int, string>(classID, classTitle));
                this->teacherInfoMap.insert(it, std::pair<int, string>(classID, teacherName));
            }
        } else {
            cout << "skip invalid word." << endl;
        }
    }
    // close file
    mapFile.close();
    std::cout << "There are " << this->classInfoMap.size() << " classes tought by " << this->teacherInfoMap.size() << " teachers." << endl;
    
    return 0;
}

// Function: print class information by the given class ID
void SchoolClass::getClassInfoByID_useCompareOperator(string comment, int id) {
    std::cout << comment << endl;
    if (this->classInfoMap.find(id) != this->classInfoMap.end()) {
        cout << "Found class ID: " << id << " class name is " << this->classInfoMap[id] << " tought by " << this->teacherInfoMap[id] << endl;
    } else {
        cout << "Not found." << endl;
    }
}

int main(int argc, const char * argv[]) {

    // Check Standard C++ version
    showStandardCppVersion();
    // Create School Class instance
    SchoolClass myClass;
    // Load class information to the classInfoMap structure
    myClass.readFile("[Read class information from file ClassInfo.txt]", classInfoFile);
    // Print all class information
    myClass.printAllClasses("[Print all classes]");
    // Search and print Class information by class title
    myClass.getClassInfoByTitle("[Get class info by title]", "C++");
    // Find class by ID use compare operator
    myClass.getClassInfoByID_useCompareOperator("[Get class info by id use compare() operator]", 102);
    // Search and print Class information by class id
    myClass.getClassInfoByID("[Get class info by id]", 101);

    return 0;
}

