// Solved on GFG

// class Solution {
//   public:
//     vector<int> findUnion(vector<int>& a, vector<int>& b) {
//         // code here
//         set<int> st;
//         for(auto it: a){
//             st.insert(it);
//         }
//         for(auto it: b){
//             st.insert(it);
//         }
//         vector<int> temp;
//         for(auto it: st){
//             temp.push_back(it);
//         }
//         return temp;
//     }
// };
// Time complexity:- O(3n)
// Space complexity:- O(n)

// class Solution {
//   public:
//     vector<int> findUnion(vector<int>& a, vector<int>& b) {
//         // code here
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         int n1=a.size();
//         int n2=b.size();
//         int i=0;
//         int j=0;
//         vector<int> UnionArr;
//         while(i<n1 && j<n2){
//             if(a[i]<=b[j]){
//                 if(UnionArr.size()==0 || UnionArr.back()!=a[i]){
//                     UnionArr.push_back(a[i]);
//                 }
//                 i++;
//             }
//             else{
//                 if(UnionArr.size()==0 || UnionArr.back()!=b[j]){
//                     UnionArr.push_back(b[j]);
//                 }
//                 j++;
//             }
//         }

//         while(j<n2){
//             if(UnionArr.size()==0 || UnionArr.back()!=b[j]){
//                     UnionArr.push_back(b[j]);
//                 }
//                 j++;
//         }

//         while(i<n1){
//             if(UnionArr.size()==0 || UnionArr.back()!=a[i]){
//                     UnionArr.push_back(a[i]);
//                 }
//                 i++;
//         }

//         return UnionArr;
//     }
// };

// GPT version
class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        const int MAX = 100000;
        vector<bool> seen(MAX + 1, false);
        vector<int> result;

        for (int x : a)
        {
            if (!seen[x])
            {
                seen[x] = true;
                result.push_back(x);
            }
        }

        for (int x : b)
        {
            if (!seen[x])
            {
                seen[x] = true;
                result.push_back(x);
            }
        }

        return result;
    }
};