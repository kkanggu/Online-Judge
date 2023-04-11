import java.util.Arrays;

public class PG_EmoticonSaleEvent {
	int[] answer;

	public int[] solution(int[][] users, int[] emoticons) {
		answer = new int[2];
		int[] permutation = new int[emoticons.length];

		getAnswer(permutation, emoticons, users, 0);

		return answer;
	}

	private void getAnswer(int[] permutation, int[] emoticons, int[][] users, int count) {
		if (count == permutation.length) {
			int plusCount = 0;
			int priceSum = 0;

			for (int[] user : users) {
				int sum = 0;
				for (int i = 0; i < count; ++i) {
					if (user[0] <= permutation[i]) {
						sum += emoticons[i] * (100 - permutation[i]) / 100;
					}
				}

				if (user[1] <= sum) {
					++plusCount;
				} else {
					priceSum += sum;
				}
			}

			if ((answer[0] < plusCount)
					|| ((answer[0] == plusCount) && (answer[1] < priceSum))) {
				answer[0] = plusCount;
				answer[1] = priceSum;
			}

			return;
		}

		for (int i = 1; i <= 4; ++i) {
			permutation[count] = i * 10;
			getAnswer(permutation, emoticons, users, count + 1);
		}
	}
}
