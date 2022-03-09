/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            mp[temp->val] += 1;
            temp = temp->next;
        }
        /*for(auto i : mp)
            cout<<i.first<<":"<<i.second<<endl;*/
        ListNode* ans = nullptr;
        for(auto itr = mp.begin(); itr != mp.end(); itr++) {
            if(itr->second == 1)
            {
                ListNode* temp = new ListNode(itr->first);
                if(ans == nullptr)
                    ans = temp;
                else
                {
                    ListNode* t =ans;
                    while(t->next != nullptr)
                    {
                        t = t->next;
                    }
                    t->next = temp;
                }
            }
        }
        return ans;
    }
};