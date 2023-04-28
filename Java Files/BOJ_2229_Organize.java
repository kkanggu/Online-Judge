import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_2229_Organize {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n;
		int[] scores;

		n = Integer.parseInt(br.readLine());
		scores = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

		int answer = solution(n, scores);
		sb.append(answer);
		System.out.println(sb);
	}

	public static int solution(int n, int[] scores) {
		int[] dp = new int[scores.length + 1];

		for (int i = 1; i < scores.length; ++i) {
			int max = scores[i];
			int min = scores[i];

			dp[i + 1] = dp[i];
			for (int j = i - 1; j >= 0; --j) {
				max = Math.max(max, scores[j]);
				min = Math.min(min, scores[j]);
				dp[i + 1] = Math.max(dp[i + 1], dp[j] + max - min);
			}
		}

		return dp[scores.length];
	}
}
