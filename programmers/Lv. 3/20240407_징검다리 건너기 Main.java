class Solution {
    public boolean check(int[] stones, int k, int people){
        int continuous_zero = 0;
        boolean flag = false;
        for(int i = 0; i < stones.length; i++){
            int stone = stones[i] - people;
            if(stone <= 0 && flag) continuous_zero++;
            else if(stone <= 0 && !flag) {
                continuous_zero = 1;
                flag = true;
            } else {
                flag = false;
                continuous_zero = 0;
            }
            if(continuous_zero >= k) return false;
        }       
        return true;
    }
    
    public int binary_search(int[] stones, int k){
        int left = 1, right = 200000000, answer = 0;
        while(left <= right){
            int mid = (right + left) / 2;
            if(check(stones, k, mid)) {
                answer = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        return answer;
    }
    
    public int solution(int[] stones, int k) {        
        return 1 + binary_search(stones, k);
    }
}