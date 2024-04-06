import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int answer = 1, max_point = 0, wanho_score = scores[0][0] + scores[0][1];
        int[] wanho = scores[0];
        
        Arrays.sort(scores, new Comparator<int[]>(){
            @Override
            public int compare(int[] a1, int[] a2){
                if(a1[1] == a2[1]) return a1[0] - a2[0];
                else return a2[1] - a1[1];
            }
        });
        
        for(int[] s : scores){
            if(s[0] > wanho[0] && s[1] > wanho[1]) return -1;
            
            if(max_point <= s[0]){
                max_point = s[0];
                if(wanho_score < (s[0] + s[1])){
                    answer++;
                }
            }
        }        
        return answer;
    }
}