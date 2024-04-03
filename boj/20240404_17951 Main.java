import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int answer = 0, N, K;
    static Integer[] arr;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static boolean check(int n){
        int idx = 0, sum = 0, group = 0;
        while(idx < arr.length){
            sum += arr[idx];
            if(sum >= n) {
                sum = 0;
                group++;
            }
            if(group >= K) return true;
            idx++;
        }
        return group >= K;
    }

    public static void binary_search(){
        int lo = 0, hi = 2000000;
        while(lo <= hi){
           int mid = (lo + hi) / 2;
           if(check(mid)){
               answer = mid;
               lo = mid + 1;
           }
           else hi = mid - 1;
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new Integer[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());

        binary_search();
        System.out.println(answer);
    }
}