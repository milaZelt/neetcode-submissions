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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){return list2;}
        if(list2==nullptr){return list1;}

        //code for head 
        ListNode* mergeHead;
        ListNode* lastAdded;

        if(list1->val <= list2->val){
            mergeHead=list1;
            lastAdded=list1;
            list1=list1->next;
        }else{
            mergeHead=list2;
            lastAdded=list2;
            list2=list2->next;
        }
        //code for body list
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                lastAdded->next=list1;
                lastAdded= lastAdded->next;
                list1=list1->next;
            }else{
                lastAdded->next=list2;
                lastAdded= lastAdded->next;
                list2=list2->next;
            }
        }
        if(list2!=nullptr){
            lastAdded->next=list2;
        }else if (list1!=nullptr){
            lastAdded->next=list1;
        }
        
        return mergeHead;
    }

    //ideaa
    //for k-1 lists
    //each time mergege two lists (maybe make it a function and call it)

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }

        while(lists.size()>1){
            vector <ListNode*> merged;

            for(int i=0; i<lists.size(); i+=2){
                ListNode* list1= lists[i];
                ListNode* list2= nullptr; 
                //checks that list2 is in boundry 
                if(i+1<lists.size()){
                    list2= lists[i+1];
                }

                merged.push_back( mergeTwoLists(list1, list2) );

            }
            lists=merged;
        }
        return lists[0];

    }
};
