class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        List<Set<Integer>> freqs = new ArrayList<>();
        for (int i = 0; i <= nums.length; i++) {
            freqs.add(new HashSet<>());
        }
        for (int num: nums) {
            freqs.get(0).add(num);
        }

        Map<Integer, Integer> freq = new HashMap<>();
        for (int num: nums) {
            freq.putIfAbsent(num, 0);
            var f = freq.get(num);
            freqs.get(f).remove(num);
            freqs.get(f + 1).add(num);
            freq.put(num, f + 1);
        }
        int size = 0;
        int[] res = new int[k];
        for (int i = nums.length; i >= 0 && size <= k; i--) {
            Set<Integer> s = freqs.get(i);
            for (Integer n : s) {
                if (size >= k) break;
                res[size] = n;
                size++;
            }
        }
        return res;
    }
}
