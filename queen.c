#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printBoard(vector< vector<char> >& board)
{
    for (auto row : board) 
    {
        cout<<"| ";
        for (auto ch : row) 
        cout<<ch<<" | ";
        cout<<endl;
    }
}
void solveBoard(vector<vector<char> >& board, int row, int rowmask, int ldmask, int rdmask, int& ways)
{
    int n = board.size();
    int all_rows_filled = (1 << n) - 1;
    if (rowmask == all_rows_filled) 
    {
        ways++;
        cout<<"=====================\n";
        cout<<"QUEEN PLACEMENT - "<<ways<<endl;
        cout<<"=====================\n";
        printBoard(board);
        return;
    }
    int safe = all_rows_filled & (~(rowmask | ldmask | rdmask));
    while (safe) 
    {
        int p = safe & (-safe);
        int col = (int)log2(p);
        board[row][col] = 'Q';
        solveBoard(board, row+1, rowmask|p, (ldmask|p) << 1, 
                (rdmask|p) >> 1, ways);
        safe = safe & (safe-1);
        board[row][col] = ' '; 
    }
    return;
}
void main()
{
int n;
int ways = 0;
cout << "ENTER THE NUMBER OF QUEENS:- " << endl;
cin >> n;
vector< vector<char> > board;
for (int i = 0; i < n; i++)
{
vector<char> tmp;
	for (int j = 0; j < n; j++) 
		tmp.push_back(' ');
	board.push_back(tmp);
}
int rowmask = 0, ldmask = 0, rdmask = 0; int row = 0;
solveBoard(board, row, rowmask, ldmask, rdmask, ways);
cout<<endl<<"NUMBER OF WAYS TO PLACE "<<n<<" QUEENS : "<<ways<<endl;
}
