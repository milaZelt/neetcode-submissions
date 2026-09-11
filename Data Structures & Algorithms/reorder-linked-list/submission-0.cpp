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
    void reorderList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast=head->next;

        //find middle 
        while(fast!=nullptr && fast->next!=nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }

        //splt into two lists
        ListNode* second= slow->next;
        slow->next= nullptr;

        //reverse list 
        ListNode* prev = nullptr;
        ListNode* current = second;

        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }
        second = prev;

        //now merege 
        ListNode* first = head;
        
        while(second !=nullptr){
            ListNode* temp1= first->next;
            ListNode* temp2= second->next;

            first->next= second;
            second->next =temp1;

            first=temp1;
            second=temp2; 
        }
 
    }
};
