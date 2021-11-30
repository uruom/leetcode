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
        ListNode* num=head;
        int al=1;
        while(num->next!=NULL)
        {
            al++;
            num=num->next;
        }
        n=al-n;
        num=head;
        
        for(int i=1;i<n;i++)
        num=num->next;
        if(n!=0)
        num->next=num->next->next;
        else head=head->next;
 //       cout<<num->val;
 //       cout<<n<<head->val<<endl;
        return head;
    }
};
