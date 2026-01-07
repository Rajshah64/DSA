// This is solved on GFG and is bascially left rotation by d places

class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int> &arr, int d)
    {
        // code here
        int n = arr.size();
        d = d % n;
        // Step1:- store d elements from the start in a temp vector
        vector<int> temp;
        for (int i = 0; i < d; i++)
        {
            temp.push_back(arr[i]);
        }

        // Step2:- shift the elements by d places behind.
        for (int i = d; i < n; i++)
        {
            arr[i - d] = arr[i];
        }

        // Step3:- insert the saved elements in the end.
        int cnt = 0;
        for (int i = n - d; i < n; i++)
        {
            arr[i] = temp[cnt];
            cnt++;
        }
    }
};