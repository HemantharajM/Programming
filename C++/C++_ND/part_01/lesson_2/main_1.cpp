#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::vector;
using std::string;
using std::istringstream;

/*
 ** Parse line string, store interger
*/
vector <int> ParseLine(string s)
{
	istringstream line(s);
	
	vector <int> row;	
	int n;
	char c;

	while(line >> n >> c) {
		row.push_back(n);
	}

	return row;
}

/*
 ** Read board from file
*/
vector <vector <int> > ReadBoardFile(string board_path)
{
	std::ifstream grid;
	grid.open(board_path);
	
	vector <vector <int> > board;
	
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
void PrintBoard(vector< vector<int> > grid)
{
	for(auto i: grid) {
		for(auto j: i) {
			cout << j;
		}
		cout << "\n";
	}
	
	return;
}
int main()
{
	//Initialize the board
	vector< vector<int> > board;
	
	//cout << "Print board \n";
	board = ReadBoardFile("1.board");
	PrintBoard(board);
	
	return 0;
} 
