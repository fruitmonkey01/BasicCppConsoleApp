#ifndef Header_h
#define Header_h

#include <stdio.h>

using namespace std;

class SchoolClass {
private:
    std::string title;
    int id;
    std::map<int, std::string> classMap;

public:
    int loadClassMap(string comment, string fileName);
    void printClassByTitle(string comment, string title);
    void printClassByID(string comment, int id);
    void printAllClasses(string comment);
};

#endif /* Header_h */
