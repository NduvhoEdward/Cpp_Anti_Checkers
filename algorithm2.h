#ifndef ALGORITHM2_H
#define ALGORITHM2_H

#include "checkers.h"
#include <vector>


using namespace std;

void checkers::ALGORITHM_2(char &turn,int boardSize,ofstream &f_out,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
	int pos=0,row=0,i=0,j=0;
	vector<int> position;
    if (!list_1.empty())
    {
        // taking the first move available for now
        f_out <<"p2 "<<list_1[0][0]<<"x"<<list_1[0][2]<<"("<<list_1[0][1]<<")"<<endl;
        remv_one(turn,boardSize,pos,i,j,row,position,list_1,Board,nBoard);
    }
    else if (!list_2.empty())
    {
        // taking the first move available for now
        f_out <<"p2 "<<list_2[0][0]<<"x"<<list_2[0][2]<<"("<<list_2[0][1]<<")"<<list_2[0][2]<<"x"<<list_2[0][4]<<"("<<list_2[0][3]<<")"<<endl;
        remv_two(turn,boardSize,pos,i,j,row,position,list_2,Board,nBoard);
    }
    else if (!list_0.empty())
    {
    	f_out <<"p2 "<<list_0[0][0]<<"-"<<list_0[0][1]<<endl;
    	//cout <<"p2 "<<list_0[0][0]<<"-"<<list_0[0][1]<<endl;
    	remv_none(turn,boardSize,pos,i,j,row,position,list_0,Board,nBoard);
    }
}
void checkers::SEARCH_2(int boardSize,vector<vector<char>> &Board,vector<vector<int>> &nBoard,char &turn,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0)
{
    int counter1=0,counter2=0;

    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardSize; j++)
        {
            if(Board[i][j]=='O')
            {
                UpLeft(i,j,counter1,counter2,list_3,list_2,list_1,list_0,Board,nBoard);
                UpRight(i,j,boardSize,counter1,counter2,list_3,list_2,list_1,list_0,Board,nBoard);
            }
        }
    }
}
void checkers::UpRight(int i,int j,int boardSize,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
    vector<int> tempVect;
    //////cout << "in DownLeft" << endl;
    if(i>0&&j<boardSize-1)        // making sure it doesnt search above the board.. ie. (i-1)>Board(0-1)()>Board[-1]
    {
        if(Board[i-1][j+1]==' ')
        {
            //load the coordinates
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j+1]);
            list_0.push_back(tempVect);
            return;
        }
    }
    if(i>3&&j<boardSize-4)
    {
        if(Board[i-1][j+1]=='X'&&Board[i-2][j+2]==' '&&Board[i-3][j+3]=='X'&&Board[i-4][j+4]==' ')
        {
            //load the coordinates
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j+1]);
            tempVect.push_back(nBoard[i-2][j+2]);
            tempVect.push_back(nBoard[i-3][j+3]);
            tempVect.push_back(nBoard[i-4][j+4]);
            list_2.push_back(tempVect); 
        }
    }
    if (i>3&&j<boardSize-2)
    {
        if(Board[i-1][j+1]=='X'&&Board[i-2][j+2]==' '&&Board[i-3][j+1]=='X'&&Board[i-4][j]==' ')
        {
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j+1]);
            tempVect.push_back(nBoard[i-2][j+2]);
            tempVect.push_back(nBoard[i-3][j+1]);
            tempVect.push_back(nBoard[i-4][j]);
            list_2.push_back(tempVect); 
        }
    }

    if(list_2.empty()&&i>2&&j<boardSize-2)
    {
        if(Board[i-1][j+1]=='X' && Board[i-2][j+2]==' ')
        {
            //load the coordinates
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j+1]);
            tempVect.push_back(nBoard[i-2][j+2]);
            list_1.push_back(tempVect); 
        }
    }
}
void checkers::UpLeft(int i,int j,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
    vector<int> tempVect;
    if(i>0&&j>0)        // making sure it doesnt search above the board.. ie. (i-1)>Board(0-1)()>Board[-1]
    {
        if(Board[i-1][j-1]==' ')
        {
            //load the coordinates
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j-1]);
            list_0.push_back(tempVect);
            return;
        }
    }
    if(i>3&&j>3)
    {
        if(Board[i-1][j-1]=='X'&&Board[i-2][j-2]==' '&&Board[i-3][j-3]=='X'&&Board[i-4][j-4]==' ')
        {
            //load the coordinates
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j-1]);
            tempVect.push_back(nBoard[i-2][j-2]);
            tempVect.push_back(nBoard[i-3][j-3]);
            tempVect.push_back(nBoard[i-4][j-4]);
            list_2.push_back(tempVect); 
        }
    }
    if (i>3&&j>1)
    {
        if(Board[i-1][j-1]=='X'&&Board[i-2][j-2]==' '&&Board[i-3][j-1]=='X'&&Board[i-4][j]==' ')
        {
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j-1]);
            tempVect.push_back(nBoard[i-2][j-2]);
            tempVect.push_back(nBoard[i-3][j-1]);
            tempVect.push_back(nBoard[i-4][j]);
            list_2.push_back(tempVect); 
        }
    }
    if(list_2.empty()&&i>1&&j>1)
    {
        if(Board[i-1][j-1]=='X' && Board[i-2][j-2]==' ')
        {
            //load the coordinates
            tempVect={};
            tempVect.push_back(nBoard[i][j]);
            tempVect.push_back(nBoard[i-1][j-1]);
            tempVect.push_back(nBoard[i-2][j-2]);
            list_1.push_back(tempVect); 
        }
    }
}

#endif
