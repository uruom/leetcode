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
    ListNode* turn(ListNode* head,ListNode* h_next)
    {

        if(h_next->next!=NULL)
        {
            ListNode* a=h_next->next;
            h_next->next=head;
            return turn(h_next,a);
        }
        else
        {
            h_next->next=head;
        //    head->next=NULL;
            return h_next;
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head!=NULL)
        {
            if(head->next!=NULL)
            {
                ListNode* ans=turn(head,head->next);
                head->next=NULL;
                return ans;
            }
            
            else
            return head;
        }
        else return head;
    }
};
