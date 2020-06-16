#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::istringstream;
using std::string;
using std::sort;
using std::vector;

enum class State {kEmpty, kObstacle, kClosed, kPath};

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
			row.push_back(State::kEmpty);
		} else {
			row.push_back(State::kObstacle);
		}
	}

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
 ** Check Valid cell 
 */
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
	if((0 < x) && (x < grid.size()) && (0 < y) && (y < grid[0].size()) ) {
		return grid[x][y] == State::kEmpty;
	} else {
		return false;
	}
}

/*
 ** Compare two node - true if first node greater than second
*/
bool Compare(vector <int> a, vector <int> b)
{
	int fa = a[2] + a[3];
	int fb = b[2] + b[3];
	
	return fa > fb;
}

/*
 ** Cellsort - sort open list
*/
void CellSort(vector <vector <int>> *v)
{
	sort(v->begin(), v->end(), Compare);
}

/*
 ** AddToOpen list
*/
void AddToOpen(int x, int y, int g, int h, vector<vector<int> > &list, vector<vector <State>> &board)
{
	vector <int> node {x, y, g, h};
	list.push_back(node);
	board[x][y] = State::kClosed;
}

/*
 ** Heuristic function {Manhatten dist}
*/
int Heuristic(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

/*
 ** Implementation of A* Search algorithm
*/
vector <vector<State>> Search(vector <vector<State>> board,int start[2],int goal[2])
{
	vector <vector<int>> open {};
	int x = start[0];
	int y = start[1];
	int g = 0;
	int h = Heuristic(x, y, goal[0], goal[1]);
	
	AddToOpen(x, y, g, h, open, board);
	
	while(!open.empty()) {
		CellSort(&open);
		auto current_node = open.back();
		open.pop_back();
	
		x = current_node[0];
		y = current_node[1];
		
		if(x == goal[0] && y == goal[1]) {
			return board;
		}
		
		//Expand node		
	}
			
	cout << "No path found\n";
	return vector<vector<State>> {};
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
	int init[2] =  {0, 0};
	int goal[2] =  {4, 5};
	//Initialize the board
	vector< vector<State> > board;
	
	board = ReadBoardFile("1.board");
	
	auto solution = Search(board, init, goal);

	PrintBoard(solution);
	
	return 0;
} 
