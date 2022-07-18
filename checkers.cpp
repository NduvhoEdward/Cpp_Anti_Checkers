#include "checkers.h"
#include <iostream>
#include <vector>
#include <cassert>

#include "algorithm1.h"
#include "algorithm2.h"
#include "play.h"
#include "init.h"

using namespace std;

// finding availables moves for a player
int checkers::MOVES(int boardSize,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard,char &turn)
{
    if(turn=='X')
    {
        SEARCH_1(boardSize,Board,nBoard,turn,list_3,list_2,list_1,list_0);
    }
    else if(turn=='O')
    {
        SEARCH_2(boardSize,Board,nBoard,turn,list_3,list_2,list_1,list_0);
    }
    if (list_0.empty() && list_1.empty() && list_2.empty() && list_3.empty())
    {
    	return 0;
    }
    else
    {
    	return 1;
    }
}

// a function for check whether on not any of the players has won
int checkers::winStatus(int boardSize,char &turn,vector<vector<int>>& list_0,vector<vector<char>> &Board)
{
    int counter=0;

    //search for a player's pieces'
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<boardSize;j++)
        {
            if(Board[i][j]==turn)
            {
                counter++;
                break;
            }
        }
    }

    if (counter==0)
    {
        if (turn=='X')
        {
            return 1;
        }
        else if (turn=='O') 
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }

    // letting the compiler know the function will for sure return
    assert(false);
}
