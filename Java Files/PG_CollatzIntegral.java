import java.util.ArrayList;
import java.util.List;

public class PG_CollatzIntegral {
	public static void main(String[] args) {
		solution(5, new int[][]{{0, 0}, {0, -1}, {2, -3}, {3, -3}});
		solution(10000, new int[][]{{0, 0}, {0, -200}});
	}

	public static double[] solution(int k, int[][] ranges) {
		List<Double> resultList = new ArrayList<>();
		int[] dp = getDP(k);

		for (int[] range : ranges) {
			if (range[0] == range[1]) {
				resultList.add(dp[dp.length - 1] / 2.0);
			} else if (range[1] + dp.length - 1 < range[0]) {
				resultList.add(-1.0);
			} else {
				resultList.add((dp[range[1] + dp.length - 1] - dp[range[0]]) / 2.0);
			}
		}

		return resultList.stream().mapToDouble(Double::doubleValue).toArray();
	}

	private static int[] getDP(int num) {
		List<Integer> sequence = new ArrayList<>();
		int lastSum = 0;
		sequence.add(0);

		for (int i = 0; i < 400; i++) {
			int next = 0 == num % 2 ? num / 2 : num * 3 + 1;
			sequence.add(num + next + lastSum);
			lastSum += num + next;
			num = next;

			if (1 == next) {
				break;
			}
		}

		return sequence.stream().mapToInt(Integer::intValue).toArray();
	}
}
