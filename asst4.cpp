#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std ;

int main(int argc, char* argv[])
{

    int messageLength;
	int loopCounter= 0;
	bool isPerfect = false;

	int i = 0;

	char c[8192];

	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL)
	{
	    cout << "empty file \n";
		return 0;
	}

	while(!feof(fp))
		 {
			 char z = fgetc(fp);

			if (!isspace(z))
				{
					loopCounter++;
					c[i] = z;
					++i;
				}
		 }

loopCounter--;

	for (int j = 0; j < loopCounter; ++j)
		{
			if (loopCounter == j*j)
				{
					isPerfect = true;
				}
		}

	while (!isPerfect)
		{
			++loopCounter;

			for (int j = 0; j < loopCounter; ++j)
				{
					if (loopCounter == j*j)
						{
							isPerfect = true;
						}
				}
		}

	double squareSize = (double) loopCounter;
	int anotherInt = loopCounter;
	int squareLength = (int) sqrt(loopCounter);

	char dArray[squareLength][squareLength];

	cout << "Contents of message before scramble: " << endl;

	for (int j = 0; j < squareLength; ++j)
		{
			for (int k = 0; k < squareLength; ++k)
				{
					dArray[j][k] = c[loopCounter-anotherInt];
					--anotherInt;
					cout << dArray[j][k];

				}
		}

	cout << endl << "Contents of message after scramble: " << endl;

	for (int k = 0; k < squareLength; ++k)
		{

			for (int j = 0; j < squareLength; ++j)
				{
					cout << dArray[j][k];
				}
		}
	cout << endl;
		  return 0;

}
