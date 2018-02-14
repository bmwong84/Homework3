//Bryant Wong
//CSCI 2421 Homework 3

#include "Recursion.h"
#include <iostream>


int main()
{
	std::ifstream infile("vehiclein.txt");		//opens file to read to infile
	Recursion recBin;							//creates class recBin of type Recursion	
	recBin.readFromFile(infile);				//calls member function readFromFile passing infile for vehiclein.txt
	//int number =recBin.getListSize();		//test line
	//std::cout << number << std::endl;		//test line
	char menuchoice = '6';		
	while (menuchoice != '4')		//menu
	{
		std::cout << "Menu: Search by...:" << std::endl;
		std::cout << "1: Year" << std::endl;
		std::cout << "2: Make" << std::endl;
		std::cout << "3: Model" << std::endl;
		std::cout << "4: Exit" << std::endl;
		std::cin >> menuchoice;
		std::string year;
		std::string make;
		std::string model;
		int first = 0;			//first element in binary searches will be 0 for first recursion for all searches
		switch (menuchoice)
		{
		case '1':
			recBin.sortBy(0);		//calls member function to sort the vehicleList vector by parameter 0 (year)
			/*std::cout << "List sorted into " << std::endl;
			recBin.printList();*/
			std::cout << "Enter year to search for" << std::endl;
			std::getline(std::cin >> std::ws, year);												//asks user for the year to search for
			
			if (recBin.binarySearchRec(0, first, recBin.getListSize()-1, year) <0 )	//fault tolerance, if binary search returns index -1, the vehicle is not found
			{
				std::cout << "No vehicle found." << std::endl;
				break;
			}
			else
			{
				std::cout << "Recursive search found vehicle: " << std::endl;							
				recBin.displayFound(recBin.binarySearchRec(0, first, recBin.getListSize()-1, year));	//calls member function to display the found value from binary recursive search
				std::cout << std::endl;
			}
			
			if (recBin.binarySearchIter(0,first,recBin.getListSize()-1,year)<0)					//fault tolerance, if iterative binary search returns index -1, the vehicle is not found
			{
				std::cout << "No vehicle found." << std::endl;
				break;
			}
			else
			{
				std::cout << "Iterative search found vehicle: " << std::endl;
				//int check = ((recBin.binarySearchIter(0, first, recBin.getListSize(), year)));
				//std::cout << check;
				recBin.displayFound(recBin.binarySearchIter(0, first, recBin.getListSize()-1, year));		//calls member function to display the found value from binary iterative search
				std::cout << std::endl;
			}
			break;
		case '2':																		
			recBin.sortBy(1);													//calls member function to sort vector vehicleList by parameter 1 (make)
			std::cout << "Enter Make to search for" << std::endl;
			std::getline(std::cin>>std::ws, make);
			if (recBin.binarySearchRec(1, first, recBin.getListSize()-1, make) <0)
			{
				std::cout << "No vehicle found." << std::endl;
				break;
			}
			else
			{
				std::cout << "Recursive search found vehicle: " << std::endl;
				recBin.displayFound(recBin.binarySearchRec(1, first, recBin.getListSize()-1, make));
				std::cout << std::endl;
			}
			if (recBin.binarySearchIter(1, first, recBin.getListSize()-1, make) <0)
			{
				std::cout << "No vehicle found." << std::endl;
				break;
			}
			else
			{
				std::cout << "Iterative search found vehicle: " << std::endl;
				recBin.displayFound(recBin.binarySearchIter(1, first, recBin.getListSize()-1, make));
				std::cout << std::endl;
			}
			break;
		case '3':
			recBin.sortBy(2);							//calls member function to sort vector vehicleList by parameter 2 (model)
			std::cout << "Enter Model to search for" << std::endl;
			std::getline(std::cin>>std::ws, model);
			if (recBin.binarySearchRec(2, first, recBin.getListSize()-1, model) < 0)
			{
				std::cout << "No vehicle found." << std::endl;
				break;
			}
			else
			{
				std::cout << "Recursive search found vehicle: " << std::endl;
				recBin.displayFound(recBin.binarySearchRec(2, first, recBin.getListSize()-1, model));
				std::cout << std::endl;
			}
			if (recBin.binarySearchIter(2, first, recBin.getListSize()-1, model) <0)
			{
				std::cout << "No vehicle found." << std::endl;
				break;
			}
			else
			{
				std::cout << "Iterative search found vehicle: " << std::endl;
				recBin.displayFound(recBin.binarySearchIter(2, first, recBin.getListSize()-1, model));
				std::cout << std::endl;
			}
			break;
		case '4':
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
	std::cin.get();
	return 0;
	
}