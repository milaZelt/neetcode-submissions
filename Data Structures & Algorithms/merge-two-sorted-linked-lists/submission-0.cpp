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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr){
            return list2;
        }
        if (list2==nullptr){
            return list1;
        }
        
        
        ListNode* mergedHead;
        ListNode* lastAdded;

        if (list1->val <= list2->val){
            mergedHead=list1;
            lastAdded=list1;
            list1=list1->next;
        }else{
            mergedHead=list2;
            lastAdded=list2;
            list2=list2->next;
        }

        while(list1!=nullptr && list2!=nullptr ){
            if (list1->val <= list2->val){
                lastAdded->next=list1;
                lastAdded=lastAdded->next;
                list1=list1->next;

            }else{
                lastAdded->next=list2;
                lastAdded=lastAdded->next;
                list2=list2->next;
            }
        }
        if(list2!=nullptr){
            lastAdded->next=list2;
        }else if(list1!=nullptr){
            lastAdded->next=list1;
        }
        return mergedHead;
    }
};
