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
***************************************************************/

#include "MenuHeader.h" 
//VERY IMPORTANT: FOR HEADER FILES TO BE PACKAGED WITH THE FILE CONTAINING A main(),
//				  THE main()  --in this case, source.cpp-- MUST INCLUDE THE HEADER FILE 
//				  (i.e., #include "CustomFunctionsHEADER.h")

using namespace std; // using standard namespace

int main()
{
	welcome(); //A
	menuDisplay();
}