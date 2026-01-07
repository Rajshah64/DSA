class Solution
{
public:
    int largest(vector<int> &arr)
    {
        // code here
        int mx = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > mx)
            {
                mx = arr[i];
            }
        }
        return mx;
    }
};
