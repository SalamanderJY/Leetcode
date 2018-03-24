class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int[] win = new int[26];
        int[] fixwin = new int[26];

        if (s.length() == 0 || p.length() == 0 || p.length() > s.length())
            return res;

        for (int i = 0; i < p.length(); i++)
            fixwin[p.charAt(i) - 'a']++;

        for (int i = 0; i < p.length(); i++)
            win[s.charAt(i) - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            if (isMatch(fixwin, win))
                res.add(i);
            
            if ((i + p.length()) < s.length()) {
                win[s.charAt(i) - 'a']--;
                win[s.charAt(i + p.length()) - 'a']++;
            } 
            else 
                break;
        }
        return res;
    }
    
    public boolean isMatch(int[] fixwin, int[] win) {
        for (int i = 0; i < win.length; i++)
            if (win[i] != fixwin[i])
                return false;
        return true;
    }
}