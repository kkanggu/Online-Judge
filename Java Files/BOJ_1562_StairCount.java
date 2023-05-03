import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_1562_StairCount {
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
		int answer = 0;
		int[][][] dp = new int[n][10][1024];

		for (int i = 1; i < 10; ++i) {
			dp[0][i][1 << i] = 1;
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (0 != j) {
					for (int k = 0; k < 1024; ++k) {
						dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
						dp[i][j][k | (1 << j)] %= 1000000000;
					}
				}
				if (9 != j) {
					for (int k = 0; k < 1024; ++k) {
						dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
						dp[i][j][k | (1 << j)] %= 1000000000;
					}
				}
			}
		}

		for (int i = 0; i < 10; ++i) {
			answer += dp[n - 1][i][1023];
			answer %= 1000000000;
		}

		return answer;
	}
}
