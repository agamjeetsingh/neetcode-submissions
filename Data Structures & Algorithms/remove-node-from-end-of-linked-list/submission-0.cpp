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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        auto curr = head;
        while (curr) {
            size++; curr = curr->next;
        }
        ListNode* prev = nullptr;
        ListNode* remove = head;
        for (int i = 0; i < size - n; i++) {
            prev = remove;
            remove = remove->next;
        }
        if (prev) {
            prev->next = remove->next;
        } else {
            head = head->next;
        }

        return head;
    }
};
