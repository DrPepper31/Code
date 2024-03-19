/*
Ryan Pepper
November 11th 2023
CIT 245
Binary search
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>

template <typename T>
int binarySearch(const std::vector<T>& arr, const T& target) 
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) 
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    //integer test array
    std::vector<int> intArray = { 0, 1, 1, 2, 3, 5, 6, 13, 21, 32, 55 };
    std::cout << "Integer test array contains:\n";
    for (const auto& num : intArray) 
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    int intTargets[] = { -1, 0, 1, 2, 3, 4, 5, 6, 7 };
    for (const auto& target : intTargets)
    {
        int result = binarySearch(intArray, target);
        if (result != -1)
        {
            std::cout << target << " is at index " << result << "\n";
        }
        else 
        {
            std::cout << target << " is not in the array.\n";
        }
    }
    std::cout << "\n";

    //string test array
    std::vector<std::string> strArray = { "head", "knees", "shoulders", "toes" };
    std::cout << "String test array contains:\n";
    for (const auto& str : strArray) 
    {
        std::cout << str << " ";
    }
    std::cout << "\n\n";

    std::string strTargets[] = { "elbows", "knees" };
    for (const auto& target : strTargets)
    {
        int result = binarySearch(strArray, target);
        if (result != -1)
        {
            std::cout << target << " is at index " << result << "\n";
        }
        else 
        {
            std::cout << target << " is not in the array.\n";
        }
    }

    return 0;
}