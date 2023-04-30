import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class BOJ_2143_SumOfTwoArray {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t, countA, countB;
		int[] a, b;

		t = Integer.parseInt(br.readLine());
		countA = Integer.parseInt(br.readLine());
		a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		countB = Integer.parseInt(br.readLine());
		b = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

		long answer = solution(t, a, b);
		sb.append(answer);
		System.out.println(sb);
	}

	public static long solution(int t, int[] a, int[] b) {
		long answer = 0;
		int[][] dpA = new int[a.length][a.length];
		int[][] dpB = new int[b.length][b.length];
		Map<Integer, Integer> sumAMap = new HashMap<>();

		for (int i = 0; i < a.length; ++i) {
			int value = a[i];

			for (int j = 0; j <= i; ++j) {
				dpA[j][i] = value;

				if (0 != i) {
					dpA[j][i] += dpA[j][i - 1];
				}

				int count = sumAMap.getOrDefault(dpA[j][i], 0) + 1;
				sumAMap.put(dpA[j][i], count);
			}
		}
		for (int i = 0; i < b.length; ++i) {
			int value = b[i];

			for (int j = 0; j <= i; ++j) {
				dpB[j][i] = value;

				if (0 != i) {
					dpB[j][i] += dpB[j][i - 1];
				}

				int count = sumAMap.getOrDefault(t - dpB[j][i], 0);
				answer += (long) count;
			}
		}

		return answer;
	}
}
