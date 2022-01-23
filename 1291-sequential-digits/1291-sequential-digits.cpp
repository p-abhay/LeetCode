class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        /*int k=2,st=1;
        for(int i=1;i<9;i++)
        {
            st=i;
            for(int j=i+1;j<10;j++)
            {
                st = st*10 + j;
                if(st >=low and st<=high)
                    ans.push_back(st);
            }
        }
        sort(ans.begin(),ans.end());*/
        /*for(auto itr = ans.begin();itr!=ans.end();itr++)
        {
            //cout<<*itr<<" ";
            if((*itr >= low) and (*itr <=high))
                continue;
            else
            {
                ans.erase(itr);
                --itr;
            }
                
        }*/
        // Using BFS   
        queue<int> q{{1,2,3,4,5,6,7,8}};
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            if(cur > high)
                break;
            if(cur >= low and cur <=high)
                ans.push_back(cur);
            
            int rem = cur%10;
            int next = cur*10 + rem + 1;
            if(rem < 9)
                q.push(next);
            
        }
        return ans;
    }
};