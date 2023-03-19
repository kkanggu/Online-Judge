import java.util.LinkedList;
import java.util.Queue;

public class PG_EscapeMaze {
	public static void main(String[] args) {

	}

	public int solution(String[] maps) {
		int answer = 0;
		int startX = 0;
		int startY = 0;
		int leverX = 0;
		int leverY = 0;
		int endX = 0;
		int endY = 0;

		for (int i = 0; i < maps.length; i++) {
			for (int j = 0; j < maps[0].length(); j++) {
				if ('S' == maps[i].charAt(j)) {
					startX = i;
					startY = j;
				} else if ('L' == maps[i].charAt(j)) {
					leverX = i;
					leverY = j;
				} else if ('E' == maps[i].charAt(j)) {
					endX = i;
					endY = j;
				}
			}
		}

		int toLever = findMinimumRouteLength(maps, startX, startY, leverX, leverY);
		if (-1 == toLever) {
			return -1;
		}
		int toEnd = findMinimumRouteLength(maps, leverX, leverY, endX, endY);
		if (-1 == toEnd) {
			return -1;
		}

		return toLever + toEnd;
	}

	public static int findMinimumRouteLength(String[] maps, int startX, int startY, int endX, int endY) {
		boolean[][] isVisited = new boolean[maps.length][maps[0].length()];
		Queue<Node> queue = new LinkedList<>();
		queue.add(new Node(startX, startY, 0));
		isVisited[startX][startY] = true;
		int[] xDirection = {1, 0, -1, 0};
		int[] yDirection = {0, -1, 0, 1};

		while (!queue.isEmpty()) {
			Node top = queue.poll();

			for (int i = 0; i < 4; i++) {
				int currentX = top.x + xDirection[i];
				int currentY = top.y + yDirection[i];

				if ((currentX < 0) || (currentY < 0) || (maps.length <= currentX) || (maps[0].length() <= currentY)
						|| (isVisited[currentX][currentY]) || ('X' == maps[currentX].charAt(currentY))) {
					continue;
				}

				if ((currentX == endX) && (currentY == endY)) {
					return top.length + 1;
				}

				queue.add(new Node(currentX, currentY, top.length + 1));
				isVisited[currentX][currentY] = true;
			}
		}

		return -1;
	}

	static class Node {
		public int x;
		public int y;
		public int length;

		public Node(int x, int y, int length) {
			this.x = x;
			this.y = y;
			this.length = length;
		}
	}
}
