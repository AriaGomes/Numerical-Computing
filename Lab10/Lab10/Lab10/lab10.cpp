#include <iostream>
#include <iomanip>
#include <cmath>
const double x[7] = {4, 2.25, 1.45, 1.0, 0.65, 0.25, 0.006};
const double y[7] = {0.398, 0.298, 0.238, 0.198, 0.158, 0.098, 0.048};
const int dataAmt = 7;

int main()
{

	double a1, a0, xLogSum{}, yLogSum{}, YXlogSum{}, xSquaredLogSum{};
	std::cout << "Aria's Lab 10 -  Non-Linear Regression\n\n";

	for (int i = 0; i < dataAmt; i++)
	{
		xLogSum += log(x[i]);
		yLogSum += log(y[i]);
		YXlogSum += log(y[i]) * log(x[i]);
		xSquaredLogSum += pow(log(x[i]), 2);
	}

	a1 = ((dataAmt * YXlogSum) - (xLogSum * yLogSum)) / ((dataAmt * xSquaredLogSum) - pow(xLogSum, 2));
	a0 = exp((yLogSum - a1 * xLogSum) / dataAmt);

	std::cout << std::setprecision(5) << "The Regression parameters are:\n a0 = " << a0 << "\t\t a1 = " << a1 << "\n";
	std::cout << "The nonlinear regression model is:\n\t Y = " << a0 << "X^ " << a1 << "\n\n";
	return 0;
}