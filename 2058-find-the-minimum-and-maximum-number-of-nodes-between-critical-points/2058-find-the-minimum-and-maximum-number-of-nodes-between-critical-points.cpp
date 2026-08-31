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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        ListNode *curr = prev->next;
        ListNode *nxt = curr->next;
        int index = 1;
        int mini = 1e9;
        int maxi = -1e9;
        vector<int> ans;
        while(nxt!= NULL){
            if(curr->val>nxt->val && curr->val>prev->val){
                ans.push_back(index);
                index++;
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
            else if(curr->val<nxt->val && curr->val<prev->val){
                ans.push_back(index);
                index++;
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
            else{
                index++;
                prev = curr;
                curr = nxt;
                nxt = nxt->next;
            }
        }
        vector<int> sol(2,-1);
        int n = ans.size();
        if(n<2){
            return sol;
        }
        int l = ans[0];
        for(int i=1; i<n; ++i){
            mini = min(mini, ans[i]-ans[i-1]);
        }
        sol[0] = mini;
        sol[1]= ans[n-1]-ans[0];
        return sol;
    }
};