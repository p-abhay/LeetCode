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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* left=new ListNode(-1000);
        ListNode* right=new ListNode(-1000);
        ListNode* l=left,*r=right;
        while(head!=nullptr) {
            if(head->val <x) {
                l->next=head;
                l=l->next;
            }
            else {
                r->next=head;
                r=r->next;
            }
            head=head->next;
        }
        r->next=nullptr;
        l->next=right->next;
        return left->next;
        
    }
};
//Another solution using two lists