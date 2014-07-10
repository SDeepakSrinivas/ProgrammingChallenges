/*
 * ctc.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: SDS
 */

#include<iostream>
using namespace std;

void read_input(char board[10][10])
{

	for(int i=0;i<10;i++)
		for(int j=0;j<=10;j++)
			board[i][j]='.';

for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
		cin>>board[i][j];
}

int check_board_empty(char board[10][10])
{
	int flag=1;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(board[i][j]!='.')
				flag=0;
	return flag;
}

int check_pawn_white(char board[10][10],int m,int n)
{
	if((board[m+1][n-1]=='P')||(board[m+1][n+1]=='P'))
		return 1;
	return 0;
}

int check_pawn_black(char board[10][10],int m,int n)
{
	if((board[m-1][n-1]=='p')||(board[m-1][n+1]=='p'))
		return 1;
	return 0;
}


int check_knight(char board[10][10],int m,int n,char ch)
{
if((board[m+2][n-1]==ch)||(board[m+2][n+1]==ch)||(board[m+1][n-2]==ch)||(board[m+1][n+2]==ch)||(board[m-2][n-1]==ch)||(board[m-2][n+1]==ch)||(board[m-1][n-2]==ch)||(board[m-1][n+2]==ch))
	return 1;
return 0;
}

int check_bishop(char board[10][10],int m,int n,char ch)
{
for(int i=1;(((m+i)<10)&&((n+i)<10));i++)
	if(board[m+i][n+i]=='.')
		continue;
	else if(board[m+i][n+i]==ch)
		return 1;
	else
		break;

for(int i=1;(((m+i)<10)&&((n-i)>0));i++)
	if(board[m+i][n-i]=='.')
		continue;
	else if(board[m+i][n-i]==ch)
		return 1;
	else
		break;

for(int i=1;(((m-i)>0)&&((n-i)>0));i++)
	if(board[m-i][n-i]=='.')
		continue;
	else if(board[m-i][n-i]==ch)
		return 1;
	else
		break;

for(int i=1;(((m-i)>0)&&((n+i)<10));i++)
	if(board[m-i][n+i]=='.')
		continue;
	else if(board[m-i][n+i]==ch)
		return 1;
	else
		break;

return 0;
}

int check_rook(char board[10][10],int m,int n,char ch)
{
	for(int i=1;(n+i)<10;i++)
		if(board[m][n+i]=='.')
			continue;
		else if(board[m][n+i]==ch)
			return 1;
		else
			break;

	for(int i=1;(n-i)>0;i++)
			if(board[m][n-i]=='.')
				continue;
			else if(board[m][n-i]==ch)
				return 1;
			else
				break;

	for(int i=1;(m-i)>0;i++)
				if(board[m-i][n]=='.')
					continue;
				else if(board[m-i][n]==ch)
					return 1;
				else
					break;

	for(int i=1;(m+i)>0;i++)
				if(board[m+i][n]=='.')
					continue;
				else if(board[m+i][n]==ch)
					return 1;
				else
					break;

		return 0;


}

int check_queen(char board[10][10],int m,int n,char ch)
{
	return ((check_bishop(board,m,n,ch))||(check_rook(board,m,n,ch)));
}

int check_king(char board[10][10],int m,int n,char ch)
{
	if((board[m+1][n]==ch)||(board[m+1][n-1]==ch)||(board[m+1][n+1]==ch)||(board[m-1][n]==ch)||(board[m-1][n-1]==ch)||(board[m-1][n+1]==ch)||(board[m][n-1]==ch)||(board[m][n+1]==ch))
		return 1;
	return 0;
}

int check_black(char board[10][10])
{
	int m,n;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			if(board[i][j]=='k')
			{m=i;n=j;}


	return check_pawn_white(board,m,n)||
			check_knight(board,m,n,'N')||
			check_bishop(board,m,n,'B')||
			check_rook(board,m,n,'R')||
			check_queen(board,m,n,'Q')||
			check_king(board,m,n,'K');



//	cout<< check_pawn_white(board,m,n);
//				cout<<check_knight(board,m,n,'N');
//				cout<<check_bishop(board,m,n,'B');
//				cout<<check_rook(board,m,n,'R');
//				cout<<check_queen(board,m,n,'Q');
//				cout<<check_king(board,m,n,'K');

}

int check_white(char board[10][10])
{
	int m,n;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			if(board[i][j]=='K')
			{m=i;n=j;}


	return check_pawn_black(board,m,n)||
			check_knight(board,m,n,'n')||
			check_bishop(board,m,n,'b')||
			check_rook(board,m,n,'r')||
			check_queen(board,m,n,'q')||
			check_king(board,m,n,'k');



//	cout<< check_pawn_white(board,m,n);
//				cout<<check_knight(board,m,n,'N');
//				cout<<check_bishop(board,m,n,'B');
//				cout<<check_rook(board,m,n,'R');
//				cout<<check_queen(board,m,n,'Q');
//				cout<<check_king(board,m,n,'K');

}

int count()
{
	static int n=0;
	n++;
	return n;
}


int main()
{


	while(true)
	{
		char board[10][10];
		read_input(board);
if(check_board_empty(board))
	break;

		int b=check_black(board);
		int w=check_white(board);

	if(b==1)
		cout<<"Game #"<<count()<<": black king is in check."<<"\n";
	else if(w==1)
		cout<<"Game #"<<count()<<": white king is in check."<<"\n";
	else if((b==0)&&(w==0))
		cout<<"Game #"<<count()<<": no king is in check."<<"\n";


	}
	return 0;
}


