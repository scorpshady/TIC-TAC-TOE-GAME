//Lets make a tic tac toe game
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int trackwon = 0;	//  to track if someone has won the game or not
int count = 0;		// to keep the count as soon we get 9 we will stop
char first, second; // to store the characters X or O in them
int position = 0;	// the position to put the X or O in matrix
char matrix[3][3];	//
void fun2()
{
	printf("\n\n");
	printf("First Player: Your turn, enter %c\n", first);
	printf("\n");
}
void fun1()
{
	printf("\n\n");
	if (count == 0)
	{
		printf("First Player: Your turn, enter %c\n", first);
		printf("\n");
	}
	else
	{
		printf("Second Player: Your turn, enter %c\n", second);
		printf("\n");
	}
}

void rules()
{
	system("clear");
	int matrul[3][3];
	int a = 1;
	int sec = 10;
	int i = 0;
	for (i = 1; i < 11; i++)
	{
		system("clear");
		printf("Rules of the game\n\n1> You will be asked for the symbol X or O in the beginning\n\n");
		printf("2> You have to choose one option\n\n");
		printf("3> Then you will be asked to fill the position you want to enter your symbol\n\n");
		printf("4> Then you need to enter numbers from 1 to 9\n\n");
		printf("5> Then accordingly your X or O will be added in the certain row or column\n\n");

		int c = 0, d = 0;
		int e = 1;

		for (c = 0; c < 3; c++)
		{

			for (d = 0; d < 3; d++)
			{
				matrul[c][d] = e;
				e++;
			}
		}

		//design for the matrix is ready
		printf(" ___________\n");
		for (c = 0; c < 3; c++)
		{
			printf("|");
			for (d = 0; d < 3; d++)
			{
				printf(" %d |", matrul[c][d]);
			}

			printf("\n");
			printf("|___|___|___|");
			printf("\n");
		}

		printf("The game begins in %d seconds\n\n", sec);
		sec--;
		sleep(1);
	}

	system("clear");
}

void choose1()
{
	printf("First Player: Choose eiher X or O\n");
	scanf("%c", &first);
}

void spaceformatrix()
{
	printf("                                     ");
}
void printmatrix()
{
	int i = 0, j = 0;
	spaceformatrix();
	printf(" ___________\n");
	for (i = 0; i < 3; i++)
	{
		spaceformatrix();
		printf("|");
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] != first && matrix[i][j] != second)
			{
				printf("   |");
			}
			else
			{
				printf(" %c |", matrix[i][j]);
			}
		}

		printf("\n");
		spaceformatrix();
		printf("|___|___|___|");
		printf("\n");
	}
}

//this fn is to check whether the position is empty or not
int fillinelement(int position)
{
	int i = 0, j = 0;
	int box = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			box++;
			if (position == box)
			{
				if (matrix[i][j] != first && matrix[i][j] != second) 
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
	}
}

//the function to fill the X or O at the given position
void fillXorO()
{
	int i = 0, j = 0;
	//int count = 0;
	int box = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//count++;
			box++;
			if (box == position)
			{
				if (count % 2 == 1) //changing position to count
				{
					matrix[i][j] = first;
				}
				else
				{
					matrix[i][j] = second;
				}
			}
		}
	}
}

//
//this fn is to ask the user to put position he wants to enter the X or O
void positions()
{
	if (count == 0 || count % 2 == 1)
	{
		fun1(); //first player your turn
	}
	else if (count % 2 == 0)
	{
		fun2();
	}

label1:
	printf("Enter the position, you want to choose\n");
	scanf(" %d", &position);
	if (position > 9 || position < 1)
	{
		system("clear");
		printmatrix();
		printf("You have entered the wrong position\n");
		goto label1;
	}
	if (fillinelement(position))
	{
		system("clear");
		//clrscr();
		printmatrix();
		positions();
	}
	else
	{
		count++;
		fillXorO(); // a condition is left when count = 9 then break
	}
}

void checkifwon()
{
	int i = 0, j = 0;
	int counter = 0;
	trackwon = 0;
	for (i = 0; i < 3; i++)
	{
		counter = 0;
		for (j = 0; j < 2; j++)
		{
			if (matrix[i][j + 1] == matrix[i][j])
			{
				counter++;
			}
			else
			{
				break;
			}
		}
		if (counter == 2 && ((matrix[i][j - 1] == first || matrix[i][j - 1] == second)))
		{
			trackwon = 1;
			if (matrix[i][j - 1] == first)
			{
				printf("\nThe first player with %c symbol has won\n", first);
			}
			else if (matrix[i][j - 1] == second)
			{
				printf("\nThe first player with %c symbol has won\n", second);
			}
			return;
		}
	}

	j = -1;
	for (int a = 0; a < 3; a++)
	{
		counter = 0;
		//j = 0;
		j++;
		for (i = 0; i < 2; i++)
		{
			if (matrix[i + 1][j] == matrix[i][j]) //j = 0, j = 1, j = 2
			{
				counter++;
			}
			else
			{
				break;
			}
		}
		if (counter == 2 && ((matrix[i - 1][j] == first || matrix[i - 1][j] == second)))
		{
			trackwon = 1;
			if (matrix[i][j] == first)
			{
				printf("\nThe first player with %c symbol has won\n", first);
			}
			else if (matrix[i][j - 1] == second)
			{
				printf("\nThe first player with %c symbol has won\n", second);
			}
			return;
		}
	}

	i = 0;
	j = 0;
	counter = 0;
	for (i = 0, j = 0; i < 2; i++, j++)
	{
		if (matrix[i + 1][j + 1] == matrix[i][j])
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	if (counter == 2 && ((matrix[i - 1][j - 1] == first || matrix[i - 1][j - 1] == second)))
	{
		trackwon = 1;
		if (matrix[i][j] == first)
		{
			printf("\nThe first player with %c symbol has won\n", first);
		}
		else if (matrix[i][j - 1] == second)
		{
			printf("\nThe first player with %c symbol has won\n", second);
		}
		return;
	}

	counter = 0;
	i = 0;
	j = 0;
	for (i = 0, j = 2; i < 2; i++, j--)
	{
		if (matrix[i + 1][j - 1] == matrix[i][j])
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	if (counter == 2 && ((matrix[i - 1][j + 1] == first || matrix[i - 1][j + 1] == second)))
	{
		trackwon = 1;
		if (matrix[i][j] == first)
		{
			printf("\nThe first player with %c symbol has won\n", first);
		}
		else if (matrix[i][j - 1] == second)
		{
			printf("\nThe first player with %c symbol has won\n", second);
		}
		return;
	}
}

void main()
{

	count = 0;
	trackwon = 0;

	rules();

	// take a int var to keep count of 9 times as soon as we get 9 then stop to
	//check whether there is any row or column that has won the game for you

	do
	{
		//clrscr();
		system("clear");
		choose1();
	} while (first != 'X' && first != 'O');

	//clrscr();
	system("clear");

	if (first == 'X')
	{
		second = 'O';
	}
	else if (first == 'O')
	{
		second = 'X';
	}

	char c;
	do
	{
		if (count > 0)
		{

			printmatrix();
			checkifwon();
		}

		//checkifwon();
		if (trackwon)
		{

		label2:

			printf("\nIf you want to play the game again, press y if you want to exit then press e\n");
			char a;
			scanf(" %c", &a);
			if (a == 'y')
			{
				memset(matrix, 0, sizeof(matrix[0][0]) * 3 * 3);
				main();
			}
			else if (a == 'e')
			{
				exit(1);
			}
			else
			{

				goto label2;
			}
		}
		if (count == 9)
		{
			break;
		}

		positions();

		system("clear");

	} while (count != 10);

	if (trackwon != 1)
	{
		printf("\nNo one has won the game, it is a draw.\n");
	label3:
		printf("\nIf you want to play the game again press y, if you want to exit the game press e\n");
		scanf(" %c", &c);
		if (c == 'y')
		{
			memset(matrix, 0, sizeof(matrix[0][0]) * 3 * 3);
			main();
		}
		else if (c == 'e')
		{
			exit(1);
		}
		else
		{
			goto label3;
		}
	}

	//the game is complete
}
