function computeArea(ax1: number, ay1: number, ax2: number, ay2: number, bx1: number, by1: number, bx2: number, by2: number
): number {
  const area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

  const ox_start = Math.max(ax1, bx1);
  const ox_end = Math.min(ax2, bx2);
  const oy_start = Math.max(ay1, by1);
  const oy_end = Math.min(ay2, by2);

  if (ox_start >= ox_end || oy_start >= oy_end) {
    return area; // no overlap
  }

  const overlap_area = (ox_end - ox_start) * (oy_end - oy_start);
  return area - overlap_area;
}
