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
        ListNode* dummyNode = new ListNode(-1);

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* curr = dummyNode;

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 -> val < temp2 -> val){
                curr -> next = temp1;
                temp1 = temp1 -> next;
            } else {
                curr -> next = temp2;
                temp2 = temp2 -> next;
            }
            curr = curr -> next;
        }

        while(temp1 != nullptr){
            curr -> next = temp1;
            temp1 = temp1 -> next;
            curr = curr -> next;
        }

        while(temp2 != nullptr){
            curr -> next = temp2;
            temp2 = temp2 -> next;
            curr = curr -> next;
        }

        return dummyNode -> next;
    }
};