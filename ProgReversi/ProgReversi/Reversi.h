
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

enum Slot { WHITE, BLACK, EMPTY, NOTVALID }; // ENUM THAT HELPS TO CHECK WHAT COLOR IS IT 
enum Vector { UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT }; // DIRECTION THAT HELPS TO CHECK FOR BRIDGES
typedef Slot ArrSlot[SIZE][SIZE];

//-----------------------------------------------------------------------------
// 				Reversi Game
// 				------------
//
// General : This program is simulator of the known game "Reversi", To know more 
//			 about the game rules please check it out on the internet.
//			 The game always starts with the white color.
//
// Input : Every player enter location in his turn to put disk in his color.
//		   
//
// Process : The user input in his turn location, the program check if it fits right 
//			 and not breaking any rule, as for that, the program search for potetional
//			 bridges and if it can not find any bridge, the program asking from the user for a new location.
//			 the game ends when not remaind empty spaces in the board.
//			 every turn the user can save the game by typing -999 -999 instead location
//
// Output : Prints the board in every step or change in it. 
//			in the menu, you can chose to open a saved game or to start a new game.
//			In addition, when the game ends it tell who won the game.
//-----------------------------------------------------------------------------
// Programmer : Sharon Pais
// Date : 06/12/2016
//-----------------------------------------------------------------------------


typedef struct // STRUCT THAT HELPS THE FUNCTIONS AND GIVES INFO ABOUT THE CORRENT USER, IT ALSO SAVE A VALUE TO KNOW HOW MUCH EMPTY SPACES EXIST IN THE BOARD 
{
	int		nX, nY;
	Slot	color;
	int		nEmptyPlaces;
}UserStruct, *PtrUserStruct;


typedef struct {
	int		nXboard;
	int		nYboard;
	Slot	color;
}SaveStruct, *PtrSaveStruct;


void init(ArrSlot ioarrBoard, PtrUserStruct oUser);

//-----------------------------------------------------------------------------
// 					   init
// 					---------
//
// General : The function reset all the board to be empty and build a security wall
//
// Parameters :
// ioarrBoard - the Reversi board
// oUser  - the values of the user 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------


void HelpInit(ArrSlot oarrBoard); // METHOD THAT PUT BLACK AND WHITE AT THE CENTER OF THE BOARD -- START OF THE GAME
							  
							  
//-----------------------------------------------------------------------------
// 					   HelpInit
// 					-------------
//
// General : the function help to reset the board by putting Black and White at the center of the board - Start game
//
// Parameters :
// oarrBoard - the Reversi board 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------



void ScanForBridges(int ioarrnVector[], ArrSlot ioarrnBoard, UserStruct ioUser);

//-----------------------------------------------------------------------------
// 					   ScanForBridges
// 					-------------------
//
// General : the function scan for all the bridges that user values can do and if it can build a bridge in certain vector,
//			 the function put 1 in the Vector array in the index of the vector.
//
// Parameters :
// ioarrnVector - Vector array - every index is certain vector (enum value)
// ioarrnBoard	- the Reversi board
// ioUser		- the values of the user 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------

void FillBridges(int ioarrnVector[], ArrSlot ioarrBoard, UserStruct ioUser);


//-----------------------------------------------------------------------------
// 					   FillBridges
// 				    -----------------
//
// General : the function use the Vector array and fill every bridge with the user color ,
//
//
// Parameters :
// ioarrnVector - Vector array - every index is certain vector (enum value)
// ioarrBoard   - the Reversi board
// ioUser		- the values of the user 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------

void PutLocation(PtrUserStruct ioUser);

//-----------------------------------------------------------------------------
// 					   PutLocation
// 				    ------------
//
// General : the function take from the user X and Y to put on the board
//
//
// Parameters :
// ioUser - the values of the user 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------


void PrintBoard(ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   PrintBoard
// 				    ----------------
//
// General : the function printing the board, White - 'W', Black - 'B', Empty - '.'
//
//
// Parameters :
// ioarrBoard - the Reversi board
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------



void PutDisk(ArrSlot ioarrBoard, PtrUserStruct iUser);

//-----------------------------------------------------------------------------
// 					   PutDisk
// 				    -----------
//
// General : the function take the values (X,Y and color) from user(Struct) and put Disk in the board,
//			 in addition, the function decreases empty places value by 1.
//
//
//
// Parameters :
// ioarrBoard - the Reversi board
// iUser	  -  the values of the user 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------

void SwitchTurn(PtrUserStruct ioUser);

//-----------------------------------------------------------------------------
// 					   SwitchTurn
// 				    ----------------
//
// General : the function switch the color value from user(Struct) - WHITE TO BLACK or BLACK TO WHITE
//
//
// Parameters :
// ioUser  -  the values of the user 
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------

int IsExistBridges(int ioarrnBridges[]);

//-----------------------------------------------------------------------------
// 					   IsExistBridge
// 				    -------------------
//
// General : the function searching in the Vector Array if there is existing bridge in user Values 
//
//
// Parameters :
// ioarrnBridges - Vector array that every index is certain vector (by enum value)
// 
// Return Value : 1 if is exist, else 0.
//
//-----------------------------------------------------------------------------


int CanPut(int ioarrnBridges[], ArrSlot ioBoard, UserStruct ioUser);

//-----------------------------------------------------------------------------
// 					   CanPut
// 				    ------------
//
// General : the function check if the user input is proper -
//			 building a bridge and indexes that existing in the board
//
// Parameters :
// ioarrnBridges - Vector array that every index is certain vector (by enum value)
// ioBoard		 - the values of the user
// ioUser		 - the Reversi board
// 
// Return Value : 1 if its proper, else 0.
//
//-----------------------------------------------------------------------------

void PrintWinner(ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   PrintWinner
// 				    ----------------
//
// General : the function check who is the winner (or tie) by counting black and whites
//			 and print the winner.
//
//
// Parameters :
// ioarrBoard   - the Reversi board
// 
// Return Value : None.
//
//-----------------------------------------------------------------------------

int sameColor(ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   sameColor
// 				    ------------
//
// General : the function check if all the board is in the same color.
//
//
// Parameters :
// ioarrBoard   - the Reversi board
// 
// Return Value : return 1 if all the board same color, else 0.
//
//-----------------------------------------------------------------------------

int GameOver(UserStruct ioUser, ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   GameOver
// 				    --------------
//
// General : the function check if the game is over yet - if the board is full or all the board is same color
//
// Parameters :
// ioUser		- the values of the user (for the printWinner function)
// ioarrBoard   - the Reversi board
// 
// Return Value : 1 if its over, else 0(the game continues).
//
//-----------------------------------------------------------------------------

int BuildSaveStruct(SaveStruct ioarrSave[], ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   BuildSaveStruct
// 				    --------------------
//
// General : the function build an array (array of saveStruct) with the current board (for the save function)
//			 the function saves to the array only the Blacks and Whites from the board.
//
// Parameters :
// ioarrSave	- the array struct that helps to save the game.
// ioarrBoard   - the Reversi board.
// 
// Return Value : the size of the array.
//
//-----------------------------------------------------------------------------

void InitSavedGame(SaveStruct ioarrSave[], int ionSize, ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   InitSavedGame
// 				    --------------------
//
// General : the function load saved file to the board
//
// Parameters :
// ioarrSave	- the array struct that helps to save the game
// ionSize		- the size of the array struct (save)
// ioarrBoard   - the Reversi board
// 
// Return Value : None
//
//-----------------------------------------------------------------------------

void SaveToFile(UserStruct ioUser, ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   SaveToFile
// 				    -----------------
//
// General : the function saves the game into a file, file name will be entered by the user.
//
// Parameters :
// ioUser	   - the values of the user
// ioarrBoard  - the Reversi board
// 
// Return Value : None
//
//-----------------------------------------------------------------------------

void ReadFromFile(PtrUserStruct ioUser, ArrSlot ioarrBoard);

//-----------------------------------------------------------------------------
// 					   ReadFromFile
// 				    -----------------
//
// General : the function read from a file that the user enter.
//
// Parameters :
// ioUser		 - the values of the user
// ioarrBoard    - the Reversi board
// 
// Return Value : None
//
//-----------------------------------------------------------------------------