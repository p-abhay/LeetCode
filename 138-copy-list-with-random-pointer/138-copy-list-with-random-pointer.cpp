/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==nullptr)
            return nullptr;
        
        Node* node=head;
        /*
        map<Node*,Node*> mp;
        while(node!=nullptr)
        {
            Node* temp = new Node(head->val);
            mp[node] = temp;
            node = node->next;
        }
        node=head;
        while(node!=nullptr)
        {
            if(node->next!=nullptr)
                mp[node]->next = mp[node->next];
            else
                mp[node]->next = nullptr;
            if(node->random!=nullptr)
                mp[node]->random = mp[node->random];
            else
                mp[node]->random = nullptr;
            
            node=node->next;
        }
        return mp[head];*/
        
        //step1 creating A->A'->B->B'->C->C'->nullptr
        
        while(node!=nullptr)
        {
            Node* temp = new Node(node->val);
            temp->next = node->next;
            node->next = temp;
            node = node->next->next;
        }
        
        //step2 changing random pointer of A',B'and C'
        node = head;
        while(node!=nullptr)
        {
            //as B->random points to A so B'->random should points to A' which can be accessed by 
            // B->random->next.
            if(node->random == nullptr) 
                node->next->random == nullptr;
            else
                node->next->random = node->random->next;
            node = node->next->next;
        }
        
        //step3 changing next pointer of A,A',B,B',C and C'
        node = head;
        Node* result = node->next;
        Node* temp = node->next;
        
        while(temp!=nullptr)
        {
            node->next = node->next->next;
            if(temp->next != nullptr)
                temp->next = temp->next->next;
            
            node = node->next;
            temp = temp->next;
        }
        return result;
    }
};