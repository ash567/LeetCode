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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)>pq(compare);
        for(auto &x : lists) {
            if(x) {
                pq.push(x);
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* dummyHead = head;
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            head->next = node;
            head = node;
            node = node->next;
            head->next = NULL;
            if(node) {
                pq.push(node);
            }
        }
        head = dummyHead->next;
        delete(dummyHead);
        return head;
    }
};
