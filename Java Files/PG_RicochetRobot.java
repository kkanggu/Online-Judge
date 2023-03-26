import java.util.LinkedList;
import java.util.Queue;

public class PG_RicochetRobot {
	public int solution(String[] board) {
		Queue<Node> queue = new LinkedList<>();
		boolean [][][] passed = new boolean[100][100][4];       // Up Left Down Right
		Node goal = findNode(board, 'G');

		queue.add(findNode(board, 'R'));

		while(! queue.isEmpty()) {
			Node currentNode = queue.poll();

			for(int i = 0; i < 4; ++i) {
				if(passed[currentNode.x][currentNode.y][i]) {
					continue;
				}

				int x = currentNode.x;
				int y = currentNode.y;

				if(0 == i) {
					if((0 == x) || ('D' == board[x - 1].charAt(y))) {
						continue;
					}

					while((0 != x) && ('D' != board[x - 1].charAt(y))) {
						--x;
					}
				} else if(1 == i) {
					if((0 == y) || ('D' == board[x].charAt(y - 1))) {
						continue;
					}

					while((0 != y) && ('D' != board[x].charAt(y - 1))) {
						--y;
					}
				} else if(2 == i) {
					if((y + 1 == board[0].length()) || ('D' == board[x].charAt(y + 1))) {
						continue;
					}

					while((y + 1 != board[0].length()) && ('D' != board[x].charAt(y + 1))) {
						++y;
					}
				} else if(3 == i) {
					if((x + 1 == board.length) || ('D' == board[x + 1].charAt(y))) {
						continue;
					}

					while((x + 1 != board.length) && ('D' != board[x + 1].charAt(y))) {
						++x;
					}
				}

				Node nextNode = new Node(x, y, currentNode.len + 1);

				if(goal.arrive(nextNode)) {
					return nextNode.len;
				}

				queue.add(nextNode);
				passed[currentNode.x][currentNode.y][i] = true;
			}
		}

		return -1;
	}

	public Node findNode(String[] board, char target) {
		for(int i = 0; i < board.length; ++i) {
			for(int j = 0; j < board[0].length(); ++j) {
				if(target == board[i].charAt(j)) {
					return new Node(i,j,0);
				}
			}
		}

		return null;
	}

	static class Node {
		public int x;
		public int y;
		public int len;

		Node(int x, int y, int len) {
			this.x = x;
			this.y = y;
			this.len = len;
		}

		public boolean arrive(Node node) {
			return (this.x == node.x) && (this.y == node.y);
		}
	}
}
