class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(i+1);
        }
        int ans = solve(arr,0,k);
        return ans;
    }
private:
    int solve(vector<int> &arr,int count,int k)
    {
        
        if(arr.size() == 1)
            return arr[0];
        count = (count + k - 1) % arr.size();
        arr.erase(arr.begin()+count);
        return solve(arr,count,k);
        
    }
};