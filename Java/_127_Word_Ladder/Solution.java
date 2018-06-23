class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<String> visit = new LinkedList<String>();
        Set<String> words = new HashSet<>();
        words.addAll(wordList);
        visit.offer(beginWord);
        HashMap<String, Integer> maps = new HashMap<String, Integer>();
        maps.put(beginWord, 1);
        if (words.contains(beginWord))
            words.remove(beginWord);
        
        while (!visit.isEmpty()) {
            String top = visit.poll();      
            int level = maps.get(top);
            for (int i = 0; i < top.length(); i++) {
                StringBuilder builder = new StringBuilder(top);
                for (char c = 'a'; c <= 'z'; c++) {
                    builder.setCharAt(i, c);
                    String temp = builder.toString();
                    if (temp.equals(top))
                        continue;
                    else if (temp.equals(endWord) && words.contains(temp))
                        return level + 1;
                    else if (words.contains(temp)) {
                        visit.offer(temp);
                        words.remove(temp);
                        maps.put(temp, level + 1);
                    }
                }
            }
        }
        return 0;
    }
}