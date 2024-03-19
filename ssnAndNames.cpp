/*
Ryan Pepper
November 30th 2023
CIT 245
SSN and Names
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include <map>

int main()
{
	std::map<std::string, std::string> ssnMap;

    ssnMap["Paul Brown"] = "123-45-6790";
    ssnMap["Mary Smith"] = "123-45-6791";
    ssnMap["John Smith"] = "123-45-6789";
    ssnMap["Lisa Brown"] = "123-45-6792";

    std::cout << "Iterating through list..." << std::endl;
    for (const auto& pair : ssnMap) 
    {
        std::cout << pair.second << ": " << pair.first << std::endl;
    }

    std::string searchName = "John Smith";
    auto it = ssnMap.find(searchName);
    if (it != ssnMap.end())
    {
        std::cout << searchName << " found " << it->second << std::endl;
    }
    else 
    {
        std::cout << searchName << " not found" << std::endl;
    }

    std::string notFoundName = "John Brown";
    it = ssnMap.find(notFoundName);
    if (it != ssnMap.end()) 
    {
        std::cout << notFoundName << " found " << it->second << std::endl;
    }
    else 
    {
        std::cout << notFoundName << " not found" << std::endl;
    }
    std::cin.get();

    return 0;
}