import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ_2224_ProofOfProposition {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n;
		String[] propositions;

		n = Integer.parseInt(br.readLine());
		propositions = new String[n];
		for (int i = 0; i < n; ++i) {
			propositions[i] = br.readLine().replace(" => ", "");
		}

		String[] answer = solution(n, propositions);
		if (0 == answer.length) {
			sb.append("0");
		} else {
			sb.append(answer.length).append("\n");
			sb.append(answer[0]);
			for (int i = 1; i < answer.length; ++i) {
				sb.append("\n").append(answer[i]);
			}
		}
		System.out.println(sb);
	}

	public static String[] solution(int n, String[] propositions) {
		boolean[][] propositionMap = new boolean[52][52];

		for (String proposition : propositions) {
			int antecedent = proposition.charAt(0) < 'a' ? proposition.charAt(0) - 'A' : proposition.charAt(0) - 'a' + 26;
			int consequent = proposition.charAt(1) < 'a' ? proposition.charAt(1) - 'A' : proposition.charAt(1) - 'a' + 26;

			propositionMap[antecedent][consequent] = true;
		}
		for (int k = 0; k < 52; ++k) {
			for (int i = 0; i < 52; ++i) {
				for (int j = 0; j < 52; ++j) {
					if ((i == j) || (j == k) || (k == i) || (!propositionMap[i][k]) || (!propositionMap[k][j])) {
						continue;
					}
					propositionMap[i][j] = true;
				}
			}
		}

		List<String> answer = new ArrayList<>();
		for (int i = 0; i < 52; ++i) {
			for (int j = 0; j < 52; ++j) {
				if ((propositionMap[i][j]) && (i != j)) {
					char antecedent = i < 26 ? (char) ('A' + i) : (char) ('a' + i - 26);
					char consequent = j < 26 ? (char) ('A' + j) : (char) ('a' + j - 26);
					answer.add(antecedent + " => " + consequent);
				}
			}
		}

		return answer.toArray(String[]::new);
	}
}
