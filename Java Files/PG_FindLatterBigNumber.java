import java.util.PriorityQueue;
import java.util.Queue;

public class PG_FindLatterBigNumber {
	public static void main(String[] args) {
		solution(new int[]{9, 1, 5, 3, 6, 2});
	}

	public static int[] solution(int[] numbers) {
		int[] answer = new int[numbers.length];
		Queue<Pair> queue = new PriorityQueue<>((o1, o2) -> {
			return o1.first > o2.first ? 1 : -1;
		});

		for (int i = 0; i < numbers.length; i++) {
			if (queue.isEmpty()) {
				queue.add(new Pair(numbers[i], i));
			} else if (queue.peek().first < numbers[i]) {
				while (!queue.isEmpty() && (queue.peek().first < numbers[i])) {
					answer[queue.poll().second] = numbers[i];
				}

				queue.add(new Pair(numbers[i], i));
			} else {
				queue.add(new Pair(numbers[i], i));
			}
		}
		while (!queue.isEmpty()) {
			answer[queue.poll().second] = -1;
		}

		return answer;
	}

	static class Pair {
		public int first;
		public int second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}
