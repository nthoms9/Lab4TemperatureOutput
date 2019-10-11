/*
Nick Thoms
C++ 2019
Due: 10/10/19
Lab 4 Temperature Output
Description: This program will take temperatures from a file and output them to 
             a bar chart.It will be able to determine if a temperatue is valid
			 and end the program if the file stream is invalid.
*/

#include<iostream> //iostream is included 
#include<fstream>  //fstream is included to deal with file input
#include<iomanip>  //iomanip is included for th set with function

using namespace std;

void header(); //preconditions:the program runs normally without returning error code 1
               //postconditions: text is outputted to the screen then flow of control
               //                continues

void positiveData(float); //preconditions: "tempData" must be have a value, the file 
                          //                stream must be valid, and "tempData" will
                          //                meet the assertion tempData >= 1.5
                          //postconditions: "tempDdta" will be outputted to the screen
                          //                then a count controlled loop will iniate
                          //                and stars will be outputted flow of control
                          //                will return to the main function

void negativeData(float); //preconditions: "tempData" must be have a value, the file 
                          //               stream must be valid, and "tempData" will
                          //               meet the assertion tempData <= 1.5
                          //postconditions:"tempDdta" will be outputted to the screen
                          //               then a count controlled loop will iniate
                          //               and stars will be outputted flow of control
                          //               will return to the main function
int main() 
{
	float tempData; //creates a variable for temperatures from the file to be stored

	/*The file name is stored into a string "tempInput then the file stream "inFile" is b
	  created and opened*/
	string tempInput = "C:/Users/THOMS4/Documents/C++ Projects/Lab4/tempInput.dat";
	ifstream inFile;
	inFile.open(tempInput);

	if (!inFile) //This if statement's purpose is check if the file stream is valid 
	{            //if it is invalid the user will be prompeted to check the file name
		         //then the program will end with code 1
		cout << "Cannot locate file. Please double check the file name.";
		return 1;
	}

	inFile >> tempData; //priming read where data from the file is stored into "tempData"

	if (!inFile)  //This statement checks for invalid character inputs or the end of
	{             //the file then prompts user and ends the program with code 0
		cout << "Cannot read file data: End of File or Invalid Input. (Please do not use characters.)" << endl;
		return 0;
	}

	header(); // calls the "header" function

	while(inFile) // loop test for an end of file controll loop that displays the bar
	{             // chart to the screen. This loop repeats as long as the file stream 
		          // is valid
		
		if (tempData < -30 || tempData > 120) //control structure that evaluates whether
		{                                     // "tempData" is within the valid range
		cout << setw(8)<< tempData << " is an invalid temperature" << endl;
		}
		 else if (tempData >= 1.5)  //Nested if statement that calls the function
		{                           //"positiveData" if "tempData" is a positive value
			positiveData(tempData); //above 1.5 within the valid range
		}
		else if (tempData <= -1.5)  //Nested if statement that calls the function
		{                           //"negativeData" if "tempData is a negative value
			negativeData(tempData); //less than -1.5 within the valid range
		}
		else if (tempData < 1.5 && tempData > -1.5 )
		{
			cout << setw(8) << tempData;      //Lastly if tempData falls in the range
			cout << "           |" << endl;   // between -1.5 and 1.5 then the following  
		}                                     // will be output to the screen 
		
		 inFile >> tempData; //Second read that exists within the loop giving "tempData"
		                     //another value 

		 if (!inFile) //Ouputs a statement that marks either the end of the file or the
		 {            //end of the validity of the file stream then closes the program
			 cout << "Cannot read file data: End of File or Invalid Input. (Please do not use characters.)" << endl;
			 return 0;
		 }
	}

	return 0;
}

void header() //definition for the "header" function
{
	string space = "        "; 
	
	cout << "Temperatures for 24 hours:" << endl;
	cout << "        " << -30 << space << "0" << space << "30" << space << "60" << space << "90" << space << "120" << endl;
}

void positiveData(float tempData) //defintion for the "positiveData" function
{                                 //uses the "tempData" variable
	int count1 = 1;
	float star = (tempData / float(3)); //the star variable is a representation of 
	                                    //of how many stars should be outputted
	cout << setw(8) << tempData;
	cout << "           |";             //first the function displays the temperature 
	                                    //and a space

	while (count1 <= int(star + 0.5))   //Next a count controlled loop displays the 
	{                                   //amount of stars according to "star" rounded
		cout << "*";                    //to the nearest integer
		count1++;
		if (count1 > int(star + 0.5))
		{
			cout << endl;
		}
	}
}

void negativeData(float tempData) //function definition for "negativeData"
{                                 //uses the "tempData" variable
	int count1 = 1;
	float star = (tempData / float(3)); //the star variable is a representation of 
										//of how many stars should be outputted
	cout << setw(8) << tempData;
	cout << setw(int(star-0.5) + 12);   //this set with statement accounts for the 
	                                    //space between the temperature and the stars

	while (count1 <= int((-(star)) + 0.5)) //this count controlled loop functions just
	{                                      //the one in the "positiveData" function
		cout << "*";                       //the difference is that "star" must be made
		                                   //positive in the loop test
		count1++;
		if (count1 > int((-(star)) + 0.5))
		{
			cout << "|" << endl;
		}
	}
}
