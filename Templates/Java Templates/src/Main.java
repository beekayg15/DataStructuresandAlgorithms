import java.util.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;

class Reader {
    BufferedReader br;
    StringTokenizer st;

    Reader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public int nextInt() throws IOException {
        st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }

    public String nextString() throws IOException {
        st = new StringTokenizer(br.readLine());
        return "" + st.nextToken();
    }

    public ArrayList<Integer> nextIntArray(int n) throws IOException {
        ArrayList<Integer> arr= new ArrayList<>();
        for(int i = 0; i < n; i ++) {
            int x = readInt();
            arr.add(x);
        }

        return arr;
    }
}

class Solver {
    public void solve() {
        Reader rd = new Reader();


    }
}

public class Main {
    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
    }
}
