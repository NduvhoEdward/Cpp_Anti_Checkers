#ifndef CHECKERS_H
#define CHECKERS_H

#include <fstream>
#include <vector>


using namespace std;

// class def..

class checkers
{
public:
	void PLAY(ifstream &f_in,ofstream &f_out);
private:
	void BOARDS(int boardSize, vector<vector<char>> &Board, vector<vector<int>> &nBoard);
	int  MOVES(int boardSize,vector<vector<int>>&,vector<vector<int>>&,vector<vector<int>>&,vector<vector<int>>&,vector<vector<char>>&,vector<vector<int>>&,char&);
	void SEARCH_1(int boardSize,vector<vector<char>> &Board,vector<vector<int>> &nBoard,char &turn,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0);
	void SEARCH_2(int boardSize,vector<vector<char>> &Board,vector<vector<int>> &nBoard,char &turn,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0);
	void DownLeft(int i,int j,int &boardSize,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	void DownRight(int i,int j,int boardSize,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	void UpLeft(int i,int j,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	void UpRight(int i,int j,int boardSize,int& counter1,int& counter2,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	void disp(int bs,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	int  winStatus(int boardSize,char &turn,vector<vector<int>>& list_0,vector<vector<char>> &Board);
	int  find_pos(int pos,int boardSize,vector<int> &position,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	void remv_one(char &turn,int boardSize,int pos,int &i,int &j,int &rand_move,vector<int> position,vector<vector<int>>&list_1,vector<vector<char>>&Board,vector<vector<int>>&nBoard);
	void remv_two(char &turn,int boardSize,int pos,int &i,int &j,int &rand_move,vector<int> position,vector<vector<int>>&list_2,vector<vector<char>>&Board,vector<vector<int>>&nBoard);
	void remv_none(char &turn,int boardSize,int pos,int &i,int &j,int &rand_move,vector<int> position,vector<vector<int>>&list_1,vector<vector<char>>&Board,vector<vector<int>>&nBoard);
	void ALGORITHM_1(char &turn,int boardSize,ofstream &f_out,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);
	void ALGORITHM_2(char &turn,int boardSize,ofstream &f_out,vector<vector<int>>& list_3,vector<vector<int>>& list_2,vector<vector<int>>& list_1,vector<vector<int>>& list_0,vector<vector<char>> &Board,vector<vector<int>> &nBoard);	

};

#endif

