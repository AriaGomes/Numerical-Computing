/*********************************************************************************************************************************************************************************************************************
Student Name: Aria Gomes
Student Number: 040878659
Assignment: 1 - McLaurin Application
Course: Numerical Computing - CST8233
Section: 
Proffessor Name: Hala Own
Due Date: 10/9/2020
Submission Date: 10/9/2020
Files: Ass1.cpp
**********************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************************************************
Filename: Ass1.cpp
Version: 1.0
Author: Aria Gomes
Student Number: 040878659
Course Name: Numerical Computing - CST8233
Section: 
Assignment: 1 - McLaurin Application
Due Date: 10/9/2020
Submission Date: 10/9/2020
Professor Name: Hala Own
Purpose: Takes user input and calculates the McLaurin Series using the values the user entered in with the power series formula. Outputs The Term number, Aproximation, Exact, Relative Error and Absoulter Error.
/*********************************************************************************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define FIRST_ROW 7 //Defines made for each row spacing
#define SECOND_ROW 20
#define THIRD_ROW 25
#define FOURTH_ROW 25

void evaluateSeries();
bool isNumberI(const std::string& input, bool type);

/**********************************************************************************************************************************************************************************************************************
Function Name: main()
Purpose: Holds the main menu loop and calls the McLaurin Series Function or Quits the application
Function In Params: None
Function Out Params: 0 for succesful execution
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
int main()
{
	bool RUNNING = true; // Loop Control Variable

	std::cout << "Aria's Assignment 1" << std::endl << std::endl;

	while (RUNNING) // Main menu loop
	{
		std::string userChoice;
		std::cout << "1: Evaluate the series" << std::endl;
		std::cout << "2: Quit" << std::endl;
		std::cin >> userChoice;

		switch (userChoice[0]) // takes the first char from the user input
		{
		case '1':
			evaluateSeries();
			break;
		case '2':
			RUNNING = false;
			break;
		default:
			std::cout << "Invalid input try again" << std::endl << std::endl;
		}
	}
	return 0;
}

/**********************************************************************************************************************************************************************************************************************
Function Name: evaluateSeries()
Purpose: Evaluates several values including the: number of terms, numerical & Exact series of B, Absoulte, Relative & Truncation error. It will calculate up to 10 terms 
Function In Params: None
Function Out Params: Void
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
void evaluateSeries()
{
	// Variable Declaration & Initialization
	std::string nonZeroTerms;
	int nonZeroTermsAI;
	std::string bRange;
	double bRangeAD = {};
	double calcB{};
	double calcBCurrent = 0.0;
	double VBSeriesExact = 1.0;
	double VBSeriesApprox = 1.0;
	double AbsoluteError = 0.0;
	double relativeError = 0.0;
	double trunc = 0.0;
	double truncationError = 0.0;

	std::cout << "Evaluating the series" << std::endl;
	std::cout << "Enter the number of (non-zero) terms in the series (1, 2, 3, 4, 5, 6): ";
	std::cin >> nonZeroTerms; // User Input for non zero terms with error checking
	if (isNumberI(nonZeroTerms, true)) // Checks if the user inputed a valid integer
	{
		nonZeroTermsAI = std::stoi(nonZeroTerms);

		if (nonZeroTermsAI < 1 || nonZeroTermsAI > 6)
		{
			std::cout << "Please enter a integer between 1-6, Restarting the evaluation of the series\n\n";
			evaluateSeries(); // Restart method
		}
	}
	else
	{
		std::cout << "Please enter a valid integer, Restarting the evaluation of the series\n\n";
		evaluateSeries(); // Restart method
	}
	std::cout << "Please enter the range of B to evaluate in 10 increments (0.0 < B <= 0.9): ";
	std::cin >> bRange; // User input for b's range with error checking
	if (isNumberI(bRange, false)) // Checks if the user inputed a valid double
	{
		bRangeAD = std::stod(bRange);
		calcB = bRangeAD / 10.0; // Get the increment value of the user input

		if (bRangeAD < 0.0 || bRangeAD > 0.9)
		{
			std::cout << "Please enter a double between 0.0-0.9, Restarting the evaluation of the series\n\n";
			evaluateSeries(); // Restart method
		}
	}
	else
	{
		std::cout << "Please enter a valid double, Restarting the evaluation of the series\n\n";
		evaluateSeries(); // Restart method
	}
	std::cout << "\n\nMACLAURIN SERIES\n"; //Print the begging of the McLaurin series table with formatting
	std::cout << std::setw(FIRST_ROW) << "B" << std::setw(SECOND_ROW) << "V(B) Series" << std::setw(THIRD_ROW) << "V(B) Exact" << std::setw(FOURTH_ROW) << "Relative Error" << std::setw(FOURTH_ROW) << "%RSerE" << std::endl;
	for (int i = 0; i < 11; i++) // Loops for 10 terms as asked for in the spec 
	{
		switch (nonZeroTerms.at(0)) // Calculates B series approximation
		{
			//Power series based on user input for non zero terms
		case '1':
			VBSeriesApprox = 1;
			trunc = 1 + (calcBCurrent * calcBCurrent) / 2.0;
			break;
		case '2':
			VBSeriesApprox = 1 + (calcBCurrent * calcBCurrent) / 2.0;
			trunc = (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 3.0 / 8.0;
			break;
		case '3':
			VBSeriesApprox = 1 + (calcBCurrent * calcBCurrent) / 2.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 3.0 / 8.0 ;
			trunc = (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 5.0 / 16.0;
			break;
		case '4':
			VBSeriesApprox = 1 + (calcBCurrent * calcBCurrent) / 2.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent)* 3.0 / 8.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 5.0 / 16.0;
			trunc =  (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 35.0 / 128.0;
			break;
		case '5':
			VBSeriesApprox = 1 + (calcBCurrent * calcBCurrent) / 2.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 3.0 / 8.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 5.0 / 16.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 35.0 / 128.0;
			trunc =  (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 63.0 / 256.0;
			break;
		case '6':
			VBSeriesApprox = 1 + (calcBCurrent * calcBCurrent) / 2.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 3.0 / 8.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 5.0 / 16.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 35.0 / 128.0 + ((calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) / 8.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 5.0 / 16.0 + (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 63.0 / 256.0);
			trunc = (calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent * calcBCurrent) * 231.0 / 1024.0;
			break;
		default:
			std::cout << "\n \n\t\tSomething went wrong\n \n";
		}
			// Exact Series Calculation + Absolute, Relative & Truncation error calculation
			VBSeriesExact = 1.0 / sqrt(1.0 - pow(calcBCurrent, 2));
			AbsoluteError = abs(VBSeriesExact - VBSeriesApprox);
			relativeError = abs(AbsoluteError / VBSeriesExact);
			truncationError = 100.0 * abs(trunc / VBSeriesApprox);
			//Prints the tables values with formatting
			std::cout << std::setprecision(11) << std::setw(FIRST_ROW) << calcBCurrent << std::setw(SECOND_ROW) << VBSeriesApprox << std::setw(THIRD_ROW) << VBSeriesExact << std::setw(FOURTH_ROW) << relativeError << std::setw(FOURTH_ROW) << truncationError << std::endl;
			calcBCurrent += calcB; // Increment of B is needed after the table is printed to get Inital values printed
	}
	std::cout << std::endl << std::endl;
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