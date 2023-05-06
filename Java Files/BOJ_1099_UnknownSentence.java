import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Collectors;

public class BOJ_1099_UnknownSentence {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String sentence;
		int n;
		String[] words;

		sentence = br.readLine();
		n = Integer.parseInt(br.readLine());
		words = new String[n];
		for (int i = 0; i < n; i++) {
			words[i] = br.readLine();
		}

		int answer = solution(sentence, words);
		sb.append(answer);
		System.out.println(sb);
	}

	public static int solution(String sentence, String[] words) {
		int[] dp = new int[sentence.length() + 1];

		Arrays.fill(dp, 100);
		dp[0] = 0;
		sentence = " " + sentence;

		for (int i = 1; i < sentence.length(); ++i) {
			for (String word : words) {
				if ((word.length() <= i + 1) && isWordContain(sentence.substring(i - word.length() + 1, i + 1), word)) {
					dp[i] = Math.min(dp[i], dp[i - word.length()] + getWordDiff(sentence.substring(i - word.length() + 1, i + 1), word));
				}
			}
		}

		return 100 == dp[sentence.length() - 1] ? -1 : dp[sentence.length() - 1];
	}

	static boolean isWordContain(String sentence, String word) {
		String sortedSentence = Arrays.stream(sentence.split(""))
				.sorted()
				.collect(Collectors.joining());
		String sortedWord = Arrays.stream(word.split(""))
				.sorted()
				.collect(Collectors.joining());

		return sortedSentence.equals(sortedWord);
	}

	static int getWordDiff(String sentence, String word) {
		int count = 0;

		for (int i = 0; i < sentence.length(); ++i) {
			if (sentence.charAt(i) != word.charAt(i)) {
				++count;
			}
		}

		return count;
	}
}
