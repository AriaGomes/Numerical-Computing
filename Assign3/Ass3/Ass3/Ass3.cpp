/*********************************************************************************************************************************************************************************************************************
Student Name: Aria Gomes
Student Number: 040878659
Assignment: 3 - Trasiant First Order Systems
Course: Numerical Computing - CST8233
Section: 302
Proffessor Name: Hala Own
Due Date: 12/06/2020
Submission Date: 12/03/2020
Files: Ass3.cpp
**********************************************************************************************************************************************************************************************************************/


/*********************************************************************************************************************************************************************************************************************
Filename: Ass3.cpp
Version: 1.0
Author: Aria Gomes
Student Number: 040878659
Course Name: Numerical Computing - CST8233
Section: 302
Assignment: 3 - Trasiant First Order Systems
Due Date: 12/06/2020
Submission Date: 12/03/2020
Professor Name: Hala Own
Purpose: Takes data from the user and calculates using the specified method and step value
/*********************************************************************************************************************************************************************************************************************/
//Includes
#include <iostream>
#include <string>
#include <iomanip>
//Function Declaration List
bool isNumberI(const std::string& input, bool type);
void eulersMethod(double h);
void rungeKutta(double h, int i);
double differential(double x, double y);

/**********************************************************************************************************************************************************************************************************************
Function Name: main()
Purpose: Holds the main menu loop and calls the specified method or Quits the application
Function In Params: None
Function Out Params: 0 for succesful execution
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
int main()
{
	//Local Varibles
	bool running = true;
	std::string userIn, stepSize;
	int userInAI;
	double stepSizeAD{};

	std::cout << "Aria's Assignment 3 - Trasiant First Order Systems\n\n";
	while (running) // Main Menu
	{
		std::cout << "Pick a method for solviing the ODE:\n"; // Get Method type
		std::cout << "1. Euler's Method.\n2. Runge-Kutta 2nd Order Method\n3. Runge-Kutta 3rd Order Method\n4. Runge-Kutta 4th Order Method\n5. Exit\n\n";
		std::cin >> userIn;
		if (!isNumberI(userIn, true)) // Error Checking
		{	
			std::cout << "Invlaid, Try again\n\n";
			continue;
		}
		else
		{
			userInAI = std::stoi(userIn);

			if (userInAI <= 4 && userInAI >= 1)
			{
				std::cout << "Choose step size 'h' (0.8, 0.2, 0.05): "; // Get Step size
				std::cin >> stepSize;

				if (!isNumberI(stepSize, false)) // Error Checking
				{
					std::cout << "Invlaid, Try again\n\n";
					continue;
				}
				else
					stepSizeAD = std::stod(stepSize);
			}

			switch (userInAI) // Logic to jump to methods based on user input
			{
			case 1: // Eulers Method
				eulersMethod(stepSizeAD);
				break;
			case 2: // Runge-Kutta 2nd Order Method
				rungeKutta(stepSizeAD, 2);
				break;
			case 3: // Runge-Kutta 3nd Order Method
				rungeKutta(stepSizeAD, 3);
				break;
			case 4: // Runge-Kutta 4nd Order Method
				rungeKutta(stepSizeAD, 4);
				break;
			case 5: // Exit
				running = false;
				break;
			}
		}
	}
	return 0; // Succesful Execution
}

/***********************************************
Function name: eulerMethod()
Purpose: Runs the program to calculate the euler ode
In parameters: double h
Out Parameters: void
Version: 1.0
Author: Aria Gomes
************************************************/
void eulersMethod(double h)
{
	// local variables
	double y = 3;
	double t = 0;

	// the amount of loops
	int n = (int)(2.0 / h);

	// print out the table head
	std::cout << "Time(s)\tExact Temp(C)\tEstimated Temp(C)\tPercentage Error(%)\n";

	// loop through each line of table
	for (int i = 0; i < n; i++) 
	{

		// get the values to be printed out
		y = y + h * differential(t, y);
		t += h;
		double exact = 0.1 * cos(4.0 * t) + 0.2 * sin(4.0 * t) + 2.9 * exp(-2.0 * t);
		double error = 100 * fabs((y - exact) / exact);

		// print out the values
		std::cout << std::fixed << std::setprecision(1) << t << "\t" << std::setprecision(3) << exact << "\t\t" << y << "\t\t\t" << std::setprecision(2) << error << "\n";
	}
	std::cout << "\n";
}


/**********************************************************************************************************************************************************************************************************************
Function Name: rungeKutta()
Purpose: Takes in 2 parameters, the step value double and the int value of which order of rungeKutta to use. Then preforms the algorithm for the order the user requested.
Function In Params: double h, int i
Function Out Params: void
Version: 1.0
Author: Aria Gomes
/*********************************************************************************************************************************************************************************************************************/
void rungeKutta(double h, int i)
{
	// local variables
	double rk1, rk2, rk3, rk4;
	double y = 3;
	double t = 0;
	double exact = 0.0;
	double error = 0.0;

	int n = (int)(2.0 / h);

	// print out table head 
	std::cout << "Time(s)\tExact Temp(C)\tEstimated Temp(C)\tPercentage Error(%)\n";

	// loop through each line of the table
	for (int j = 0; j < n; j++)
	{
		switch (i)
		{
		case 2:
			rk1 = differential(t, y);
			rk2 = differential(t + h, y + rk1 * h);
			y = y + ((h / 2) * (rk1 + rk2));
			t += h;

			exact = 0.1 * cos(4 * t) + 0.2 * sin(4 * t) + 2.9 * exp(-2 * t);
			error = 100 * fabs((y - exact) / exact);
			break;
		case 3:
			rk1 = differential(t, y);
			rk2 = differential(t + (h / 2), y + ((0.5 * rk1) * h));
			rk3 = differential(t + h, y - (rk1 * h) + (2 * (rk2 * h)));
			y = y + (h / 6.0) * (rk1 + (4 * rk2) + rk3);
			t += h;

			exact = 0.1 * cos(4 * t) + 0.2 * sin(4 * t) + 2.9 * exp(-2 * t);
			error = 100 * fabs((y - exact) / exact);
			break;
		case 4:
			// get values for runge_kutta
			rk1 = h * differential(t, y);
			rk2 = h * differential(t + 0.5 * h, y + 0.5 * rk1);
			rk3 = h * differential(t + 0.5 * h, y + 0.5 * rk2);
			rk4 = h * differential(t + h, y + rk3);

			// get the values to be printed out
			y = y + (1.0 / 6.0) * (rk1 + 2 * rk2 + 2 * rk3 + rk4);
			t += h;

			// print out the values
			exact = 0.1 * cos(4 * t) + 0.2 * sin(4 * t) + 2.9 * exp(-2 * t);
			error = 100 * fabs((y - exact) / exact);
			break;
		}
		//Print values
		std::cout << std::fixed << std::setprecision(1) << t << "\t" << std::setprecision(3) << exact << "\t\t" << y << "\t\t\t" << std::setprecision(2) << error << "\n";
	}
	std::cout << "\n";
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

/***********************************************
Function name: differential()
Purpose: Returns the equation cos(4t)-2y
In parameters: double
Out Parameters: double
Version: 1.0
Author: Aria Gomes
************************************************/
double differential(double x, double y) {return cos(4 * x) - (2 * y);}