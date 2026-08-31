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

        auto comp = [](ListNode* l1, ListNode* l2) {
            return l1->val < l2->val;
        };

        multiset<ListNode*, decltype(comp)> ls(comp);
        for (auto l: lists) if (l) ls.insert(l);

        while (!ls.empty()) {
            ListNode* l = *ls.begin();
            ls.erase(ls.begin());

            if (l->next) ls.insert(l->next);
            head->next = l;
            head = head->next;
        }

        return dummy->next;
    }
};
