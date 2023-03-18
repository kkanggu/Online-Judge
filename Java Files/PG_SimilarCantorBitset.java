public class PG_SimilarCantorBitset {
	public int solution(int n, long l, long r) {
		--l;
		--r;

		long countTol = getCount(l - 1, n);
		long countTor = getCount(r, n);

		return (int) (countTor - countTol);
	}

	public static long getCount(long index, int level) {
		long count = 0;
		int partialIndex = ((int) (index / Math.pow(5, level - 1))) % 5;

		if (0 == level) {
			if ((-1 == index) ||(2 == index % 5)) {
				return 0;
			} else {
				return 1;
			}
		}

		if (1 == partialIndex) {
			count += Math.pow(4, level - 1);
		} else if ((2 == partialIndex) || (3 == partialIndex)) {
			count += Math.pow(4, level - 1) * 2;
		} else if (4 == partialIndex) {
			count += Math.pow(4, level - 1) * 3;
		}

		if ((1 != level) && (2 == partialIndex)) {
			return count;
		}
		count += getCount(index, level - 1);

		return count;
	}
}
