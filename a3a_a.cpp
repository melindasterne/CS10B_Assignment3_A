//Assignment a3a_a written by Melinda Sterne

/*
	this program takes a user entered text file, validates that the file opens succesfully, reads the text in said file, outputs it to the console, then outputs a Caesar cipher translation of the text to the console and a user entered output file before closing both the input and output file.  The program then prompts the user if they want to use the program again or exit. 
	
	INPUT:  This program requires the user to enter a txt file and an output file
	OUTPUT: This program outputs ciphered code to the console and an output file
	VALIDATION:  This program check to see if the input file stream  is in fail state.  If it is, the program will prompt the user and notify them of the issue then prompt user for a valid file.
*/
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
//ROT13
//a value returning function that returns the translated character
char rot13(/*in*/ char letter);
//a void function that writes the translated character to the console and an output file
void writeTranslatedChar(/*in*/char letter, /*out*/ ofstream& outFile);

int main()
{
	//variable declarations
	string word;
	string fileName;
	string printFileName;
	ifstream inFile;
	ofstream outFile;
	char again = 'Y';
	char character = 0;	

	//initial program format output
	cout << "*****************************************" << endl;
	cout << "ROT13 - A Caesar cipher program" << endl;
	cout << "*****************************************" << endl;	

	do
	{
		//open file
		cout << "Enter the name of a text file with alpha characters to convert: ";
		cin >> fileName;
		cout << "Enter the data output file to store Caesar cipher translated text: ";
		cin >> printFileName;
		outFile.open(printFileName);
		//validate file did not open in failstate
		while(!inFile)//file not found
		{
			//clear buffer then prompt user for valid filename
			inFile.clear();
			inFile.ignore(200, '\n');
			cout << " File not found. Please retype valid filename: ";
			cin >> fileName;
	
			inFile.open(fileName);
		}
	
		inFile.open(fileName);
		cout << fileName << " data read:" << endl;
		cout << "-------------------------------------" << endl;
		//iterate through file to output initial file read
		while(inFile.get(character))
		{
			cout << character;
		}
		cout << "-------------------------------------" << endl;
		//go to the begining of the file
		inFile.clear();
		inFile.seekg(0);
		//output ciphered text
		cout << printFileName << " data converted and stored:" << endl;
		cout << "-------------------------------------" << endl;
		//read file data and translate
		while(inFile.get(character))
		{
			character = rot13(character);
			writeTranslatedChar(character, outFile);
		}
		//close opend file
		inFile.close();
		outFile.close();
		//clear buffer
		inFile.clear();
		inFile.ignore(200, '\n');
		cout << "-------------------------------------" << endl;
		//prompt user to run program again
		cout << "Great! Do you want to try another file to convert to ROT13 (y/n)? ";
		cin >> again;
		cout << endl;
		//validate if user entered correct option to run program again or terminate
		while((again == 'y')+(again =='Y')+(again=='n')+(again=='N')== false)
		{
			
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Invalid input, please enter y/n to try again or quit: ";
			cin >> again;
		}
		again = toupper(again);
	}
	while(again == 'Y');	

	return 0;
}
//*****************************************************************************************
//This function takes a char data type and returns a char upercase data type which is 13
//values away from it depending on its value.  If the char dat type passed to this function
//is a newline, period, or space, this function will return these three data types as is
//*****************************************************************************************
char rot13(/*in*/ char letter)
//PRE:  This function requires a char data type is passed to it
//POST: This Function returns a char data type
{
	//change character to upper case as long as it's not a new line, space, or period
	if((letter == 32)+(letter == 46)+(letter == 10) == false)
	{
		letter = toupper(letter);
	}
	// return letter if it's a new line, space, or period
	if((letter == 32)+(letter == 46)+(letter == 10) == true)
	{
		return letter;
	}
	//return if char is between A-M
	else if(letter < 78)
	{
		letter += 13;
		return letter;
	}
	//return if char is between N-Z
	else
	{
		letter-= 13;
		return letter;
	} 

}
//*****************************************************************************************
//This function takes prints to the console and writes to a file one char data type at a
// time
//*****************************************************************************************
void writeTranslatedChar(/*in*/char letter, /*out*/ ofstream& outFile)
//PRE: char and ofstream have been declared and validated
//POST: char has been printed to console and external file
{
	cout << letter;
	outFile << letter;

}

//******************************************SAMPLE RUN*************************************
/*
*****************************************
ROT13 - A Caesar cipher program
*****************************************
Enter the name of a text file with alpha characters to convert: sometext.txt
Enter the data output file to store Caesar cipher translated text: output3.txt
sometext.txt data read:
-------------------------------------
Now is the time for all good men 
and women to come 
to the aid of their party.
-------------------------------------
output3.txt data converted and stored:
-------------------------------------
ABJ VF GUR GVZR SBE NYY TBBQ ZRA 
NAQ JBZRA GB PBZR 
GB GUR NVQ BS GURVE CNEGL.
-------------------------------------
Great! Do you want to try another file to convert to ROT13 (y/n)? n
*/
//******************************************SAMPLE RUN*************************************
