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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int c = 0;
        while(p1 && p2) {
            int sum = p1->val + p2->val + c;
            if(sum >= 10) {
                c = 1;
                sum -= 10;
            }
            else {
                c = 0;
            }
            ListNode* tmp = new ListNode(0);
            head->next = tmp;
            head = head->next;
            head->val = sum;
            p1 = p1->next;
            p2 = p2->next;

        }
        while(p1) {
            if(p1->val + c < 10) {
                p1->val += c;
                head->next = p1;
                c = 0;
                break;
            }
            else {
                ListNode* tmp = new ListNode(0);
                head->next = tmp;
                head = head->next;
                p1 = p1->next;
            }
        }
        while(p2) {
            if(p2->val + c < 10) {
                p2->val += c;
                head->next = p2;
                c = 0;
                break;
            }
            else {
                ListNode* tmp = new ListNode(0);
                head->next = tmp;
                head = head->next;
                p2 = p2->next;
            }
        }
        if(c == 1) {
            ListNode* tmp = new ListNode(1);
            head->next = tmp;
        }

        
        return dummy->next;

        
    }
};