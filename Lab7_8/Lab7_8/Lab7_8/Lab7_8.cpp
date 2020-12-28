// Lab7_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <algorithm>
int dataNumsAI{};
bool isNumberI(const std::string& input, bool type);
void createTable();
double mean();
double median();
double range();
double standardDeviation();
void normalization();



double data[10] = {};

int main()
{
    bool RUNNING = true;
    std::string userInput;
    
    std::cout << "Aria's Lab 7&8 - Descriptive Statistics\n\n";

	createTable();

    while (RUNNING)
    {
		

        std::cout << "Enter one of the following:\n";
        std::cout << "1- Mean\n";
        std::cout << "2- Median\n";
        std::cout << "3- Standard deviation\n";
        std::cout << "4- Range\n";
        std::cout << "5- Normalize(z-score)\n";
        std::cout << "6- Exit\n\n";
		std::cout << "Entry: ";
        std::cin >> userInput;
		if (isNumberI(userInput, true))
		{
			switch (userInput[0])
			{
			case '1':
				std::cout << "Mean = " << mean() << "\n";
				break;
			case '2':
				std::cout << "Median = " << median() << "\n";
				break;
			case '3':
				std::cout << "SD = " << standardDeviation() << "\n";
				break;
			case '4':
				std::cout << "Range = " << range() << "\n";
				break;
			case '5':
				normalization();
				break;
			case '6':
				RUNNING = false;
				break;
			default:
				std::cout << "Invalid menu option, try again\n\n";
				break;
			
			}
		}
		else
		{
			std::cout << "Invalid menu option, try again\n\n";
		}
    }

}

double mean()
{
	double sum = 0;

	for (int i = 0; i < dataNumsAI; i++)
		sum += data[i];
	
	sum /= dataNumsAI;

	return sum;
}

double median()
{
	double dataSorted[50];
	for (int i = 0; i < dataNumsAI; i++)
		dataSorted[i] = data[i];
	
	std::sort(dataSorted, dataSorted + dataNumsAI);
	double mean = 0.0;
	int index = 0;

	if (dataNumsAI % 2 == 0)
	{
		index = dataNumsAI / 2 - 1;
		mean = dataSorted[index] + dataSorted[index+1];
		mean = mean / 2;
	}
	else
	{
		index = dataNumsAI / 2;
		mean = dataSorted[index];
	}

	return mean;
}

double standardDeviation()
{
	double m =  mean();
	double totalNewMean ={};

	for (int i = 0; i < dataNumsAI; i++) {
		totalNewMean += pow(data[i] - m, 2);
	}
	totalNewMean /= dataNumsAI - 1;
	return sqrt(totalNewMean);
}

double range()
{
	double min, max;
	double dataSorted[50];
	for (int i = 0; i < dataNumsAI; i++)
		dataSorted[i] = data[i];

	std::sort(dataSorted, dataSorted + dataNumsAI);
	 
	min = dataSorted[0];
	max = dataSorted[dataNumsAI-1];


	return max - min;
}

void normalization()
{
	double normieNumber = {};

	std::cout << "\nData after standardization: \n";

	for (int i = 0; i < dataNumsAI; i++)
	{
		normieNumber = (data[i] - mean()) / standardDeviation();
		std::cout << normieNumber << "\n";
	}
	std::cout << "\n\n";
}


void createTable()
{
	std::string dataNums;
    std::string dataEntry;
	double dataEntryAD;

	std::cout << "How many data points would you like in the table: ";
	std::cin >> dataNums;
	if (isNumberI(dataNums, true))
	{
		dataNumsAI = std::stoi(dataNums);

		if (!(dataNumsAI > 0 && dataNumsAI <= 10))
		{
			std::cout << "Please enter an amount between 1-10, Restarting create table\n\n";
			createTable();
		}
	}
	else
	{
		std::cout << "Please enter a valid integer value, Restarting create table\n\n";
		createTable();
	}

    std::cout << "Enter " << dataNumsAI << " datapoints:\n";

	for (int i = 0; i < dataNumsAI; i++)
	{
		std::cin >> dataEntry;
		if (isNumberI(dataEntry, false))
		{
			dataEntryAD = std::stod(dataEntry);
			data[i] = dataEntryAD;
		}
		else
		{
			i--; 
			std::cout << "The datapoint you have entered is invalid, try again";
		}
	}
	std::cout << "\n";
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