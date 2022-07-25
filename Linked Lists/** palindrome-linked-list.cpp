class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* slowPrev = dummy, *slow = head, *slowNext = slow, *fast = head;
        dummy->next = head;
        bool isOdd = false;

        while(fast){

            // Move fast forward
            if(fast->next){
                fast = fast->next->next;
            }else{
                fast = fast->next;
                isOdd = true;
            }

            // Reverse slow
            slowNext = slow->next;
            slow->next = slowPrev;
            slowPrev = slow;
            slow = slowNext;
        }

        // Detach dummy node (otherwise will get memory access error)
        head->next = nullptr;
        delete dummy;

        if(isOdd){
            slowPrev = slowPrev->next;
        }

        while(slowPrev && slow){
            if (slow->val != slowPrev->val) return false;
            slowPrev = slowPrev->next;
            slow = slow->next;
        }

        return true;
    }
};
