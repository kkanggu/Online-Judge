import java.util.*;

public class PG_CutRollcake {
	public static void main(String[] args) {
		solution(new int[]{1, 2, 1, 3, 4, 1, 2});
		solution(new int[]{1, 2, 3, 1, 4});
	}

	public static int solution(int[] topping) {
		int answer = 0;
		Set<Integer> leftDistinctSet = new HashSet<>();
		Map<Integer, Integer> rightMap = new HashMap<>();

		if (1 == topping.length) {
			return answer;
		}
		for (int num : topping) {
			Integer count = rightMap.get(num);
			if (null == count) {
				rightMap.put(num, 1);
			} else {
				rightMap.replace(num, count + 1);
			}
		}
		for (int i = 0; i < topping.length - 1; ++i) {
			leftDistinctSet.add(topping[i]);
			Integer count = rightMap.get(topping[i]);
			if (1 == count) {
				rightMap.remove(topping[i]);
			} else {
				rightMap.replace(topping[i], count - 1);
			}

			if (leftDistinctSet.size() == rightMap.size()) {
				++answer;
			}
		}

		return answer;
	}
}
