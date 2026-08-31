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
        ListNode* head = nullptr;
        auto head1 = list1;
        auto head2 = list2;
        ListNode* res = nullptr;

        while (head1 && head2) {
            ListNode* next;
            if (head1->val <= head2->val) {
                next = head1;
                head1 = head1->next;
            } else {
                next = head2;
                head2 = head2->next;
            }

            if (head) {
                head->next = next;
            } else {
                res = next;
            }
            head = next;
        }
        if (head1) {
            if (head) {
                head->next = head1;
            } else {
                head = head1;
                res = head;
            }
        } else if (head2) {
            if (head) {
                head->next = head2;
            } else {
                head = head2;
                res = head;
            }
        }

        return res;
    }
};
