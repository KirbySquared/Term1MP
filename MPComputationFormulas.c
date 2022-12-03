#include <stdio.h>
/*This file contains other functions to be used in the Machine Project*/
int Primechecker();
int BinaryToDecimal();
int PrimeSequenceChecker();
int BinaryToDecimal();
int BinaryChecker();
int DecimalToBinary();
/* 
This function is where the menu 1 Guess the Pattern takes place, 
in the very first input.
Precondition: if the user enters 1 in the main menu, accepted inputs are integers only.
No parameters 
No return since void
*/

//MENU 1 GUESS THE PATTERN STARTS HERE
void guessthepattern()
{
	int input1, input2, input3, input4; 
	int nPattern1, nPattern2, nPattern3, nPatternFinal ,nResult;
	int nBinPattern1, nBinPattern2, nBinPattern3;

	while (input1 != -999) //Loops while first input is not -999
	{
	nResult = 0;	
	printf("\n\nInput the first number: ");
		scanf("%d", &input1);

	if (input1 != -999) // Gets 2nd, 3rd, and 4th inputs while first input is not -999
		{
	printf("Input the second number: ");
		scanf("%d", &input2);
	printf("Input the third number: ");
		scanf("%d", &input3);
	printf("Input the fourth number: ");
		scanf("%d", &input4);
	
	nPattern1 = input2 - input1;
	nPattern2 = input3 - input2; 
	nPattern3 = input4 - input3;
	
	 /* For code debugging 
	printf("\nPattern 1: %d", nPattern1);
	printf("\nPattern 2: %d", nPattern2);
	printf("\nPattern 3: %d", nPattern3); */
	
		if ( Primechecker(input1) == 1 && Primechecker(input2) == 1 && Primechecker(input3) == 1 && Primechecker(input4) == 1 )	//Checks if all inputs are prime
			{
				if ( (PrimeSequenceChecker(input1, input2) == 1) && ( (PrimeSequenceChecker(input2, input3) == 1) && PrimeSequenceChecker (input3, input4) == 1) )
				{	//Checks if all prime inputs are sequential or not
					nResult = input4;
					nResult++;
					while (Primechecker (nResult) != 1)
					{
						nResult++;
					}
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: Prime Series");
				}
			}
		if ( BinaryChecker(input1) == 1 && BinaryChecker(input2) == 1 && BinaryChecker(input3) == 1 && BinaryChecker(input4) == 1  ) 
			{ //Binary Series, checks if all inputs are Binary
				nBinPattern1 = BinaryToDecimal(input2) - BinaryToDecimal(input1);
				nBinPattern2 = BinaryToDecimal(input3) - BinaryToDecimal(input2);
				nBinPattern3 = BinaryToDecimal(input4) - BinaryToDecimal(input3);
				if (nBinPattern1 == nBinPattern2 && nBinPattern1 == nBinPattern3 && nBinPattern1 == 1)
				{
					nResult = 1 + BinaryToDecimal(input4);
					nResult = DecimalToBinary(nResult);
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: Binary Series");
				}
				else if (input1 != 0 && input2 != 0 && input3 != 0 && input4 != 0)
				{
					nResult = 1;
					printf("\nAnswer: ?");	
					printf("\tReason/s: No relation!");
				}
			}
		if ( nPattern1 == nPattern2 && nPattern1 == nPattern3 && nPattern1 == 2 ) // Increments of Odd and Even
			{
				nResult = input4 + nPattern1;
				nPatternFinal = nPattern1;
				
				if (nResult % 2 == 0)
				{
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: Increments of %d", nPatternFinal);
					printf("\n\t\t\t  Even series");
				}
				else 
				{
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: Increments of %d", nPatternFinal);
					printf("\n\t\t\t  Odd series");
				}
			}	
		else if ( nPattern1 == nPattern2 && nPattern1 == nPattern3 && nPattern1 == -2) // Decrements of Odd and Even
			{
				nResult = input4 + nPattern1;
				nPatternFinal = nPattern1;
				
				if (nResult % 2 == 0)
				{
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: Decrements of %d", nPatternFinal * -1);
					printf("\n\t\t\t  Even series");
				}
				else 
				{
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: Decrements of %d", nPatternFinal * -1);
					printf("\n\t\t\t  Odd series");
				}
			}
		else if ( nPattern1 == nPattern2 && nPattern1 == nPattern3 && nPattern1 < 0) //Decrement only
			{
				nPatternFinal = nPattern1;
				nResult = input4 + nPatternFinal;
				printf("\nAnswer: %d", nResult);	
				printf("\tReason/s: Decrements of %d", nPatternFinal);
			}	
		else if ( nPattern1 == nPattern2 && nPattern1 == nPattern3 && nPattern1 > 0) //Increment only
			{
				nPatternFinal = nPattern1;
				nResult = input4 + nPatternFinal;
				printf("\nAnswer: %d", nResult);	
				printf("\tReason/s: Increments of %d", nPatternFinal);
			}
		 else if ( (nPattern1 != nPattern2 && nPattern1 != nPattern3 && nResult == 0) || (input1 == input2 && input1 == input3 && input1 == input4) )	
			{ 	 // For *N series, and if all inputs are 0
				 if (input1 == 0 && input2 == 0 && input3 == 0 && input4 == 0)
					{
						nResult = 0;
						printf("\nAnswer: %d", nResult);	
						printf("\tReason/s: *%d sequence", nResult);
					}
				else if (  input1 != 0 && input2 != 0 && input3 != 0 && input4 != 0 && ( (input2 % input1) == (input3 % input2) ) && ( (input3 % input2) == (input4 % input3) ) ) 
					{
						nResult = input4 * (input2 / input1);
						if ( ( input2 == input1 * (input2/input1) ) && ( input3 == input2 * (input2/input1) ) && ( input4 == input3 * (input2/input1) ) ) 
						{
							printf("\nAnswer: %d", nResult);	
							printf("\tReason/s: *%d sequence", input2 / input1);
						}
						else 
						{
							printf("\nAnswer: ?");	
							printf("\tReason/s: No relation!");
						}	
					}
				else if (input1 == -999) //prints a new line since input1 enters in this condition
					{
						printf("\n");
					}
				else 
					{
						printf("\nAnswer: ?");	
						printf("\tReason/s: No relation!");
					}	
			}
		else if ( (nPattern1 != nPattern2 && nPattern1 == nPattern3) ) 
			//For +M +N; -M -N; +M -N; -M +N series			
			{
				if (nPattern1 < 0 && nPattern2 < 0) // -M -N Series
				{
					if (nPattern1 != nPattern2)
					{
						nResult = input4 + nPattern2;
						printf("\nAnswer: %d", nResult);	
						printf("\tReason/s: %d %d sequence", nPattern1, nPattern2);
					}
					else
					{
						printf("\nAnswer: ?");	
						printf("\tReason/s: No relation!");
					}
				}
				else if (nPattern1 >= 0 && nPattern2 < 0) // +M -N Series
				{
					nResult = input4 + nPattern2;
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: +%d %d sequence", nPattern1, nPattern2);
					
				  if (input1 != 0 && input2 != 0 && input3 != 0 && input4 != 0)
				  {
					if ( ( (input2 % input1) == (input3 % input2) ) && ( (input3 % input2) == (input4 % input3) ) )
					{
						if ( ( input2 == input1 * (input2/input1) ) && ( input3 == input2 * (input2/input1) ) && ( input4 == input3 * (input2/input1) ) ) 	
						printf("\n\t\tReason/s: *%d sequence", input2 / input1);
					}
				  }
				}
				else if (nPattern1 < 0 && nPattern2 >= 0) // -M +N Series
				{
					nResult = input4 + nPattern2;
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: %d +%d sequence", nPattern1, nPattern2);
					
				  if (input1 != 0 && input2 != 0 && input3 != 0 && input4 != 0)
				   {
					if ( ((input2 % input1) == (input3 % input2)) && ((input3 % input2) == (input4 % input3)) )
					{	if ( ( input2 == input1 * (input2/input1) ) && ( input3 == input2 * (input2/input1) ) && ( input4 == input3 * (input2/input1) ) )
						printf("\n\t\tReason/s: *%d sequence", input2 / input1);
				  	}
				   }
				}
				else if (nPattern1 >= 0 && nPattern2 >= 0) //+M +N Series
				{
					if (nPattern1 != nPattern2)
					{
					nResult = input4 + nPattern2;
					printf("\nAnswer: %d", nResult);	
					printf("\tReason/s: +%d +%d sequence", nPattern1, nPattern2);
					} 
					else
					{
					printf("\nAnswer: ?");	
					printf("\tReason/s: No relation!");
					}
				}
				else
				{
					printf("\nAnswer: ?");	
					printf("\tReason/s: No relation!");
				}
			}
			else 
			{
				if (nResult == 0)
				{
					printf("\nAnswer: ?");	
					printf("\tReason/s: No relation!");
				}
			}
			 
		} 
	else //This will only print when the first input is -999, marking the end of the program.
	{	
		printf("\nGoing back to 1st main menu. . .\n");
	}
	
	}			
}
//MENU 1 GUESS THE PATTERN MAIN CODE ENDS HERE***************

//MENU 2 INCREMENTS AND DECREMENTS START HERE****************

/* This function is used to compute and show decrements of N according to user input
	Precondition: Decrement value is not negative or 0 and is an integer, and user picked 2nd option in the second menu.
	N should be positive number, N represents the increments / decrements it will do.
	X represents how many values to be generated, X should be greater than or equal to 2 else it will display error if X is not at 
	least 2, else it will go back to second menu. 
	Y represents first number in the series 
No parameters used
No return value since void
*/
void DecrementsN()
{
	int NDecrement, Xnumofvalues, Yfirstnumber;
	printf("\n**********DECREMENTS OF N**********");
	printf("\nEnter the value of N (3 = Decrements of 3):\n");
		scanf("%d", &NDecrement);
	if  (NDecrement > 0)
	{
		printf("\nEnter the value of X (How many numbers should be generated, Minimum of 2):\n");
			scanf("%d", &Xnumofvalues);
			if (Xnumofvalues >= 2)
			{
				printf("\nEnter the value of Y (The starting number to be printed):\n");
					scanf("%d", &Yfirstnumber);
					printf("\nThe numbers are: ");

					for (; Xnumofvalues != 0; Xnumofvalues--)
					{
						printf("%d ", Yfirstnumber);
						Yfirstnumber -= NDecrement;
					}	
					printf("\n**********SERIES ENDS HERE**********");
			}
			else
			{
				printf("\nERROR! INVALID INPUT.\n");
			}
	}
	else 
	{
		printf("\nERROR! INVALID INPUT.\n");
	}	
}

/* This function is used to compute and show increments of N according to user input
	Precondition: Increment value is not negative or 0 and is an integer, and user picked 1st option in the second menu.
	N should be positive number, N represents the increments / decrements it will do.
	X represents how many values to be generated, X should be greater than or equal to 2 else it will display error if X is not at 
	least 2 and N is not a positive number and will go back to second option menu. 
	Y represents first number in the series 
No parameters used
No return value since void
*/
void IncrementsN()
{

	int NIncrement, Xnumofvalues, Yfirstnumber;
	printf("\n**********INCREMENTS OF N**********");
	printf("\nEnter the value of N (3 = Increments of 3):\n");
		scanf("%d", &NIncrement);
	if  (NIncrement > 0)
	{
		printf("\nEnter the value of X (How many numbers should be generated, Minimum of 2):\n");
			scanf("%d", &Xnumofvalues);
			if (Xnumofvalues >= 2)
			{
				printf("\nEnter the value of Y (The starting number to be printed):\n");
					scanf("%d", &Yfirstnumber);
						printf("\nThe numbers are: ");

					for (; Xnumofvalues != 0; Xnumofvalues--)
					{
						printf("%d ", Yfirstnumber);
						Yfirstnumber += NIncrement;
					}
					printf("\n**********SERIES ENDS HERE**********\n");
			}
			else
			{
				printf("\nERROR! INVALID INPUT.\n");
			}
	}
	else
	{
	printf("\nERROR! INVALID INPUT.\n");
	}
}	

/* This function is used to compute and show increments of even numbers by 2, and only accepts even numbers.
	Precondition: User picked 3rd option in the second menu.
	X represents how many values to be generated, X should be greater than or equal to 2 else it will display error if X is not at 
	least 2 and goes back to second menu.
	Y represents first number in the series and only accepts even numbers, if not even, program will end and go back to 2nd menu. 
No parameters used
No return value since void
*/
void IncrementEven()
{
	int Xnumofvalues, Yfirstnumber;

		printf("\n**********INCREMENTS EVEN SERIES**********");
		printf("\nEnter the value of X (How many numbers should be generated, Minimum of 2):\n");
			scanf("%d", &Xnumofvalues);
			if (Xnumofvalues >= 2)
			{
				printf("\nEnter the value of Y (The starting number to be printed):\n");
					scanf("%d", &Yfirstnumber);
				if (Yfirstnumber % 2 == 0)
				{	
						printf("\nThe numbers are: ");

					for (; Xnumofvalues != 0; Xnumofvalues--)
					{
						printf("%d ", Yfirstnumber);
						Yfirstnumber += 2;
					}
						printf("\n**********SERIES ENDS HERE**********\n");
				}
				else 
				{
					printf("\nERROR! INVALID INPUT.\n");
				}		
			}
			else 
			{
				printf("\nERROR! INVALID INPUT.\n");
			}	
}

/* This function is used to compute and show increments of odd numbers by 2, and only accepts odd numbers.
Precondition: User picked 4th option in the second menu.
X represents how many values to be generated, X should be greater than or equal to 2 else it will display error if X is not at 
least 2 and goes back to 2nd menu.
Y represents first number in the series and only accepts odd numbers, if not odd, program will go back to 2nd menu. 
No parameters used
No return value since void
*/
void IncrementOdd()
{
	
	int Xnumofvalues, Yfirstnumber;

		printf("\n**********INCREMENTS ODD SERIES**********");
		printf("\nEnter the value of X (How many numbers should be generated, Minimum of 2):\n");
			scanf("%d", &Xnumofvalues);
			if (Xnumofvalues >= 2)
			{
				printf("\nEnter the value of Y (The starting number to be printed):\n");
					scanf("%d", &Yfirstnumber);
				if (Yfirstnumber % 2 == 1)
				{	
					printf("\nThe numbers are: ");

					for (; Xnumofvalues != 0; Xnumofvalues--)
					{
						printf("%d ", Yfirstnumber);
						Yfirstnumber += 2;
					}
					printf("\n**********SERIES ENDS HERE**********\n");
				}
				else 
				{
					printf("\nERROR! INVALID INPUT.\n");
				}		
			}
			else 
			{
				printf("\nERROR! INVALID INPUT.\n");
			}
}
//MENU 2 INCREMENTS AND DECREMENTS END HERE****************

//MENU 2 PRIME SERIES STARTS HERE****************

/* This function is used to compute and show prime numbers, and only accepts prime numbers.
	Precondition: User picked 5th option in the second menu.
	X represents how many values to be generated, X should be >= 2 else it will display error if X is not at 
	least 2 and goes back to 2nd menu.
	Y represents first number in the series and only accepts prime numbers, if not prime, program will go back to 2nd menu. 
No parameters used
No return value since void
*/
void PrimeSeries()
{
	//In my code, if value returned is 2, number is not prime, if value returned is 1, number is prime.
		int Xnumofvalues, Yfirstnumber;

		printf("\n**********INCREMENTS PRIME SERIES**********");
		printf("\nEnter the value of X (How many numbers should be generated, Minimum of 2):\n");
			scanf("%d", &Xnumofvalues);

			if (Xnumofvalues >= 2)
			{
				printf("\nEnter the value of Y (The starting number must be prime):\n");
					scanf("%d", &Yfirstnumber);  
					
					if ( Primechecker(Yfirstnumber) == 1 )
					{
						printf("\nThe numbers are: ");
						while (Xnumofvalues != 0)
						{
							if ( Primechecker(Yfirstnumber) == 1)
							{
								printf("%d ", Yfirstnumber);
								Yfirstnumber++;
								Xnumofvalues--;
							}
							else
							{
								Yfirstnumber++;
							}
						}
					}
					else
					{
						printf("\nERROR! INVALID INPUT, NUMBER NOT PRIME!\n");
					}
			}
			else 
			{
				printf("\nERROR! INVALID INPUT.\n");
			}
}
//MENU 2 PRIME SERIES ENDS HERE****************

//OTHER FUNCTIONS BEING USED IN THE PROGRAM

/* This function checks if the number in the parameter is prime or not.
Precondition: Parameter value is positive and is an integer.
@param numbertobechecked is the number that will be checked if it is prime or not.
@return 2 if the number is not prime, return 1 if the number is prime.
*/
int Primechecker(int numbertobechecked)
{
	int numbercount = 2;
	int testval = 1; //sentinel data to stop the while loop
	int finalvalue; //if value is 2, number is not prime, if value is 1, number is prime

	if (numbertobechecked == 0 || numbertobechecked == 1 || numbertobechecked < 0)
	{
		return finalvalue = 2;
	}
	else if (numbertobechecked == 2)
	{
		return finalvalue = 1;
	}
	else
	{
		while (testval != 0)
		{
			if (numbertobechecked % numbercount == 0 && numbercount != numbertobechecked)
			{
				return finalvalue = 2;
				testval = 0;
			}
			else if (numbertobechecked % numbercount == 0 && numbercount == numbertobechecked)
			{
				return finalvalue = 1;
				testval = 0;
			}
			else
			{
				numbercount++;
			}
		}
	}
	return 0;
}

/* This function checks if 2 prime numbers are sequential or not.
Precondition: Parameter values are prime, and positive values only.
@param userinput1 is the first input to be compared, userinput2 is the second input to be compared.
@return 0 If the 2 inputs are not sequential, return 1 if the 2 inputs are sequential.
*/
int PrimeSequenceChecker(int userinput1, int userinput2)
{
	int stopval, checkval;
	checkval = 0;
	stopval = 1;
	userinput1++;
	// For Primechecker, if the value is 2, number is not prime; if value is 1, the number is prime.
	// For sequence checking, value returned is 2 if the 2 numbers are not sequential, 1 if two numbers are sequentail.
		while (stopval != 0)
		{ 
			if ( Primechecker(userinput1) == 1 && userinput1 != userinput2 )
			{
				stopval = 0;
				return checkval = 2;	
			}
			else if ( Primechecker(userinput1) == 1 && userinput1 == userinput2)
			{
				stopval = 0;
				return checkval = 1;
			}
			else
			{
			userinput1++;
			}
		}	
		return 0;
}

int BinaryChecker (int inputtoconvert)
{
	int remainder = 0;
	int stopval = 1;
	int valuecheck = 0; //Valuecheck = 2 means number is not binary, Valuecheck = 1 means number is binary.
	
	while (stopval != 0)
	{
		remainder = inputtoconvert % 10;
		
		if ( (remainder == 1 || remainder == 0) && inputtoconvert != 0)
		{
			inputtoconvert /= 10;	
		}
		else if ( (remainder == 1 || remainder == 0) && inputtoconvert == 0 )
		{
			stopval = 0;
			return valuecheck = 1;
		}
		else 
		{	
			stopval = 0;
			return valuecheck = 2;
		}	
	}
	
}

int DecimalToBinary (int inputtoconvert)
{
	int remainder, convertedbinary, counter;
	
	convertedbinary = 0;
	counter = 1;
	
	while (inputtoconvert != 0)
	{
		remainder = inputtoconvert % 2;
		inputtoconvert /= 2;
		convertedbinary += remainder * counter;
		counter *= 10; //Similiar to 10^1, 10^2, 10^3., 1 * 10 = 10, 10 * 10 = 100, 100 * 10 = 1000, etc.
	} 
	
	return convertedbinary;
}

int BinaryToDecimal (int inputtoconvert)
{
	int exponent = 0; 
	int remainder = 0; 
	int converteddecimal = 0;
	
	while (inputtoconvert != 0)
	{
		remainder = inputtoconvert % 10;
		inputtoconvert /= 10; 
		converteddecimal += remainder << exponent; // 1 << 0 is 1, 1 << 1 is 2, 1 << 2 is 4, 1 << 3 is 8, etc...
		exponent++;
	}
	return converteddecimal;
}