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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* lst1=reverse(l1);
        ListNode* lst2=reverse(l2);
        
        ListNode* newHead=nullptr,*newH=nullptr;
        int carry=0;
        while(lst1!=nullptr || lst2!=nullptr)
        {
            if(lst1!=nullptr)
            {
                carry+=lst1->val;
                lst1=lst1->next;
            }
            if(lst2!=nullptr)
            {
                carry+=lst2->val;
                lst2=lst2->next;
            }
            
            if(newHead==nullptr)
            {
                newHead=new ListNode(carry%10);
                newH=newHead;
            }
            else
            {
                newH->next=new ListNode(carry%10);
                newH=newH->next;
            }
            carry/=10;
        }
        if(carry!=0)
            newH->next=new ListNode(carry);
        
        return reverse(newHead);
        
    }
};