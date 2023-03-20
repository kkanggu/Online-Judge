import java.util.Arrays;

public class PG_ReserveHotel {
	public static void main(String[] args) {

	}

	public int solution(String[][] book_time) {
		int answer = 0;
		int[] timeTable = new int[1440];

		for (String[] strings : book_time) {
			int startTime = toTime(strings[0]);
			int endTime = toTime(strings[1]) + 9;
			if (1440 <= endTime) {
				endTime = 1439;
			}

			for (int i = startTime; i <= endTime; i++) {
				++timeTable[i];
			}
		}

		return Arrays.stream(timeTable).max().getAsInt();
	}

	public int toTime(String time) {
		String[] splitTime = time.split(":");
		return Integer.parseInt(splitTime[0]) * 60 + Integer.parseInt(splitTime[1]);
	}
}
