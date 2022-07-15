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
    int getDecimalValue(ListNode* head) {
        int res = 0, count = 0;
        ListNode *curr = head;
        while(curr) {
            count += 1; curr = curr -> next;
        }
        while(head) {
            --count;
            if(head -> val) res += pow(2, count);
            head = head -> next;
        }
        return res;
    }
};
