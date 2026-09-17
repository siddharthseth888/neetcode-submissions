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
    ListNode* reverseLL(ListNode* startHead, int k)
    {
        ListNode* prev = NULL;
        
        while(k != 0)
        {
            ListNode* temp = startHead->next;
            startHead->next = prev;
            prev = startHead;
            startHead = temp;
            k--;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || k == 1) return head;
        ListNode* curr = head;
        ListNode* subHead = head;
        ListNode* newHead = NULL;
        ListNode* prevTail = NULL;
        int cnt = 1;

        while(curr != NULL)
        {
            if(cnt == k)
            {
                ListNode* temp = curr->next;
                ListNode* tempHead = reverseLL(subHead, k);
                if(newHead == NULL)
                {
                    newHead = tempHead;
                }

                else
                {
                    // ADDED: Connect the previous group to this new reversed group
                    prevTail->next = tempHead; 
                }
                // ADDED: The old 'subHead' becomes the tail of this reversed group.
                // We save it in prevTail for the NEXT iteration.
                prevTail = subHead; 
                
                curr = subHead;
                subHead->next = temp;
                
                // ADDED: Update subHead to point to the start of the next group!
                subHead = temp; 
                
                // MODIFIED: Reset to 0 because the cnt++ at the bottom will immediately make it 1
                cnt = 0;
            }

            curr = curr->next;
            cnt++;
        }

        return newHead == NULL ? head : newHead;
        
    }
};
