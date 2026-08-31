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
        ListNode* head = new ListNode();
        auto dummy = head;
        int carry = 0;

        while (l1 || l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = (sum - (sum % 10)) / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // if (l1) {
        //     head->next = l1;
        //     head = head->next;
        // } else if (l2) {
        //     head->next = l2;
        //     head = head->next;
        // }

        if (carry != 0) {
            head->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
