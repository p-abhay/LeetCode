class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
    	int n = S.size();
    	int count = 0;
    	for(int i = n - 1; i >= 0; i--) {
    	    if(count == K && S[i] != '-') {
    	        ans += '-';
    	        count = 0;
    	        }
    	    if(S[i] != '-') {
    	        if(S[i] >= 97 && S[i] <= 122)
    	        S[i] = S[i] - 32;
    	        ans += S[i];
    	        count += 1;
    	    }
    	   //cout<<i<<" "; 
    	}
    	reverse(ans.begin(),ans.end());
    	return ans;
    }
};