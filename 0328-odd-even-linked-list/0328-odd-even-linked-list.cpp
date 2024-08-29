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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;
        ListNode* odd_head = odd;

        head = head->next->next;
        odd->next = nullptr;
        int cnt = 1;

        while(head) {
            if(cnt % 2 == 1) {
                odd->next = head;
                odd = odd->next;
                even->next = nullptr;
            }
            else {
                even->next = head;
                even = even->next;
                odd->next = nullptr;
            }
            head = head->next;
            cnt ++;
        }
        odd->next = even_head;

        // while(odd) {
        //     cout << odd->val << endl;
        //     odd = odd->next;
        // }

        return odd_head;
        
    }
};