import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.IntStream;

public class PG_ConsecutivePartialSequence {
	public static void main(String[] args) {
		solution(new int[]{7, 9, 1, 1, 4});
	}

	public static int solution(int[] elements) {
		int answer = 0;
		int[] sequence = IntStream.concat(Arrays.stream(elements), Arrays.stream(elements)).toArray();
		Set<Integer> distinctNumber = new HashSet<>();

		for (int i = 1; i <= elements.length; i++) {
			for (int j = 0; j < elements.length; j++) {
				distinctNumber.add(getNumber(sequence, j, i));
			}
		}

		return distinctNumber.size();
	}

	private static int getNumber(int[] sequence, int start, int length) {
		int[] specificSequence = Arrays.copyOfRange(sequence, start, start + length);
		return Arrays.stream(specificSequence).sum();
	}
}
