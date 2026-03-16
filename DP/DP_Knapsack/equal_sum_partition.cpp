class Solution {
public:
    int dp[201][10001];
    bool solve(int n,int targetSum,vector<int>& nums){
        if(targetSum == 0){
            return true;
        }
        else if(n<0){
            return false;
        }
        if(dp[n][targetSum] != -1){
            return dp[n][targetSum];
        }
        if(nums[n]<=targetSum){
            return dp[n][targetSum] = solve(n-1,targetSum-nums[n],nums) || solve(n-1,targetSum,nums);
        }else{
            return dp[n][targetSum] = solve(n-1,targetSum,nums);
        }
    }

    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i: nums){
            totalSum +=i;
        }
        if(totalSum%2!=0){
            return false;
        }
        memset(dp, -1, sizeof(dp)); // initialization of that dp array
        int targetSum = totalSum / 2;
        int n = nums.size() -1;
         return solve(n,targetSum,nums);
    }
};
