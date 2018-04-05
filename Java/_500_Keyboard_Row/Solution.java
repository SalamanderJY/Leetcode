class Solution {
    public String[] findWords(String[] words) {
        int[] dict = new int[26];
        String[] rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.length; i++) {
            for (int j = 0; j < rows[i].length(); j++) 
                dict[rows[i].charAt(j) - 'A'] = 1 << i;
        }
        ArrayList<String> res = new ArrayList<String>();
        for (String w : words) 
        {
            int mark = dict[w.toUpperCase().charAt(0) - 'A'];
            for (int i = 0; i < w.length(); i++) 
            {
                if (mark != dict[w.toUpperCase().charAt(i) - 'A'])
                    break;
                if (i == w.length() - 1)
                    res.add(w);
            }
        }
        return res.toArray(new String[res.size()]);
    }
}