class Solution {
    public boolean isAnagram(String s, String t) {
        int[] freqs_s = new int[26];
        int[] freqs_t = new int[26];
        for (char c: s.toCharArray()) {
            freqs_s[c - 'a']++;
        }
        for (char c: t.toCharArray()) {
            freqs_t[c - 'a']++;
        }
        System.out.println(freqs_s);
        return Arrays.equals(freqs_s, freqs_t);
    }
}
