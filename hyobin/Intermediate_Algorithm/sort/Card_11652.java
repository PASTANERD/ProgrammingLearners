package sort;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Card_11652 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		long N = Integer.parseInt(br.readLine());
		HashMap<BigInteger, BigInteger> map = new HashMap<BigInteger, BigInteger>();
		boolean first = true;
		BigInteger max = BigInteger.ZERO;
		BigInteger num;
		
		for(int i=0; i<N; i++) {
			BigInteger card = new BigInteger(br.readLine());
			if(first) {
				max = card;
				first = false;
				map.put(card, BigInteger.ONE);
				continue;
			}
			
			if(map.containsKey(card)) {
				num = map.get(card).add(BigInteger.ONE);
			} else num = BigInteger.ONE;
			
			if(num.compareTo(map.get(max)) == 1) max = card;
			else if ((num.compareTo(map.get(max))==0) && card.compareTo(max)<=0) max = card;
			map.put(card, num);
		}
		System.out.println(max);
	}

}
