import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Template {

    public static void main(String[] args) throws IOException {
        init(); // Initialize input/output from template
        out.close();
    }


    /* PrintWriter and BufferedReader Template from Codeforces */
    public static MyScanner in;
    public static PrintWriter out;
    public static void init(){
        in = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
    }
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
        MyScanner(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch(IOException e){ e.printStackTrace(); }
            }
            return st.nextToken();
        }
        int nextInt(){return Integer.parseInt(next());}
        long nextLong(){return Long.parseLong(next());}
        double nextDouble(){return Double.parseDouble(next());}
        String nextLine(){
            String str = "";
            try{
                str = br.readLine();
            }catch(IOException e){ e.printStackTrace(); }
            return str;
        }
    }

    /* End of Template */
}