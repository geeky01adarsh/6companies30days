// Question link :- https://leetcode.com/problems/rotate-function/
// idea sliding window
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans=INT_MIN;
        int sum=0, sum1=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            sum1 += nums[i]*i;
        }
        ans = sum1;
        for(int i=n-1; i>=0; i--){
            sum1 += sum - (nums[i]*n);
            ans = max(ans , sum1);
        }
        return ans;
    }
};