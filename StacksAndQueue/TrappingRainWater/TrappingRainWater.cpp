#include <bits/stdc++.h>

using namespace std;

// int trap(vector<int>& height) {
//         int n=height.size();
//         int total=0;
//         vector<int> prefixMax(n), suffixMax(n);
//         prefixMax[0] = height[0];
//         for(int i = 1; i < n; ++i) {
//         prefixMax[i] = max(prefixMax[i - 1], height[i]);
//         }

//         suffixMax[n - 1] = height[n - 1];
//         for(int i = n - 2; i >= 0; --i) {
//             suffixMax[i] = max(suffixMax[i + 1], height[i]);
//         }
//         for(int i=0;i<n;i++){
            
//             if(height[i]<prefixMax[i] && height[i]<suffixMax[i]){
//                 total+= min(prefixMax[i],suffixMax[i])-height[i];
//             }
//         }
//         return total;
//     }
// This is a good method but the problem is it takes O(2N) space to store the prefix and suffix max . 
// We can improve it by using 2ptr approach.  

int trap(vector<int>& height) {
    int n=height.size();
    int l=0,r=n-1;
    int lmax=0;
    int rmax=0;
    int total=0;
    while(l<r){
        if(height[l]<=height[r]){
            if(lmax > height[l])
                total+= lmax-height[l];
            else
                lmax=height[l];
            
            l=l+1;
        }else{
            if(rmax> height[r]){
                total+= rmax- height[r];
            }else{
                rmax= height[r];
            }
            r=r-1;
        }
    }
    return total;
     
}

int main(){
    vector<int> hts = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = trap(hts);
    cout << "the answer is : " << res << endl;
    return 0;
}