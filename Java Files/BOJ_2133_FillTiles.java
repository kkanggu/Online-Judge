import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_2133_FillTiles {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n;

		n = Integer.parseInt(br.readLine());

		int answer = solution(n);
		System.out.println(answer);
	}

	public static int solution(int n) {
		int[] dp = new int[16];
		Arrays.fill(dp,2);

		if (1 == n % 2) {
			return 0;
		}
		dp[0] = 3;
		n /= 2;

		for (int i = 1; i < n; ++i) {
			dp[i] += dp[i - 1] * 3;
			for (int j = 0; j < i - 1; ++j) {
				dp[i] += dp[j] * 2;
			}
		}

		return dp[n - 1];
	}
}
