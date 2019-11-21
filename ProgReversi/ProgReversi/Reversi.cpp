#include "Reversi.h"

void HelpInit(ArrSlot oarrBoard) // METHOD THAT PUT BLACK AND WHITE AT THE CENTER OF THE BOARD -- START OF THE GAME
{
	oarrBoard[4][4] = WHITE;
	oarrBoard[5][5] = WHITE;
	oarrBoard[4][5] = BLACK;
	oarrBoard[5][4] = BLACK;
}



void init(ArrSlot ioarrBoard, PtrUserStruct oUser) // RESET ALL THE BOARD TO BE EMPTY AND BUILD A SECURITY WALL
{
	oUser->color = BLACK;
	oUser->nX	 = 0;
	oUser->nY	 = 0;
	oUser->nEmptyPlaces = (SIZE - 2) * (SIZE - 2) - 4;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			ioarrBoard[row][col] = NOTVALID;
		}
	}
	//SECURITY WALL
	for (int row = 1; row < SIZE - 1; row++)
	{
		for (int col = 1; col < SIZE - 1; col++)
			ioarrBoard[row][col] = EMPTY;
	}
}



void ScanForBridges(int ioarrnVector[], ArrSlot ioarrnBoard, UserStruct ioUser) // THIS METHOD USE THE ENUM BY FILLING THE VECTORS ARRAY
{
	int nCountLength = 0;
	int nXLocation	 = ioUser.nX - 1;
	int nYLocation   = ioUser.nY;

	//SCAN FOR UP BRIDGE
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nXLocation--;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[UP] = 1;

	//SCAN FOR DOWN BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX + 1;
	nYLocation = ioUser.nY;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nXLocation++;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[DOWN] = 1;

	//SCAN FOR LEFT BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX;
	nYLocation = ioUser.nY - 1;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nYLocation--;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[LEFT] = 1;

	//SCAN FOR RIGHT BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX;
	nYLocation = ioUser.nY + 1;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nYLocation++;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[RIGHT] = 1;

	//SCAN FOR UP-LEFT BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX - 1;
	nYLocation = ioUser.nY - 1;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nXLocation--;
		nYLocation--;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[UPLEFT] = 1;

	//SCAN FOR UP-RIGHT BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX - 1;
	nYLocation = ioUser.nY + 1;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nXLocation--;
		nYLocation++;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[UPRIGHT] = 1;

	//SCAN FOR DOWN-LEFT BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX + 1;
	nYLocation = ioUser.nY - 1;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nXLocation++;
		nYLocation--;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[DOWNLEFT] = 1;

	//SCAN FOR DOWN-RIGHT BRIDGE
	nCountLength = 0;
	nXLocation = ioUser.nX + 1;
	nYLocation = ioUser.nY + 1;
	while (ioarrnBoard[nXLocation][nYLocation] != ioUser.color && ioarrnBoard[nXLocation][nYLocation] != EMPTY &&
		ioarrnBoard[nXLocation][nYLocation] != NOTVALID)
	{
		nCountLength++;
		nXLocation++;
		nYLocation++;
	}
	if (ioarrnBoard[nXLocation][nYLocation] == EMPTY || ioarrnBoard[nXLocation][nYLocation] == NOTVALID)
		nCountLength = 0;
	if (nCountLength > 0)
		ioarrnVector[DOWNRIGHT] = 1;

}


void FillBridges(int ioarrnVector[], ArrSlot ioarrBoard, UserStruct ioUser)
// METHOD THAT GET ARRAY OF VECTORS AND PUT ALL THE BRIDGES THAT NEED TO GET DRAW ON THE BOARD AS THE ARRAY SAY
{
	int nXLocation = ioUser.nX - 1;
	int nYLocation = ioUser.nY;

	//FILLING UP BRIDGE (IF NEEDED)
	if (ioarrnVector[UP])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nXLocation--;
		}
		ioarrnVector[UP] = 0;
	}

	//FILLING DOWN BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX + 1;
	nYLocation = ioUser.nY;

	if (ioarrnVector[DOWN])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nXLocation++;
		}
		ioarrnVector[DOWN] = 0;
	}

	//FILLING LEFT BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX;
	nYLocation = ioUser.nY - 1;
	if (ioarrnVector[LEFT])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nYLocation--;
		}
		ioarrnVector[LEFT] = 0;
	}

	//FILLING RIGHT BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX;
	nYLocation = ioUser.nY + 1;
	if (ioarrnVector[RIGHT])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nYLocation++;
		}
		ioarrnVector[RIGHT] = 0;
	}

	//FILLING UPLEFT BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX - 1;
	nYLocation = ioUser.nY - 1;
	if (ioarrnVector[UPLEFT])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nXLocation--;
			nYLocation--;
		}
		ioarrnVector[UPLEFT] = 0;
	}

	//FILLING UPLEFT BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX - 1;
	nYLocation = ioUser.nY + 1;
	if (ioarrnVector[UPRIGHT])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nXLocation--;
			nYLocation++;
		}
		ioarrnVector[UPRIGHT] = 0;
	}

	//FILLING DOWN-LEFT BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX + 1;
	nYLocation = ioUser.nY - 1;
	if (ioarrnVector[DOWNLEFT])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nXLocation++;
			nYLocation--;
		}
		ioarrnVector[DOWNLEFT] = 0;
	}

	//FILLING DOWN-RIGHT BRIDGE (IF NEEDED)
	nXLocation = ioUser.nX + 1;
	nYLocation = ioUser.nY + 1;
	if (ioarrnVector[DOWNRIGHT])
	{
		while (ioarrBoard[nXLocation][nYLocation] != ioUser.color)
		{
			ioarrBoard[nXLocation][nYLocation] = ioUser.color;
			nXLocation++;
			nYLocation++;
		}
		ioarrnVector[DOWNRIGHT] = 0;
	}


}



void PutLocation(PtrUserStruct ioUser)
{									// TAKE FROM THE USER X AND Y TO PUT ON THE BOARD, DEPENDS WHICH COLOR HE IS
	int nX;
	int nY;
	
	printf("  ENTER X and Y\n");
	scanf("%d %d", &nX, &nY);
	ioUser->nX = nX;
	ioUser->nY = nY;
}



void PrintBoard(ArrSlot ioarrBoard)
{									// PRINTING THE BOARD.
	for (int row = 0; row < SIZE; row++)
	{
		if (row < 9)
			printf(" %d ", row);
		for (int col = 0; col < SIZE; col++)
		{
			if (row == 0)
				if (col > 0 && col < 9)
					printf("%c", '0' + col);
			if (ioarrBoard[row][col] == WHITE)	// printing White as 'W'
				printf("%c", 'W');
			if (ioarrBoard[row][col] == BLACK)	// printing Black as 'B'
				printf("%c", 'B');
			if (ioarrBoard[row][col] == EMPTY)	// printing Empty as '.'
				printf("%c", '.');
			printf(" ");
		}
		printf("\n");
	}
}



void PutDisk(ArrSlot ioarrBoard, PtrUserStruct iUser)
{									// THE METHOD TAKES VALUES (X and Y) FROM UserStruct AND PUT DISK IN THE BOARD
	ioarrBoard[iUser->nX][iUser->nY] = iUser->color;
	iUser->nEmptyPlaces--;
}



void SwitchTurn(PtrUserStruct ioUser)
{									// THE METHOD SWITCH THE VALUE OF COLOR FROM - WHITE TO BLACK or BLACK TO WHITE
	if (ioUser->color == WHITE)
		ioUser->color = BLACK;
	else
		ioUser->color = WHITE;
}



int IsExistBridges(int ioarrnBridges[]) 
{
	int bIsFoundBridge = 0;
	for (int index = 0; (index < 8)&&(!bIsFoundBridge); index++)
	{
		if (ioarrnBridges[index] == 1)
			bIsFoundBridge = 1;
	}
	return bIsFoundBridge;
}



int CanPut(int ioarrnBridges[], ArrSlot ioBoard, UserStruct ioUser)
// CHECK IF SOMETHING EXIST IN THE INDEX FROM USER INPUT AND RETURN TRUE IF YOU CAN PUT ELSE RETURN FALSE
{
	if (ioUser.nX == -999 || ioUser.nY == -999) // FOR THE SAVE FUNCTION
	{
		return 1;
	}

	if ((ioUser.nX > 0 && ioUser.nX < 9 && ioUser.nY > 0 && ioUser.nY < 9)) // if the values is existing in the board
	{ 
		if (ioBoard[ioUser.nX][ioUser.nY] == EMPTY) // check if there is no disk already in the X and Y input
		{
			if (IsExistBridges(ioarrnBridges))
			{
				return 1;
			}
			else
			{
				printf("Your Value doesn't build a bridge\n");
			}
		}
		else
		{
			printf("Your Value isn't Valid\n");
		}
	}
	else
	{
		printf("Your Value isn't exist in the Board\n");
	}

	return 0;
}



void PrintWinner(ArrSlot ioarrBoard)
{
	int nCountWhite = 0;
	int nCountBlack = 0;
	for (int row = 1; row < SIZE - 1; row++)			 // for(x2)loop that counts black and whites
	{
		for (int col = 1; col < SIZE - 1; col++)
		{
			if (ioarrBoard[row][col] == BLACK)
				nCountBlack++;
			if (ioarrBoard[row][col] == WHITE)
				nCountWhite++;
		}
	}
	if (nCountBlack == nCountWhite)
	{
		printf("\n  TIE ! GAMER OVER\n");
	}
	else
	{
		if (nCountBlack > nCountWhite)
			printf("\n  The Winner is BLACK user");
		else
			printf("\n  The Winner is WHITE user");
	}
}



int sameColor(ArrSlot ioarrBoard)
{
	Slot slotTemp = EMPTY;
	for (int row = 0; row < SIZE - 1; row++)
	{
		for (int col = 0; col < SIZE - 1; col++)
		{
			if (ioarrBoard[row][col] != EMPTY)
			{
				if (slotTemp != ioarrBoard[row][col] &&
					slotTemp != EMPTY)
					return 0;
				slotTemp = ioarrBoard[row][col];
			}
		}
	}
	return 1;
}


int GameOver(UserStruct ioUser, ArrSlot ioarrBoard)
{

	if (ioUser.nEmptyPlaces == 0)
	{
		PrintWinner(ioarrBoard);
		return 1;
	}

	if (sameColor(ioarrBoard))
	{
		PrintWinner(ioarrBoard);
		return 1;
	}
	return 0;
}


int BuildSaveStruct(SaveStruct ioarrSave[], ArrSlot ioarrBoard)
{
	int nCount = 0;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (ioarrBoard[row][col] == BLACK)
			{
				ioarrSave[nCount].color = BLACK;
				ioarrSave[nCount].nXboard = row;
				ioarrSave[nCount].nYboard = col;
				nCount++;
			}
			if (ioarrBoard[row][col] == WHITE)
			{
				ioarrSave[nCount].color = WHITE;
				ioarrSave[nCount].nXboard = row;
				ioarrSave[nCount].nYboard = col;
				nCount++;
			}
		}
	}
	return nCount;
}



void InitSavedGame(SaveStruct ioarrSave[], int ionSize, ArrSlot ioarrBoard) // THIS METHOD LOAD THE SAVED FILE TO THE BOARD
{
	int		nXBoard;
	int		nYBoard;
	Slot	color;
	for (int index = 0; index < ionSize; index++)
	{
		nXBoard = ioarrSave[index].nXboard;
		nYBoard = ioarrSave[index].nYboard;
		color = ioarrSave[index].color;
		ioarrBoard[nXBoard][nYBoard] = color;
	}
}



void SaveToFile(UserStruct ioUser, ArrSlot ioarrBoard) // METHOD THAT SAVES THE GAME TO A FILE THAT THE USER ENTER
{ 
	SaveStruct arrsSave[(SIZE - 2)*(SIZE - 2)];

	int nSize = BuildSaveStruct(arrsSave, ioarrBoard);
	int nEmptyPlaces = ioUser.nEmptyPlaces;
	char arrcFileName[120];

	printf("\n Write the name of the file to save the game(.dat)\n");
	scanf("%s", arrcFileName);
	FILE * fp = fopen(arrcFileName, "wb");

	while (fp == NULL) {
		printf("There is a problem with saving the file. try again\n");
		scanf("%s", arrcFileName);
		fp = fopen(arrcFileName, "wb");
	}

	fwrite(&nSize, sizeof(int), 1, fp);
	fwrite(&arrsSave, sizeof(SaveStruct), (SIZE - 2)*(SIZE - 2), fp);
	fwrite(&ioUser.color, sizeof(ioUser.color), 1, fp);
	fwrite(&nEmptyPlaces, sizeof(int), 1, fp);
	fclose(fp);
	printf("\nThe file is saved successfully!\n");
}



void ReadFromFile(PtrUserStruct ioUser, ArrSlot ioarrBoard)
{
	SaveStruct arrsSaved[(SIZE)*(SIZE)];
	Slot	   color;
	char	   arrcFileName[120];
	int		   nSize;
	int		   nEmptyPlaces;

	printf("\n Write the name of the file(.dat)\n");
	scanf("%s", arrcFileName);
	init(ioarrBoard, ioUser);
	FILE * fp = fopen(arrcFileName, "rb");

	while (fp == NULL)
	{
		printf("the Game file does not exist, try again.\n");
		scanf("%s", arrcFileName);
		fp = fopen(arrcFileName, "rb");
	}

	fread(&nSize, sizeof(int), 1, fp);
	fread(&arrsSaved, sizeof(SaveStruct), (SIZE - 2)*(SIZE - 2), fp);
	fread(&color, sizeof(Slot), 1, fp);
	fread(&nEmptyPlaces, sizeof(int), 1, fp);
	fclose(fp);

	InitSavedGame(arrsSaved, nSize, ioarrBoard);
	ioUser->color = color;
	ioUser->nEmptyPlaces = nEmptyPlaces;
}




