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
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;


        if(head1->val <= head2->val)
        {
            head1->next = merge(head1->next, head2);
            return head1;
        }

        else
        {
            head2->next = merge(head1, head2->next);
            return head2;
        }

        return NULL;
    }
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists)
    {
        if(start == end)
        {
            return lists[start];
        }

        int mid = start + (end-start)/2;

        ListNode* head1 = partitionAndMerge(start, mid, lists);
        ListNode* head2 = partitionAndMerge(mid+1, end, lists);
        ListNode* head = merge(head1, head2);

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0)
        {
            return NULL;
        }

        int n = lists.size();
        int start = 0;
        int end = n-1;

        return partitionAndMerge(start, end, lists);
    }
};
