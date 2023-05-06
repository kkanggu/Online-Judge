import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_13703_SurvivalProbabilityOfWaterFlee {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int k, n;
		int[] temp;

		temp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		k = temp[0];
		n = temp[1];

		long answer = solution(k, n);
		sb.append(answer);
		System.out.println(sb);
	}

	public static long solution(int k, int n) {
		long[][] dp = new long[n + 1][k + n + 1];

		dp[0][k] = 1;
		for (int i = 1 ; i <= n; ++i) {
			for (int j = 1; j < k + n + 1; ++j) {
				if (1 != j) {
					dp[i][j] += dp[i - 1][j - 1];
				}
				if (k + n != j) {
					dp[i][j] += dp[i - 1][j + 1];
				}
			}
		}

		return Arrays.stream(dp[n]).sum();
	}
}
