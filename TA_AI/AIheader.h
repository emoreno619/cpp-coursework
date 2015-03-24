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
***                                                			***
***            CUSTOM-DEFINED FUNCTION LIST                	***
***                                        					***
***															***
***	writeFile_fstream()										***
***															***
*** readTextFile()											***
***															***
*** openFileOut()   										***
***															***
*** openFileAppend()									   	***
***															***
*** talkToMe()												***
***															***
*** displayDic()											***
***															***
*** willTeachMe()											***
***															***
*** checkSpace()											***
***															***
*** makeUpper()												***
***															***
*** teachMe()									            ***
***															***
*** writeDic()												***
***															***
*** readDic()												***
***															***
*** checkDic()												***
***															***
***	checkWordsLearned()										***
***															***
*** iDunno()												***
***															***
*** checkLearned()											***
***															***
*** pauseFunc2()											***
***															***
*** displayDic2()											***
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

#ifndef AIHEADER_H
#define AIHEADER_H

#include<fstream>		// for all file operations
#include<iomanip>		// for output formatting
#include<iostream>
#include<string> // for handlng string variables
#include<vector>
#include <locale>
#include <windows.h>	//Necessary for HANDLE, SetConsoleTextAttribute, Sleep,

using namespace std;

//DESCRIPTION:  This function writes out southern california coastal city names to an output text file
//              using the general purpose file stream data type ofstream, which requires a file
//              access arguement.  Arguments include the address of the city names array and the array size. 
bool writeFile_fstream( vector<string> &wordsKnown, vector<string> &wordsLearned);

//DESCRIPTION:  This function reads a text file with the name passed in as a parameter.
bool readTextFile(string fileName, vector<string> &wordsKnown, vector<string> &wordsLearned);

//DESCRIPTION:  This function figures out if the output file can be opend successfully in output mode.
//              Arguments the file stream object and file name.
bool openFileOut(fstream &file, string outputFileName);

//DESCRIPTION:  This function figures out if the output file can be opend successfully in append mode.
//              Arguments the file stream object and file name.
bool openFileAppend(fstream &file, string outputFileName);

// 	NAME:  		talkToMe
//DESCRIPTION:  Begins and controls logic for 'discussion' with dictionary. Creates vectors of strings in which
//					synonyms are stored from both the file and input by user. Function is called from menu and continues
//					running until an answer of "no" is given. Then returns to menu.
void talkToMe();

// 	NAME:  		teachMe
//	DESCRIPTION:	If willTeachMe returns true, then program asks user to enter synonym for yes. Controls for answers
//					of "no", in which case program exits to menu, then compares synonym to yes synonyms already in dictionary
//					and if it is not, calls function to write that synonym to dictionary file
bool teachMe( vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		willTeachMe
//	DESCRIPTION:	Asks user whether s/he would like to teach a synonym for "yes". Controls for lower/upper case,
//					doesn't accept entries beginning with whitespace and sends input to checkDic function. Returns
//					bool depending on response from checkDic (i.e., whether userEntry matches an entry in dictionary).
bool willTeachMe( vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		writeDic
//	DESCRIPTION:	Begins file writing process, ensures fstream opens correctly and if so, passes vectors to be written
//					to dictionary file
bool writeDic(string userAnswer, vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		checkLearned
//	DESCRIPTION:	Checks whether user input is already stored in vector of words input this session (as opposed to words
//					read from dictionary)
bool checkLearned(string unknownWord, vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		iDunno
//	DESCRIPTION:	This function is called when user doesn't enter a recognized answer to willTeachMe(). This function
//					checks user entry for "no" and exits to menu if so, checks for and rejects entry beginning with
//					whitespace, checks user entry for redundant entries in dictionary and calls to write to dictionary if not.
//					If the next answer is also unknown, the function calls itself to continue checking new user input.
bool iDunno(string unknownWord, vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		readDic
//	DESCRIPTION:	Takes file name and vectors to store words from dictionary into.
bool readDic(string fileName, vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		checkDic
//	DESCRIPTION:	Compares user input (string) to each string within the vectors that are composed of strings from
//					dicitonary file. Returns true if user entry IS contained in vectors
bool checkDic(string userAnswer, vector<string> &wordsKnown, vector<string> &wordsLearned ); //returns true if word IS IN dictionary

// 	NAME:  		pauseFunc2
//	DESCRIPTION:	Pauses program output and waits for the user to push enter
void pauseFunc2();

// 	NAME:  		checkWordsLearned
//	DESCRIPTION:	Compares user input (string) to each string input within this 'session' (i.e., strings not already
//					written to dictionary file). If word is found, then returns true.
bool checkWordsLearned(string userAnswer, vector<string> &wordsLearned );

// 	NAME:  		checkSpace
//	DESCRIPTION:	Takes user input of string and checks first character for whitespace. Returns true if it is.
bool checkSpace (string userAnswer);

// 	NAME:  		makeUpper
//	DESCRIPTION:	takes user entry of string and converts all characters to their uppercase equivalents
void makeUpper (string &userAnswer);

// 	NAME:  		displayDic
//	DESCRIPTION:	Prints words already known (i.e., in dictionary) from vector which contains strings read from file
void displayDic( vector<string> &wordsKnown, vector<string> &wordsLearned);

// 	NAME:  		displayDic2
//	DESCRIPTION:	Begins read from dictionary process but takes different parameters than displayDic
void displayDic2();

#endif