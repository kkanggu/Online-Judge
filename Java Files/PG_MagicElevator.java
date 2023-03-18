public class PG_MagicElevator {
	public int solution(int storey) {
		int answer = 0;

		while (0 != storey) {
			int lastDigit = storey % 10;
			storey /= 10;

			if ((5 < lastDigit)
					|| ((5 == lastDigit) && (5 <= storey % 10))) {
				answer += 10 - lastDigit;
				++storey;
			} else {
				answer += lastDigit;
			}
		}

		return answer;
	}
}
