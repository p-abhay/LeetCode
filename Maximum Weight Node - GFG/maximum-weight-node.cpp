//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      vector<int> v(N,0);
    //   for(auto i : v)
    //     cout<<i<<" ";
      for(int i = 0; i < N; i++) {
          if(Edge[i] == -1)
            continue;
          v[Edge[i]] += i;
      }
    //   for(auto i : v)
    //     cout<<i<<" ";
        //return 0;
      int ans = 0;
      int maxi = *max_element(v.begin(),v.end());
      for(int i = 0; i < N; i++) {
          if(v[i] >= maxi) {
              maxi = v[i];
              ans = i;
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends