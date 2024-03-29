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
    ListNode* deleteMiddle(ListNode* head) {
        // if(head->next == nullptr) {
        //     ListNode* temp = head;
        //     delete(temp);
        //     head = nullptr;
        //     return head;
        // }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow == prev) {
            ListNode* temp = slow;
            delete(temp);
            head = nullptr;
            return head;
        }
        prev->next = slow->next;
        delete(slow);
        return head;
    }
};