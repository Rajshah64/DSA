// solved on gfg

class Solution
{
private:
    void dfs(int row, int col, vector<string> &ans, string &temp, vector<vector<int>> &maze)
    {

        if (row == maze.size() - 1 && col == maze.size() - 1)
        {
            ans.push_back(temp);
            return;
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        vector<char> dir = {'U', 'R', 'D', 'L'};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            int n = maze.size();
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && maze[nrow][ncol] == 1)
            {
                temp += dir[i];
                maze[nrow][ncol] = 0;
                dfs(nrow, ncol, ans, temp, maze);
                temp.pop_back();
                maze[nrow][ncol] = 1;
            }
        }
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here

        vector<string> ans;
        if (maze[0][0] == 0)
            return ans;
        string temp;
        maze[0][0] = 0;
        dfs(0, 0, ans, temp, maze);
        sort(ans.begin(), ans.end());
        return ans;
    }
};