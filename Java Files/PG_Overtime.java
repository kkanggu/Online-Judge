import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class PG_Overtime {
	public long solution(int n, int[] works) {
		long answer = 0;
		Queue<Integer> queue = new PriorityQueue<>();

		Arrays.stream(works).map(i -> i * -1).forEach(queue::add);

		for (int i = 0; i < n; ++i) {
			Integer top = queue.poll() + 1;
			queue.add(top);
		}
		while (!queue.isEmpty()) {
			Integer top = queue.poll();
			if (0 <= top) {
				return answer;
			}
			answer += top * top;
		}

		return answer;
	}
}
