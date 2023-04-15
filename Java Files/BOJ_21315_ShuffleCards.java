import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.IntStream;

public class BOJ_21315_ShuffleCards {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n;
		int[] targetCards;

		n = Integer.parseInt(br.readLine());
		targetCards = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

		int[] answer = solution(n, targetCards);
		sb.append(answer[0]).append(" ").append(answer[1]);
		System.out.println(sb);
	}

	public static int[] solution(int n, int[] targetCards) {
		int[] answer = new int[2];

		for (int i = 1; Math.pow(2, i) < n; ++i) {
			for (int j = 1; Math.pow(2, j) < n; ++j) {
				int[] cards = IntStream.range(1, n + 1).toArray();
				int value1 = i;
				int value2 = j;
				int former = n;

				for (int k = 0; k <= i; ++k) {
					cards = shuffle(cards, former - (1 << value1), 1 << value1);
					former = 1 << value1;
					--value1;
				}
				former = n;
				for (int k = 0; k <= j; ++k) {
					cards = shuffle(cards, former - (1 << value2), 1 << value2);
					former = 1 << value2;
					--value2;
				}

				if (Arrays.equals(targetCards, cards)) {
					answer[0] = i;
					answer[1] = j;
					i = n;
					break;
				}
			}
		}

		return answer;
	}

	private static int[] shuffle(int[] cards, int index, int count) {
		int[] shuffleCards = Arrays.copyOf(cards, cards.length);

		for (int i = index; i < index + count; ++i) {
			shuffleCards[i - index] = cards[i];
		}
		for (int i = 0; i < index; ++i) {
			shuffleCards[i + count] = cards[i];
		}

		return shuffleCards;
	}
}
