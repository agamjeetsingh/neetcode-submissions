class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<List<Integer>, List<String>> map = new HashMap<>();
        
        for (String str : strs) {
            List<Integer> freqs = new ArrayList<>();
            for (int i = 0; i < 26; i++) { freqs.add(0); }
            for (char c : str.toCharArray()) {
                freqs.set(c - 'a', freqs.get(c - 'a') + 1);
            }
            map.putIfAbsent(freqs, new ArrayList<>());
            map.get(freqs).add(str);
        }

        return map.values().stream().toList();
    }
}
