import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class PG_MakeTwoQueueSame {
	public int solution(int[] queue1, int[] queue2) {
		int answer = -1;
		int leftPopCount = 0;
		int rightPopCount = 0;
		long dif = Arrays.stream(queue1).mapToLong(i -> i).sum() - Arrays.stream(queue2).mapToLong(i -> i).sum();
		Queue<Integer> leftQueue = new LinkedList<>();
		Queue<Integer> rightQueue = new LinkedList<>();

		for (int num : queue1) {
			leftQueue.add(num);
		}
		for (int num : queue2) {
			rightQueue.add(num);
		}

		while ((0 != dif) && ((leftPopCount <= queue1.length) || (rightPopCount <= queue2.length))) {
			if (dif < 0) {
				dif += rightQueue.peek() * 2;
				leftQueue.add(rightQueue.poll());
				++rightPopCount;
			} else {
				dif -= leftQueue.peek() * 2;
				rightQueue.add(leftQueue.poll());
				++leftPopCount;
			}
		}

		return 0 == dif ? leftPopCount + rightPopCount : -1;
	}
}
