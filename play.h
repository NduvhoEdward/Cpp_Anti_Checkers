#ifndef PLAY_H
#define PLAY_H

#include "checkers.h"
#include <vector>

using namespace std;

void checkers::PLAY(ifstream &f_in,ofstream &f_out)
{
    // vectors for storing the moves
    vector<vector<int>> list_0;
    vector<vector<int>> list_1;
    vector<vector<int>> list_2;
    vector<vector<int>> list_3;
    int bs=0; //the board size

    while(f_in>>bs)
    {
        // detemine if the input is valid
        if (bs%2!=0 || bs<6 || bs> 12)
        {
            f_out<<"invalid board size"<<endl;
            break;
        }
        // initialising and clearing the boards for storing move and positions
        vector<vector<char>> Board{};
        vector<vector<int>> nBoard{};
        BOARDS(bs, Board, nBoard);          // creating boards of a selected boardsize

        // distplaying the board size on the file
        f_out << bs << endl;
        // selecting the first player
        char turn='X';
        // checking if any player has won
        while(winStatus(bs,turn,list_0,Board)==0)  //-->> (while..)'==0'
        {
            // checking if there are moves for player 1 and play tyem if there are any
            if (MOVES(bs,list_3,list_2,list_1,list_0,Board,nBoard,turn)!=0)
            {
            	ALGORITHM_1(turn,bs,f_out,list_3,list_2,list_1,list_0,Board,nBoard);
            }
            else
                break; 

    	    //clearing the list before player 2 can use them
    	    list_0={}, list_1={}, list_2={}, list_3={};

            // switching player
            turn='O';
            // checking if there are moves for player 1 and play tyem if there are any
            if (winStatus(bs,turn,list_0,Board)==0)//--> '==0' if there's still no win
            {
    	        if (MOVES(bs,list_3,list_2,list_1,list_0,Board,nBoard,turn)!=0)	// get the available moves
    	        {
    	        	ALGORITHM_2(turn,bs,f_out,list_3,list_2,list_1,list_0,Board,nBoard);
    	        }
                else
                    break;
            }
            // switching player
            turn='X';

    	    //clearing the list before player 1 can use them
    	    list_0={}, list_1={}, list_2={}, list_3={};
        }

        //counting pieces left on the board for win or draw detemination
        int p1p=0,p2p=0;
        for (int i = 0; i < bs; i++)
        {
            for (int j = 0; j < bs; j++)
            {
                if (Board[i][j]=='X')
                    p1p++;
                if (Board[i][j]=='O')
                    p2p++;
            }
        }

        //sending the outcome to the file
        f_out <<"tp1 "<<p1p<<endl<<"tp2 "<<p2p<<endl;
        if (p1p==0&&p2p>0)
        {
            f_out <<"wp1"<<endl<<endl;
        }
        if (p1p>0&&p2p==0)
        {
            f_out <<"wp2"<<endl<<endl;
        }
        if (p1p>0&&p2p>0)
        {
            f_out <<"d"<<endl<<endl;
        }
    }
}

// finding the position (int) of a piece
int checkers::find_pos(int pos,int boardSize,vector<int> &position,vector<vector<char>> &Board,vector<vector<int>> &nBoard)
{
	position={};
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (nBoard[i][j]==pos)
			{
				position.push_back(i);
				position.push_back(j);
				return 0;
			}
		}
	}
    // ensuring the compiler the code will return
    assert(false);  
}

// removing one and moving piece after 1-jump
void checkers::remv_one(char &turn,int boardSize,int pos,int &i,int &j,int &rand_move,vector<int> position,vector<vector<int>>&list_1,vector<vector<char>>&Board,vector<vector<int>>&nBoard)
{
    // remove init piece
    pos = list_1[rand_move][0];
    find_pos(pos,boardSize,position,Board,nBoard);
    i = position.at(0);
    j = position.at(1);
    Board[i][j]=' ';
    
    // remove taken piece
    pos = list_1[rand_move][1];
    find_pos(pos,boardSize,position,Board,nBoard);
    i = position.at(0);
    j = position.at(1);
    Board[i][j]=' ';

    // place the piece in the new pos
    pos = list_1[rand_move][2];
    find_pos(pos,boardSize,position,Board,nBoard);
    i = position.at(0);
    j = position.at(1);
    Board[i][j]=turn;
}

// removing 2 and moving one piece after 2-jumps
void checkers::remv_two(char &turn,int boardSize,int pos,int &i,int &j,int &rand_move,vector<int> position,vector<vector<int>>&list_2,vector<vector<char>>&Board,vector<vector<int>>&nBoard)
{
	// remove init piece
	pos = list_2[rand_move][0];
	find_pos(pos,boardSize,position,Board,nBoard);
	i = position.at(0);
	j = position.at(1);
	Board[i][j]=' ';

	// remove taken piece
	pos = list_2[rand_move][1];
	find_pos(pos,boardSize,position,Board,nBoard);
	i = position.at(0);
	j = position.at(1);
	Board[i][j]=' ';

	// remove taken piece 2
	pos = list_2[rand_move][3];
	find_pos(pos,boardSize,position,Board,nBoard);
	i = position.at(0);
	j = position.at(1);
	Board[i][j]=' ';

	// place the piece in the new pos
	pos = list_2[rand_move][4];
	find_pos(pos,boardSize,position,Board,nBoard);
	i = position.at(0);
	j = position.at(1);
	Board[i][j]=turn;
}

// simply moving a piece
void checkers::remv_none(char &turn,int boardSize,int pos,int &i,int &j,int &rand_move,vector<int> position,vector<vector<int>>&list_1,vector<vector<char>>&Board,vector<vector<int>>&nBoard)
{
    // remove init piece
    pos = list_1[rand_move][0];
    find_pos(pos,boardSize,position,Board,nBoard);
    i = position.at(0);
    j = position.at(1);
    Board[i][j]=' ';

    // place the piece in the new pos
    pos = list_1[rand_move][1];
    find_pos(pos,boardSize,position,Board,nBoard);
    i = position.at(0);
    j = position.at(1);
    Board[i][j]=turn;
}

#endif
