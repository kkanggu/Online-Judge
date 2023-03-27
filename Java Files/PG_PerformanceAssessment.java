import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class PG_PerformanceAssessment {
	public static void main(String[] args) {
		solution(new int[][]{{3, 1}, {1, 4}, {2, 3}, {2, 3}, {1, 5}, {1, 0}, {1, 0}});
	}

	public static int solution(int[][] scores) {
		int answer = 1;
		int[] target = scores[0];
		Arrays.sort(scores, (o1, o2) -> o1[0] != o2[0] ? o2[0] - o1[0] : o1[1] - o2[1]);
		int secondMax = scores[0][1];

		for (int[] score : scores) {
			int first = score[0];
			int second = score[1];

			// always former first >= this first, so compare second
			if (second < secondMax) {
				if(Arrays.equals(target, score)) {
					return -1;
				}

				continue;
			}
			secondMax = second;

			if (target[0] + target[1] < first + second) {
				++answer;
			}
		}

		return answer;
	}
}
