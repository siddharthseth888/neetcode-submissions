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
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        //finding the middleNode
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //finding the reverse of link list from {mid, end}
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;

        while(curr != NULL)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2 != NULL)
        {
            ListNode* temp_front = p1->next;
            ListNode* temp_back = p2->next;
            p1->next = p2;
            p2->next = temp_front;
            p1 = temp_front;
            p2 = temp_back;
        }
    }
};
