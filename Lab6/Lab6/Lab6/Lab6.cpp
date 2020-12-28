#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

void lagrange();
bool isNumberI(const std::string& input, bool type);
void interpolate(int i, int j, int dataAmtAI, double s, double t, double p, double yP, double xP, double** dataPoints);

int main()
{
	std::cout << "Aria's Lab6 - Lagrange Interpolation\n\n";
	lagrange();
	return 0;
}

void lagrange()
{
	std::string dataAmt;
	int dataAmtAI = 0, i=0, j=0;
	std::string userDataEntry, interpolationPoint;
	double userDataEntryAD = 0.0, interpolationPointAD = 0.0, s=1.0, t=1.0, yP = 0.0, p=0.0;
	double minX = LONG_MAX, MaxX = 0.0;
	char XorY[2] = {'X', 'Y'};

	std::cout << "Enter number of data: ";
	std::cin >> dataAmt;

	if (isNumberI(dataAmt, true))
	{
		dataAmtAI = std::stoi(dataAmt);
		if (dataAmtAI < 0)
		{
			std::cin.ignore(1);
			std::cout << "Please enter an integer over 0, Restarting the lagrange interpolation\n\n";
			lagrange();
		}
	}
	else
	{
		std::cout << "Please enter a valid integer, Restarting the lagrange interpolation\n\n";
		lagrange();
	}
	double** dataPoints = new double*[dataAmtAI]; // 2d array initalized dynamically with user values 
	for (int i = 0; i < dataAmtAI; i++)
		dataPoints[i] = new double[2];

	std::cout << "Enter data:\n\n";
	
	for(int i = 0; i < dataAmtAI; i++)
		for (int j = 0; j < 2; j++)
		{
			std::cout << XorY[j] <<"[" << i+1 << "] = ";
			std::cin >> userDataEntry;
			if (isNumberI(userDataEntry, false))
			{
				userDataEntryAD = std::stod(userDataEntry);
				if (XorY[j] == 'X')
					dataPoints[i][j] = userDataEntryAD;
				else if (XorY[j] == 'Y')
					dataPoints[i][j] = userDataEntryAD;
			}
			else
			{
				std::cout << "Please enter a valid double. Restarting the lagrange interpolation\n\n";
				lagrange();
			}
		}

	while (true)
	{
		
		std::cout << "Enter interpolation point: ";
		std::cin >> interpolationPoint;

		if (interpolationPoint[0] == 'q' || interpolationPoint[0] == 'Q')
			break;

		if (isNumberI(interpolationPoint, false))
		{
			interpolationPointAD = std::stod(interpolationPoint);

			for (int a = 0; a < dataAmtAI; a++) // Get min and Max x values
			{
				if (dataPoints[a][0] > MaxX)
					MaxX = dataPoints[a][0];
				if (dataPoints[a][0] < minX)
					minX = dataPoints[a][0];

			}


			if (interpolationPointAD > MaxX || interpolationPointAD < minX)
			{
				std::cout << "Please enter a valid x value between " << minX << " and " << MaxX << " Restarting interpolation\n\n";
				continue;
			}

		}
		else
		{
			std::cout << "Please enter a valid x value to interpolate to. Restarting interpolation\n\n";
			continue;
		}


		interpolate(i, j, dataAmtAI, s, t, p, yP, interpolationPointAD, dataPoints);
	}
}

void interpolate(int i, int j, int dataAmtAI, double s, double t, double p, double yP, double xP, double** dataPoints)
{
	for (i = 0; i < dataAmtAI; i++)
	{
		s = 1.0;
		t = 1.0;
		for (j = 0; j < dataAmtAI; j++)
		{
			if (j != i)
			{
				s = s * (xP - dataPoints[j][0]); 
				t = t * (dataPoints[i][0] - dataPoints[j][0]);
			}
		}
		p = s / t; // calculate p
		yP = (double)(yP + (p * dataPoints[i][1])); // Calculate yp
	}

	std::cout << std::fixed << std::setprecision(3) << "Interpolated value at " << xP << " is " << yP << "\n\n";
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