/*
Ryan Pepper
october 16th 2023
CIT 245
Chapter 12 assignment
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include <fstream>

void writeAdvice(const std::string& advice)
{
	std::ofstream outFile("advice.txt", std::ios::out | std::ios::trunc);
	
	//prints error if no file called advice.txt is found
	if (!outFile.is_open())
	{
		std::cerr << "Could not open Advice File." << std::endl;
		return;
	}

	outFile << advice;
	outFile.close();

	std::cout << "Advice saved successfully!" << std::endl;
}

void readAdvice()
{
	std::ifstream inFile("advice.txt");

	if (!inFile.is_open())
	{
		std::cerr << "Could not open Advice File." << std::endl;
		return;
	}
	
	std::string advice;
	std::cout << "Old Advice:" << std::endl;
	while (std::getline(inFile, advice)) 
	{
		std::cout << advice << std::endl;
	}

	inFile.close();
}

int main() 
{
	char choice;
	std::string advice;

	do {
	std::cout << "Read or write (r/w)? ";
	std::cin >> choice;

	if (choice == 'w') 
	{
		std::cout << "Enter your phrase for the next user: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, advice);
		writeAdvice(advice);
	}
	else if (choice == 'r') {
		readAdvice();
	}
	else {
		std::cout << "Please enter r or w." << std::endl;
	}
	std::cout << "Enter 1 to continue or 0 to end: ";
	std::cin >> choice;
} while (choice == '1');
	return 0;
}