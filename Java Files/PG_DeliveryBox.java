import java.util.Stack;

public class PG_DeliveryBox {
	public static void main(String[] args) {
		solution(new int[]{3, 2, 1, 4, 5});
	}

	public static int solution(int[] order) {
		int answer = 0;
		int[] boxOrder = new int[order.length];
		Stack<Integer> stack = new Stack<>();
		int nextBoxOrder = 0;

		for (int i = 0; i < order.length; i++) {
			boxOrder[order[i] - 1] = i;
		}

		for (int i = 0; i < order.length; ++i) {
			while ((nextBoxOrder == boxOrder[i]) || (!stack.isEmpty() && nextBoxOrder == stack.peek())) {
				++answer;

				if (nextBoxOrder != boxOrder[i]) {
					stack.pop();
				}
				++nextBoxOrder;
			}
			if (nextBoxOrder <= boxOrder[i]) {
				stack.add(boxOrder[i]);
			}
		}

		while (!stack.isEmpty() && nextBoxOrder == stack.peek()) {
			++answer;
			stack.pop();
		}

		return answer;
	}
}
