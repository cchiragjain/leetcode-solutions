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
        // recursive
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* newHead = reverseList(head -> next);
        ListNode* nextNode = head -> next; // this is the node that was there before reversing the list
        nextNode -> next = head;

        head -> next = nullptr;

        return newHead;

        // iterative
        // if(head == nullptr || head -> next == nullptr){
        //     return head;
        // }

        // ListNode* previousNode = nullptr;
        // ListNode* currentNode = head;
        
        // while(currentNode != nullptr){
        //     ListNode* nextNode = currentNode -> next;
        //     currentNode -> next = previousNode;
        //     previousNode = currentNode;
        //     currentNode = nextNode;
        // }

        // return previousNode;
    }
};