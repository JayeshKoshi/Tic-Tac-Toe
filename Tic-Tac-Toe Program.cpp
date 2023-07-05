#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1,n2;

	void menu()
	{	
		cout << "			** TIC TAC TOE **" << endl;
		cout << endl;
		cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << endl;
		cout << "-----------" << endl;
		cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << endl;
		cout << "-----------" << endl;
		cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << endl;
	}
	
	void game()
	{
		int digit;
		
		if (token=='x')
		{
			cout << n1 << endl;
			cout << " Please enter: ";
			cin >> digit;
		}
		if (token=='o')
		{
			cout << n2 << endl;
			cout << " Please enter: ";
			cin >> digit;
		}
		
		if (digit==1)
		{
			row=0;
			column=0;
		}
		if (digit==2)
		{
			row=0;
			column=1;
		}
		if (digit==3)
		{
			row=0;
			column=2;
		}
		if (digit==4)
		{
			row=1;
			column=0;
		}
		if (digit==5)
		{
			row=1;
			column=1;
		}
		if (digit==6)
		{
			row=1;
			column=2;
		}
		if (digit==7)
		{
			row=2;
			column=0;
		}
		if (digit==8)
		{
			row=2;
			column=1;
		}
		if (digit==9)
		{
			row=2;
			column=2;
		}
		else if (digit<0 || digit>9)
		{
			cout << "INVALID!"<<endl;
		}
		
		if (token=='x' && space[row][column] != 'x' && space[row][column] != 'o')
		{
			space[row][column] = 'x';
			token = 'o';
		}
		else if (token=='o' && space[row][column] != 'x' && space[row][column] != 'o')
		{
			space[row][column] = 'o';
			token = 'x';
		}
		else 
		{
			cout << "There is no empty space!" <<endl;
			game();
		}
		menu();
	}
	
	bool endgame()
	{
		for (int i=0;i<3;i++)
		{
			if (space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
			{
				return true;
			}
		}
		if (space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
		{
			return true;
		}
		
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				if (space[i][j] != 'x' && space[i][j] != 'o')
				{
					return false;
				}
			}
		}
		tie = true;
		return false;
	}


int main()
{
	system("Color 1F");
	
	cout << "			*** TIC TAC TOE GAME ***"<<endl;
	cout << "			------------------------	 "<<endl;
	cout << endl;
	cout << "Press Enter to Start :- " << endl;
	getch();
	system("cls");
	
	cout << "			/// Instructions \\\\\\" << endl;
	cout << endl;
	cout << "-> Player one will begin the game."<<endl;
	cout << "-> Match a pair of either three x or o to be declared the winner."<<endl;
	cout << "-> Do not use any other digits other than 0-9 nor any characters."<<endl;
	cout << "-> To fill a box, press the number assigned to the particular box."<<endl;
	cout << endl;
	cout << "Press Enter to continue :- "<<endl;
	getch();
	system("cls");
	
	cout << "Enter the name of the first player: \n";
	getline(cin,n1);
	cout << "Enter the name of the second player: \n";
	getline(cin,n2);
	cout << n1 << " will play first"<<endl;
	cout << n2 << " will play second"<<endl;
	
	while(!endgame())
	{
		menu();
		game();
		endgame();
	}
	
	if (token=='x' && tie==false)
	{
		cout << "** " << n2 << " is the winner **" << endl;
	}
	else if (token=='o' && tie==false)
	{
		cout << "** " << n1 << " is the winner **" << endl;
	}
	else
	cout << "Its a Draw :("<<endl;
}
