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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        auto curr = head;
        while (curr) {
            curr = curr->next;
            if (++size == k) break;
        }
        if (size < k) return head;
        
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
