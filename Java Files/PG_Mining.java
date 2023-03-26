import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class PG_Mining {
	public int solution(int[] picks, String[] minerals) {
		int answer = 0;
		int pickCount = Arrays.stream(picks).sum();
		Queue<Triple> queue = new PriorityQueue<>();

		for(int i = 0; (i * 5 < minerals.length) && (i < pickCount); ++i) {
			int dia = 0;
			int iron = 0;
			int stone = 0;

			for(int j = i * 5; (j < i * 5 + 5) && (j < minerals.length); ++j) {
				char first = minerals[j].charAt(0);

				if('d' == first) {
					++ dia;
				} else if('i' == first) {
					++ iron;
				} else {
					++ stone;
				}
			}

			queue.add(new Triple(dia, iron, stone));
		}

		while(!queue.isEmpty()) {
			Triple triple = queue.poll();

			if(0 != picks[0]) {
				answer += triple.dia + triple.iron + triple.stone;
				--picks[0];
			} else if(0 != picks[1]) {
				answer += triple.dia * 5 + triple.iron + triple.stone;
				--picks[1];
			} else if(0 != picks[2]) {
				answer += triple.dia * 25 + triple.iron * 5+ triple.stone;
				--picks[2];
			}
		}

		return answer;
	}

	static class Triple implements Comparable<Triple> {
		public int dia;
		public int iron;
		public int stone;

		Triple(int dia, int iron, int stone) {
			this.dia = dia;
			this.iron = iron;
			this.stone = stone;
		}

		@Override
		public int compareTo(Triple t) {
			if(this.dia != t.dia) {
				return t.dia - this.dia;
			} else if(this.iron != t.iron) {
				return t.iron - this.iron;
			}
			return t.stone - this.stone;
		}
	}
}
