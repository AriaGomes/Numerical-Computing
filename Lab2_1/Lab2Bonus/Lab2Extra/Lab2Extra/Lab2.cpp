// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

void userChoice(std::string userIn);
void binToDec(std::string bN);
void decToBin(std::string dN);

int main()
{
    std::string userIn;
    bool exit = false;


    while (exit == false)
    {
        std::cout << "Aria Gomes - Numerical Lab 2\n\n";
        std::cout << "Enter 1 for Deciaml to Binary conversion\n";
        std::cout << "Enter 2 for Binary to Decimal conversion\n";
        std::cout << "Enter 3 to exit\n\n";
        std::cout << "Your selection: ";
        std::cin >> userIn;

        if (userIn[0] == '3')
            exit = true;
        else
            userChoice(userIn);
    }
}

void userChoice(std::string userIn)
{
    std::string userNum;

    switch (userIn[0])
    {
    case '1':
        std::cout << "Enter binary to convert to decimal: ";
        std::cin >> userNum;
        decToBin(userNum);
        break;
    case '2':
        std::cout << "Enter binary to convert to decimal: ";
        std::cin >> userNum;
        binToDec(userNum);
        break;
    default:
        std::cout << "Invalid Input! try again\n\n";
        break;
    }


}

void binToDec(std::string bN)
{
    int integralDecimalNumber = 0;
    double fractionalD;
    int twos = 1;
    double fractionalAdd = 0;
    int temp = std::stoi(bN);
    // Initializing base value to 2^0 = 1
    int base = 1, i = 0;


    while (temp) //Integral Calculation 
    {
        int endDigit = temp % 10;
        temp = temp / 10;

        integralDecimalNumber += endDigit * base;

        base = base * 2;
    }

    std::string fracational = bN;
    std::size_t found = fracational.find('.');
    if (found != std::string::npos)
    {
        fracational = fracational.substr(found + 1, fracational.length());
        fracational = fracational.replace(0, fracational.length(), fracational);
        fractionalD = std::stod(fracational);

        twos = 2;
        for (unsigned int i = 0; i < fracational.length(); i++)
        {
            fractionalAdd += ((double)(fracational[i]) - (double)('0')) * (1.0 / twos);
            twos *= 2;
        }
    }
    else
        fractionalD = 0.00;

    
    // Convert fractional part of binary to 
     // decimal equivalent 
   
    std::cout << "\nDecimal form of " << bN << " is " << integralDecimalNumber + fractionalAdd << std::endl << std::endl;
    fractionalAdd = 0;
}

void decToBin(std::string dN)
{
    double fractionalD;
    int *integralBinaryNumber = new int[100];
    int *fractionalBinaryNumber = new int[10000];
    int i = 0, x = 0;

    int integral = std::stoi(dN);
    std::string fracational = dN;
    std::size_t found = fracational.find('.');
    if (found != std::string::npos)
    {
        fracational = fracational.substr(found + 1, fracational.length());
        fracational = fracational.replace(0, fracational.length(), "0." + fracational);
        fractionalD = std::stod(fracational);
    }
    else
        fractionalD = 0.00;

    while (integral > 0) //Integral Calculation
    {
        integralBinaryNumber[i] = integral % 2;
        integral = integral / 2;
        i++;
    }
    

    std::cout << "\nBinary form of " << dN<< " is ";
    for (int j = i - 1; j >= 0; j--)
        std::cout << integralBinaryNumber[j];
    std::cout << '.';

    while (fractionalD != 1.00 && fractionalD != 0.00) //Fractional Calculation
    {
        fractionalD = fractionalD * 2;
        fractionalBinaryNumber[x] = (int)std::floor(fractionalD);
        if (fractionalD > 1)
            fractionalD--;
        std::cout << fractionalBinaryNumber[x];
        x++;
    }

    std::cout << std::endl << std::endl;


    delete[] fractionalBinaryNumber, integralBinaryNumber;
}