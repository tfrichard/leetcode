class Solution {
public:
  void solve(vector<vector<char>> &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<pair<int, int>> trace;
    if (board.size() < 3) return;
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
        
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (board[i][j] == 'X') visited[i][j] = true;
	else {
	  if (solveImpl(board, i, j, m, n, trace, visited)) {
	    for (auto p : trace) {
	      board[p.first][p.second] = 'X';
	    }
                        
	  } 
	  trace.clear();
	}
      }
    }
        
  }
    
  bool solveImpl(vector<vector<char>> &board, int i, int j, int m, int n, \
		 vector<pair<int, int>> &trace, vector<vector<bool>> &visited) {
            
    if (i >= m - 1 || j >= n - 1 || i <= 0 || j <= 0) return false;
        
    assert(i > 0 && i < m - 1 && j > 0 && j < n - 1);
        
    if (visited[i][j]) return true;
    else visited[i][j] = true;
        
    //add new 'O'
        
        
    pair<int, int> p(i, j);
    trace.push_back(p);
        
    bool b1 = true, b2 = true, b3 = true, b4 = true;
        
    if (i + 1 < m && board[i+1][j] == 'O') {
      b1 = solveImpl(board, i + 1, j, m, n, trace, visited);
    }
        
    if (j + 1 < n && board[i][j+1] == 'O') {
      b2 = solveImpl(board, i, j + 1, m, n, trace, visited);
    }
        
    if (i - 1 >= 0 && board[i-1][j] == 'O') {
      b3 = solveImpl(board, i - 1, j, m, n, trace, visited);
    }
        
    if (j - 1 >= 0 && board[i][j-1] == 'O') {
      b4 = solveImpl(board, i, j - 1, m, n, trace, visited);
    }
        
    return b1 && b2 && b3 && b4;

  }

};




