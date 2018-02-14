//Bryant Wong
//CSCI 2421 Homework 3

#include "Recursion.h"

//default constructor, sets all private member functions to blank by default
Recursion::Recursion()
{
}		//end default constructor


void Recursion::readFromFile(std::ifstream& file)
{
	std::string Make, Model, Year, Delineation;
	std::vector<std::string> vehicle;
	int count = 0;
	while (std::getline(file >> std::ws, Year))		//while there is input from the file, place first into string Make
	{
		std::getline(file >> std::ws, Make);	//add next line to Model
		std::getline(file >> std::ws, Model);	//add next line to Year
		std::getline(file >> std::ws, Delineation);		//add the line
		vehicle.push_back(Year);		//adds make to vector vehicle
		vehicle.push_back(Make);	//adds model to vector vehicle
		vehicle.push_back(Model);	//adds year to vector vehicle
		//vehicle.push_back(Delineation);	//adds the line to vector vehicle
		vehicleList.push_back (vehicle);	//adds the vehicle to the vehicleList
		count++;
		vehicle.clear();	//erases the contents of vehicle so the next vehicle can be added
	}
	
	std::cout << "Vehicles added: " << std::endl;		//prints a list of the vehicles added
	for (int list = 0; list< count; list++)
	{
		for (int num = 0; num < param; num++)
		{
			std::cout << vehicleList[list][num] << std::endl;
		}
	}
	
}	

void Recursion::printList()		//prints out the list of vehicles
{
	for (int list = 0; list< vehicleList.size(); list++)
	{
		for (int num = 0; num < param; num++)
		{
			std::cout << vehicleList[list][num] << std::endl;
		}
	}
}

int Recursion::getListSize()	//gets the size of the vector vehicleList
{
	return vehicleList.size();
}


//selection sort, passed the parameter of the vehicle to search for
void Recursion::sortBy(int menuchoice)
{
	int startScan, minIndex;
	std::vector<std::vector <std::string>> minValue;		//creates a temporary vector named minValue
	
	for (startScan = 0; startScan < (vehicleList.size()-2); startScan++)	//for loop going from the first element to the second-to-last element
	{
		minIndex = startScan;		//minimum index number = whatever element is being checked
		minValue = vehicleList;		//sets the temporary vector element value to the element value being searched
		for (int index = startScan + 1; index < (vehicleList.size()-1); index++)	//for loop going from the 2nd element to the last element in the vector
		{
			if (vehicleList[index][menuchoice] < minValue[minIndex][menuchoice])		//if the next value is less than the current value being checked...
			{
				for (int num = 0; num < param; num++)
				{
					minValue[minIndex][num] = vehicleList[index][num];		//set the temp vector element value to the value checked.
				}
				minIndex = index;		//set the minimum index to the current index number
			}
		}
		for (int num = 0; num < param; num++)		//for each vehicle parameter in the vector
		{
			vehicleList[minIndex][num] = vehicleList[startScan][num];		//set the larger vehicleList element value equal to the smaller value
			vehicleList[startScan][num] = minValue[minIndex][num];				//set the smaller vehicleList element value equal to the larger value i.e. switch the values
		}
	}

}


//display the vehicle that was found, passed the index number of the vehicle that was found
void Recursion::displayFound(int index)
{
	for (int display = 0; display < param; display++)
		std::cout << vehicleList[index][display] << " ";
}

//from Carrano & Henry Data Abstraction & Problem Solving Walls and Mirrors 7th ed.  
//modified to use vector of vehicles 
//recursive binary search
int Recursion::binarySearchRec(int choice, int first, int last, std::string target)		//binary search passed the vehicle parameter to search for, the first element index, the last element index, and the target
{
	int index = 0;		
	if (first > last)		//if there is nothing to search for, return -1
		index = -1;
	else
	{
		int mid = first + ((last - first) / 2);		//set the midpoint to the middle of the first + (size of vector)/2
		if (target == vehicleList[mid][choice])		//if the target is the middle element
			index = mid;							//index is middle 
		else if (target < vehicleList[mid][choice])		//if the target is less than the middle element
			index = binarySearchRec(choice, first, mid - 1, target);		//function recurs with last element being the middle element - 1 and no other changes	(searches front half)
		else														//if target is less than the middle element	
			index = binarySearchRec(choice, mid + 1, last, target);		//function recurs with last element being the middle element +1 and no other changes.  (searches back half)
	}
	return index;			//returns the index number of the target
	
}


//recursive/loop binary search member function
int Recursion::binarySearchIter(int choice, int first, int last, std::string target)
{
	last = last - 1;
	int mid;
	int index = -1;
	bool found = false;
	while (!found && first <= last)
	{
		mid = (first + last) / 2;	//find the midpoint of the vector vehicleList
		if (vehicleList[mid][choice] == target)
		{
			found = true;		//if the middle element is the target, found is true
			index = mid;			//and position is set to middle
		}
		else if (vehicleList[mid][choice] > target)
			last = mid - 1;		//if the read value is greater than the target, the last element becomes the middle element -1
		else
			first = mid + 1;	//if the read value is less than the target, the first element becomes the middle + 1
			
	}


	return index;
}

