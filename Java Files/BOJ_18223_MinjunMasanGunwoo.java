import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class BOJ_18223_MinjunMasanGunwoo {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int v, e, p;
		int[][] edges;

		int[] inputs = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		v = inputs[0];
		e = inputs[1];
		p = inputs[2];
		edges = new int[e][3];
		for (int i = 0; i < e; i++) {
			edges[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		}

		String answer = solution(v, edges, p);
		sb.append(answer);
		System.out.println(sb);
	}

	public static String solution(int v, int[][] edges, int p) {
		List<Node>[] adjacentList = new List[v];
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.length - o2.length);
		int[] fromMinjun = new int[v];
		int[] fromGunwoo = new int[v];
		--p;

		for (int i = 0; i < v; ++i) {
			List<Node> list = new LinkedList<>();
			adjacentList[i] = list;
		}
		for (int[] edge : edges) {
			adjacentList[edge[0] - 1].add(new Node(edge[1] - 1, edge[2]));
			adjacentList[edge[1] - 1].add(new Node(edge[0] - 1, edge[2]));
		}

		Arrays.fill(fromMinjun, Integer.MAX_VALUE);
		Arrays.fill(fromGunwoo, Integer.MAX_VALUE);
		pq.add(new Node(0, 0));
		while (!pq.isEmpty()) {
			Node node = pq.poll();

			if (fromMinjun[node.end] <= node.length) {
				continue;
			}
			fromMinjun[node.end] = node.length;

			for (Node nextNode : adjacentList[node.end]) {
				if (node.length + nextNode.length < fromMinjun[nextNode.end]) {
					pq.add(new Node(nextNode.end, node.length + nextNode.length));
				}
			}
		}

		pq.add(new Node(p, 0));
		while (!pq.isEmpty()) {
			Node node = pq.poll();

			if (fromGunwoo[node.end] <= node.length) {
				continue;
			}
			fromGunwoo[node.end] = node.length;

			for (Node nextNode : adjacentList[node.end]) {
				if (node.length + nextNode.length < fromGunwoo[nextNode.end]) {
					pq.add(new Node(nextNode.end, node.length + nextNode.length));
				}
			}
		}

		if (fromMinjun[v - 1] < fromMinjun[p] + (long) fromGunwoo[v - 1]) {
			return "GOOD BYE";
		}

		return "SAVE HIM";
	}

	static class Node {
		public int end;
		public int length;

		Node (int end, int length) {
			this.end = end;
			this.length = length;
		}
	}
}
