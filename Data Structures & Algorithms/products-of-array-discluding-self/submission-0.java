class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] prefix = new int[nums.length];
        int[] suffix = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            if (i == 0) {
                prefix[i] = nums[0];
            } else {
                prefix[i] = prefix[i - 1] * nums[i];
            }
        }

        for (int i = nums.length - 1; i >= 0; i--) {
            if (i == nums.length - 1) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = suffix[i + 1] * nums[i];
            }
        }

        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (i == 0) {
                res[i] = suffix[i + 1];
            } else if (i == nums.length - 1) {
                res[i] = prefix[nums.length - 2];
            } else {
                res[i] = prefix[i - 1] * suffix[i + 1];
            }
        }
        
        return res;
    }
}  
