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

        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = (sum - (sum % 10)) / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1) {
            head->next = l1;
        } else {
            head->next = l2;
        }

        if (carry != 0) {
            head->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
