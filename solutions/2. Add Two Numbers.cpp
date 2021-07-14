/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lsum, *head;
        head = lsum = new ListNode(-1, NULL);
        int carry = 0, val = 0;
        while(l1 != NULL or l2 != NULL or carry != 0) {
            val = carry +  (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
            carry = val/10;
            val = val % 10;
            lsum->next = new ListNode(val);
            lsum = lsum->next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        lsum = head->next;
        delete(head);
        return lsum;
    }
};
