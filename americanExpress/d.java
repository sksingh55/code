import java.io.*;
import java.util.*;

public class d {

    static long mod = 1000000007L;
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        StringBuilder result = new StringBuilder("");
        int t = sc.nextInt();
        int A, B, C, previous, end, stop, k;
        long ans;
        while (t-- > 0) {
            A = sc.nextInt();
            B = sc.nextInt();
            C = sc.nextInt();
            ans = 0;
            for (int b = 1; b <= B; b++) {
                end = b * b;
                previous = A;
                stop = (b + 1 < A) ? b + 1 : A;
                for (int a = 1; a < stop; a++) {
                    k = (b * b / (a)) + 1;
                    if (k < C) {
                        ans = (ans + (C - k));
                        ans = ans % mod;
                    }
                    if (previous - k < 1 || (C - a) < 1)
                        continue;
                    ans += (previous - k) * (C - a);
                    ans = ans % mod;
                    previous = k;
                }
            }
            result.append(ans+"\n");
        }
        System.out.println(result);
    }

}