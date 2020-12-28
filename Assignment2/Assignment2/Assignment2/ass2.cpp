/*********************************************************************************************************************************************************************************************************************
Student Name: Aria Gomes
Student Number: 040878659
Assignment: 2 - Extrapolation
Course: Numerical Computing - CST8233
Section: 302
Proffessor Name: Hala Own
Due Date: 11/20/2020
Submission Date: 11/16/2020
Files: ass2.cpp
**********************************************************************************************************************************************************************************************************************/


/*********************************************************************************************************************************************************************************************************************
Filename: Ass1.cpp
Version: 1.0
Author: Aria Gomes
Student Number: 040878659
Course Name: Numerical Computing - CST8233
Section:
Assignment: 2 - Extrapolation
Due Date: 11/20/2020
Submission Date: 11/16/2020
Professor Name: Hala Own
Purpose: Takes a file and parses through the data(assuming the file is formatted correctly). It then takes that data and extrapolates to a point in time not on the file.
/*********************************************************************************************************************************************************************************************************************/

#define COLOUMN_ONE 0 // Defines for Collomn spacing
#define COLOUMN_TWO 20
#define COLOUMN_THREE 30


#include <iostream>
#include <string>	//used for parsing string to int or double(error checking)
#include <fstream> // Used for splitting the files data
#include <vector> // ^
#include <sstream> // ^
#include <iomanip> // Used for setw


bool isNumberI(const std::string& input, bool type); // Method Declorations
void exponentialFit();
void readFile(std::string fileName);
void extrapolation();


double years[50]; // Member Varible decleration
double transistorCounts[50];
std::string names[50];
int dataAmt;
double eqA = 0, eqB = 0;


/**********************************************************************************************************************************************************************************************************************
Function Name: main()
Purpose: Holds the main menu loop and calls the Extraponential fit function or Quits the application
Function In Params: None
Function Out Params: 0 for succesful execution
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
int main()
{
	bool RUNNING = true; // Loop control variable
	std::string userOption;
	std::cout << "Aria's Assignemnt 2 - Moore's Law\n\n";

	while (RUNNING) // Main Menu
	{
		std::cout << "MENU\n" << "  1. Exponential Fit\n" << "  2. Quit\n" << "Choice: ";
		std::cin >> userOption;

		switch (userOption[0])  // Takes the first character the user enters
		{
		case '1':
			exponentialFit(); 
			break;
		case '2':
			RUNNING = false;
			break;
		default:
			std::cout << "Please enter a valid menu option\n\n";
			break;
		}
	} // End of Menu

	return 0; // Successful execution
}

/**********************************************************************************************************************************************************************************************************************
Function Name: exponentialFit()
Purpose: Prompts the user for a filename(adds the .txt extentsion automatically) and will check if the file exists or is not corrupt. if not, it passes the filename to the readFile() function
Function In Params: None
Function Out Params: void
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
void exponentialFit()
{
	bool RUNNING = true; // loop control variable
	std::string userOption;
	std::string fileName;

	std::cout << "Please enter the name of the file to open: "; // Prompt user for file name
	std::cin >> fileName;
	std::ifstream MyFile(fileName + ".txt"); // adds the txt extrnsion
	if (MyFile.fail() && !MyFile.is_open()) // checking the files existance (Error checking)
	{
		std::cout << "File is invalid/Corrupted or does not exist. Retrying...\n\n";
		exponentialFit(); // Restart the function
	}
	else
		readFile(fileName); // Pass the file name to ReadFile()

	while (RUNNING) // Second Menu loop
	{
		std::cout << "MENU\n" << "  1. Extrapolation\n" << "  2. Main Menu\n" << "Choice: ";
		std::cin >> userOption;

		switch (userOption[0]) // Takes the first character the user enters
		{
		case '1':
			extrapolation();
			break;
		case '2':
			return; // quit back to first menu
			break;
		default:
			std::cout << "Please enter a valid menu option\n\n";
			break;
		}
	} // End of Second Menu

}

/**********************************************************************************************************************************************************************************************************************
Function Name: readFile()
Purpose: Takes the filename from the previous method and
1. Prints the files contents
2. Stores the data of the file in respective variable arrays
Function In Params: std::string fileName
Function Out Params: void
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
void readFile(std::string fileName)
{

	int i , sc = 0; // Method variable decleration
	int arraytype = 0;
	double eq0, sumofyears = 0, sumoftransistors = 0, sumofyeartransistor = 0, sumofyearsquared = 0;
	std::string line;
	std::string word = "";
	std::ifstream MyFile(fileName + ".txt");

	for (i = 0; getline(MyFile, line); i++) // Start of reading file by lines;
	{
		std::string str = line;
		std::istringstream buf(str);
		std::istream_iterator<std::string> beg(buf), end;

		std::vector<std::string> tokens(beg, end); // Splits the data into  words

		for (auto& s : tokens) // Start of splitting lines to words
		{
		    if (sc < 3) // Lets the first 3 words print as they are the Titles for each row
			{
				switch (sc)
				{
					case 0:
						std::cout << std::setw(COLOUMN_ONE);
						break;
					case 1:
						std::cout << std::setw(COLOUMN_TWO);
						break;
					case 2:
						std::cout << std::setw(COLOUMN_THREE);
						break;
				}

				std::cout << s; 
				sc++;

				if (sc == 3) // prints a new line character every 3 words/columns
				{
					std::cout << "\n";
				}
			}
			
				if (arraytype == 0 && i > 0) // Adds all the appropiate values to data containing years from the file and stores them for later use
				{
					arraytype++;
					years[i] = std::stod(s);
					sumofyears += years[i];
					sumofyearsquared += pow(years[i], 2);
					std::cout << std::setw(COLOUMN_ONE) << years[i];
				}
				else if (arraytype == 1 && i > 0) // Adds all the appropiate values to data containing transistor Count from the file and stores them for later use
				{
					arraytype++;
					transistorCounts[i] = std::stod(s);
					sumoftransistors += log(transistorCounts[i]);
					sumofyeartransistor += (years[i] * log(transistorCounts[i]));
					std::cout << std::setw(COLOUMN_TWO) << transistorCounts[i];
				}
				else if (arraytype == 2 && i > 0) // Adds all the appropiate values to data containing name from the file and stores them for later use
				{
					arraytype = 0;
					names[i] = s;
					std::cout << std::setw(COLOUMN_THREE) << names[i] << "\n";
				}
		}
	} // End of reading file
	dataAmt = i - 1; // Gets the ammount of data points/lines (-1 for the titles row)

	eqB = ((dataAmt * sumofyeartransistor) - (sumofyears * sumoftransistors)) / (dataAmt * sumofyearsquared - (sumofyears * sumofyears)); // Liner regression Formula 1
	eq0 = sumoftransistors / dataAmt - eqB * (sumofyears - (1970.00 * dataAmt)) / dataAmt; // Liner regression 2 (relies on eqB)
    eqA = exp(eq0); // Liner regression Formula 3 (relies on eq0)

	std::cout << "\nNumber of Records: " << dataAmt << "\n";
	std::cout << "Linear Regression Fit: Transistor Count = " << std::scientific << std::setprecision(3) << eqA << " * exp ( " << eqB << " * (year - 1970))\n\n"; // Prints the Linear Regression fit formula used to extrapolate this data
}

/**********************************************************************************************************************************************************************************************************************
Function Name: extrapolation()
Purpose: Promts the user for a year to exroplate to outside of the data range and uses our formula from the previous method to calculate the ammount of transistors in that given year
Function In Params: None
Function Out Params: void
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
void extrapolation()
{
	std::string extrapYear; // Variable decleration
	double extrapYearAD;
	double growthRate, transistor;

	std::cout << "Enter the year to exprapolate to: "; // Get user input for year to extrapolate to
	std::cin >> extrapYear;
	if (isNumberI(extrapYear, true)) // Error checking user input
	{
		extrapYearAD = std::stod(extrapYear); // Parse valid data
		if (extrapYear.length() < 4 || extrapYearAD <= years[dataAmt]) // Checks if the ammount entered is inside the data set.
		{
			std::cout << "Please enter a valid year beyond the last year in the list. Restarting...\n\n";
			extrapolation(); // restarts the function
		}
		transistor = eqA * exp(eqB * (extrapYearAD - 1970.00)); // Calculate transitors
		growthRate = (eqA * eqB) * exp(eqB * (extrapYearAD - 1970.00)); // Calculate Growth rate
		std::cout << std::fixed << "\nYear = " << (int)extrapYearAD << "\n";
		std::cout << std::scientific << std::setprecision(3) <<"transistor count = " << transistor << "\n"; // Print Results
		std::cout << std::scientific << std::setprecision(3) << "rate of count increase = " << growthRate << "\n\n";
	}
	else
	{
		std::cout << "Please enter a valid year. Restarting...\n\n";
		extrapolation(); // Restarts the function
	}
}

/**********************************************************************************************************************************************************************************************************************
Function Name: isNumberI()
Purpose: Takes in 2 parameters, the userinput string and a boolean that represents if the value should be checked as an Integer or a Double. The function will return a boolean type to be used for conditional statements
Function In Params: const std::string& input, bool type
Function Out Params: true for Valid input, false for invalid input
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
bool isNumberI(const std::string& input, bool type)
{
	if (type) // Knows what to look for with the passed in variable
	{
		for (char c : input) // Integer Check
		{
			if (!isdigit(c))
				return false; // Means its invalid integer
		}

		return true; // Valid Integer
	}
	else
	{
		for (char c : input) // Double Check
		{
			if (!isdigit(c))
				if (!(c == '.'))
					return false; // invalid Double
		}

		return true; // Valid Double
	}
}