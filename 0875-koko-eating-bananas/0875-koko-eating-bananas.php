class Solution {

    /**
     * @param Integer[] $piles
     * @param Integer $h
     * @return Integer
     */    
    function minEatingSpeed($piles, $h) {
        $low = 1;
		$high = max($piles);

		while ($low < $high) {
			$mid = floor(($low + $high) / 2);
			$hours = 0;

			foreach ($piles as $pile) {
				$hours += ceil($pile / $mid);
			}

			if ($hours > $h) {
				$low = $mid + 1;
			} else {
				$high = $mid;
			}
		}

		return $low;
    }
}