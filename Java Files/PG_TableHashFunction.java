import java.util.Arrays;

public class PG_TableHashFunction {
	public static void main(String[] args) {
		solution(new int[][]{{2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3}}, 2, 2, 3);
	}

	public static int solution(int[][] data, int col, int row_begin, int row_end) {
		int answer = 0;
		Arrays.sort(data, (o1, o2) -> {
			if (o1[col - 1] == o2[col - 1]) {
				return o2[0] - o1[0];
			}
			return o1[col - 1] - o2[col - 1];
		});

		for (int i = row_begin - 1; i < row_end; i++) {
			int colNum = i;
			int sum = Arrays.stream(data[i])
					.map(value -> value % (colNum + 1))
					.sum();
			answer ^= sum;
		}

		return answer;
	}
}
