import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

public class PG_SelectTangerine {
	public static void main(String[] args) {
		solution(6, new int[]{1, 3, 2, 5, 4, 5, 2, 3});
	}
	public static int solution(int k, int[] tangerine) {
		int answer = 0;
		Map<Integer, Long> duplicateCount = Arrays.stream(tangerine)
				.boxed()
				.collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
		Long[] duplicates = duplicateCount.values().toArray(Long[]::new);
		Arrays.sort(duplicates, Collections.reverseOrder());
		int sum = 0;

		for (long count : duplicates) {
			sum += count;
			++answer;

			if (k <= sum) {
				break;
			}
		}

		return answer;
	}
}
