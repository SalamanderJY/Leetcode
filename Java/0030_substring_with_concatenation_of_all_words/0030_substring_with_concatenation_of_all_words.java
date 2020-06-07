class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        if (words.length == 0) {
            return new ArrayList<Integer>();
        }   
        int wordsSize = words[0].length();
        int wordsNum = words.length;
        Map<String, Integer> wordCnt = new HashMap<String, Integer>();
        Map<String, Integer> wordCntTmp = new HashMap<String, Integer>();
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < wordsNum; i++) {
            if (wordCnt.containsKey(words[i])) {
                int count = wordCnt.get(words[i]) + 1;
                wordCnt.put(words[i], count);
            }
            else {
                wordCnt.put(words[i], 1);
            }
        }
        for (int i = 0; i < s.length() - wordsNum * wordsSize + 1; i++) {
            int j = 0;
            wordCntTmp.clear();
            for (j = 0; j < wordsNum; j++) {
                String word = s.substring(i + j * wordsSize, i + j * wordsSize + wordsSize);
                if (wordCnt.containsKey(word)) {
                    if (wordCntTmp.containsKey(word)) {
                        int count = wordCntTmp.get(word) + 1;
                        wordCntTmp.put(word, count);
                    }
                    else {
                        wordCntTmp.put(word, 1);
                    }
                    if (wordCntTmp.get(word) > wordCnt.get(word)) {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if (j == wordsNum) {
                res.add(i);
            }
        }
        return res;
    }
}
