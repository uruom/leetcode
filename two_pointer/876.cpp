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
    ListNode* middleNode(ListNode* head) {
        int n=1;
        ListNode* num=head;
        while(num->next!=NULL)
        {
            n++;
            num=num->next;
        }
        n=n/2;
        num=head;
        for(int i=0;i<n;i++)
        num=num->next;
        return num;
    }
};
