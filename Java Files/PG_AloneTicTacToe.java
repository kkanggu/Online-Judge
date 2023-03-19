public class PG_AloneTicTacToe {
	public static void main(String[] args) {

	}

	public int solution(String[] board) {
		int oCount = 0;
		int xCount = 0;
		int oCorrectCount = 0;
		int xCorrectCount = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (isOXInclude(board, i, j, 'O')) {
					++oCount;
				} else if (isOXInclude(board, i, j, 'X')) {
					++xCount;
				}
			}
		}

		if ((oCount < xCount) || (xCount + 2 <= oCount)) {
			return 0;
		}

		oCorrectCount = 0;
		xCorrectCount = 0;

		for (int i = 0; i < 3; i++) {
			if (("OOO".equals(board[i])) || ((isOXInclude(board, 0, i, 'O')) && (isOXInclude(board, 1, i, 'O')) && (isOXInclude(board, 2, i, 'O')))) {
				++oCorrectCount;
			} else if (("XXX".equals(board[i])) || ((isOXInclude(board, 0, i, 'X')) && (isOXInclude(board, 1, i, 'X')) && (isOXInclude(board, 2, i, 'X')))) {
				++xCorrectCount;
			}
		}
		if (((isOXInclude(board, 0, 0, 'O')) && (isOXInclude(board, 1, 1, 'O')) && (isOXInclude(board, 2, 2, 'O')))
				|| ((isOXInclude(board, 0, 2, 'O')) && (isOXInclude(board, 1, 1, 'O')) && (isOXInclude(board, 2, 0, 'O')))) {
			++oCorrectCount;
		} else if (((isOXInclude(board, 0, 0, 'X')) && (isOXInclude(board, 1, 1, 'X')) && (isOXInclude(board, 2, 2, 'X')))
				|| ((isOXInclude(board, 0, 2, 'X')) && (isOXInclude(board, 1, 1, 'X')) && (isOXInclude(board, 2, 0, 'X')))) {
			++xCorrectCount;
		}

		if ((0 < oCorrectCount) && (0 < xCorrectCount)) {
			return 0;
		}
		if ((0 < oCorrectCount) && (oCount == xCount)) {
			return 0;
		}
		if ((0 < xCorrectCount) && (oCount > xCount)) {
			return 0;
		}

		return 1;
	}

	private static boolean isOXInclude(String[] board, int i, int j, char target) {
		return target == board[i].charAt(j);
	}
}
