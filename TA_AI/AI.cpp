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

#include "AIheader.h"


using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//		START FUNCTION DEFINITIONS

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*********************************************************************
NAME:			writeFile_fstream
DESCRIPTION:	This function writes out southern california coastal city names to an output text file
	            using the general purpose file stream data type ofstream, which requires a file
                access arguement.  It also appends more records to the file.
				Arguments include the address of the city names array and the array size.
				//Thanks to Jim from our File IO Team Tutorial
*********************************************************************/
bool writeFile_fstream( vector<string> &wordsKnown, vector<string> &wordsLearned)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/
	string outputFileName = "aiDic.txt",
		   fileMode;
	bool flag = false;
	int index1,index2;

	// defines an file stream object
	// If the file already exists it is recreated empty.
	//Note:  the short cut method is also applicable to fstream.  No separate open statement needed.
	fstream outputFile;
	/**************************************************************************************/

	// call function to open file and report back status
	if (openFileOut(outputFile, outputFileName))
	{
		for (index1 = 0; index1 < wordsKnown.size(); index1++)
		{
			// The string array element is written to the output file
			// Note: The data is first written to a buffer in memory for
			// performance reasons.  C++ figures out when the data gets 
			// physically written to the file.
			outputFile << wordsKnown[index1] << endl;

			//cout << "\trecord " << index1 << ": " << wordsKnown[index1] << "\n";

		}

		for (index2 = 0; index2 < wordsLearned.size(); index2++)
		{
			outputFile << wordsLearned[index2] << endl;
			//cout << "\trecord " << index2 << ": " << wordsLearned[index2] << "\n";
		}
		// The close function closes the file.  Although it is not 
		// necessary for the program to compile, it is necessary to ensure
		// that anything still in the buffer is written to the file.
		outputFile.close();
		//cout << "\n\tRecords written to " << outputFileName << " file: " << index1+index2 << endl;
		flag = true;
	}
	else
		flag = false;

	pauseFunc2();

	return flag;		//Go back to where you came from!
}

/*********************************************************************
NAME:			readTextFile
DESCRIPTION:	This function reads a text file.
				Arguments include the text file name.
				//Thanks to Jim from our File IO Team Tutorial
*********************************************************************/
bool readTextFile(string fileName, vector<string> &wordsKnown, vector<string> &wordsLearned)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/
	int readCntr = 0;
	bool flag = false;
	string rec;
	string rec2;

	fstream fileStream;
	/**************************************************************************************/
 

	// open the binary file for reading
	fileStream.open(fileName, ios::in);

	// test for errors
	if (!fileStream)
	{
		cout << fileName << " file could not be opened \n";
		pauseFunc2();
		return flag;
	}
	else
	{
		// this reads data from the file using the the file stream object. The data is written to string object.
		// The data is read up to a delimiter in this case \n.  
		getline(fileStream, rec, '\n');
		//cout << rec << "\n";
		flag = true;
	}
	fileStream.seekg(0, ios::beg);
	// display records until end-of-file
	while (!fileStream.eof())
	{
		readCntr++;
		getline(fileStream, rec, '\n');
		wordsKnown.push_back(rec);
		//cout << "\trecord " << readCntr << ": " << rec << "\n";
	}

	fileStream.close();
	/*for (int j = 0; j < wordsKnown.size(); j++)
			cout << "\tWordsKnown [" << j << "] : " << wordsKnown[j] << "\n";
	for (int i = 0; i < wordsLearned.size(); i++)
			cout << "\tWordsLearned [" << i << "] : " << wordsLearned[i] << "\n";*/
	cin.ignore();
	pauseFunc2();
	return flag;
}

/*********************************************************************
NAME:			openFileOut
DESCRIPTION:	This function checks that the file can be opened in output mode.  
				Parameters are the fstream object, output file name, file i/o mode.
				//Thanks to Jim from our File IO Team Tutorial
*********************************************************************/
bool openFileOut(fstream &file, string outputFileName)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/
	bool status;
	/**************************************************************************************/

	file.open(outputFileName, ios::out);
	if (file.fail())
	{
		status = false;
		cout << "\n" << outputFileName + " file did not open successfully!\n";
	}
	else
	{
		status = true;
		//cout << "\n\t" << outputFileName + " file opened successfully for output.\n";
	}
	return status;
}

/*********************************************************************
NAME:			openFileAppend
DESCRIPTION:	This function checks that the file can be opened in append mode.
				Parameters are the fstream object, output file name
				//Thanks to Jim from our File IO Team Tutorial
*********************************************************************/
bool openFileAppend(fstream &file, string outputFileName)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/
	bool status;
	/**************************************************************************************/

	file.open(outputFileName, ios::app);
	if (file.fail())
	{
		status = false;
		cout << "\n" << outputFileName + " file did not open successfully!\n";
	}
	else
	{
		status = true;
		cout << "\n\t" << outputFileName + " file opened successfully in append mode.\n";
	}
	return status;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		talkToMe
//	DESCRIPTION:	Begins and controls logic for 'discussion' with dictionary. Creates vectors of strings in which
//					synonyms are stored from both the file and input by user. Function is called from menu and continues
//					running until an answer of "no" is given. Then returns to menu.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void talkToMe(){
	
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	bool keepTalking = true;
	vector<string> wordsKnown;
	vector<string> wordsLearned;
	/*vector<string> NOwordsLearned;
	vector<string> NOwordsKnown;*/

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	cout << "Thank you for selecting \"c\" . . . \n"
		 <<	"Time for some affirmative interactions!\n";
	do 
	{
		if (readDic("aiDic.txt", wordsKnown, wordsLearned))
		{
			displayDic(wordsKnown, wordsLearned);
			if (willTeachMe(wordsKnown, wordsLearned))
			{
				teachMe(wordsKnown, wordsLearned);
			}
			/*else if (checkDicNo(userAnswer, NOwordsKnown, NOwordsLearned))
			{
			}*/
			else 
			{
				keepTalking = iDunno(wordsLearned[wordsLearned.size()- 1], wordsKnown, wordsLearned);
				displayDic(wordsKnown, wordsLearned);
			}
		}
		else{
			cout << "Error reading dictionary";
			pauseFunc2();
			keepTalking = false;
		}

		wordsKnown.clear();
		wordsLearned.clear();

	} while (keepTalking);


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		displayDic
//	DESCRIPTION:	Prints words already known (i.e., in dictionary) from vector which contains strings read from file

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayDic( vector<string> &wordsKnown, vector<string> &wordsLearned){
	
	cout << "Here are the words already in my dictionary:\n";
	
	for (int j = 0; j < wordsKnown.size(); j++)
	{
		if (wordsKnown[j] != "")
			cout << wordsKnown[j] << "\n";
	}
	
	pauseFunc2();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		willTeachMe
//	DESCRIPTION:	Asks user whether s/he would like to teach a synonym for "yes". Controls for lower/upper case,
//					doesn't accept entries beginning with whitespace and sends input to checkDic function. Returns
//					bool depending on response from checkDic (i.e., whether userEntry matches an entry in dictionary).

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool willTeachMe( vector<string> &wordsKnown, vector<string> &wordsLearned)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	vector<string> NOwordsLearned;
	vector<string> NOwordsKnown;
	bool flag = false;
	bool goodAnswer = false;
	string userAnswer;
	locale loc;
	
	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	while (!goodAnswer)
	{
		cout << "Can you please teach me another word that means yes? ";
		getline(cin,userAnswer);
		makeUpper(userAnswer);
		if (checkSpace(userAnswer))
		{
				cout << "Sorry." << userAnswer << " is not a valid entry. Please try again. \n";
				Sleep(100);
		}
		else {
			goodAnswer = true;
		}
	}
	if (checkDic(userAnswer, wordsKnown, wordsLearned))
		flag = true;
	else
		flag = false;
	return flag;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		checkSpace
//	DESCRIPTION:	Takes user input of string and checks first character for whitespace. Returns true if it is.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkSpace (string userAnswer)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	
	bool flag = false;
	locale loc;
	char c;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	c = userAnswer[0];
	if (isspace(c,loc) || c == NULL)
	{
		flag = true;
	}
	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		makeUpper
//	DESCRIPTION:	takes user entry of string and converts all characters to their uppercase equivalents

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void makeUpper (string &userAnswer)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	char *c;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	c = &userAnswer[0];
	for (int i = 0; i < userAnswer.length(); i++)
	{
		userAnswer[i] = ((char) toupper(*c));
		c++;
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		teachMe
//	DESCRIPTION:	If willTeachMe returns true, then program asks user to enter synonym for yes. Controls for answers
//					of "no", in which case program exits to menu, then compares synonym to yes synonyms already in dictionary
//					and if it is not, calls function to write that synonym to dictionary file

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool teachMe( vector<string> &wordsKnown, vector<string> &wordsLearned)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	bool flag = false;
	bool goodAnswer = false;
	locale loc;
	string userAnswer;
	
	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	while (!goodAnswer)
	{
		cout << "Good – please enter a word that means \"yes\": ";
		getline(cin,userAnswer);
		makeUpper(userAnswer);
		if (checkSpace(userAnswer) || userAnswer == "NO")
		{
				cout << "Sorry. " << userAnswer << " is not a valid entry. Please try again.\n";
				Sleep(100);
		}
		else {
			goodAnswer = true;
		}
	}
	
	wordsLearned.push_back(userAnswer);

	if (!checkDic(userAnswer, wordsKnown, wordsLearned) )
	{
			flag = true;
			if (writeDic(userAnswer, wordsKnown, wordsLearned))
				cout << userAnswer << " successfully added to dictionary \n";
			else
				cout << "Error writing to dictionary. \n";
	}
	else
	{
		flag = false;
		cout << userAnswer << " is already in the dictionary!\n";
	}
	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		writeDic
//	DESCRIPTION:	Begins file writing process, ensures fstream opens correctly and if so, passes vectors to be written
//					to dictionary file

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool writeDic(string userAnswer, vector<string> &wordsKnown, vector<string> &wordsLearned)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	
	bool flag = false;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	if (writeFile_fstream(wordsKnown, wordsLearned))
		flag = true;
	else
		flag = false;
	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		readDic
//	DESCRIPTION:	Takes file name and vectors to store words from dictionary into.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool readDic(string fileName, vector<string> &wordsKnown, vector<string> &wordsLearned)
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	bool flag = false;
	
	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	if (readTextFile(fileName, wordsKnown, wordsLearned))
		flag = true;
	else
		flag = false;
	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		checkDic
//	DESCRIPTION:	Compares user input (string) to each string within the vectors that are composed of strings from
//					dicitonary file. Returns true if user entry IS contained in vectors

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkDic(string userAnswer, vector<string> &wordsKnown, vector<string> &wordsLearned ) //returns true if word IS IN dictionary
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	bool flag = false;
	int i = 0;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	if (wordsLearned.size() < 1)
		wordsLearned.resize(1);
	do
	{
		if (wordsKnown[i] == userAnswer)
		{
			flag = true;
			i =  wordsKnown.size();
		}
		else if (i == (wordsKnown.size()-1) && !checkWordsLearned(userAnswer, wordsLearned))
		{
			flag = false;
			wordsLearned.push_back(userAnswer);
			i =  wordsKnown.size();
			
		}
		
		i++;
	} while (i < wordsKnown.size());

	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		checkWordsLearned
//	DESCRIPTION:	Compares user input (string) to each string input within this 'session' (i.e., strings not already
//					written to dictionary file). If word is found, then returns true.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkWordsLearned(string userAnswer, vector<string> &wordsLearned )
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	
	bool flag = false;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < wordsLearned.size(); i++)
		{
				if (wordsLearned[i] == userAnswer)
				{
					flag = true;
					i = wordsLearned.size();
				}
		}

	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		iDunno
//	DESCRIPTION:	This function is called when user doesn't enter a recognized answer to willTeachMe(). This function
//					checks user entry for "no" and exits to menu if so, checks for and rejects entry beginning with
//					whitespace, checks user entry for redundant entries in dictionary and calls to write to dictionary if not.
//					If the next answer is also unknown, the function calls itself to continue checking new user input.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool iDunno(string unknownWord, vector<string> &wordsKnown, vector<string> &wordsLearned) 
{

	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	string userEntry;
	bool flag = false;
	bool goodAnswer = false;
	locale loc;
	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	makeUpper(unknownWord);
	if (unknownWord == "NO")
	{
		cout << "Well thanks for your positive, never-say-no attitude! Glad you believe in affirmative interaction! \n";
		pauseFunc2();
		return false;
	}
/*
	vector<string> NOwordsLearned;
	vector<string> NOwordsKnown;

	if (checkDicNo(userEntry, NOwordsKnown, NOwordsLearned ))
		return false;*/
	//returns true if word IS IN dictionary

	while (!goodAnswer)
	{
		cout << "Hmm, I don’t know \"" << unknownWord << "\". Does it mean \"yes\"? ";
		getline(cin,userEntry);
		makeUpper(userEntry);
		if (checkSpace(userEntry))
		{
				cout << "Sorry." << userEntry << " is not a valid entry. Please try again.\n";
				Sleep(100);
		}
		else {
			goodAnswer = true;
		}
	}

	if(checkDic(userEntry, wordsKnown, wordsLearned))
	{
		writeDic(userEntry, wordsKnown, wordsLearned);
		for (int i = 0; i < wordsLearned.size(); i++)
			wordsKnown.push_back(wordsLearned[i]);
		flag = true;
	}
	else
	{
		iDunno(userEntry, wordsKnown, wordsLearned);
		flag = false;
	}
	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		checkLearned
//	DESCRIPTION:	Checks whether user input is already stored in vector of words input this session (as opposed to words
//					read from dictionary)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkLearned(string unknownWord, vector<string> &wordsKnown, vector<string> &wordsLearned) //returns true if IS IN wordsKnown
{

	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	bool flag = false;
	int i = 0;
	
	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	do
	{
		if (wordsLearned[i] == unknownWord)
		{
			flag = true;
			i =  wordsLearned.size();
		}
		else 
		{
			flag = false;
			if (i == (wordsLearned.size()-1))
			{
				cout <<  "unKnownWord to be pushed from checkLearned: " << unknownWord;
				wordsLearned.push_back(unknownWord);
			}
		}
		
		i++;
	} while (i < wordsLearned.size());

	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		pauseFunc2
//	DESCRIPTION:	Pauses program output and waits for the user to push enter

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pauseFunc2()
{
	cout << "\n\t\t\t>>> HIT ENTER TO CONTINUE <<<\n";
	cin.ignore();	
	return; 
}//M

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 	NAME:  		displayDic2
//	DESCRIPTION:	Begins read from dictionary process but takes different parameters than displayDic

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayDic2()
{
	/////////////////////////////////////////////////////////////////////////

	//			LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////
	vector<string> wordsKnown;
	vector<string> wordsLearned;

	/////////////////////////////////////////////////////////////////////////

	//			END LOCAL VARIABLE DECLARATIONS

	/////////////////////////////////////////////////////////////////////////

	readDic("aiDic.txt", wordsKnown, wordsLearned);
	displayDic(wordsKnown, wordsLearned);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//		END FUNCTION DEFINITIONS

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//bool checkDicNo(string userAnswer, vector<string> &NOwordsKnown, vector<string> &NOwordsLearned ) //returns true if word IS IN dictionary
//{
//	bool flag = false;
//	int i = 0;
//
//	if (NOwordsLearned.size() < 1)
//		NOwordsLearned.resize(1);
//	do
//	{
//		if (NOwordsKnown[i] == userAnswer)
//		{
//			flag = true;
//			i =  NOwordsKnown.size();
//		}
//		else if (i == (NOwordsKnown.size()-1) && !checkWordsLearned(userAnswer, NOwordsLearned))
//		{
//			flag = false;
//			NOwordsLearned.push_back(userAnswer);
//			i =  NOwordsKnown.size();
//			
//		}
//		
//		i++;
//	} while (i < NOwordsKnown.size());
//
//	return flag;
//}