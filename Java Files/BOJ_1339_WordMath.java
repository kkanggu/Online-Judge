import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class BOJ_1339_WordMath {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n;
		String[] words;

		n = Integer.parseInt(br.readLine());
		words = new String[n];
		for (int i = 0; i < n; i++) {
			words[i] = br.readLine();
		}

		int answer = solution(n, words);
		sb.append(answer);
		System.out.println(sb);
	}

	public static int solution(int n, String[] words) {
		int answer = 0;
		int maxNum = 9;
		Map<Character, Integer> map = new HashMap<>();
		PriorityQueue<Pair> pq = new PriorityQueue<>((o1, o2) -> o2.count - o1.count);

		for (String word : words) {
			String reverseWord = getReverseWord(word);
			for (int i = 0; i < word.length(); ++i) {
				char ch = reverseWord.charAt(i);
				int count = map.getOrDefault(ch, 0);

				count += Math.pow(10, i);
				map.put(ch, count);
			}
		}

		map.forEach((key, value) -> {
			pq.add(new Pair(key,value));
		});

		while (!pq.isEmpty()) {
			answer += pq.poll().count * maxNum;
			--maxNum;
		}

		return answer;
	}

	private static String getReverseWord(String word) {
		String reverseWord = "";

		for (int i = word.length() - 1; i >= 0; --i) {
			reverseWord += word.charAt(i);
		}

		return reverseWord;
	}

	static class Pair {
		public char ch;
		public int count;

		Pair(char ch, int count) {
			this.ch = ch;
			this.count = count;
		}
	}
}

