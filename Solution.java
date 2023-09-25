public class Solution {
    public int solve(int[] A, int B) {
        HashSet<Integer> set = new HashSet<>();
        // 1 1 1 1 5 //  B = 0
        // set = 1
        for(int i = 0 ; i < A.length ; i++){
            if(set.contains(A[i] + B) || set.contains(A[i] - B)){
                return 1;
            }
            set.add(A[i]);
        }
        return 0;
    }
}