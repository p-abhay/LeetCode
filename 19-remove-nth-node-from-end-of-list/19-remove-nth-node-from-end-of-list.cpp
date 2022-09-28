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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count==1)
            head=head->next;
        else
        {
            count=count-n;
            if(count==0)
            {
                head=head->next;
            }
            else
            {
                ListNode *ptr=head,*preptr=head;
                while(count--)
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
                preptr->next=ptr->next;
            }
            
        }
        
        return head;
        
    }
};