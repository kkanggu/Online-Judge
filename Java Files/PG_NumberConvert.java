import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class PG_NumberConvert {
	public static void main(String[] args) {
		solution(10, 40, 5);
	}

	public static int solution(int x, int y, int n) {
		if (x == y) return 0;

		int answer = 0;
		int[] countDP = new int[y + 1];
		Queue<Integer> queue = new LinkedList<>();
		Arrays.fill(countDP, 1000000);
		countDP[x] = 0;
		queue.add(x);

		while (!queue.isEmpty()) {
			int num = queue.poll();
			if ((num + n <= y) && (countDP[num] + 1 < countDP[num + n])) {
				countDP[num + n] = countDP[num] + 1;
				queue.add(num + n);

				if (num + n == y) {
					return countDP[y];
				}
			}
			if ((num * 2 <= y) && (countDP[num] + 1 < countDP[num * 2])) {
				countDP[num * 2] = countDP[num] + 1;
				queue.add(num * 2);

				if (num * 2 == y) {
					return countDP[y];
				}
			}
			if ((num * 3 <= y) && (countDP[num] + 1 < countDP[num * 3])) {
				countDP[num * 3] = countDP[num] + 1;
				queue.add(num * 3);

				if (num * 3 == y) {
					return countDP[y];
				}
			}
		}

		return -1;
	}
}
