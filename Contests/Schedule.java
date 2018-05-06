import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.Date;

public class Template {

    public static void main(String[] args) throws IOException {
        init(); // Initialize input/output from template
        int TC = in.nextInt();
        for (int tc = 1; tc <= TC; tc++) {
          Date[][] dates = new Date[4][2];
          for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 2; j++) {
              int year, month, date, hours, minutes, seconds;
              date = in.nextInt();
              month = in.nextInt();
              year = in.nextInt();
              hours = in.nextInt();
              minutes = in.nextInt();
              seconds = in.nextInt();

              year -= 3000;
              dates[i][j] = new Date(year, month, date, hours, minutes, seconds);
            }
          }
        }
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