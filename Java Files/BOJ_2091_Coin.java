import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_2091_Coin {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int x, a, b, c, d;
		int[] temp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		x = temp[0];
		a = temp[1];
		b = temp[2];
		c = temp[3];
		d = temp[4];

		int[] answer = solution(x, a, b, c, d);
		sb.append(answer[0]);
		for (int i = 1; i < 4; ++i) {
			sb.append(" ");
			sb.append(answer[i]);
		}
		System.out.println(sb);
	}

	public static int[] solution(int x, int a, int b, int c, int d) {
		Coin[] dp = new Coin[x + 1];

		dp[0] = new Coin();
		++dp[0].a;
		for (int i = 1; i <= x; ++i) {
			Coin coin = new Coin();

			if ((0 <= dp[i - 1].getCount()) && (dp[i - 1].a < a) && (coin.getCount() <= dp[i - 1].getCount())) {
				coin = new Coin(dp[i - 1]);
				++coin.a;
			}
			if ((5 <= i) && (0 <= dp[i - 5].getCount()) && (dp[i - 5].b < b) && (coin.getCount() <= dp[i - 5].getCount())) {
				coin = new Coin(dp[i - 5]);
				++coin.b;
			}
			if ((10 <= i) && (0 <= dp[i - 10].getCount()) && (dp[i - 10].c < c) && (coin.getCount() <= dp[i - 10].getCount())) {
				coin = new Coin(dp[i - 10]);
				++coin.c;
			}
			if ((25 <= i) && (0 <= dp[i - 25].getCount()) && (dp[i - 25].d < d) && (coin.getCount() <= dp[i - 25].getCount())) {
				coin = new Coin(dp[i - 25]);
				++coin.d;
			}

			dp[i] = coin;
		}

		if (-1 == dp[x].a) {
			dp[x].a = 0;
		}

		return new int[]{dp[x].a, dp[x].b, dp[x].c, dp[x].d};
	}

	static class Coin {
		public int a;
		public int b;
		public int c;
		public int d;

		public Coin() {
			this.a = -1;
			this.b = 0;
			this.c = 0;
			this.d = 0;
		}

		public Coin(Coin coin) {
			this.a = coin.a;
			this.b = coin.b;
			this.c = coin.c;
			this.d = coin.d;
		}

		public int getCount() {
			return a + b + c + d;
		}
	}
}
