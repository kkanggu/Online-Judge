import java.util.Arrays;

public class PG_SeesawSearch {
	public static void main(String[] args) {
		solution(new int[]{100, 100, 180, 360, 270});
	}

	public static long solution(int[] weights) {
		long answer = 0;
		int[] weightCounts = new int[1001];

		for (int weight : weights) {
			++weightCounts[weight];
		}

		for (int i = 100; i < 1001; i++) {
			int count = weightCounts[i];

			if (0 == count) {
				continue;
			}

			answer += (long) count * (count - 1) / 2;

			if ((0 == i % 2) && (i * 3 / 2 <= 1000)) {
				answer += (long) count * weightCounts[i * 3 / 2];
			}
			if (i * 2 <= 1000) {
				answer += (long) count * weightCounts[i * 2];
			}
			if ((0 == i % 3) && (i * 4 / 3 <= 1000)) {
				answer += (long) count * weightCounts[i * 4 / 3];
			}
		}

		return answer;
	}
}
