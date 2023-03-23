import java.util.Arrays;

public class PG_BestSet {
	public int[] solution(int n, int s) {
		int[] answer = new int[n];

		if (n > s) {
			return new int[]{-1};
		}

		Arrays.fill(answer, s / n);

		for (int i = answer[0] * n; i < s; ++i) {
			++answer[answer[0] * n + n - 1 - i];
		}

		return answer;
	}
}
