import java.util.Arrays;

public class PG_DeliveryAndPickup {
	public long solution(int cap, int n, int[] deliveries, int[] pickups) {
		long answer = 0;
		int rightDeliverIndex = deliveries.length;
		int rightPickupIndex = deliveries.length;
		int deliverCount = Arrays.stream(deliveries).sum();
		int pickupCount = Arrays.stream(pickups).sum();

		for (int i = deliveries.length - 1; i >= 0; --i) {
			if (0 != deliveries[i]) {
				rightDeliverIndex = i;
				break;
			}
		}
		for (int i = pickups.length - 1; i >= 0; --i) {
			if (0 != pickups[i]) {
				rightPickupIndex = i;
				break;
			}
		}

		while ((0 != deliverCount) || (0 != pickupCount)) {
			answer += Math.max(rightDeliverIndex, rightPickupIndex) * 2 + 2;

			int tempDeliverCount = Math.min(cap, deliverCount);
			int tempPickupCount = Math.min(cap, pickupCount);
			deliverCount -= tempDeliverCount;
			pickupCount -= tempPickupCount;

			while (0 != tempDeliverCount) {
				if (tempDeliverCount < deliveries[rightDeliverIndex]) {
					deliveries[rightDeliverIndex] -= tempDeliverCount;
					tempDeliverCount = 0;
				} else {
					tempDeliverCount -= deliveries[rightDeliverIndex];
					deliveries[rightDeliverIndex] = 0;

					while (-1 != rightDeliverIndex) {
						if (0 != deliveries[rightDeliverIndex]) {
							break;
						}
						--rightDeliverIndex;
					}
				}
			}

			while (0 != tempPickupCount) {
				if (tempPickupCount < pickups[rightPickupIndex]) {
					pickups[rightPickupIndex] -= tempPickupCount;
					tempPickupCount = 0;
				} else {
					tempPickupCount -= pickups[rightPickupIndex];
					pickups[rightPickupIndex] = 0;

					while (-1 != rightPickupIndex) {
						if (0 != pickups[rightPickupIndex]) {
							break;
						}
						--rightPickupIndex;
					}
				}
			}
		}

		return answer;
	}
}
