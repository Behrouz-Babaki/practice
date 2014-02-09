import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

class Main {

	public static void main(String[] args) {

		BigInteger height_initial, num_workers;
		String line = null;

		String height_initial_str = null;
		String num_workers_str = null;

		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		try {
			line = reader.readLine();
			StringTokenizer tokenizer = new StringTokenizer(line);
			height_initial_str = tokenizer.nextToken();
			num_workers_str = tokenizer.nextToken();
		} catch (IOException e) {
			e.printStackTrace();
		}

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
				while (height_initial.compareTo(BigInteger.ONE) != 0) {
					total_height = total_height.add(height_initial);
					height_initial = height_initial.divide(new BigInteger("2"));
				}
				total_height = total_height.add(BigInteger.ONE);
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
							&& ((N.add(BigInteger.ONE)).pow(val))
									.compareTo(height_initial) == 0) {
						success = true;
						depth = val;
					} else
						N = N.add(BigInteger.ONE);
				}

				if (success) {
					System.out.print((N.pow(depth).subtract(BigInteger.ONE)
							.divide(N.subtract(BigInteger.ONE))));
					System.out.print("\t");

					BigInteger total_height = BigInteger.ZERO;
					/* @Thrid method */
					BigInteger NP1 = N.add(BigInteger.ONE);
					BigInteger numer0 = (NP1.pow(depth + 1)).subtract(N
							.pow(depth + 1));
					BigInteger numer = numer0.multiply(height_initial);
					BigInteger denom = NP1.pow(depth);
					total_height = numer.divide(denom);

					/*
					 * @First method BigInteger current_height = new BigInteger(
					 * String.valueOf(height_initial)); ; BigInteger
					 * current_number = BigInteger.ONE; while
					 * (current_height.intValue() >= 1) { total_height =
					 * total_height.add(current_number
					 * .multiply(current_height)); current_number =
					 * N.multiply(current_number); current_height =
					 * current_height.divide(N .add(BigInteger.ONE)); }
					 */

					/*
					 * @second method for (int counter = 0; counter <= depth;
					 * counter++) { BigInteger numer = height_initial.multiply(N
					 * .pow(counter)); BigInteger denom = (N.add(new
					 * BigInteger("1"))) .pow(counter); BigInteger current_sum =
					 * numer.divide(denom); total_height =
					 * total_height.add(current_sum); }
					 */
					System.out.println(total_height.toString());
				}
			}

			try {
				line = reader.readLine();
				StringTokenizer tokenizer = new StringTokenizer(line);
				height_initial_str = tokenizer.nextToken();
				num_workers_str = tokenizer.nextToken();
			} catch (IOException e) {
				e.printStackTrace();
			}

			height_initial = new BigInteger(height_initial_str);
			num_workers = new BigInteger(num_workers_str);

		}

	}

}
