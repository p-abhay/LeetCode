class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        int k=2,st=1;
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
        sort(ans.begin(),ans.end());
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
            
        
        return ans;
    }
};