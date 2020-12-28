#define _USE_MATH_DEFINES
#define FIRST_ROW 7
#define SECOND_ROW 20
#define THIRD_ROW 25
#define FOURTH_ROW 25

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#define x M_PI/3.0

bool isNumberD(const std::string& input);
void mclurin();
double fact(int numTerms);

int main()
{

	std::cout << "Aria's Lab5 - McLurin Series" << std::endl << std::endl;
	mclurin();

	return 0;
}


double fact(int numTerms)
{
	double factorial = 1.0;
	for (int i = 1; i <= numTerms; i++)
		factorial *= i; //Factorial calc

    return factorial;
}


void mclurin()
{
	std::string errorBound;
	double errorBoundAD = {}, absoluteError = 20.0, approximateValue = 1.0, ExactValue = 0.0, factorial = 1.0, relativeError = 0.0;

	std::cout << "Enter your error bound: ";
	std::cin >> errorBound;

	if (!isNumberD(errorBound))
	{
		std::cout << "Error, invalid input. Enter a valid double" << std::endl << std::endl;
		mclurin();
	}
	else
		errorBoundAD = std::stod(errorBound);

	std::cout << std::setw(FIRST_ROW) << "N.terms" << std::setw(SECOND_ROW) << "Exact" << std::setw(THIRD_ROW) << "approximate value" << std::setw(FOURTH_ROW) << "absolute error" << std::setw(FOURTH_ROW) << "%trelative error" << std::endl;

	for (int i = 1; absoluteError > errorBoundAD; ++i)
	{
		
		ExactValue = cos(x);
		approximateValue += pow((-1.0), i) * (pow(x, 2.0 * i) / fact(2.0 * i));
		absoluteError = abs(ExactValue - approximateValue);
		relativeError = 100 * abs(absoluteError / ExactValue);
		std::cout << std::fixed << std::setprecision(7) << std::setw(FIRST_ROW) << i + 1 << std::setw(SECOND_ROW) << ExactValue << std::setw(THIRD_ROW) << approximateValue  << std::setw(FOURTH_ROW) << absoluteError << std::setw(FOURTH_ROW) << relativeError << std::endl;
	}
}

bool isNumberD(const std::string& input)
{
	for (char c : input)
	{
		if (!isdigit(c))
			if (!(c == '.'))
				return false;
	}

	return true;
}
		


