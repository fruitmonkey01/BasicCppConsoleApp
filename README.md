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
4. Get Class information by class title
5. Get Class information by class id

![alt Example](https://github.com/fruitmonkey01/BasicCppConsoleApp/blob/main/Example.png)

Sample output:
Standard C++ Version: C++14
[Read class information from file ClassInfo.txt]
There are 8 classes tought by 8 teachers.
[Print all classes]
Class ID: 101, Name: ENGLISH tought by ADAM
Class ID: 102, Name: MATH tought by CINDY
Class ID: 103, Name: HISTORY tought by ERIC
Class ID: 104, Name: PYTHON tought by GEORGE
Class ID: 105, Name: JAVASCRIPT tought by IVY
Class ID: 106, Name: C++ tought by JACK
Class ID: 107, Name: ROBLOX tought by MARY
Class ID: 108, Name: SWIFT tought by ROY
There are 8 classes tought by 8 teachers.
[Get class info by title]
Class ID: 106, Name: C++ tought by JACK
[Get class info by id use compare() operator]
Found class ID: 102 class name is MATH tought by CINDY
[Get class info by id]
Class ID: 101, Name: ENGLISH tought by ADAM


Program ended with exit code: 0
