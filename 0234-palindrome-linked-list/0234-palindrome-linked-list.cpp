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
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL && fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    bool compare(ListNode* head1, ListNode* head2){
        while(head2 != NULL){
            if(head1->val != head2->val)
                return false;
            else{
            head1 = head1->next;
            head2 = head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        //finding middle node from the linked List
        ListNode* mid = middleNode(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        //reverse the half linked list
        head2 = reverse(head2);
        //compare the two LL
        bool compared = compare(head,head2);
        return compared;
    }
};