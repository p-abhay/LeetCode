//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int ans = 0;
	    int n = nums.size();
	    for(int i = 0; i < n; i++) {
	        int left = 0;
	        int right = 0;
	        for(int j = 0; j < i; j++) {
	            if(nums[j] < nums[i])
	                left += 1;
	        }
	        for(int j = i+1; j < n; j++) {
	            if(nums[j] > nums[i])
	                right += 1;
	        }
	        ans += left*right;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends