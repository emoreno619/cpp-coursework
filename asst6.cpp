#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <ctype.h>

using namespace std ;

bool chk_isbn(string ISBNtoCheck);

bool chk_isbn(string ISBN)
	{
		cout << endl << "ISBNtoCheck: " << ISBN << endl;
		bool cleanflag = false;
		int pos = 0;
		
		while (!cleanflag)
		{
			if (!isdigit(ISBN[pos]))
			{
				if (ISBN.length() >= 10 && toupper(ISBN[pos]) != 'X' || pos != ISBN.length() - 1 )
				{
					ISBN.erase(pos, 1) ;
					pos = -1;
				}
			}
			
			if (pos != ISBN.length() - 1)
			{
				pos++;
			}
			else
			{
				cleanflag = true;
			}

		}

		cout << endl << "ISBNtoCheck: " << ISBN << endl;

		if (ISBN.length() == 10)
		{
			cout << endl << "ISBN length = 10 ";
			int sum = 0;
			int checkDigit;
			if (toupper(ISBN[9]) != 'X')
			{
					checkDigit = (ISBN[9] - 48);
			}
			else
			{
				checkDigit = (int) 'X';
			}

			cout << "checkDigit : " << checkDigit << endl;

			for (int x = 0; x < ISBN.length(); x++)
			{
				if ( x != 9)
				{
						sum += ((ISBN[x] - 48 ) * (x+1));
				}

				cout << "sum is : " << sum << endl;
			}

			int calcCheckDig = (sum%11);
			cout << "calcCheckDig : " << calcCheckDig << endl;

			if ( calcCheckDig < 10 && calcCheckDig > 0)
			{
				if (calcCheckDig == checkDigit)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (calcCheckDig == 10 && checkDigit == (int) 'X')
				{
						return true;
				}
				return false;
			}
		}

		cout << endl << "ISBNtoCheck: " << ISBN << endl;
		
		if (ISBN.length() == 13)
		{
			int sum = 0;
			int checkDigit = (ISBN[12] - 48);
			cout << "checkDigit : " << checkDigit << endl;

			for (int x = 0; x < ISBN.length(); x++)
			{
				if (x != 12)
				{
					if (((x+1)%2) == 0)
						sum += ((ISBN[x] - 48) * (3));
					if (((x+1)%2) != 0)
						sum += ((ISBN[x] - 48) * (1));
				}
				cout << "sum is : " << sum << endl;
			}

			cout << "sum is : " << sum << endl;
			cout << "sum mod 10 : " << (sum%10) << endl;
	
			int calcCheckDig = (10 - (sum%10));

			cout << "calcCheckDig : " << calcCheckDig << endl;
			cout << "checkDigit : " << checkDigit << endl;

				if (calcCheckDig == checkDigit)
				{
						return true;
				}
				else
				{
					return false;
				}
		}
	}

int main(int argc, char* argv[])
{
	string ISBNtoCheck = (string) argv[1];

	if (chk_isbn(ISBNtoCheck))
	{
			cout << "RESULT : VALID ISBN" << endl;
	}
	else
	{
		cout<< "RESULT : INVALID ISBN" << endl;
	}

	return 0;
}
