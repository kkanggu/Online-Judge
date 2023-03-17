import java.util.*;

public class PG_NoIsland {
	public static void main(String[] args) {
		int[] ans1 = solution(new String[]{"X591X", "X1X5X", "X231X", "1XXX1"});
		System.out.println("1 = " + ans1.toString());
		int[] ans2 = solution(new String[]{"XXX", "XXX", "XXX"});
		System.out.println("2 = " + ans2.toString());
	}

	public static int[] solution(String[] maps) {
		List<Integer> sumList = new ArrayList<>();
		Queue<Pair> qBFS = new LinkedList<>();
		int[] xDirection = {1, 0, -1, 0};
		int[] yDirection = {0, -1, 0, 1};
		boolean[][] isVisited = new boolean[maps.length][maps[0].length()];

		for (int i = 0; i < maps.length; i++) {
			for (int j = 0; j < maps[0].length(); j++) {
				int sum = 0;

				if (('X' != maps[i].charAt(j)) && (!isVisited[i][j])) {
					qBFS.add(new Pair(i, j));
					isVisited[i][j] = true;
				}

				while (!qBFS.isEmpty()) {
					Pair poll = qBFS.poll();
					int iCurrentX = poll.first;
					int iCurrentY = poll.second;
					sum += maps[iCurrentX].charAt(iCurrentY) - '0';

					for (int k = 0; k < 4; k++) {
						int iX = iCurrentX + xDirection[k];
						int iY = iCurrentY + yDirection[k];

						if ((iX < 0) || (iY < 0)
								|| (maps.length <= iX) || (maps[0].length() <= iY)) {
							continue;
						}
						if (!isVisited[iX][iY])
							if ('X' != maps[iX].charAt(iY)) {
								qBFS.add(new Pair(iX, iY));
								isVisited[iX][iY] = true;
							}
					}
				}

				sumList.add(sum);
			}
		}

		int[] answer = sumList.stream().filter(integer -> integer != 0).mapToInt(Integer::intValue).toArray();
		Arrays.sort(answer);

		if (0 != answer.length) {
			return answer;
		} else {
			return new int[]{-1};
		}
	}

	static class Pair {
		public int first;
		public int second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}
