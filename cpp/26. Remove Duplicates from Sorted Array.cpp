class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1, n = nums.size();
        if(n <= 1) return n;
        while(fast < n){
            if(nums[fast] != nums[slow - 1]) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};

