import java.math.BigInteger;
import java.util.Scanner;

class P107 {

	public static void main(String[] args) {
		BigInteger height_initial, num_workers;

		Scanner sc = new Scanner(System.in);

		String height_initial_str = sc.next();
		String num_workers_str = sc.next();
		height_initial = new BigInteger(height_initial_str);
		num_workers = new BigInteger(num_workers_str);


		while (height_initial.compareTo(BigInteger.ZERO) != 0
				&& num_workers.compareTo(BigInteger.ZERO) != 0) {

			if (num_workers.compareTo(BigInteger.ONE) == 0) {
				int depth = 0;
				while ((new BigInteger("2").pow(depth))
						.compareTo(height_initial) != 0)
					depth++;
				System.out.print(depth + "\t");
				BigInteger total_height = BigInteger.ZERO;
				while (height_initial.compareTo(new BigInteger("1")) != 0) {
					total_height = total_height.add(height_initial);
					height_initial = height_initial.divide(new BigInteger("2"));
				}
				total_height = total_height.add(new BigInteger("1"));
				System.out.println(total_height.toString());
			} else {
				boolean success = false;

				/*
				 * TODO make it work for N = 1 without using case-based
				 * exceptions
				 */
				BigInteger N = new BigInteger("2");
				int depth = 0;
				/* Try different values of N until one matches what want */
				while (!success
						&& N.compareTo(height_initial.subtract(new BigInteger(
								"1"))) != 1) {
					int val = 1;
					BigInteger num;
					while ((num = N.pow(val)).compareTo(num_workers) == -1)
						val++;
					if (num.compareTo(num_workers) == 0
							&& ((N.add(new BigInteger("1"))).pow(val))
									.compareTo(height_initial) == 0) {
						success = true;
						depth = val;
					} else
						N = N.add(new BigInteger("1"));
				}

				if (success) {
					System.out.print((N.pow(depth)
							.subtract(new BigInteger("1")).divide(N
							.subtract(new BigInteger("1")))));
					System.out.print("\t");

					// BigInteger current_height = new BigInteger(
					// String.valueOf(height_initial));
					BigInteger total_height = BigInteger.ZERO;
					// while (current_height.intValue() >= 1) {
					// total_height = total_height.add(current_number
					// .multiply(current_height));
					// current_number = N.multiply(current_number);
					// current_height = current_height.divide(N
					// .add(new BigInteger("1")));
					// }
					for (int counter = 0; counter <= depth; counter++) {
						BigInteger numer = height_initial.multiply(N
								.pow(counter));
						BigInteger denom = (N.add(new BigInteger("1")))
								.pow(counter);
						BigInteger current_sum = numer.divide(denom);
						total_height = total_height.add(current_sum);
					}
					System.out.println(total_height.toString());
				}
			}
			height_initial_str = sc.next();
			num_workers_str = sc.next();
			height_initial = new BigInteger(height_initial_str);
			num_workers = new BigInteger(num_workers_str);

		}

		sc.close();
	}

}
