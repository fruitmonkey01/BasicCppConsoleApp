#ifndef Header_h
#define Header_h

#include <stdio.h>

using namespace std;

class compare {
public:
    bool operator()(const char *s, const char *t) const {
        return strcmp(s, t) < 0;
    }
    bool operator()(const int s, const int t) const {
        return (s - t) < 0;
    }
};

class SchoolClass {
private:
    std::string title;
    int id;
    
public:
    std::map<int, std::string, compare> classInfoMap;
    std::map<int, std::string, compare> teacherInfoMap;
    
    int readFile(string comment, string fileName);
    int saveOutput(string comment, string fileName);
    
    void getClassInfoByTitle(string comment, string title);
    void getClassInfoByID(string comment, int id);
    void printAllClasses(string comment);
    
    // use compare() operator
    void getClassInfoByID_useCompareOperator(string comment, int id);
};

#endif /* Header_h */
