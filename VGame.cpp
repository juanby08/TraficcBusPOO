#include "VGame.h"
#include <iostream>

using namespace std;
void VGame::DisplayText(const std::string& text)
{
    cout << text << endl;
}
void VGame::DisplayGame(Grid& grid)
{
    vector<vector<char>> board = grid.getBoard();

    for (const auto& row : board)
    {
        for (char cell : row)
        {
            cout << cell << ' ';
        }
        cout << endl;
    }

    cout << endl;
}

