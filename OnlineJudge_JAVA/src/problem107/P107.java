package problem107;

import java.math.BigInteger;

public class P107 {

	public static void main(String[] args) {
		int heigth_initial, 
			num_workers,
			num_non_working;
		
		heigth_initial = 5764801;
		num_workers = 1679616;
		
		num_non_working = 1;
		
		boolean success = false;
		int N = 2;
		int depth = 0;
		/*Try different values of N until one matches what want*/ 
		while (!success && N <= (heigth_initial - 1)){
			int val = 1;
			double num;
			while ((num = Math.pow((double)(N), (double)val)) < num_workers)
				val++;
			if ((int)num == num_workers){
				success = true;
				depth = val;
			}
			else
				N++;	
		}
		
		if (success)
			System.out.println("N:" + N + "\ndepth:" + depth);
		System.out.println((int)((Math.pow(N,depth) -1)/(N -1)));
		
		BigInteger current_height = new BigInteger(String.valueOf(heigth_initial));
		BigInteger current_number = BigInteger.ONE;
		BigInteger total_height = BigInteger.ZERO;
		while (current_height.intValue() >= 1){
			total_height = total_height.add(current_number.multiply(current_height));
			current_number = BigInteger.valueOf(N).multiply(current_number);
			current_height = current_height.divide(BigInteger.valueOf(N+1));
		}
		
		System.out.println(total_height.toString());
		
	}

}
