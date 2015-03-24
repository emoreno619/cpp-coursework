#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <ctype.h>

using namespace std ;


int main(int argc, char* argv[])
{
	int count[26];
	int lines = atoi(getenv("LINES")) ;
	int cols  = atoi(getenv("COLUMNS")) ;
	int greatFreq = 0;
	int plotAmt = 0;
	int countAmt = 0;

	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL)
	{
	    cout << "empty file \n";
		return 0;
	}

	for (int i = 0; i < 26; ++i)
	{
		count[i] = 0;
	}

	while (!feof(fp))
	{
		int z = fgetc(fp);

		if (isalpha(z))
		{
			if (isupper(z))
			{
				tolower(z);
			}

			count[z - 'a']++;
		}
	}

	//horizontal histogram

	for (int i =0; i < 26; ++i)
	{
		cout << "count[" << (char) (i + (int)'a') << "]" << " ";
		cout << count[i] << endl;

		if (count[i] > greatFreq)
		{
			greatFreq = count[i];
		}
	}

	cout << endl;

	for (int i = 0; i < 26; ++i)
	{
		countAmt = count[i];
		plotAmt = ((cols - 11) * countAmt) / greatFreq;
		cout << "count[" << (char) (i + (int)'a') << "]" << " | ";
		for (int j = 0; j < plotAmt; ++j)
		{
			cout << "=";
		}

		cout << endl;
	}

	cout << endl;
	//vertical histogram

	for (int i = 0; i < (lines - 2); ++i)
	{
		int y = (lines - (lines / 6));

		if (i == y + 1)	
		{
			for (int k = 0; k < 52; ++k)
			{
				cout << "=";
			}
			
			cout << endl;
		}

		if (i > (y+1) && i <= (y+2))
		{
			for (int k = 0; k < 26; ++k)
			{
				cout << (char) (k+97);
				cout << " ";
			}
			
			cout << endl;
		}

		if (i < y)
		{
			for (int j = 0; j < 26; ++j)
			{
				countAmt = count[j];
				plotAmt = (y * countAmt) / greatFreq;

				if ( (plotAmt / (y - i)) >= 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}

				cout << " ";
			}
		}

		cout << endl;
		
	}
	return 0;
}