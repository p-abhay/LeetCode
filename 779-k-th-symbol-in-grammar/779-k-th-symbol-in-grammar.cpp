class Solution {
public:
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
    
private:
    int solve(int n,int k) {
        
        int mid = pow(2,n-1)/2;
        if(n == 1 or k == 1)
            return 0;
        else if(k <= mid)
            return solve(n-1,k);
        else
            return !solve(n-1,k-mid);
    }
};