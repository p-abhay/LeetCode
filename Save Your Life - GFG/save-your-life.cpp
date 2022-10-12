//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
        map<char,int> mp;
        for(int i = 0; i < n; i++) {
          mp[x[i]] = b[i];
        }
        string ans = "";
        int sum = INT_MIN;
        int currSum = 0;
        int start = 0,end = 0,s = 0;
        for(int i = 0; i < w.size(); i++) {
            if(mp.find(w[i]) == mp.end())
                currSum += w[i];
            else
                currSum += mp[w[i]];
            if(currSum > sum) {
              sum = currSum;
              start = s;
              end = i;
            }
            if(currSum < 0) {
              s = i+1;
              currSum = 0;
            }
        }
        for(int i = start; i <= end; i++) {
            ans += w[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends