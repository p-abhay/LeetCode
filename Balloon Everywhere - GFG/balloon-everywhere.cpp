//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int ans = 0;
        map<char,int> mp;
        for(auto ch : s) {
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch =='o' || ch == 'n') {
                mp[ch] += 1;
            }
        }
        while(1) {
            if(mp['b'] >= 1 && mp['a'] >= 1 && mp['l'] >= 2 && mp['o'] >= 2 && mp['n'] >= 1) {
                ans += 1;
                mp['b'] -= 1;
                mp['a'] -= 1;
                mp['l'] -= 2;
                mp['o'] -= 2;
                mp['n'] -= 1;
            }
            else
                return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends