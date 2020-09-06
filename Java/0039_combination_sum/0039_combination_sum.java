class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        // Arrays.sort(candidates);
        backtrack(res, new ArrayList<Integer>(), candidates, target, 0);
        return res;
    }

    private void backtrack(List<List<Integer>> res, ArrayList<Integer> current, int[] candidates, int target, int index) {
        if (target < 0 || index >= candidates.length)
            return;
        if (target == 0) {
            res.add(new ArrayList<Integer>(current));
            return;
        }
        else {
            current.add(candidates[index]);
            backtrack(res, current, candidates, target - candidates[index], index);
            current.remove(current.indexOf(candidates[index]));
            backtrack(res, current, candidates, target, index + 1);
        }
    }
}