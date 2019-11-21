#include "Reversi.h"

int main()
{
	UserStruct  userValues;										// STRUCT THAT SAVES VALUES OF USER
	int		    arrnBridges[8] = { 0,0,0,0,0,0,0,0 };			// RESET BRIDGE ARR (VECTOR array)
	ArrSlot		arrReversiBoard;								// ARRAY OF 10 BY 10 THAT USE FOR THE BOARD AND SECURITY WALL
	int			bOpenSave;										// bool
	int			bSaveGame = 0;
	printf("   WELCOME TO REVERSI SIMULATOR ! \n");
	printf("\nPress 1 : To open an Existing File\nPress 2 : To start a new game\n");
	scanf("%d", &bOpenSave);
	
	if (bOpenSave == 1)								// if the user chose to open saved game
	{
		ReadFromFile(&userValues, arrReversiBoard);	// open saved game
		SwitchTurn(&userValues);
	}
	else
	{												// if the user chose new game
		init(arrReversiBoard, &userValues);				// reset the board
		HelpInit(arrReversiBoard);						// help to reset the game
	}
	
	while (!GameOver(userValues, arrReversiBoard) && !bSaveGame) // while the game is not over (no points remaind) 
																  // or the user chose to save the game
	{
		SwitchTurn(&userValues);				// switching turn every step
		system("cls");							// clear the screen
		PrintBoard(arrReversiBoard);			// printing the reversi board

		if (userValues.color == WHITE)
			printf("   WHITE TURN\n");
		if (userValues.color == BLACK)
			printf("   BLACK TURN\n");

		do
			// LOOP THAT CONTINUES UNTILL THE USER PUT INDEXES THAT CAN BE FILLED IN THE BOARD 
			// ( is valid and can make a bridge )
		{
			PutLocation(&userValues);
			if (userValues.nX != -999 &&
				userValues.nY != -999)									// if the user dont want to save the game 
				ScanForBridges(arrnBridges, arrReversiBoard, userValues);  // checking for bridges with the new X and Y input
		} 
		while (!CanPut(arrnBridges, arrReversiBoard, userValues));

		if (userValues.nX == -999 ||	 // if the user chose to save the game 
			userValues.nY == -999)
			bSaveGame = 1;		 	  	 // boolean bSaveGame is true
		else							 // the game continues
		{
			PutDisk(arrReversiBoard, &userValues);					//it put the new Disk in X and Y input
			FillBridges(arrnBridges, arrReversiBoard, userValues); // it fill all the bridges in corrent X and Y
		}
	}

	if (bSaveGame)
	{						  // if the user didn't finished the game but clicked to save the to file
		SaveToFile(userValues, arrReversiBoard); // saving the corrent board to file with the name of user input
	}

	getchar();
	getchar();
	return 0;								  // returning 0 if there in no errors in the program
}
