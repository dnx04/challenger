from functools import lru_cache

def project_euler_109(max_score=99):
    # Define point values for all 62 distinct region types
    singles = list(range(1, 21)) + [25]
    doubles = [2 * i for i in range(1, 21)] + [50]
    trebles = [3 * i for i in range(1, 21)]
    regions = singles + doubles + trebles  # 62 regions total

    @lru_cache(maxsize=None)
    def count_non_finishing(region_idx, darts_left, score):
        """
        Recursively counts unique combinations of 0, 1, or 2 non-finishing darts.
        - region_idx: Index of current region (0 to 61) to enforce combination order
        - darts_left: Throws remaining (2, 1, or 0)
        - score: Target sum to reach with non-finishing darts
        """
        if score == 0:
            return 1  # Valid combination formed
        if score < 0 or darts_left == 0 or region_idx >= len(regions):
            return 0

        val = regions[region_idx]
        total_ways = 0
        
        # Choice: Hit current region 0, 1, or 2 times (up to darts_left)
        for count in range(darts_left + 1):
            if score >= count * val:
                total_ways += count_non_finishing(
                    region_idx + 1, 
                    darts_left - count, 
                    score - count * val
                )
            else:
                break

        return total_ways

    total_checkouts = 0

    # Iterate through all checkout targets T < 100
    for target in range(1, max_score + 1):
        for double_val in doubles:
            rem_score = target - double_val
            if rem_score >= 0:
                # Count combinations of 0, 1, or 2 darts summing to rem_score
                total_checkouts += count_non_finishing(0, 2, rem_score)

    return total_checkouts

# Solve Project Euler 109
print(f"Total checkouts under 100: {project_euler_109(99)}")
