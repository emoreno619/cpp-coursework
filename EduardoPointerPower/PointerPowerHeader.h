#ifndef POINTERPOWERHEADER_H
#define POINTERPOWERHEADER_H
//VERY IMPORTANT: FUNCTION PROTOTYPES WITHIN A HEADER FILE MUST BE DECLARED AS PART OF A HEADER FILE
//				  NOTICE THAT THERE ARE TWO STATEMENTS HERE:
//															#ifndef CUSTOMFUNCTIONSHEADER_H
//															#define CUSTOMFUNCTIONSHEADER_H
//				  ALSO NOTICE LINE 18:						#endif
//				  THESE MARK THE BEGINNING AND END OF THE HEADER FILE AND WHICH PROTOTYPES WILL BE
//				  INCLUDED WHEN THE HEADER FILE IS INCLUDED AS WELL AS THE NAME THE COMPILER USES TO
//				  IDENTIFY THE HEADER FILE

#include<vector>
#include<iostream>
#include <windows.h>	
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace std;

void createPegs(short ** pegBoard, short * rowPtr, int rows);
int fillPegs(short ** pegBoard, short * rowPtr);
void showPegs(short ** pegBoard, short * rowPtr, int playNum);
void drawHisto(short ** pegBoard, short * rowPtr, double (&scoreArray)[2][10],  int (&dim)[2], double ** scores, int gameNum);
void gotoXY2(int x, int y);
void emptyPegs(short ** pegBoard, short * rowPtr );
void pauseFunc2();
void printConsoleDim(int (&dim)[2]);
void drawHorizon(short ** pegBoard, short * rowPtr, double (&scoreArray)[2][10], int (&dim)[2]);
void drawVertical(short ** pegBoard, short * rowPtr, double (&scoreArray)[2][10], int (&dim)[2]);
void psuedoMain(int gameNum);
bool openFileOut(fstream &file, string outputFileName);
//bool writeFile_fstream(double (&scoreArray)[2][10]);
bool writeFile_fstream(double ** scores, int gameNum);
bool openFileAppend(fstream &file, string outputFileName);
bool readTextFile(string fileName);
#endif POINTERPOWERHEADER_H