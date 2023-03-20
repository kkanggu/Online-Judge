import java.util.Arrays;

public class PG_SplitNumberCard {
	public int solution(int[] arrayA, int[] arrayB) {
		int gcdA = Arrays.stream(arrayA).reduce(this::getGCD).getAsInt();
		int gcdB = Arrays.stream(arrayB).reduce(this::getGCD).getAsInt();
		int answer1 = getAnswer(arrayA, gcdB);
		int answer2 = getAnswer(arrayB, gcdA);

		return Math.max(answer1,answer2);
	}

	private int getAnswer(int[] array, int gcd) {
		for (int num : array) {
			if (0 == num % gcd) {
				return 0;
			}
		}
		return gcd;
	}

	private int getGCD(int a, int b) {
		return b == 0 ? a : getGCD(b, a % b);
	}
}
