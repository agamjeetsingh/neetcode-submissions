class Solution {
    public boolean hasDuplicate(int[] nums) {
        var set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        
        return set.size() != nums.length;
    }
}