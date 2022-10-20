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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //cout<<slow->val<<" ";
        reverse(slow);
        // cout<<slow->val<<" ";
        // while(slow) {
        //     cout<<slow->val<<" ";
        //     slow = slow->next;
        // }
        int ans = INT_MIN,sum = 0;
        while(head && slow) {
            sum = head->val + slow->val;
            ans = max(ans,sum);
            head = head->next;
            slow = slow->next;
        }
        return ans;
    }
    void reverse(ListNode* &head) {
        ListNode* prev = nullptr ;
        ListNode* curr = head;
        ListNode* next = head;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    } 
};