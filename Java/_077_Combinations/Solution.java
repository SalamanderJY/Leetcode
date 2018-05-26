class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> stack = new ArrayList<Integer>();
        int x = 1;
        while (true) {
            int l = stack.size();
            if (l == k) {
                //List<Integer> temp = new ArrayList<Integer>(stack);
                ans.add(new ArrayList<Integer>(stack));
            }
            // there is not enough number to choose OR stack is full.
            if (l == k || k - l > n - x + 1) {
                if (stack.size() == 0)
                    return ans;
                x = stack.get(stack.size() - 1) + 1;
                stack.remove(stack.size() - 1);
            }
            else {
                stack.add(x);
                x++;
            }
        }
    }
}