#include <iostream>
//#include <math.h>  
#include <exception>
#include <string>

#define n 10
#define a 1
#define ln(x) log(x) 

double taylor(double x);
bool isNumber(const std::string& input);

int main()
{
	bool RUNNING = true;

	std::cout << "Aria's Lab4\nEnter 'X' to close the program\n\n";

	while (RUNNING)
	{
		std::string x;
		double xAD;
		double Tv, Av, Ae, Re;

		std::cout << "Enter the value of x: ";
		std::cin >> x;

		if (isNumber(x))
		{
			xAD = std::stod(x);
			Av = taylor(xAD);
			Tv = ln(xAD);
			Ae = Tv - Av;
			Re = Ae / Tv;
			
			std::cout << std::fixed << "The number of terms: " << n << std::endl;
			std::cout << std::fixed << "True value = " << Tv << std::endl;
			std::cout << std::fixed << "Approximate value = " << Av << std::endl;
			std::cout << std::fixed << "Absolute error = " << Ae << std::endl;
			std::cout << std::fixed << "Relative error = " << Re << std::endl;
			std::cout << "\n\n";
		}
		else if (x[0] == 'x' || x[0] == 'X')
			RUNNING = false;
		else
			std::cout << "The value you have entered is invalid please try again\n\n";
	}

	return 0;
}

double taylor(double x)
{
    double sum = 1.0; // initialize sum of series  

    for (int i = 1; i < n + 1; i++)
    {
        sum += pow((-1), (i - 1)) * (pow((x - a), i)/i); // Taylor series expansion formula
        //std::cout << sum << std::endl; // Testing purposes
    }
    return sum - 1;
}

bool isNumber(const std::string& input)
{
	for (char c : input)
	{
		if (!isdigit(c))
			if(!(c == '.'))
				return false;
	}

	return true;
}