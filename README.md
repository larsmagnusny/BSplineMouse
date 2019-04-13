# BSplineMouse
A library for moving the mouse to a location on screen using a random or constructed Basis Spline Curve. For now this is Windows 32/64 bit only, but might be expanded to work on all platforms in the future.

# How do i use this libary in QT?
First of all just look at the release section of this repository, then extract the library to where-ever you would like the library to be.
In my case it is the path: "C:\BSplineMouse"
So just add the line "INCLUDEPATH += C:\\BSplineMouse\include"
And link the .dll file in "C:\BSplineMouse\bin\Win(32/64)\BSplineMouse.dll" like so:
Add the line "LIBS += "C:/BSplineMouse/Win64/BSplineMouse.dll"
Remember to also copy over the dll to the .exe path after compile.

# Compile Instructions
To compile this project, the simplest way is to install QT and open the .pro file, and finally build it. You should probably be able to create your own project in Visual Studio and include the files in this project to get it compiled that way.
