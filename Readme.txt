*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 2421           
*  HW#       :  3              
*  Due Date  :  Feb 8, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program is supposed to read a series of vehicles with year, make, and model into a vector, ask the user 
which parameter to search for and the value, sort the vector into that order, then run a binary recursive search
for the value entered.  Then, the program runs a binary iterative search for the same value and should return
the same vehicle.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This creates the class instance recBin and opens a file to read into it then imports the data
from the file.  The user is then asked if they want to search for a vehicle's year, make or model, then asks what
year, make or model they would like to search for.  The vehicle data are sorted and then the vehicle is found
using a recursive binary search and an iterative binary search.  


Name:  Recursion.h
	Contains the class definition for Class Recursion.

Name: Recursion.cpp
	Contains member functions recursive binary search, iterative binary search, selection sort, vector size,
and display vector.

   
*******************************************************
*  Circumstances of programs
*******************************************************
The program is complete and compiles and runs on visual studio community and csegrid.



Developed on Visual Studio Community 2015 14.0.25431.01 Update 3.



*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WongHW2]

   Now you should see a directory named homework with the files:
        main.cpp
	Recursion.h
	Recursion.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WongHW3] 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw3

4. Delete the obj files, executables, and core dump by
   %./make clean
