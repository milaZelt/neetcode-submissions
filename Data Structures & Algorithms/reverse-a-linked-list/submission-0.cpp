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
    ListNode* reverseList(ListNode* head) {
        ListNode* previousAdress= nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* nextAdress= current->next; //here we are saving the next value
            current->next = previousAdress;     // updating so now current node points back

            previousAdress= current;
            current = nextAdress;
        }
        return previousAdress;
    }
};
