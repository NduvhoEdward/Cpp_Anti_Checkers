#ifndef ALGORITHM1_H
#define ALGORITHM1_H

#include "checkers.h"
#include <vector>
#include <ctime>

using namespace std;

void checkers::ALGORITHM_1(char &turn,int boardSize,ofstream &f_out,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
    srand(time(NULL));
    int pos=0,row=0;
    int i=0, j=0;
    vector<int> position;
    // compulsory moves
    if (!list_1.empty()&&!list_2.empty())
    {
        int rand_list=rand()%2;                 // for choosing from which list
        if (rand_list==0)                       // ()()() list_1 list
        {
            int row=rand()%list_1.size();    // for choosing which of the possible moves on the list..1st.2nd...
            f_out <<"p1 "<<list_1[row][0]<<"x"<<list_1[row][2]<<"("<<list_1[row][1]<<")"<<endl;
            //remv_one piece
            remv_one(turn,boardSize,pos,i,j,row,position,list_1,Board,nBoard);

        }
        else if (rand_list==1)                  // ()()()()() list_2 list
        {
            int row=rand()%list_2.size();
            f_out <<"p1 "<<list_2[row][0]<<"x"<<list_2[row][2]<<"("<<list_2[row][1]<<")"<<list_2[row][2]<<"x"<<list_2[row][4]<<"("<<list_2[row][3]<<")"<<endl;
        	// remove two pieces
        	remv_two(turn,boardSize,pos,i,j,row,position,list_2,Board,nBoard);
        }
    }
    else if (!list_1.empty()&&list_2.empty())
    {
        row=rand()%list_1.size();    // for choosing which of the possible moves on the list..1st.2nd...
        f_out <<"p1 "<<list_1[row][0]<<"x"<<list_1[row][2]<<"("<<list_1[row][1]<<")"<<endl;
        remv_one(turn,boardSize,pos,i,j,row,position,list_1,Board,nBoard);
    }
    else if (list_1.empty()&&!list_2.empty())
    {
        row=rand()%list_2.size();
        f_out <<"p1 "<<list_2[row][0]<<"x"<<list_2[row][2]<<"("<<list_2[row][1]<<")"<<list_2[row][2]<<"x"<<list_2[row][4]<<"("<<list_2[row][3]<<")"<<endl;
        remv_two(turn,boardSize,pos,i,j,row,position,list_2,Board,nBoard);
    }
    else if(!list_0.empty())
    {
        row=rand()%list_0.size();
        f_out <<"p1 "<<list_0[row][0]<<"-"<<list_0[row][1]<<endl;
        remv_none(turn,boardSize,pos,i,j,row,position,list_0,Board,nBoard);
    }
}

// a functions needed for seaching player 1 moves
void checkers::SEARCH_1(int boardSize,vector<vector<char>> &Board,vector<vector<int>> &nBoard,char &turn,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0)
{
    int counter1=0,counter2=0;

    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(Board[i][j]=='X')
            {
                DownLeft(i,j,boardSize,counter1,counter2,list_3,list_2,list_1,list_0,Board,nBoard);
                DownRight(i,j,boardSize,counter1,counter2,list_3,list_2,list_1,list_0,Board,nBoard);
            }
        }
    }
}
// a functions needed for seaching player 1 moves
void checkers::DownRight(int i,int j,int boardSize,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
	vector<int> tempVect;
	//
	if(i<(boardSize-1)&&j<boardSize-1)		// making sure it doesnt search above the board.. ie. (i-1)>Board(0-1)()>Board[-1]
	{
	    if(Board[i+1][j+1]==' ')
	    {
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j+1]);
	        list_0.push_back(tempVect);
	        return;
	    }
	}
	if (i<(boardSize-4)&&j<(boardSize-2))
	{
		if (Board[i+1][j+1]=='O'&&Board[i+2][j+2]==' '&&Board[i+3][j+1]=='O'&&Board[i+4][j]==' ')
		{
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j+1]);
	        tempVect.push_back(nBoard[i+2][j+2]);
	        tempVect.push_back(nBoard[i+3][j+1]);
	        tempVect.push_back(nBoard[i+4][j]);
	        list_2.push_back(tempVect);
		}
	}
	if (i<(boardSize-4)&&j<(boardSize-4))
	{
		if (Board[i+1][j+1]=='O'&&Board[i+2][j+2]==' '&&Board[i+3][j+3]=='O'&&Board[i+4][j+4]==' ')
		{
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j+1]);
	        tempVect.push_back(nBoard[i+2][j+2]);
	        tempVect.push_back(nBoard[i+3][j+3]);
	        tempVect.push_back(nBoard[i+4][j+4]);
	        list_2.push_back(tempVect);
		}
	}
	if (list_2.empty()&&i<(boardSize-2)&&j<boardSize-2)
	{
	    if(Board[i+1][j+1]=='O'&& Board[i+2][j+2]==' ')
	    {
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j+1]);
	        tempVect.push_back(nBoard[i+2][j+2]);
	        list_1.push_back(tempVect);
	    }
	}
}

// a functions needed for seaching player 1 moves
void checkers::DownLeft(int i,int j,int &boardSize,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
	vector<int> tempVect;
	////cout << "in DownLeft" << endl;
	if(i<(boardSize-1)&&j>0)		// making sure it doesnt search above the board.. ie. (i-1)>Board(0-1)()>Board[-1]
	{
	    if(Board[i+1][j-1]==' ')
	    {
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j-1]);
	        list_0.push_back(tempVect);
	        return;
	    }
	}
	if(i<(boardSize-4)&&j>1)
	{
	    if(Board[i+1][j-1]=='O'&&Board[i+2][j-2]==' '&&Board[i+3][j-1]=='O'&&Board[i+4][j]==' ')
	    {
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j-1]);
	        tempVect.push_back(nBoard[i+2][j-2]);
	        tempVect.push_back(nBoard[i+3][j-1]);
	        tempVect.push_back(nBoard[i+4][j]);
	        list_2.push_back(tempVect); 
	        ///then maybe call iteself and the
	        ///forward op (after the first takeout)
	    }
	}
	if (i<(boardSize-4)&&j>3)
	{
		if(Board[i+1][j-1]=='O'&&Board[i+2][j-2]==' '&&Board[i+3][j-3]=='O'&&Board[i+4][j-4]==' ')
		{
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j-1]);
	        tempVect.push_back(nBoard[i+2][j-2]);
	        tempVect.push_back(nBoard[i+3][j-3]);
	        tempVect.push_back(nBoard[i+4][j-4]);
	        list_2.push_back(tempVect); 
		}
	}
	//else if(i<(boardSize-2)&&j>1)
	if(list_2.empty()&&i<(boardSize-2)&&j>1)
	{
	    if(Board[i+1][j-1]=='O' && Board[i+2][j-2]==' ')
	    {
	        //load the coordinates
	        tempVect={};
	        tempVect.push_back(nBoard[i][j]);
	        tempVect.push_back(nBoard[i+1][j-1]);
	        tempVect.push_back(nBoard[i+2][j-2]);
	        list_1.push_back(tempVect); 
	        ///then maybe call iteself and the
	        ///forward op (after the first takeout)
	    }
	}
	////cout << "out DownLeft" << endl;
}

// down_

#endif