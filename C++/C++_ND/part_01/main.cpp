#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;
using std::string;

/*
 ** Read board from file
*/
void ReadBoardFile(string board_path)
{
	std::ifstream grid;
	grid.open(board_path);

	if(grid) {
		string line;
		cout << "Grid\n";
		while(getline(grid, line)) {
			cout << line << "\n";
		}
	} else {
		cout << "Unable to open file \n";
	}
	
	return;
}
	
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
	vector< vector<int> > board = {{0, 1, 0, 0, 0, 0},
				     {0, 1, 0, 0, 0, 0},
				     {0, 1, 0, 0, 0, 0},
				     {0, 1, 0, 0, 0, 0},
				     {0, 0, 0, 0, 1, 0}};
	
	//cout << "Print board \n";
	//PrintBoard(board);
	ReadBoardFile("1.board");	
	return 0;
} 
