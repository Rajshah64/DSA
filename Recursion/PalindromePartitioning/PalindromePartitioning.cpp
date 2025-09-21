// Leetcode 131. Palindrome Partitioning

class Solution
{
private:
    bool isPalindrome(string c)
    {
        int left = 0, right = c.size() - 1;
        while (left < right)
        {
            if (c[left] != c[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void Partition(int idx, string s, vector<vector<string>> &ans, vector<string> temp)
    {
        if (idx == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            string c = s.substr(idx, i - idx + 1);
            if (isPalindrome(c))
            {
                temp.push_back(c);
                Partition(i + 1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        Partition(0, s, ans, temp);
        return ans;
    }
};