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
    ListNode* reverseLinkedList(ListNode* head){
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* previousNode = nullptr;
        ListNode* currentNode = head;
        while(currentNode != nullptr){
            ListNode* nextNode = currentNode -> next;
            currentNode -> next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        return previousNode;
    }

    void print(ListNode* head){
        ListNode* temp = head;
        while(temp){
            cout << temp -> val << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;
        if(head -> next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast-> next != nullptr && fast -> next -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode* newHead = reverseLinkedList(slow -> next);
        ListNode* temp = head;
        ListNode* tempNew = newHead;

        while(tempNew != nullptr && temp != nullptr){
            if(tempNew -> val != temp -> val){
                return false;
            }
            tempNew = tempNew -> next;
            temp = temp -> next;
        }

        reverseLinkedList(newHead);
        return true;
    }
};