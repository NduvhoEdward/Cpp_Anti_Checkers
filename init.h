#ifndef INIT_H
#define INIT_H

// remove unneccessary files to time and improve efficiency
#include "checkers.h"
#include <vector>

using namespace std;

// creating the boards (Board for piece and nBoard for positions)
void checkers::BOARDS(int boardSize,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
    int counter=1;
    for (int i=0; i<boardSize; i++)
    {
        vector<char> Board_temp;
        vector<int> nBoard_temp;
        for (int j=0; j<boardSize; j++)
        {
            if((i%2==0&&j%2!=0&&i<(boardSize-1)/2)||(i%2!=0&&j%2==0&&i<(boardSize-1)/2))
            {
                Board_temp.push_back('X');
                nBoard_temp.push_back(counter);
            }
            else if((i%2==0&&j%2!=0&&i>boardSize/2)||(i%2!=0&&j%2==0&&i>boardSize/2))
            {
                Board_temp.push_back('O');
                nBoard_temp.push_back(counter);
            }
            else if(((i%2==0&&j%2!=0)||(i%2!=0&&j%2==0)))//||((i%2==0&&j%2!=0)||(i%2!=0&&j%2==0)))
            {
                Board_temp.push_back(' ');
                nBoard_temp.push_back(counter);
            }
            else if(i<boardSize && j<boardSize)
            {
                Board_temp.push_back(' ');
                nBoard_temp.push_back(0);
                counter--;
            }
            counter++;
        }
        Board.push_back(Board_temp);
        nBoard.push_back(nBoard_temp);
    }
}

#endif
