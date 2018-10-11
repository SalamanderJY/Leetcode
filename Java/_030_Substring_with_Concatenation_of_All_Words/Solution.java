class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        if (words.length == 0)
            return new ArrayList<Integer>();   
        int word_size = words[0].length();
        int word_nums = words.length;
        Map<String, Integer> word_count = new HashMap<String, Integer>();
        Map<String, Integer> word_count_temp = new HashMap<String, Integer>();
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < word_nums; i++) {
            if (word_count.containsKey(words[i])) {
                int count = word_count.get(words[i]) + 1;
                word_count.put(words[i], count);
            }
            else {
                word_count.put(words[i], 1);
            }
        }
        for (int i = 0; i < s.length() - word_nums * word_size + 1; i++) {
            int j = 0;
            word_count_temp.clear();
            for (j = 0; j < word_nums; j++) {
                String word = s.substring(i + j * word_size, i + j * word_size + word_size);
                if (word_count.containsKey(word)) {
                    if (word_count_temp.containsKey(word)) {
                        int count = word_count_temp.get(word) + 1;
                        word_count_temp.put(word, count);
                    }
                    else {
                        word_count_temp.put(word, 1);
                    }
                    if (word_count_temp.get(word) > word_count.get(word))
                        break;
                }
                else
                    break;
            }
            if (j == word_nums)
                res.add(i);
        }
        return res;
    }
}
