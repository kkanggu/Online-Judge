import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_12904_AandB {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String s, t;

		s = br.readLine();
		t = br.readLine();

		int answer = solution(s, t);
		sb.append(answer);
		System.out.println(sb);
	}

	public static int solution(String s, String t) {
		while (s.length() < t.length()) {
			if ('A' == t.charAt(t.length() - 1)) {
				t = t.substring(0, t.length() - 1);
			} else {
				t = t.substring(0, t.length() - 1);
				t = reverse(t);
			}
		}

		if (s.equals(t)) {
			return 1;
		}

		return 0;
	}

	private static String reverse(String str) {
		String reverseString = "";

		for (int i = str.length() - 1; i >= 0; --i) {
			reverseString += str.charAt(i);
		}

		return reverseString;
	}
}
