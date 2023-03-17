import java.util.PriorityQueue;
import java.util.Queue;

public class PG_DefenceGame {
	public static void main(String[] args) {
		int i = solution(7, 3, new int[]{5, 5, 5, 5, 2, 3, 1});
	}

	public static int solution(int n, int k, int[] enemy) {
		int answer = enemy.length;
		long enemySum = 0;
		long skipSum = 0;
		Queue<Integer> skipQueue = new PriorityQueue<>(k);

		for (int i = 0; i < enemy.length; ++i) {
			enemySum += enemy[i];
			if ((skipQueue.size() == k) && (skipQueue.peek() < enemy[i])) {
				skipSum -= skipQueue.poll();
				skipQueue.add(enemy[i]);
				skipSum += enemy[i];
			} else if (skipQueue.size() != k) {
				skipSum += enemy[i];
				skipQueue.add(enemy[i]);
			}

			if (n < enemySum - skipSum) {
				answer = i;
				break;
			}
		}

		return answer;
	}
}
