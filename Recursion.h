//Bryant Wong
//CSCI 2421 Homework 3


#ifndef RECURSIVE_
#define RECURSIVE_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>


class Recursion
{
private:
	std::ifstream infile;
	static const int param = 3;
	std::vector<std::vector <std::string>> vehicleList; //vector of vectors of strings named VehicleList

	public:
	Recursion();	//for class Recursion
	void readFromFile(std::ifstream& file);		//member function declaration to read and import information from text file to vector vehicleList
	int getListSize();					//member function declaration finding the size of the vector vehicleList
	void sortBy(int menuchoice);		//member function declaration to selection sort by user input
	void displayFound(int);				//member fucntion declaration for displaying the vehicle with element number being passed 
	void printList();
	int binarySearchRec(int menuchoice, int first, int last, std::string target);	//member function declaration for recursive binary search
	int binarySearchIter(int menuchoice, int first, int last, std::string target);	//member function declaration for iterative binary search
	
};

#endif