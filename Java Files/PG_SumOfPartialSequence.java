public class PG_SumOfPartialSequence {
	public int[] solution(int[] sequence, int k) {
		int[] answer = new int[2];
		int left = 0;
		int right = 1;
		int[] dp = new int[sequence.length + 1];

		answer[1] = Integer.MAX_VALUE;

		for (int i = 1; i < dp.length; ++i) {
			dp[i] = dp[i - 1] + sequence[i - 1];
		}

		while (left != dp.length) {
			if ((dp[right] - dp[left] == k) && (right - left - 1 < answer[1] - answer[0])) {
				answer[0] = left;
				answer[1] = right - 1;
			} else if ((dp[right] - dp[left] <= k) && (right != dp.length - 1)) {
				++right;
			} else {
				++left;
			}
		}

		return answer;
	}
}
