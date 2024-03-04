class Solution {
public: 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count=0;
        while(curr) {
            curr = curr->next;
            count++;
        }
        if(count == n) return head->next;
        n = count - n; //從前面數來第count-n+1個, 但從count-n個的next開始斷開
        curr = head;
        while(--n) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};