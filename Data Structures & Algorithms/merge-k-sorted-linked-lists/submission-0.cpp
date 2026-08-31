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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        auto head = dummy;

        unordered_set<ListNode*> ls(lists.begin(), lists.end());
        ls.erase(nullptr);

        while (!ls.empty()) {
            ListNode* l = *ls.begin();
            for (auto node: ls) {
                if (l->val > node->val) l = node;
            }
            ls.erase(l);
            if (l->next) ls.insert(l->next);
            head->next = l;
            head = head->next;
        }

        return dummy->next;
    }
};
