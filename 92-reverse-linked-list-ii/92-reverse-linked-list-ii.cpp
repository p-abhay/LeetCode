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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr)
            return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(left > 1)
        {
            prev = curr;
            curr = curr->next;
            right -= 1;
            left -= 1;
        }
        ListNode* prev1 = prev;
        ListNode* tail = curr;
        ListNode* temp = nullptr;
        //int diff = right - left-1;
        while(right > 0)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            right -= 1;
        }
        if(prev1 != nullptr)
            prev1->next = prev;
        else
            head = prev;
        tail->next = curr;
        
        
        return head;
    }
};