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
    ListNode* midOfLinkedList(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* mid=midOfLinkedList(head);
        ListNode* first=head;
        ListNode* second=reverse(mid);
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