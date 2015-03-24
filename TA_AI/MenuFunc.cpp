/**************************************************************
***************************************************************
***************************************************************
***                                    			    		***
***                  ID INFORMATION                    		***
***                                    			    		***
***   Programmers			:		    Eduardo Moreno     	***
***   Assignment #		 	:   		TA #1.4AI          	***
***   Assignment Name		:	  Affirmative Interaction   ***
***   Course # and Title	:		    CISC 205 – OOPS		***
***   Class Meeting Time	:		    TTH 9:35 – 12:45	***
***   Instructor			:	    	Professor Forman 	***
***   Hours			   		:			16					***
***   Difficulty			:	    	6					***
***   Completion Date		:	    	10/01/14		  	***
***   Project Name			:  	    	OOPS_TA_AI	 	    ***
***                                        					***
***************************************************************
***************************************************************
***                                        					***
***               PROGRAM DESCRIPTION                  		***
***                                        					***
***   	My program is an interactive dictionary that 		***
***		identifies and can learn synonyms for the word 		***
***	    "Yes" that are stored in, read from and written		***
***		to a disk file. The program understands NO, and		***
***     there are also a number of features for controlling ***
***		bad data, repetitive synonyms and storing multiple	***
***		synonyms at once.									***
***                                     					***
***************************************************************
***************************************************************
***************************************************************
***                                                			***
***            CUSTOM-DEFINED FUNCTION LIST                	***
***                                        					***
***															***
***	welcome()												***
***															***
*** logoDisplay()											***
***															***
*** login()			   										***
***															***
*** loginBurp()											   	***
***															***
*** farewell()												***
***															***
*** pauseFunc()												***
***															***
*** gotoXY()												***
***															***
*** menuDisplay()											***
***															***
*** printMenu()												***
***															***
*** errorCounter()								            ***
***															***
***************************************************************
***************************************************************
***                                                      	***
***						CREDITS	                         	***
***                                        					***
***   	 Many thanks to Professor Forman, Jim				***
***                                        					***
***************************************************************
***************************************************************
**************************************************************/

#include "MenuHeader.h"
#include "AIheader.h"

using namespace std;

void welcome(){

	/////////////////////////////////////////////////////////////////////////

	//			LOCAL CONSTANT DECLARATIONS AND DEFINITIONS

	/////////////////////////////////////////////////////////////////////////

	const string	MY_NAME = "Eduardo Moreno";

	/////////////////////////////////////////////////////////////////////////

	cout << "  \1  \1  \1  Welcome to "
		 << MY_NAME
		 << "'s TA #1.4AI  \2  \2  \2\n";
	pauseFunc();
	return;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		logoDisplay
//	DESCRIPTION:	Displays my logo (a large ? mark) in ASCII graphics

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void logoDisplay()
{
	system("CLS");
	gotoXY(31, 1);
	cout <<   "..lddddddddddo... \n";       
	gotoXY(28, 2);
   cout << ".okWMMMMMMMMMMMMMMWWx. \n";     
   gotoXY(27, 3);
   cout << ",NMMMMMMMMMMMMMMMMMMMMWk' \n";   
   gotoXY(26, 4);
  cout << "kWMMMMMMMMW0OOO0WMMMMMMMMN, \n";
  gotoXY(25, 5);
 cout << ";NMMMMMMWk'.     'kWMMMMMMMX. \n"; 
 gotoXY(24, 6);
cout << ".XMMMMMMMK.        .XMMMMMMMX. \n"; 
gotoXY(24, 7);
cout << ".XWWWWWWX.         .XMMMMMMMX. \n"; 
gotoXY(26, 8);
  cout << "......           cNMMMMMMWo \n";  
  gotoXY(42, 9);
           cout <<      "cXMMMMMMMNl \n";   
		   gotoXY(41, 10);
             cout << ".oNMMMMMMMXl \n";     
			 gotoXY(40, 11);
            cout << ".dNMMMMMMKl; \n";       
			gotoXY(39, 12);
           cout << ".XMMMMMM0: \n";          
		   gotoXY(39, 13);
           cout << ".XMMMMMX. \n";           
		   gotoXY(39, 14);
           cout << ".xOOOOOx. \n";           
			cout << "\n";                   
			gotoXY(38, 17);
			cout << ".xKx.";
			gotoXY(37, 18);
			cout << ".xKKKx.";
			gotoXY(36, 19);
           cout << ".xKKKKKx. \n";            
		   gotoXY(36, 20);
           cout << ".WMMMMMX. \n";           
		   gotoXY(37, 21);
            cout << ".ldXdl. \n";            
			gotoXY(38, 22);
             cout << "  .   ";               
	cin.ignore();
	pauseFunc();	
}//B

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		login
//	DESCRIPTION:	Takes a string from user with cin.getline and returns the submitted data

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool login(string &userName)
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	//		LOCAL VARIABLE DECLARATIONS 

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool flag = false;
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if (userName == " ")
	{
		gotoXY(15, 18);
		cout << "Please login with your first name: ";
		cout << "                     ";
		gotoXY(50, 18);
		cin >> userName;
		flag = true;
		cin.ignore();
		loginBurp(userName, flag);

	}else{
		flag = true;
	}
	return flag;
} //C

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		loginBurp
//	DESCRIPTION:	The returned username string from login() is passed to this function and burped (or displayed)
//                 back to the user and a boolean loggedIn is set to true that is later used as a control structure
//                 in menu()

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loginBurp(string &userName, bool &loggedIn)
{
	loggedIn = true;
	cout << "\nYou entered " + userName + " as your username.\n";
	pauseFunc();
} //D

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		printMenu
//	DESCRIPTION:	Prints menu with options: S - Sign, L - Logo Display, C - Cellular Automata and X - Exit to screen.
//               Control and logic of the menu implementation is located in menuDisplay()

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printMenu()
{
	system("CLS");
	gotoXY(38, 8);
	cout << "MENU";
	gotoXY(30, 10);
	cout << "S - Sign In";
	gotoXY(30, 11);
	cout << "L - Logo Display";
	gotoXY(30, 12);
	cout << "A - Affirmative Interaction";
	gotoXY(30, 13);
	cout << "D - Display Dictionary";
	gotoXY(30, 14);
	cout << "X - Exit Program";

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		menuDisplay
//	DESCRIPTION:	Displays menu with options: S - Sign, L - Logo Display, C - Cellular Automata and X - Exit by calling
//                 menuDisplay(). When an option is selected, its respective function is called. This method also has control
//                 structures for 'dirty' data (i.e., data that doesn't match a menu selection), accepts both
//                 upper- and lower-case letters for correct menu selections, requires a sign-in before selecting
//                 another option, only allows 3 incorrect menu selections then warns user that program will exit
//                 upon another incorrect selection

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuDisplay()
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	string userName = " ";
	char userEntry;
	locale loc;
	int j = 1;
	int error = 0;
	bool loggedIn = false;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	printMenu();

	do{
		gotoXY(15, 18);
		cout << "Please enter a letter corresponding to your selection:  \n";
		for (int j = 0; j < 5; j++){
			for (int i = 0; i < 80; i++)
				cout << " ";
		}
		gotoXY(70, 18);

		cin >> userEntry;

			switch (toupper(userEntry, loc))
			{
				case 'X':

						farewell(userName);
						cin.ignore();
						break;
					
				case 'S':
					if (!loggedIn)
					{
						loggedIn = login(userName);
						break;
					}
					else {
						cout << userName + ", you're already logged in!";
						cin.ignore();
						pauseFunc();
						break;
					}

				case 'L':

					if (loggedIn)
					{
						//cin.ignore();
						logoDisplay();
						printMenu();
					}
					else{
						cin.ignore();
						cout << "Sorry, you must first login.";
						pauseFunc();
					}
					break;

				case 'A':

					if (loggedIn)
					{
						talkToMe();
						printMenu();
					}
					else{
						cin.ignore();
						cout << "Sorry, you must first login.";
						pauseFunc();
					}
					break;
				case 'D':

					if (loggedIn)
					{
						displayDic2();
						printMenu();
					}
					else{
						cin.ignore();
						cout << "Sorry, you must first login.";
						pauseFunc();
					}
					break;
				default:
					cin.ignore();
					errorCounter(userName, error);
					if (error == 3){
						cout << "\nWARNING: You only have one more attempt to select a correct option, otherwise you will exit the program!";
					}
					if (error == 4){
						farewell(userName);
					}
					if (error < 3){
						cout << "\nYou didn't enter a valid option (i.e., S, L, C or X). Please try again.\n";
					}
					//cin.ignore();
					pauseFunc();
					//cin.ignore();
					//system("CLS");
					gotoXY(69, 18);
					for (int i = 0; i < 80; i++)
						cout << " ";
					gotoXY(69, 18);
			}
	}while(j = 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		errorCounter
//	DESCRIPTION:	Counts number of erroneous login attempts by a userName and once those attemps reaches 3, calls
//                 farewell() to exit program

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int errorCounter(string userName, int &error)
{
	error++;
	return error;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		farewell
//	DESCRIPTION:	Bids adieu to the user by username in a friendly way

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int farewell(string userName)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL CONSTANT DECLARATIONS AND DEFINITIONS

	/////////////////////////////////////////////////////////////////////////

	const string	MY_NAME = "Eduardo Moreno";

	/////////////////////////////////////////////////////////////////////////
	//cin.ignore();
	cout << "\nThanks " + userName + " for using " + MY_NAME + "'s Affirmative Interaction Program!\n";
	cin.ignore();
	pauseFunc();
	exit(0);
} //L

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		pauseFunc
//	DESCRIPTION:	Pauses program output and waits for the user to push enter

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pauseFunc()
{
	cout << "\n\t\t\t>>> HIT ENTER TO CONTINUE <<<\n";
	cin.ignore();	
	return; 
}//M


void gotoXY(int x, int y)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	COORD  xy = { x, y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	SetConsoleCursorPosition(hConsole, xy);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//		END FUNCTION DEFINITIONS

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
