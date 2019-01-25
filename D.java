import java.util.*;
import java.io.*;

public class D{

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int a,b,c,bal,n;

    static void balanceA(char[] arr){
        if(a<bal){
            for(int i=0;i<n;i++){
                if(arr[i]=='1' && b>bal){
                    arr[i] = '0';
                    b--;
                    a++;
                }

                if(arr[i]=='2' && c>bal){
                    arr[i] = '0';
                    c--;
                    a++;
                }

                if(a==bal)
                    break;
            }
        }

        return;
    }

    static void balanceB(char[] arr){
        int end = 0, rem = bal;

        for(int i=0;i<n;i++)
            if(arr[i] == '0'){
                rem--;
                end = i;
                if(rem<=0)
                    break;
            }

        if(b<bal){
            for(int i=0;i<n;i++){
                if(arr[i]=='2' && c>bal){
                    arr[i] = '1';
                    c--;
                    b++;
                }

                if(b==bal)
                    return;
            }
            //System.out.println(end);
            for(int i=end+1;i<n;i++){
                if(arr[i]=='0' && a>bal){
                    arr[i] = '1';
                    a--;
                    b++;
                }

                if(b==bal)
                    return;
            }
        }

        return;
    }

    static void balanceC(char[] arr){
        if(c<bal){
            for(int i=n-1;i>=0;i--){
                if(arr[i]=='1' && b>bal){
                    arr[i] = '2';
                    b--;
                    c++;
                }
                if(c==bal)
                    return;
            }

            for(int i=n-1;i>=0;i--){
                if(arr[i]=='0' && a>bal){
                    arr[i] = '2';
                    a--;
                    c++;
                }

                if(c==bal)
                    return;
            }
        }

        return;
    }

    public static void main (String[] args) throws Exception{
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        n = sc.nextInt();
        char[] arr = sc.nextLine().toCharArray();

        a=0; b=0; c=0; bal = n/3;

        for(int i=0;i<n;i++){
            if(arr[i]=='0')a++;
            if(arr[i]=='1')b++;
            if(arr[i]=='2')c++;
        }

        balanceA(arr);
        balanceB(arr);
        balanceC(arr);
        for(int i=0;i<n;i++)
            out.print(arr[i]);

        out.close();
    }
}