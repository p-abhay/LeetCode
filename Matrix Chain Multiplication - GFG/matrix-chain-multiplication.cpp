// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        //return mcm(arr, 1, N - 1);
        
        vector<vector<int>> dp(N,vector<int>(N,-1));
        
        return mcm2(arr, 1, N - 1, dp);
        
    }
private:
    int mcm(int arr[], int i, int j)
    {
        if(i == j)
            return 0;
        
        int minimum = INT_MAX;
        int count = 0;
        for(int k  = i; k < j; k++)
        {
            count = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i - 1]*arr[k]*arr[j];
            if(count < minimum)
                minimum = count;
        }
        return minimum;
    }
    int mcm2(int arr[], int i, int j, vector<vector<int>>& dp)
    {
        if(i == j)
            dp[i][j] = 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int minimum = INT_MAX;
        int count = 0;
        for(int k  = i; k < j; k++)
        {
            count = mcm2(arr,i,k,dp) + mcm2(arr,k+1,j,dp) + arr[i - 1]*arr[k]*arr[j];
            if(count < minimum)
                minimum = count;
        }
        dp[i][j] = minimum;
        return dp[i][j];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends