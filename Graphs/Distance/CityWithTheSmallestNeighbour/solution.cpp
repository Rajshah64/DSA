// Leetcoe question 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Step 3 + 4: Count reachable cities and find the answer
        int bestCity = -1;
        int bestCount = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            // Choose smallest count; if tie → choose larger index
            if (cnt < bestCount || (cnt == bestCount && i > bestCity))
            {
                bestCount = cnt;
                bestCity = i;
            }
        }

        return bestCity;
    }
};