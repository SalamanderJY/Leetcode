class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(res, new ArrayList<Integer>(), candidates, target, 0);
        res = res.stream().distinct().collect(Collectors.toList());
        return res;
    }

    private void backtrack(List<List<Integer>> res, ArrayList<Integer> current, int[] candidates, int target, int index) {
        if (target < 0 || index > candidates.length)
            return;
        if (target == 0) {
            res.add(new ArrayList<Integer>(current));
            return;
        }
        else if (index <= candidates.length - 1) {
            current.add(candidates[index]);
            backtrack(res, current, candidates, target - candidates[index], index + 1);
            current.remove(current.indexOf(candidates[index]));
            backtrack(res, current, candidates, target, index + 1);
        }
    }
}