import java.io.*;
import java.util.*;

public class Main {
    
    static int n, answer;
    static int[] number;
    static List<Integer> list = new ArrayList<>();
    
    public static int binary_search(int n){
        int lo = 0, hi = list.size() - 1, idx = 0;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(n <= list.get(mid)){
                idx = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return idx;
    }
    
    public static void LIS(){
        for(int i = 1; i < n; i++){
            if(number[i] > list.get(list.size() - 1)) list.add(number[i]);
            else list.set(binary_search(number[i]), number[i]);
        }
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        number = new int[n];
        for(int i = 0; i < n; i++) number[i] = Integer.parseInt(st.nextToken());
        list.add(number[0]);
        LIS();
        // System.out.println(list;
        System.out.println(list.size());
        
    }
}