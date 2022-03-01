// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxSum = INT_MIN, currSum = 0;
        int s = 0;
        int e;
        
        for(int i = 0; i  < n; i++) {
            currSum += arr[i];
            if(currSum > maxSum)
            {
                maxSum = currSum;
                e = i;
            }
            if(currSum < 0)
            {
                currSum = 0;
                s = i + 1;
            }
        }
        return maxSum;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends