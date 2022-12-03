#include "MPComputationFormulas.c"
void Secondmainmenu();

/* This function contains the 1st main menu
	Precondition: Executed as the program starts. If user inputs any number that is not 3, program will keep looping, if user inputs 1 - 2, 
	program will call the functions and go back to this menu when user is done with that function. If user enters 3, program will end.
No parameter used
No return since void
*/
void Firstmainmenu() //Function for the first main menu
{
	int menuSelect = 0; 
	while (menuSelect != 3)
		{
		printf("\n********** MAIN MENU **********");
		printf("\n");
		printf("\n(1) Guess the pattern and generate the 5th number in a sequence.");
		printf("\n(2) Generating N numbers in a series given a pattern to follow");
		printf("\n(3) Exit the program");
		printf("\n");
		printf("\n*******************************");
		printf("\nSelect your option: ");
			scanf("%d", &menuSelect);
			
			switch (menuSelect)
			{
				case 1: guessthepattern(); break;
				case 2: Secondmainmenu(); break;
				case 3: printf("Exiting program..."); break;
				default: 
				printf("\nInvalid option, please select again."); break;
			}
		}	
}

/* This function contains the 2nd main menu
	Precondition: Executed as the program starts. If user inputs any number that is not 6, program will keep looping, if user inputs 1 - 5, 
	program will call the functions and go back to this menu when user is done with that function. If user enters 6, program will go back to
	first main menu.
	No parameter used
	No return since void
*/
void Secondmainmenu()
{
	int secondmenuselect = 0;
	
	while (secondmenuselect != 6)
	{
		printf("\n*******************************");
		printf("\n");
		printf("\n(1.) Increments of N");
		printf("\n(2.) Decrements of N");
		printf("\n(3.) Incrementing Even Series");
		printf("\n(4.) Incrementing Odd Series");
		printf("\n(5.) Incrementing Prime Series");
		printf("\n(6.) [Go back to Main Menu]");
		printf("\n");
		printf("\n*******************************");
		printf("\nSelect your option: ");
			scanf("%d", &secondmenuselect);
			
			switch (secondmenuselect)
			{
				case 1: IncrementsN(); break;
				case 2: DecrementsN(); break;
				case 3: IncrementEven(); break; 
				case 4: IncrementOdd(); break;
				case 5: PrimeSeries(); break;
				case 6: printf("\nGoing back to main menu. . . "); break;
				default: printf("\nInvalid option, please select again."); break;
			}
	}
}

