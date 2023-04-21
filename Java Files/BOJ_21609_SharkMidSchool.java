import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_21609_SharkMidSchool {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n, m;
		int[][] blocks;

		String[] nm = br.readLine().split(" ");
		n = Integer.parseInt(nm[0]);
		m = Integer.parseInt(nm[1]);
		blocks = new int[n][n];
		for (int i = 0; i < n; ++i) {
			blocks[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		}

		int answer = solution(n, m, blocks);
		sb.append(answer);
		System.out.println(sb);
	}

	public static int solution(int n, int m, int[][] blocks) {
		int answer = 0;
		int[][] extendedBlocks = new int[blocks.length + 2][blocks.length + 2];

		Arrays.stream(extendedBlocks).forEach(row -> Arrays.fill(row, -1));

		for (int i = 1; i < blocks.length + 1; ++i) {
			for (int j = 1; j < blocks.length + 1; ++j) {
				extendedBlocks[i][j] = blocks[i - 1][j - 1];
			}
		}

		while (true) {
			int count = getScore(extendedBlocks);

			if (0 == count) {
				break;
			}

			answer += count;
		}

		return answer;
	}

	private static int getScore(int[][] extendedBlocks) {
		int totalSize = 1;
		int rainbow = 0;
		Node standard = new Node(-1, -1, 0);
		int[][] blocks = Arrays.stream(extendedBlocks).map(int[]::clone).toArray(int[][]::new);
		int[][] tempBlocks = Arrays.stream(extendedBlocks).map(int[]::clone).toArray(int[][]::new);
		int score = 0;

		for (int i = 1; i < blocks.length - 1; ++i) {
			for (int j = 1; j < blocks.length - 1; ++j) {
				if (0 < tempBlocks[i][j]) {
					BlockInfo blockInfo = removeBlocks(tempBlocks, new Node(i, j, 0), false);

					if (blockInfo.size < 2) {
						continue;
					}

					if ((totalSize < blockInfo.size)
							|| ((totalSize == blockInfo.size) && (rainbow < blockInfo.rainbow))
							|| ((totalSize == blockInfo.size) && (rainbow == blockInfo.rainbow) && (standard.x < i))
							|| ((totalSize == blockInfo.size) && (rainbow == blockInfo.rainbow) && (standard.x == i) && (standard.y < j))) {
						totalSize = blockInfo.size;
						rainbow = blockInfo.rainbow;
						standard.x = i;
						standard.y = j;
					}
				}
			}
		}

		if (1 == totalSize) {
			return 0;
		}

		score = totalSize * totalSize;

		removeBlocks(extendedBlocks, standard, true);
		gravityBlocks(extendedBlocks);
		rotateBlocks(extendedBlocks);
		gravityBlocks(extendedBlocks);

		return score;
	}

	private static BlockInfo removeBlocks(int[][] blocks, Node standard, boolean removeRainbow) {
		Queue<Node> queue = new LinkedList<>();
		int color = blocks[standard.x][standard.y];
		int[] xDiff = {0, -1, 0, 1};
		int[] yDiff = {-1, 0, 1, 0};
		BlockInfo blockInfo = new BlockInfo(0, 0);
		boolean[][] isVisited = new boolean[blocks.length][blocks.length];

		queue.add(new Node(standard.x, standard.y, color));
		blocks[standard.x][standard.y] = -2;
		isVisited[standard.x][standard.y] = true;

		while (!queue.isEmpty()) {
			Node node = queue.poll();

			if (0 == node.color) {
				++blockInfo.rainbow;
			}
			++blockInfo.size;

			for (int k = 0; k < 4; ++k) {
				int tempX = node.x + xDiff[k];
				int tempY = node.y + yDiff[k];

				if ((0 == tempX) || (0 == tempY) || (blocks.length - 1 == tempX) || (blocks.length - 1 == tempY) || (isVisited[tempX][tempY])) {
					continue;
				}

				isVisited[tempX][tempY] = true;

				if ((0 == blocks[tempX][tempY]) || (color == blocks[tempX][tempY])) {
					queue.add(new Node(tempX, tempY, blocks[tempX][tempY]));

					if ((color == blocks[tempX][tempY]) || (removeRainbow)) {
						blocks[tempX][tempY] = -2;
					}
				}
			}
		}

		return blockInfo;
	}

	private static void gravityBlocks(int[][] blocks) {
		for (int j = 1; j < blocks.length - 1; ++j) {
			for (int i = blocks.length - 2; i >= 1; --i) {
				if (0 <= blocks[i][j]) {
					int target = i + 1;

					while ((-2 == blocks[target][j]) && (target < blocks.length - 1)) {
						++target;
					}

					if (-2 == blocks[target - 1][j]) {
						blocks[target - 1][j] = blocks[i][j];
						blocks[i][j] = -2;
					}
				}
			}
		}
	}

	private static void rotateBlocks(int[][] blocks) {
		for (int i = 1; i <= (blocks.length / 2); ++i) {
			for (int j = i; j <= blocks.length - i - 2; ++j) {
				int temp = blocks[i][j];
				blocks[i][j] = blocks[j][blocks.length - i - 1];
				blocks[j][blocks.length - i - 1] = blocks[blocks.length - i - 1][blocks.length - j - 1];
				blocks[blocks.length - i - 1][blocks.length - j - 1] = blocks[blocks.length - j - 1][i];
				blocks[blocks.length - j - 1][i] = temp;
			}
		}
	}

	static class Node {
		public int x;
		public int y;
		public int color;

		Node(int x, int y, int color) {
			this.x = x;
			this.y = y;
			this.color = color;
		}
	}

	static class BlockInfo {
		public int size;
		public int rainbow;

		public BlockInfo(int size, int rainbow) {
			this.size = size;
			this.rainbow = rainbow;
		}
	}
}
