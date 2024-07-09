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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        ListNode* ptr1 = list1, *ptr2 = list2;
        while(ptr1 && ptr2) {
            if(ptr1->val < ptr2->val) {
                cur->next = ptr1;
                ptr1 = ptr1->next;
                
            }
            else {
                cur->next = ptr2;
                ptr2 = ptr2->next;
            }
            cur = cur->next;

        }

        if(ptr1) cur->next = ptr1;
        else cur->next = ptr2;
        return dummy->next;
        
    }
};