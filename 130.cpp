
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numRow{};
  int numCol{};

  void capture(vector<vector<char>> &board, int r, int c) {
    if (r < 0 || c < 0 || r >= numRow || c >= numCol)
      return;

    if (board[r][c] == 'X' || board[r][c] == 'T')
      return;

    board[r][c] = 'T';

    capture(board, r + 1, c);
    capture(board, r - 1, c);

    capture(board, r, c + 1);

    capture(board, r, c - 1);
  }

  void solve(vector<vector<char>> &board) {

    numCol = board[0].size();
    numRow = board.size();
    for (int i{}; i < numRow; i++) {

      for (int j{}; j < numCol; j++) {

        if ((numCol - 1 == j || numRow - 1 == i || j == 0 || i == 0) &&
            board[i][j] == 'O') {
          capture(board, i, j);
        }
      }
    }

    for (int i{}; i < numRow; i++) {

      for (int j{}; j < numCol; j++) {

        if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }

    for (int i{}; i < numRow; i++) {

      for (int j{}; j < numCol; j++) {

        if (board[i][j] == 'T')
          board[i][j] = 'O';
      }
    }
  }
};

int main() {
  Solution s;

  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};

  s.solve(board);

  for (const auto &row : board) {
    for (char c : row) {
      std::cout << c << " ";
    }
    std::cout << "\n";
  }

  return 0;
}