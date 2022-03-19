Project development environment:
<br />
Recommend: use Standard C++11 version and above.
<br />
Read and write file configuration for Xcode App running on Mac OS X:
<br />
Configure your project path for read file function.
<br />
1. Put your "ClassInfo.txt" files in the same directory (folder) as your "main.cpp" file.
<br />
2. Settings in the Xcode App for Max OS:
<br />
Go to Product > Scheme > Edit Scheme > Run > Options
<br />
Check “Use custom working directory” the directory to project folder, 
<br />
which constins main.cpp file and ClassInfo.txt file.
<br />

Project description:
<br />
1 Check Standard C++ version:
<br />
Check the Standard C++ version to see if it supports older version or not.
2. Create School Class instance
<br />
Load class information (id and title) from File ("ClassInfo.txt") with CSV format to the class's map<int, string> structure
<br />
3. Print all class information
<br />
Print all class information by iterating the map data structure.
<br />
4. Get Class information by class title
<br />
5. Get Class information by class id
<br />

![alt Example](https://github.com/fruitmonkey01/BasicCppConsoleApp/blob/main/Example.png)

