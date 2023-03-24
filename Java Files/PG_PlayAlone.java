import java.util.*;
import java.util.stream.IntStream;

public class PG_PlayAlone {
	public static void main(String[] args) {
		solution(new int[]{8, 6, 3, 7, 2, 5, 1, 4});
//		solution(new int[]{1,2});
	}
	public static int solution(int[] cards) {
		int answer = 0;
		int [] array = IntStream.range(0, cards.length).toArray();
		Queue<Integer> group = new PriorityQueue<>(Collections.reverseOrder());
		int formerBox = array[0];
		array[0] = -1;
		group.add(0);
		int count = 1;

		while(true) {
			int nextBox = cards[formerBox] - 1;
			cards[formerBox] = 0;
			array[formerBox] = -1;

			if(nextBox <= 0) {
				group.add(count);

				count = -1;
				nextBox = 0;

				while(0 == cards[nextBox]) {
					nextBox = Arrays.stream(array).filter(i -> -1 != i).min().orElse(-1);

					if (-1 == nextBox) {
						group.add(count);

						return group.poll() * group.poll();
					}
				}
			}
			++ count;
			formerBox = nextBox;
		}
	}
}
