int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
// Normal Linear Search Algorithm which searches for an element in an array and returns its index if found else returns -1.
// Solved on coding ninjas.