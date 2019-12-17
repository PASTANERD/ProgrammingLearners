package IO;
import java.io.*;
import java.util.*;

public class BufferedReader_{
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader (new InputStreamReader (System.in));
		String s = bf.readLine(); //String
		int i = Integer.parseInt(bf.readLine()); //Int
		
		StringTokenizer st = new StringTokenizer(s);
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		
		String array[] = s.split(" ");
		
		BufferedWriter bw = new BufferedWriter (new OutputStreamWriter(System.out));
		bw.write(s+"\n");
		bw.flush();
		bw.close();
	}
}   
