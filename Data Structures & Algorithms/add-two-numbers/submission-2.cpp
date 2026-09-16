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
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) 
    {
        int sum = 0;
        int carry = 0;
        ListNode* prev = new ListNode(-1);
        ListNode* head = prev;
        while(head1 && head2)
        {
            ListNode* node;
            sum = carry + head1->val + head2->val;
            if(sum > 9)
            {
                carry = sum / 10;
                int el = sum % 10;
                node = new ListNode(el);
            }

            else
            {
                node = new ListNode(sum);
                carry = 0;
            }

            prev->next = node;
            prev = node;

            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1)
        {
            ListNode* node;
            sum = carry + head1->val;
            if(sum > 9)
            {
                carry = sum / 10;
                int el = sum % 10;
                node = new ListNode(el);
            }

            else
            {
                node = new ListNode(sum);
                carry = 0;
            }
            prev->next = node;
            prev = node;

            head1 = head1->next;
        }

        while(head2)
        {
            ListNode* node;
            sum = carry + head2->val;
            if(sum > 9)
            {
                carry = sum / 10;
                int el = sum % 10;
                node = new ListNode(el);
            }

            else
            {
                node = new ListNode(sum);
                carry = 0;
            }
            prev->next = node;
            prev = node;

            head2 = head2->next;
        }

        if(carry != 0)
        {
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }

        return head->next;
    }
};
