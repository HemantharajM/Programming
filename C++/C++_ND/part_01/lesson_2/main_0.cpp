#include <iostream>
#include <vector>

using std::cout;
using std::vector;

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
	
	cout << "Print board \n";
	PrintBoard(board);
	
	return 0;
} 
