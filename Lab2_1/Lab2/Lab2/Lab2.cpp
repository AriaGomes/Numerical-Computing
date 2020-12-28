// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include <cstdlib>
//#include <iterator> 
//#include <bitset>

void userChoice(std::string userIn);
void binToDec(int n);
void decToBin(int n);

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
        std::cout << "Enter decimal to convert to binary: ";
        std::cin >> userNum;
        decToBin(std::atoi(userNum.c_str()));
        break;
    case '2':
        std::cout << "Enter binary to convert to decimal: ";
        std::cin >> userNum;
        binToDec(std::atoi(userNum.c_str()));
        break;
    default:
        std::cout << "Invalid Input! try again\n\n";
        break;
    }


}

void binToDec(int n)
{
    int decimalNumber = 0;
    int temp = n;
    // Initializing base value to 2^0 = 1
    int base = 1;

    
    while (temp) 
    {
        int endDigit = temp % 10;
        temp = temp / 10;

        decimalNumber += endDigit * base;

        base = base * 2;
    }
    std::cout << "\nDecimal form of " << n << " is " << decimalNumber << std::endl << std::endl;
}

void decToBin(int n)
{
    int binaryNumber[100];
    int i = 0;

    while (n > 0) {
        binaryNumber[i] = n % 2;
        n = n / 2;
        i++;
    }
    std::cout << "\nBinary form of " << n << " is ";
    for (int j = i - 1; j >= 0; j--)
        std::cout << binaryNumber[j];
    std::cout << std::endl << std::endl;
    
}