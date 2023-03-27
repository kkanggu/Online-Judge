import java.util.Arrays;

public class PG_SequentialPurse {
	public long solution(int[] sequence) {
		long answer = 0;
		long [] dp = new long[sequence.length + 1];

		for(int i = 0; i < sequence.length; ++i) {
			int value = sequence[i];
			if(1 == (i & 1)) {
				value *= -1;
			}
			dp[i + 1] = dp[i] + (long) value;
		}

		return Arrays.stream(dp).max().getAsLong() - Arrays.stream(dp).min().getAsLong();
	}
}
