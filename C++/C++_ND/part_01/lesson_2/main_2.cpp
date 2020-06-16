#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::vector;
using std::string;
using std::istringstream;

enum class State {kEmpty, kObstacle};

/*
 ** CellString return different state of board
*/
string CellString(State cell)
{
	/*	
	switch(cell) {
		case State::kObstacle: return "⛰️   ";
		defalut: return "0 ";
	}
	*/
	if(cell == State::kEmpty) {
		return "0   ";
	} else {
		return "⛰️   ";
	}
}

/*
 ** Parse line string, store interger
*/
vector <State> ParseLine(string s)
{
	istringstream line(s);
	
	vector <State> row;	
	int n;
	char c;

	while(line >> n >> c) {
		if(n == 0) {
			cout << "0,";
			row.push_back(State::kEmpty);
		} else {
			cout << "1,";
			row.push_back(State::kObstacle);
		}
	}
	cout << "\n";
	return row;
}

/*
 ** Read board from file
*/
vector <vector <State> > ReadBoardFile(string board_path)
{
	std::ifstream grid;
	grid.open(board_path);
	
	vector <vector <State> > board {};
	
	if(grid) {
		string line;
		while(getline(grid, line)) {
			board.push_back(ParseLine(line));
		}
	} else {
		cout << "Unable to open file \n";
	}
	
	return board;
}

/*
 ** Print the board 
*/	
void PrintBoard(vector< vector<State> > grid)
{
	for(int i = 0; i < grid.size(); ++i) {
		for(int j = 0; j < grid[i].size(); ++j) {
			cout << CellString(grid[i][j]);
		}
		cout << "\n";
	}
	
	return;
}
int main()
{
	//Initialize the board
	vector< vector<State> > board;
	
	board = ReadBoardFile("1.board");
	PrintBoard(board);
	
	return 0;
} 
