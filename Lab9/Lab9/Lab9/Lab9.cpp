#include <iostream>
#include <string>
#include <iomanip>

#define FIRST_ROW 5
#define SECOND_ROW 15
#define THIRD_ROW 20

void linerRegression(double** dataPoints, int noNums);
bool isNumberI(const std::string& input, bool type);
void entry();

double eqA1 = 0, eqA0 = 0;
double A1P1, A1P2;
double xy;
double xSum;
double ySum;
double x2;


int main()
{
	std::cout << "Aria's Lab 9 - Linear Regression\n\n";
	entry();

	return 0;
}

void entry()
{
	std::string noNums, data;
	int noNumsAI;
	double dataAD;

	std::cout << "Enter the no. of data pairs to be entered: ";
	std::cin >> noNums;

	if (!isNumberI(noNums, true))
	{
		std::cout << "Invalid, Please enter another number\n\n";
		entry();
	}
	noNumsAI = std::stoi(noNums);

	double** dataPoints = new double* [noNumsAI]; // 2d array initalized dynamically with user values 
	for (int i = 0; i < noNumsAI; i++)
		dataPoints[i] = new double[2];

	std::cout << "Enter the x-axis values:\n";
	for (int x = 0; x < noNumsAI; x++)
	{
		std::cin >> data;
		if (isNumberI(data, false))
		{
			dataAD = std::stod(data);
			dataPoints[x][0] = dataAD;
		}
		else
		{
			std::cout << "Invalid data point entered, try again.\n\n";
			x--;
		}
	}

	std::cout << "Enter the y-axis values:\n";
	for (int y = 0; y < noNumsAI; y++)
	{
		std::cin >> data;
		if (isNumberI(data, false))
		{
			dataAD = std::stod(data);
			dataPoints[y][1] = dataAD;
		}
		else
		{
			std::cout << "Invalid data point entered, try again.\n\n";
			y--;
		}
	}
	linerRegression(dataPoints, noNumsAI);
}

void linerRegression(double** dataPoints, int noNums)
{
	double yFitted[500];
	std::cout << std::fixed << "\nS.no" << std::setw(FIRST_ROW + 3) << "x" << std::setw(SECOND_ROW + 6) << "y(observed)" << std::setw(THIRD_ROW) << "y(fitted)\n";
	std::cout << "------------------------------------------------------------------------------\n";


	for (int i = 0; i < noNums; i++)
	{
		xy += dataPoints[i][0] * dataPoints[i][1];
		xSum += dataPoints[i][0];
		ySum += dataPoints[i][1];
		x2 += pow(dataPoints[i][0], 2);
	}

	A1P1 = (noNums * xy) - (xSum * ySum);
	A1P2 = (noNums * x2) - pow(xSum, 2);
	eqA1 = A1P1 / A1P2;
	eqA0 = (ySum - eqA1 * xSum) / noNums;
	

	for (int i = 0; i < noNums; i++)
		yFitted[i] = eqA1 * dataPoints[i][0] + eqA0;
		

	for (int i = 0; i < noNums; i++)
		std::cout << std::setprecision(3) << i + 1  << '.' << std::setw(FIRST_ROW + 7) << dataPoints[i][0] << std::setw(SECOND_ROW) << dataPoints[i][1] << std::setw(THIRD_ROW) << yFitted[i] <<"\n";

	std::cout << "The linear fit line is of the form:\n\n";
	std::cout << std::setprecision(6) << eqA1 << "x + " << eqA0 << "\n\n";
}

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