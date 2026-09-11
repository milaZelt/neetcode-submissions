#include <bits/stdc++.h>
using namespace std;
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
        int size= 0;
        ListNode* current=head;

        //to find size
        while(current!=nullptr){
            size++;
            current=current->next;
        }

        //remove at the index
        int removeIndex= size-n;
        
        //edge case rmeoving head
        if(removeIndex==0){
            return head->next;
        }

        current=head;

        for(int i=0; i<removeIndex-1; i++){
            current= current->next;
        }

        current->next= current->next->next;

        return head;
        
    }
};
