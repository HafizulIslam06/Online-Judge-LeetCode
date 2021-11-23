/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
*/

class Solution {
public:
    bool isSafe(int row, int col, int rows, int cols){
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int i, j;
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int, int>, int>> bfs;
        int fresh = 0;

        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    bfs.push(make_pair(make_pair(i, j), 0));
                }
            }
        }

        int time = 0;
        vector<pair<int, int>> moves{make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

        while(fresh > 0 && !bfs.empty()){
            pair<pair<int, int>, int> p = bfs.front();
            bfs.pop();
            int row = p.first.first;
            int col = p.first.second;
            int steps = p.second;

            for(auto it = moves.begin(); it != moves.end(); it++){
                int nextRow = row + it->first;
                int nextCol = col + it->second;
                if(isSafe(nextRow, nextCol, rows, cols) && grid[nextRow][nextCol] == 1){
                    fresh--;
                    grid[nextRow][nextCol] = 2;
                    time = max(time, steps + 1);
                    bfs.push(make_pair(make_pair(nextRow, nextCol), steps + 1));
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
