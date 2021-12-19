#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <locale>
#include <algorithm>
#include <vector>
#include "Header.h"

using namespace std;

// Function: Print the Standard C++ version
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
void SchoolClass::printClassByID(string comment, int id) {
    bool foundTitle = false;
    std::cout << comment << endl;
    
    if (__cplusplus >= 201703L) {
        // C++17 and above
        for (const auto& [key, value] : this->classMap) {
            if (key == id) {
                foundTitle = true;
                std::cout << "Class ID: " << key << ", Name: " << value << endl;
            }
        }
    } else {
        // For C++14, C++11, C++98
        for (auto iter = this->classMap.begin(); iter != this->classMap.end(); iter++) {
            if (iter->first == id) {
                foundTitle = true;
                std::cout << "Class ID: " << iter->first << ", Name: " << iter->second << endl;
            }
        }
    }
    if (! foundTitle) {
        std::cout << "Class not found!" << endl;
    }
    return;
}

// Function: print class information by the given class Title
void SchoolClass::printClassByTitle(string comment, string title) {
    string classTitleStr = toUpperCase(title);
    bool foundID = false;
    std::cout << comment << endl;
    
    if (__cplusplus >= 201703L) {
        // C++17 and above
        for (const auto& [key, value] : this->classMap) {
            if (value == classTitleStr) {
                foundID = true;
                std::cout << "Class ID: " << key << ", Name: " << value << endl;
            }
        }
    } else {
        // For C++14, C++11, C++98
        for (auto iter = this->classMap.begin(); iter != this->classMap.end(); iter++) {
            if (iter->second == title) {
                foundID = true;
                std::cout << "Class ID: " << iter->first << ", Name: " << iter->second << endl;
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
        for (const auto& [key, value] : this->classMap) {
            std::cout << "Class ID: " << key << ", Name: " << value << endl;
        }
    } else {
        // For C++14, C++11, C++98
        for (auto iter = this->classMap.begin(); iter != this->classMap.end(); iter++) {
            std::cout << "Class ID: " << iter->first << ", Name: " << iter->second << endl;
        }
    }
}

// Function: load class information from the local text file "ClassInfo.txt"
int SchoolClass::loadClassMap(string comment, string fileName) {
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
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        // skip empty data
        if (line.length() < 1) {
            continue;
        }
        // local variables for storing classID and classTitle strings
        vector<string> words;
        size_t pos = 0;
        while ((pos = line.find(space)) != string::npos) {
            // append the class id string
            words.push_back(line.substr(0, pos));
            // remove the class id string and keep class title part
            line.erase(0, pos + space.length());
            // append the class title string
            words.push_back(line);
        }
        // convert string to integer with std::stoi() API
        int classID = std::stoi(words.at(0));
        string classTitle = words.at(1);
        // insert the class info to the classMap structure
        if (__cplusplus >= 201103L) {
            // C++11 and above
            // this->classMap.insert({classID, classTitle});
            this->classMap.insert(std::pair<int, string>(classID, classTitle));
        } else {
            // C++98
            std::map<int, string>::iterator it = this->classMap.begin();
            this->classMap.insert(it, std::pair<int, string>(classID, classTitle));
        }
    }
    // close file
    mapFile.close();
    cout << "Class information loaded." << endl;
    return 0;
}

int main(int argc, const char * argv[]) {
    // Check Standard C++ version
    showStandardCppVersion();
    // Create School Class instance
    SchoolClass myClass;
    // Load class information to the classMap structure
    myClass.loadClassMap("[Read class information from local file]", "ClassInfo.txt");
    // Print all class information
    myClass.printAllClasses("[Find all classes]");
    // Search and print Class information by class title
    myClass.printClassByTitle("[Find class by title]", "C++");
    // Search and print Class information by class id
    myClass.printClassByID("[Find class by id]", 101);
    
    return 0;
}

