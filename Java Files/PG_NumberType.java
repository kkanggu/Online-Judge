import java.util.Arrays;

public class PG_NumberType {
	public int solution(String numbers) {
		int[][][] dp = new int[numbers.length() + 1][10][10];
		int[][] weight = {      // [a][b] -> weight a to b
				{1, 7, 6, 7, 5, 4, 5, 3, 2, 3},
				{7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
				{6, 2, 1, 2, 3, 2, 3, 5, 4, 5},
				{7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
				{5, 2, 3, 5, 1, 2, 4, 2, 3, 5},
				{4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
				{5, 5, 3, 2, 4, 2, 1, 5, 3, 2},
				{3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
				{2, 5, 4, 5, 3, 2, 3, 2, 1, 2},
				{3, 6, 5, 4, 5, 3, 2, 4, 2, 1}
		};

		for (int[][] arrayDimension2 : dp) {
			for (int[] arrayDimension1 : arrayDimension2) {
				Arrays.fill(arrayDimension1, 1000000);
			}
		}
		dp[0][4][6] = 0;

		for (int i = 1; i <= numbers.length(); ++i) {
			int num = numbers.charAt(i - 1) - '0';
			for (int j = 0; j < 10; ++j) {
				for (int k = 0; k < 10; ++k) {
					if (1000000 == dp[i - 1][j][k]) {
						continue;
					}

					if (j != num) {
						dp[i][j][num] = Math.min(dp[i][j][num], dp[i - 1][j][k] + weight[k][num]);
					}
					if (k != num) {
						dp[i][num][k] = Math.min(dp[i][num][k], dp[i - 1][j][k] + weight[j][num]);
					}
				}
			}
		}

		return Arrays.stream(dp[numbers.length()])
				.flatMapToInt(Arrays::stream)
				.min()
				.getAsInt();
	}
}
