//HEADER FILES

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

intigraph();

// FOR PLAYER VS PLAYER
void main1();
int checkwin(char[]);
int st();
void board1(char[]);
int choice1();


void main()
{
 int gd=DETECT,gm;
 int x1=10,y1=10,x2=600,y2=460;
 int n1,i,ns=200;
 clrscr();
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 setbkcolor(9);
 rectangle(x1,y1,x2,y2);
 printf("\n\n\t\t\t TIC TAC TOE \n\n");
 printf("\t\t\t-------------\n\n");
 sound(800);
 delay(500);
 sound(1030);
 delay(400);
 sound(1900);
 delay(300);
 nosound();

 printf("\n     PRESS[1] : PLAYER V/S PLAYER");
 printf("\n     PRESS[2] : EXIT");
 printf("\n\n\t Enter your choice : ");
 scanf("%d",&n1);

 printf("\n");

 switch(n1)

 {

 case 1:
	sound(150);
	delay(100);
	nosound();
 main1();
 break;

 default:
  printf("\t\t\tEXIT...");
  for(i=1;i<=20;i++)
		{
		 sound(ns);
		 delay(100);
		 nosound();
		 ns=ns-10;
		}
 }

 getch();
}

void main1()
{
		int gd=DETECT,gm;
		int x1=10,y1=10,x2=600,y2=460;
 clrscr();
 cleardevice();
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 setbkcolor(9);
 rectangle(x1,y1,x2,y2);

	printf("\n");
	printf("\t\t\tMENU\n");
	printf("\t\t     ----------\n\n");
	printf("\tPRESS[1] : GAME\n");
	printf("\tPRESS[2] : EXIT\n");
choice1();
getch();
closegraph();
}


int choice1()
{
	int choice,i;
	printf("\n\tEnter your choice :>  ");
	scanf("%d",&choice);

	if(choice==1)
	{
		printf("\n\t\t GAME\n");
		 sound(150);
		 delay(100);
		 nosound();
		 st();
	}

	else
	{
		 sound(150);
		 delay(100);
		 nosound();
		  main();
	}
return 0;
}


int st()
{
	char square[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int player = 1,i, choice,n=200,j;
	char mark,as;
	do
	{
	 board1(square);
	 player = (player % 2) ? 1 : 2;

		  printf("\n\tPlayer %d, enter a number:  ", player);
		  scanf("%d", &choice);

		  mark = (player == 1) ? 'X' : 'O';

		  if (choice == 1 && square[1] == '1')
				square[1] = mark;

		  else if (choice == 2 && square[2] == '2')
				square[2] = mark;

		  else if (choice == 3 && square[3] == '3')
				square[3] = mark;

		  else if (choice == 4 && square[4] == '4')
				square[4] = mark;

		  else if (choice == 5 && square[5] == '5')
				square[5] = mark;

		  else if (choice == 6 && square[6] == '6')
				square[6] = mark;

		  else if (choice == 7 && square[7] == '7')
				square[7] = mark;

		  else if (choice == 8 && square[8] == '8')
				square[8] = mark;

		  else if (choice == 9 && square[9] == '9')
				square[9] = mark;

		  else
		  {
			printf("\n\tInvalid move ");
			printf("\n\tPRESS ANY KEY TO REDO >>>");
			player--;
			sound(160);
			delay(100);
			getch();
		  }

		  i = checkwin(square);
		  player++;
		  }
		  while (i ==  - 1);
		  board1(square);

	 if(i == 1)
	 {
		printf("\t==>  Player %d wins.....", --player);
		for(i=1;i<=20;i++)
		{
		 sound(n);
		 delay(100);
		 nosound();
		 n=n-10;
		}
	 }

	 else
	 {
		printf("\t==>  Game draw...");
		for(i=1;i<=20;i++)
		{
		 sound(n);
		 delay(100);
		 nosound();
		 n=n-10;
		}
	 }
return 0;
}

/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin(char square[])
{
	 if (square[1] == square[2] && square[2] == square[3])
		  return 1;

	 else if (square[4] == square[5] && square[5] == square[6])
		  return 1;

	 else if (square[7] == square[8] && square[8] == square[9])
		  return 1;

	 else if (square[1] == square[4] && square[4] == square[7])
		  return 1;

	 else if (square[2] == square[5] && square[5] == square[8])
		  return 1;

	 else if (square[3] == square[6] && square[6] == square[9])
		  return 1;

	 else if (square[1] == square[5] && square[5] == square[9])
		  return 1;

	 else if (square[3] == square[5] && square[5] == square[7])
		  return 1;

	 else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
	 square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]!= '7' && square[8] != '8' && square[9] != '9')
	 return 0;

	 else
	 return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board1(char square[])
{
	 clrscr();
	 cleardevice();
	 printf("\n\tTic Tac Toe\n");
	 printf("\t-----------\n");

	 printf("\t\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");


	 printf("\t");printf("     |     |     \n");
	 printf("\t");printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

		 sound(300);
		 delay(100);
		 nosound();


	 printf("\t_____|_____|_____\n");
	 printf("\t     |     |     \n");

	 printf("\t  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

	 printf("\t_____|_____|_____\n");
	 printf("\t     |     |     \n");

	 printf("\t  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

	 printf("\t     |     |     \n\n");
}

/*******************************************************************
END OF PROJECT
 ********************************************************************/


