// https://open.kattis.com/problems/anagramcounting

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class anagramcounting {
	
	public static ArrayList<BigInteger> factorial;
	
	public static void main(String[] args) {
		factorial = new ArrayList<BigInteger>();
		factorial.add(BigInteger.ZERO);
		BigInteger bi = BigInteger.ONE;
		for (int i=1;i<=200;i++) {
			BigInteger curr = BigInteger.valueOf(i);
			bi = bi.multiply(curr);
			factorial.add(bi);
		}

		// for (int i=1;i<=52;i++) {
		// 	System.out.println(factorial.get(i));
		// }
		// return;

		Scanner cin = new Scanner(System.in);
		String line;
		while (cin.hasNext()) {
			
			HashMap<Character,Integer> map = new HashMap<Character,Integer>();
			line = cin.next();
			for (int i=0;i<line.length();i++) {
				Integer freq = map.get(line.charAt(i));
				if (freq != null) {
					freq += 1;
					map.put(line.charAt(i),freq);
				}
				else {
					map.put(line.charAt(i),1);
				}
			}

			BigInteger ans = factorial.get(line.length());
			Iterator iterator = map.entrySet().iterator(); 
			while (iterator.hasNext()) { 
				Map.Entry mapElement = (Map.Entry)iterator.next(); 
				int divisor = ((int)mapElement.getValue()); 
				ans = ans.divide(factorial.get(divisor));
			}
			System.out.println(ans.toString());
		}
		return;
	}
}