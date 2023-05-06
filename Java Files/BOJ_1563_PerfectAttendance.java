import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_1563_PerfectAttendance {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n;

		n = Integer.parseInt(br.readLine());

		int answer = solution(n);
		sb.append(answer);
		System.out.println(sb);
	}

	public static int solution(int n) {
		int[][][] dp = new int[n][2][3];        // [day][late][absence]

		dp[0][0][0] = 1;
		dp[0][1][0] = 1;
		dp[0][0][1] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 3; ++k) {
					if (0 != k) {
						dp[i][j][k] += dp[i - 1][j][k - 1];
					} else {
						dp[i][j][0] += Arrays.stream(dp[i - 1][j]).sum();

						if (0 != j) {
							dp[i][j][0] += Arrays.stream(dp[i - 1][j - 1]).sum();
						}
					}
					dp[i][j][k] %= 1000000;
				}
			}
		}

		return Arrays.stream(dp[n - 1]).flatMapToInt(Arrays::stream).sum() % 1000000;
	}
}
