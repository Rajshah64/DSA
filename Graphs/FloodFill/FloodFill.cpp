class Solution
{
private:
    void dfs(int sr, int sc, vector<vector<bool>> &vis, int originalColor, int color, vector<vector<int>> &image)
    {
        // int originalColor = image[sr][sc];
        vis[sr][sc] = true;
        image[sr][sc] = color;

        int n = image.size();    // row
        int m = image[0].size(); // column

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++)
        {
            int n1 = sr + dx[i];
            int n2 = sc + dy[i];

            if (n1 >= 0 && n1 < n && n2 >= 0 && n2 < m && image[n1][n2] == originalColor && !vis[n1][n2])
            {
                dfs(n1, n2, vis, originalColor, color, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;        // edge case .ai helped .
        int n = image.size();    // row
        int m = image[0].size(); // column
        int originalColor = image[sr][sc];
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr, sc, vis, originalColor, color, image);
        return image;
    }
};