#include <stdio.h>
#include <stdlib.h>  // for system () func
/*************** This First Project in Advanced C Udemy Course *************/
/*************** TicTacToe Game *****************************/

/************** Defined Macros ***********************/
#define PLAYER_ONE  'X'
#define PLAYER_TWO  'O'
#define NO_WINNER   'N'

#define CELL_BUSY 0xFE
#define INVALID_CELL 0xFF

/************ Global Variables *************/
char playground[5][5] = {{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '},{' ',' ',' ',' ',' '}};

/********** Functions Prototype ************/
/*********                     ***********/
void render_playground(void);
int get_player_input(void);
char judge(void);
/*******************************************/


int main(void)
{
	int num_empty_cells = 25;
	char winner;
	char current_player = PLAYER_ONE;
	int choice;
	int msg=0;
	while(num_empty_cells != 0)
	{
		winner = judge();
		render_playground();
		if(msg == CELL_BUSY)
		{
			printf("The selected cell is already selected before. Please try another cell\n");
		}
		else if(msg == INVALID_CELL)
		{
			printf("The selected cell is invalid. Please try another cell number\n");
		}
		if(winner != NO_WINNER)
		{
			printf("%c has won the game !\n",winner);
			return 0;
		}
		choice = get_player_input();
		if(choice == CELL_BUSY || choice == INVALID_CELL)
		{
			msg  = choice;
		}
		else{
			playground[choice/10 -1][choice%10 -1] = current_player;
			current_player = current_player == PLAYER_ONE ? PLAYER_TWO:PLAYER_ONE;
			num_empty_cells--;
		}
	}
	return 0;
}
void render_playground(void){
	
	system("cls");
	printf("\n");
	for(int i=0; i<5; i++)
	{
		printf("--------------------\n");
		printf("%c | %c | %c | %c | %c |\n",playground[i][0],playground[i][1],playground[i][2],playground[i][3],playground[i][4]);
	}
}
int get_player_input(void){
	
	int choice ;
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
			if(playground[(choice / 10) -1 ][(choice % 10) -1 ] != ' ')
			{
				return CELL_BUSY;
			}
			break;
		default :
				return INVALID_CELL;
				break;
	}
	return choice;
}
char judge(void){
	
	//diagonal Check 
	if((playground[0][0] == playground[1][1])&& (playground[1][1] == playground[2][2]) && (playground[2][2] == playground[3][3]) && (playground[3][3] == playground[4][4]))
	{
		if(playground[0][0] != ' ')
		{
			return playground[0][0];
		}
	}
	// for other diagnal
	if((playground[0][4] == playground[1][3])&& (playground[1][3] == playground[2][2])&&(playground[2][2] == playground[3][1])&&(playground[3][1] == playground[4][0]))
	{
		if(playground[1][3] != ' ')
		{
			return playground[1][1];
		}
	}
	// rows and cols check
	for(int i=0; i<5; i++)
	{
		if((playground[i][0] == playground[i][1]) && (playground[i][1] == playground[i][2])&&(playground[i][2] == playground[i][3])&&(playground[i][3] == playground[i][4]))
		{
			if(playground[i][0] != ' ')
			{
				return playground[i][0];
			}
		}
		
		if((playground[0][i] == playground[1][i]) && (playground[1][i] == playground[2][i]) && (playground[2][i] == playground[3][i])&& (playground[3][i] == playground[4][i]))
		{
			if(playground[i][0] != ' ')
			{
				return playground[0][i];
			}
		}
	}
	return NO_WINNER;
}