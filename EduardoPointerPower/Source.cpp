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