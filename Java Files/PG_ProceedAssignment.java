import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class PG_ProceedAssignment {
	public static void main(String[] args) {
//		 solution(new String[][]{{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}});
//		 solution(new String[][]{{"1", "00:00", "30"}, {"2", "00:10", "10"}, {"3", "00:30", "10"}, {"4", "00:50", "10"}});
		solution(new String[][]{{"c", "23:59", "5"}, {"a", "23:40", "30"}, {"b", "23:55", "6"}});
	}

	public static String[] solution(String[][] plans) {
		List<String> answer = new ArrayList<>();
		Stack<Assignment> stack = new Stack<>();
		Assignment[] assignments = Arrays.stream(plans)
				.map(Assignment::new)
				.toArray(Assignment[]::new);
		Arrays.sort(assignments, (a, b) -> a.start - b.start);
		int start = assignments[0].start;

		for (int i = 0; i < plans.length; ++i) {
			while ((!stack.isEmpty()) && (start < assignments[i].start)) {
				Assignment assignment = stack.pop();
				int proceedTime = Math.min(assignment.remainTime, assignments[i].start - start);
				if (proceedTime == assignment.remainTime) {
					answer.add(assignment.plan);
				} else {
					assignment.remainTime -= proceedTime;
					stack.add(assignment);
				}
				start += proceedTime;
			}
			if (stack.isEmpty()) {
				start = assignments[i].start;
			}

			stack.push(assignments[i]);
		}
		while (plans.length != answer.size()) {
			answer.add(stack.pop().plan);
		}

		return answer.toArray(String[]::new);
	}

	static class Assignment {
		public String plan;
		public int start;
		public int remainTime;

		Assignment(String[] plan) {
			this.plan = plan[0];
			this.remainTime = Integer.parseInt(plan[2]);
			String[] starts = plan[1].split(":");
			this.start = Integer.parseInt(starts[0]) * 60 + Integer.parseInt(starts[1]);
		}
	}
}
