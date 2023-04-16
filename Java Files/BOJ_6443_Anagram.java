import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class BOJ_6443_Anagram {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n;
		String[] words;

		n = Integer.parseInt(br.readLine());
		words = new String[n];
		for (int i = 0; i < n; ++i) {
			words[i] = br.readLine();
		}

		for (String word : words) {
			char[] chars = word.toCharArray();
			Arrays.sort(chars);
			setWord(chars, new boolean[word.length()], "");
		}
	}

	private static void setWord(char[] chars, boolean[] isUsed, String word) {
		if (word.length() == chars.length) {
			System.out.println(word);
			return;
		}

		Set<Character> set = new HashSet<>();

		for (int i = 0; i < isUsed.length; ++i) {
			if (isUsed[i] || set.contains(chars[i])) {
				continue;
			}
			set.add(chars[i]);
			isUsed[i] = true;
			setWord(chars, isUsed, word + chars[i]);
			isUsed[i] = false;
		}
	}

	/**
	 * Because of memory exceed, print at solution.
	 * Below is PG style
	 */

//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//
//		int n;
//		String[] words;
//
//		n = Integer.parseInt(br.readLine());
//		words = new String[n];
//		for (int i = 0; i < n; ++i) {
//			words[i] = br.readLine();
//		}
//
//		String[] answer = solution(n, words);
//		sb.append(answer[0]);
//		for (int i = 1; i < answer.length; ++i) {
//			sb.append("\n").append(answer[i]);
//		}
//		System.out.println(sb);
//	}
//
//	public static String[] solution(int n, String[] words) {
//		List<String> list = new ArrayList<>();
//		set = new HashSet<>();
//
//		for (String word : words) {
//			setWord(word, new boolean[word.length()], "");
//			String[] anagrams = set.toArray(String[]::new);
//			Arrays.sort(anagrams);
//			list.addAll(List.of(anagrams));
//			set.clear();
//		}
//
//		return list.toArray(String[]::new);
//	}
//
//	private static void setWord(String origin, boolean[] isUsed, String word) {
//		if (IntStream.range(0, isUsed.length).anyMatch(i -> !isUsed[i])) {
//			for (int i = 0; i < isUsed.length; ++i) {
//				if (isUsed[i]) {
//					continue;
//				}
//				isUsed[i] = true;
//				setWord(origin, isUsed, word + origin.charAt(i));
//				isUsed[i] = false;
//			}
//		} else {
//			set.add(word);
//		}
//	}
}
