// solved on gfg

class Solution
{
private:
    void rev(vector<int> &arr, int i, int j)
    {
        if (i >= j)
        {
            return;
        }
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
        rev(arr, ++i, --j);
    }

public:
    void reverseArray(vector<int> &arr)
    {
        // code here
        rev(arr, 0, arr.size() - 1);
    }
};