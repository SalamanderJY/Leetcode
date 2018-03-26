class Solution {
    public int compress(char[] chars) {
        int i = 0;
        for (int j = 0; j < chars.length;)
        {
            if (j == chars.length - 1 || chars[j] != chars[j + 1])
                chars[i++] = chars[j++];
            else
            {
                int cur = j;
                while (j < chars.length && chars[j] == chars[cur])
                    j++;
                chars[i++] = chars[cur];
                char[] num = Integer.toString(j - cur).toCharArray();
                for (char c : num)
                    chars[i++] = c;
            }
        }
        return i;
    }
}