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
    Node* copyRandomList(Node* head) 
    {
        if(head == NULL)
        {
            return NULL;
        }

        Node* prev = NULL;
        Node* newHead = NULL;
        Node* curr = head;
        map<Node*, Node*> mpp;

        while(curr != NULL)
        {
            Node* temp = new Node(curr->val);
            if(newHead == NULL)
            {
                newHead = temp;
                prev = temp;
            }

            else
            {
                prev->next = temp;
                prev = temp;
            }
            mpp[curr] = temp;
            curr = curr->next;
        }

        prev->next = NULL;

        curr = head;
        Node* newCurr = newHead;

        while(curr != NULL)
        {
            if(curr->random == NULL)
            {
                newCurr->random = NULL;
            }

            else
            {
                newCurr->random = mpp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
