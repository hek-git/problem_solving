import java.io.*;
import java.util.*;

public class Main {

    static long N, K;

    public static long binary_search(){
        long lo = 0, hi = N * N, answer = 0;
        while(lo <= hi){
            long cnt = 0, mid = (lo + hi) / 2;
            for(long i = 1; i <= N; i++) cnt += Math.min(mid / i, N);
            if(cnt >= K) {
                answer = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return answer;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        System.out.println(binary_search());
    }
}