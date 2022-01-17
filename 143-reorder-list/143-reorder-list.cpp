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
    void reorderList(ListNode* head) {
        //Calculate Mid
        ListNode* first=head;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //Reverse from mid to end of the list
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* second=prev;
        while(second->next!=nullptr)
        {
            ListNode* temp=first->next;
            first->next=second;
            first=temp;
            
            temp=second->next;
            second->next=first;
            second=temp;
        }
    }
};