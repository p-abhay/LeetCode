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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* left=new ListNode(-1000001);
        ListNode* right=new ListNode(-1000001);
        ListNode *l=left,*r=right;
        int cnt=1;
        while(head!=nullptr) {
            if(cnt%2!=0) {
                l->next=head;
                l=l->next;
            } else {
                r->next=head;
                r=r->next;
            }
            head=head->next;
            cnt++;
                
        }
        r->next=nullptr;
        l->next=right->next;
        
        return left->next;
    }
};