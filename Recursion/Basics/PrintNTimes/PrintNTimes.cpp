// solved on gfg

class Solution
{
public:
    void printGfg(int N)
    {
        // Code here
        if (N < 1)
        {
            // cout<< "GFG";
            return;
        }
        cout << "GFG ";
        printGfg(N - 1);
    }
};
