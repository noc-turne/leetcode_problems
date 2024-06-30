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
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(auto list: lists) {
            if(list) {
                heap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!heap.empty()) {
            cur->next = heap.top();
            if(cur->next->next) {
                heap.push(cur->next->next);
            }
            heap.pop();
            cur = cur->next;
        }
        return dummy->next;
    }
};