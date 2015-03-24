#include "PointerPowerHeader.h"
#include <ctime>

using namespace std;


//creates 2d array of pointers to short
void createPegs(short ** pegBoard, short * rowPtr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		pegBoard[i] = new short[i + 1];
	}

	for (int i = 0; i < *rowPtr; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			pegBoard[i][j] = 0;
		}
	}
}

void psuedoMain(int gameNum)
{
	short rows = 10;
	short *rowPtr = &rows;
	short *pegBoard[10];
	double *scores[1];
	int dim[2];
	double scoreArray [2][10];

	scores[0] = new double[gameNum];

	cout << "Creating...\n";
	createPegs(pegBoard, rowPtr, rows);

	cout << "Filling...\n";
	int playNum = fillPegs(pegBoard, rowPtr);

	cout << "Showing board...\n";
	showPegs(pegBoard, rowPtr, playNum);

	printConsoleDim(dim);
	drawHisto(pegBoard, rowPtr, scoreArray, dim, scores, gameNum);
	
	emptyPegs(pegBoard, rowPtr);

}

void drawHisto(short ** pegBoard, short * rowPtr, double (&scoreArray)[2][10],  int (&dim)[2], double ** scores, int gameNum)
{
	double totalScore = 0;
	cout << "Weight: ";

	for (int i = 0; i < 10; i++)
	{
		if (i == 0 || i == 9)
			scoreArray[0][i] = 126;
		else if (i == 1 || i == 8)
			scoreArray[0][i] = 14;
		else if (i == 2 || i == 7)
			scoreArray[0][i] = 3.5;
		else if (i == 3 || i == 6)
			scoreArray[0][i] = 1.5;
		else if (i == 4 || i == 5)
			scoreArray[0][i] = 1;
		scoreArray[1][i] = (pegBoard[9][i]) * (scoreArray[0][i]);
		cout << scoreArray[0][i] << " ";
	}

	cout << "\nSCORE:";

	for (int j = 0; j < 10; j++)
	{
		cout <<  scoreArray[1][j] << " ";
		totalScore += scoreArray[1][j];
	}


	scores[0][gameNum] = totalScore;
	cout << "\nscores[0][" << gameNum <<"] : " << scores[0][gameNum];
	cout << "\nTOTAL SCORE:" << totalScore << "\n";
	
	cin.ignore();
	pauseFunc2();

	if(!writeFile_fstream(scores, gameNum))
		cout << "ERROR WRITING TO FILE\n";

	drawHorizon(pegBoard, rowPtr, scoreArray, dim);
	drawVertical(pegBoard, rowPtr, scoreArray, dim);

}

void drawHorizon(short ** pegBoard, short * rowPtr, double (&scoreArray)[2][10], int (&dim)[2])
{
	int countAmt = 0;
	int plotAmt = 0;
	int greatBalls = 0;

	for (int i =0; i < 10; ++i)
	{
		if (pegBoard[9][i] > greatBalls)
		{
			greatBalls = pegBoard[9][i];
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		countAmt = pegBoard[9][i];
		plotAmt = ((dim[1] - 13) * countAmt) / greatBalls;
		cout << "balls[" << i << "]" << " | ";
		for (int j = 0; j < plotAmt; ++j)
		{
			cout << "=";
		}

		cout << endl;
	}

	cout << endl;

	pauseFunc2();
}


void drawVertical(short ** pegBoard, short * rowPtr, double (&scoreArray)[2][10], int (&dim)[2])
{
	int countAmt = 0;
	int plotAmt = 0;
	int greatBalls = 0;

	for (int i =0; i < 10; ++i)
	{
		if (pegBoard[9][i] > greatBalls)
		{
			greatBalls = pegBoard[9][i];
		}
	}

	for (int i = 0; i < (dim[0] - 2); ++i)
	{
		int y = (dim[0] - (dim[0] / 5));

		//prints border for bottom of histogram and x-axis
		if (i == y + 1)	
		{
			cout << "\t\t";
			for (int k = 0; k < 28; ++k)
			{
				cout << "=";
			}
			
			cout << endl;
		}
		//prints values along x-axis
		if (i > (y+1) && i <= (y+2))
		{
			cout << "\t\t";
			for (int k = 0; k < 10; ++k)
			{
				cout << k;
				cout << "  ";
			}
			
			cout << endl;
		}
		//actual printing of data in histogram
		if (i < y)
		{
			cout << "\t\t";
			for (int j = 0; j < 10; ++j)
			{
				countAmt = pegBoard[9][j];
				plotAmt = (y * countAmt) / greatBalls;

				if ( (plotAmt / (y - i)) >= 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}

				cout << "  ";
			}
		}

		cout << endl;
		
	}

	pauseFunc2();
}


void printConsoleDim(int (&dim)[2])
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	dim[0] = rows;
	dim[1] = columns;
}

void emptyPegs(short ** pegBoard, short * rowPtr )
{
	for (int i = 0; i < 10; i++)
	{
		delete pegBoard[i];
	}
}

int fillPegs(short ** pegBoard, short * rowPtr )
{
	int randNum = time(0);
	srand(randNum);
	int playNum = 0;
	short bounce = 0;
	short j = 0;
	//char *userBallAmt[81];

	short balls = 1000;
	/*cout << "How many balls would you like to drop?";
	cin >> *userBallAmt;
	balls = (unsigned short) strtoul(*userBallAmt, NULL, 0);*/
	short * ballsPtr = &balls;

	while (playNum < *ballsPtr)
	{
		pegBoard[0][0] += 1;
		//showPegs(pegBoard, rowPtr, playNum);
		j = 0;
		for (int i = 1; i < *rowPtr; i++)
		{
			bounce = rand() % 2;
			if (bounce)
			{
				pegBoard[i][++j] += 1;
				//showPegs(pegBoard, rowPtr, playNum);
			}
			else
			{
				pegBoard[i][j] += 1;
				//showPegs(pegBoard, rowPtr, playNum);
			}
		}
		playNum++;
	}
	return playNum;
}

void showPegs(short ** pegBoard, short * rowPtr, int playNum)
{
	int cursor[2] = {0,0};

	for (int i = 0; i < *rowPtr; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << " " << pegBoard[i][j] << "\t";
		}

		cout << "\n";
	}
}

void gotoXY2(int x, int y)
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

void pauseFunc2()
{
	cout << "\n\t\t\t>>> HIT ENTER TO CONTINUE <<<\n";
	cin.ignore();	
	return; 
}//M

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

bool readTextFile(string fileName)
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
		flag = true;
	}
	fileStream.seekg(0, ios::beg);
	// display records until end-of-file

	cout << "HIGH SCORES\n\n";
	while (!fileStream.eof())
	{
		readCntr++;
		getline(fileStream, rec, '\n');
		if (rec != "")
			cout << readCntr << "\t : \t" << rec << "\n";
	}

	fileStream.close();
	cin.ignore();
	return flag;
}

bool writeFile_fstream(double ** scores, int gameNum)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/
	string outputFileName = "HighScores.txt",
		   fileMode;
	bool flag = false;
	double totalScore = 0;
	fstream outputFile;

	if (openFileAppend(outputFile, outputFileName))
	{
		outputFile << scores[0][gameNum] << "\n";
		cout << "Score added to High Scores: " << scores[0][gameNum] << endl;

		flag = true;
		outputFile.close();
	}

	pauseFunc2();

	return flag;		//Go back to where you came from!
}

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