#ifndef MENUHEADER_H
#define MENUHEADER_H
//VERY IMPORTANT: FUNCTION PROTOTYPES WITHIN A HEADER FILE MUST BE DECLARED AS PART OF A HEADER FILE
//				  NOTICE THAT THERE ARE TWO STATEMENTS HERE:
//															#ifndef CUSTOMFUNCTIONSHEADER_H
//															#define CUSTOMFUNCTIONSHEADER_H
//				  ALSO NOTICE LINE 18:						#endif
//				  THESE MARK THE BEGINNING AND END OF THE HEADER FILE AND WHICH PROTOTYPES WILL BE
//				  INCLUDED WHEN THE HEADER FILE IS INCLUDED AS WELL AS THE NAME THE COMPILER USES TO
//				  IDENTIFY THE HEADER FILE


#include <iostream> //Necessary for cout and cin
#include <string> //Necessary for string variables
#include <windows.h>	//Necessary for HANDLE, SetConsoleTextAttribute, Sleep,
#include <mmsystem.h>	//Necessary for PlaySound
#include <locale> //Necessary for toupper

#pragma comment(lib, "winmm.lib")  //Necessary for PlaySound

using  namespace  std;		//Walter Cronkite and Victor Borge

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//		FUNCTION PROTOTYPE DECLARATIONS

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Description:   Welcomes user in a friendly way as the program begins
void welcome();

//Description:   Displays my logo (a large ? mark) in ASCII graphics
void logoDisplay();

//Description:   Takes a string from user (i.e., username) with cin.getline and returns the username
string login();

//Description:   The returned username string from login() is passed to this function and burped (or displayed)
//                 back to the user and a boolean loggedIn is set to true that is later used as a control structure
//                 in menu()
void loginBurp(string &userName, bool &loggedIn);

//Description:   Bids adieu to the user by username in a friendly way
int farewell(string userName);

//Description:   Pauses program output and waits for the user to push enter
void pauseFunc();

//Description:   Moves cursor to column x and row y on console screen
void gotoXY(int x, int y);

//Description:   Displays menu with options: S - Sign, L - Logo Display, C - Cellular Automata and X - Exit by calling
//                 menuDisplay(). When an option is selected, its respective function is called. This method also has  
//				   control structures for 'dirty' data (i.e., data that doesn't match a menu selection), accepts both
//                 upper- and lower-case letters for correct menu selections, requires a sign-in before selecting
//                 another option, only allows 3 incorrect menu selections then warns user that program will exit
//                 upon another incorrect selection
void menuDisplay();

//Description: Prints menu with options: S - Sign, L - Logo Display, C - Cellular Automata and X - Exit to screen.
//               Control and logic of the menu implementation is located in menuDisplay()
void printMenu();

//Description:   Counts number of erroneous login attempts by a userName and once those attemps reaches 3, calls
//                 farewell() to exit program
int errorCounter(string userName, int &error);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//		END FUNCTION PROTOTYPE DECLARATIONS


#endif // MENUHEADER_H