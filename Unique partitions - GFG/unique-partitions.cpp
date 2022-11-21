//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> arr(n+1);
        for(int i = 1; i < n+1; i++)
            arr[i] = i;
        vector<int> a;
        solve(n,arr,a,0,n);
        
        return ans;
    }
    void solve(int idx, vector<int>& arr, vector<int>& a, int sum, int n) {
        if(idx == 0 || sum > n)
            return;
        if(sum == n) {
            ans.push_back(a);
            return;
        }
        a.push_back(idx);
        solve(idx,arr,a,sum+arr[idx],n);
        a.pop_back();
        solve(idx-1,arr,a,sum,n);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends