class Solution {
public:
    bool isPowerOfThree(int n) {
        int rem;
        if(n==0)
            return false;
        while(n!=1)
        {
            rem=n%3;
            cout<<rem<<" ";
            if(rem!=0)
                return false;
            n/=3;
        }
        return true;
    }
};