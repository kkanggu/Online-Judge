public class PG_GatherSticker {
	public int solution(int[] sticker) {
		int answer = 0;
		int[][] dp = new int[sticker.length][2];        //[][0] =Pop 0th, [][1] =Don't pop 0th

		if (1 == sticker.length) {
			return sticker[0];
		}

		dp[0][0] = sticker[0];

		for (int i = 1; i < sticker.length; ++i) {
			if (1 < i) {
				dp[i][0] = Math.max(dp[i - 1][0], dp[i - 2][0] + sticker[i]);
				dp[i][1] = Math.max(dp[i - 1][1], dp[i - 2][1] + sticker[i]);
			} else {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1] + sticker[i];
			}
		}
		dp[sticker.length - 1][0] = 0;

		return Math.max(dp[sticker.length - 2][0], dp[sticker.length - 1][1]);
	}
}
