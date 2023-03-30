import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class PG_MillionMultiplicationTable {
	public int[] solution(int e, int[] starts) {
		int[] answer = new int[starts.length];

		if (1 == e) {
			Arrays.fill(answer, 1);

			return answer;
		}

		int startsMin = Arrays.stream(starts).min().getAsInt();
		int[] dp = getDP(startsMin, e);

		return Arrays.stream(starts).map(i -> dp[i - startsMin]).toArray();
	}

	private int[] getDP(int start, int end) {
		int[] counts = getCount(start, end);
		int[] dp = new int[counts.length];
		int max = 0;
		int num = 0;

		for (int i = end; i >= start; --i) {
			if (max <= counts[i - start]) {
				max = counts[i - start];
				num = i;
			}

			dp[i - start] = num;
		}

		return dp;
	}

	private int[] getCount(int start, int num) {
		int[] counts = new int[num - start + 1];
		int[] primes = getPrime(num);

		for (int i = start; i <= num; ++i) {
			List<Integer> primeCount = new ArrayList<>();
			int each = i;

			if (1 == i) {
				counts[0] = 1;

				continue;
			}

			for (int prime : primes) {
				int tempCount = 0;

				while (0 == each % prime) {
					each /= prime;
					++tempCount;
				}

				if (0 != tempCount) {
					primeCount.add(tempCount + 1);
				}

				if (1 == each) {
					break;
				}
			}
			if (1 != each) {
				primeCount.add(2);
			}

			counts[i - start] = primeCount.stream().reduce(1, (a, b) -> a * b);
		}

		return counts;
	}

	private int[] getPrime(int num) {
		int primeMax = (int) Math.sqrt(num);
		List<Integer> primes = new ArrayList<>();
		boolean[] isNotPrime = new boolean[primeMax + 1];

		primes.add(2);
		for (int i = 3; i <= primeMax; i += 2) {
			if (!isNotPrime[i]) {
				primes.add(i);

				for (int j = i * 3; j <= primeMax; j += i * 2) {
					isNotPrime[j] = true;
				}
			}
		}

		return primes.stream().mapToInt(Integer::intValue).toArray();
	}
}
