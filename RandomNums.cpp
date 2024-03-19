/*
Ryan Pepper
September 23th 2023
CIT 245
Sorted random nums
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

int main()
{
	const int arraySize = 20;
	const int minRand = 1;
	const int maxRand = 10;

	int randomNums[arraySize];

	srand(time(0));

	int runAgain = 1;

	while(runAgain)
	{
		//gets random nums and fills array
		for (int i = 0; i <arraySize; i++)
		{
			randomNums[i] = rand() % (maxRand - minRand + 1) + minRand;
		}

		sort(randomNums,randomNums+arraySize);

		//prints sorted array
		cout << "Sorted array: ";
		for (int i = 0; i < arraySize; i++)
		{
			cout << randomNums[i] << " ";
		}
		cout << "\n";

		vector<int> counts(maxRand-minRand+1,0);
		for (int i = 0; i<arraySize; i++) 
		{
			counts[randomNums[i] - minRand]++;
		}

		cout << "Occurances:\n";
		for (int i = 0; i < counts.size(); i++)
		{
			cout << "Number " << i + minRand << " occurs " << counts[i] << " times.\n";
		}

		cout << "Would you like to run the program again (1 for yes 0 for no)"<<"\n";
		cin >> runAgain;
	}
	return 0;
}