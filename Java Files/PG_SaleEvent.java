import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class PG_SaleEvent {
	public static void main(String[] args) {
		solution(new String[]{"banana", "apple", "rice", "pork", "pot"}, new int[]{3,2,2,1,1},new String[]{"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"});
	}

	public static int solution(String[] want, int[] number, String[] discount) {
		int answer = 0;
		int[] count = new int[want.length + 1];
		Map<String, Integer> stringToIndexMap = IntStream.range(0, want.length)
				.boxed()
				.collect(Collectors.toMap(i -> want[i], i -> i));

		for(int i = 0; i < 10; ++i) {
			Integer index = stringToIndexMap.get(discount[i]);
			if(null == index) {
				index = want.length;
			}
			++ count[index];
		}

		if(IntStream.range(0,want.length).noneMatch(i -> number[i] > count[i])) {
			++ answer;
		}

		for(int i = 10; i < discount.length; ++i) {
			Integer formerIndex = stringToIndexMap.get(discount[i - 10]);
			Integer newIndex = stringToIndexMap.get(discount[i]);

			if(null == formerIndex) {
				formerIndex = want.length;
			}
			if(null == newIndex) {
				newIndex = want.length;
			}
			-- count[formerIndex];
			++ count[newIndex];

			if(IntStream.range(0,want.length).noneMatch(j -> number[j] > count[j])) {
				++ answer;
			}
		}

		return answer;
	}
}
