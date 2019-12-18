import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class BaseConversion{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Double ADecimal = Double.parseDouble(st.nextToken());
        int BDecimal = Integer.parseInt(st.nextToken());

        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        double A[] = new double[N];
        int B[] = new int[30];

        double target = 0.0;

        for(int i=N-1; i>=0 ; i-- ){
            A[i] = Double.parseDouble(st.nextToken());
        }

        for(int i =0; i<N; i++){
            target += A[i]*Math.pow(ADecimal , i);
        }

        double quota = target;
        double remainder;
        int idx = 0;
        int stop = 0;
        do{ 
            remainder = Math.floor(quota%BDecimal);
            quota = Math.floor(quota/BDecimal);
            B[idx] = (int)remainder;
            idx++;
            stop++;
        } while(quota != 0.0);
        
        // target = 0.0;
        // for(int i =0; i<N; i++){
        //     target += B[i]*Math.pow(BDecimal , i);
        // }

        for(int i=stop-1; i>=0 ; i-- )
            System.out.print(B[i] + " ");
    }
}

// 17 8
// 2
// 2 16
// 6 2 