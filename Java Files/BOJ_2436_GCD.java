import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_2436_GCD {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int[] numbers;

		numbers = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

		int[] answer = solution(numbers[0], numbers[1]);
		sb.append(answer[0]).append(" ").append(answer[1]);
		System.out.println(sb);
	}

	public static int[] solution(int gcd, int lcm) {
		int[] answer = {1000000000, 1000000000};

		for (int i = (int) Math.sqrt(lcm); i >= 1; --i) {
			int largeNum = lcm / i;

			if (i * largeNum == lcm) {
				int smallNum = i;

				smallNum = smallNum * gcd / getGcd(gcd, smallNum);
				largeNum = largeNum * gcd / getGcd(gcd, largeNum);

				int pairGcd = getGcd(smallNum, largeNum);
				if ((pairGcd != getGcd(smallNum, largeNum))
						|| (lcm != (long) smallNum * largeNum / pairGcd)) {
					continue;
				}

				if (smallNum + largeNum < answer[0] + answer[1]) {
					answer[0] = Math.min(smallNum, largeNum);
					answer[1] = Math.max(smallNum, largeNum);
				}
			}
		}

		return answer;
	}

	private static int getGcd(int num1, int num2) {
		while (0 != (num2 % num1)) {
			int temp = num2 % num1;
			num2 = num1;
			num1 = temp;
		}

		return num1;
	}
}
