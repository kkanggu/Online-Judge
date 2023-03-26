public class PG_BilliardPractice {
	public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
		int[] answer = new int[balls.length];

		for(int i = 0; i < balls.length; ++i) {
			answer[i] = getMinDistance(startX, startY, balls[i][0], balls[i][1], m, n);
		}

		return answer;
	}

	private int getMinDistance(int startX, int startY, int endX, int endY, int m, int n) {
		int[] xPosition = {-endX, endX, endX, m * 2 - endX};
		int[] yPosition = {endY, -endY, n * 2 - endY, endY};
		int minDistance = Integer.MAX_VALUE;

		for(int i = 0; i < 4; ++i) {
			if(((0 == i) && (startY == endY) && (endX <= startX))
					|| ((1 == i) && (startX == endX) && (endY <= startY))
					|| ((2 == i) && (startX == endX) && (startY<= endY))
					|| ((3 == i) && (startY == endY) && (startX <= endX))) {
				continue;
			}

			int targetX = xPosition[i];
			int targetY = yPosition[i];

			minDistance = Math.min(minDistance, (targetX - startX) * (targetX - startX) + (targetY - startY) * (targetY - startY));
		}

		return minDistance;
	}
}
