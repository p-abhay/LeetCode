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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* prev = head;
        ListNode* temp = head;
        ListNode* curr = head->next;
        
        prev->next = nullptr;
        while(curr != nullptr)
        {
            prev = curr;
            curr = prev->next;
            prev->next = temp;
            temp = prev;
        }
        head = prev;
        return head;
    }
};