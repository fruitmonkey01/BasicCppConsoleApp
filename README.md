Project development environment:
Recommend: use Standard C++11 version and above.

Read and write file configuration for Xcode App running on Mac OS X:
Configure your project path for read file function.
1. Put your "ClassInfo.txt" files in the same directory (folder) as your "main.cpp" file.
2. Settings in the Xcode App for Max OS:
Go to Product > Scheme > Edit Scheme > Run > Options
Check “Use custom working directory” the directory to project folder, 
which constins main.cpp file and ClassInfo.txt file.

Project description:
1 Check Standard C++ version:
    Check the Standard C++ version is pre-standard or not.
2. Create School Class instance
    Load class information (id and title) from File ("ClassInfo.txt") with CSV format 
    to the class's map<int, string> structure
3. Print all class information
    Print all class information by iterating the map data structure.
4. Search and print Class information by class title
5.  Search and print Class information by class id

![alt ScreenImage](https://github.com/fruitmonkey01/BasicCppConsoleApp/blob/main/ScreenImage.png)

Sample output:
Standard C++ Version: C++14
[Read class information from local file]
Class information loaded.
[Find all classes]
Class ID: 101, Name: ENGLISH
Class ID: 102, Name: MATH
Class ID: 103, Name: HISTORY
Class ID: 104, Name: PYTHON
Class ID: 105, Name: JAVASCRIPT
Class ID: 106, Name: C++
Class ID: 107, Name: ROBLOX
Class ID: 108, Name: SWIFT
[Find class by title]
Class ID: 106, Name: C++
[Find class by id]
Class ID: 101, Name: ENGLISH
Program ended with exit code: 0
