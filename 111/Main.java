import java.util.ArrayList;
import java.util.Scanner;

class Main {

	public static void main(String[] argv) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int nextVal;
		ArrayList<Integer> ranks = new ArrayList<Integer>();
		for (int i = 1; i <= n; i++){
			nextVal = sc.nextInt();
			ranks.add(nextVal);
		}

		while (sc.hasNextInt()) {
			ArrayList<Integer> list = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				nextVal = sc.nextInt();
				list.add(nextVal);
			}

			printLCS(rank2position(ranks), rank2position(list), n);
		}
	}

	private static void printLCS(ArrayList<Integer> first,
			ArrayList<Integer> second, int n) {

		int[][] table = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			table[0][i] = 0;
			table[i][0] = 0;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (first.get(i-1) == second.get(j-1))
					table[i][j] = 1 + table[i - 1][j - 1];
				else
					table[i][j] = Math.max(table[i][j - 1], table[i - 1][j]);
			}
		System.out.println(table[n][n]);
	}
	
	private static ArrayList<Integer> rank2position(ArrayList<Integer> list){
		int n = list.size();
		
		//TODO fix the stupid initialization
		ArrayList<Integer> positionList  = new ArrayList<Integer> (n);
		for (int i = 0; i < n; i++)
			positionList.add(-1);
		
		for (int i = 0; i < n; i++)
			positionList.set(list.get(i) - 1, i);
		return positionList;
	}

}
