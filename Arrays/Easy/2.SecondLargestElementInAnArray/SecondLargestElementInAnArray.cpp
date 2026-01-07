class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        // code here
        int mx = arr[0];
        int mx2 = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > mx)
            {
                mx2 = mx;
                mx = arr[i];
            }
            else if (arr[i] < mx && arr[i] > mx2)
            {
                mx2 = arr[i];
            }
        }
        return mx2;
    }
};