/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next) return NULL;
        ListNode *slow = head, *fast = head;
        bool cycle = false;
        while(slow && fast){
            slow = slow -> next;
            fast = fast -> next ?  fast -> next -> next : fast -> next;
            if(slow == fast){ cycle = true; break;}
        }
        if(!cycle) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};