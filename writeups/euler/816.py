import numpy as np
from scipy.spatial import KDTree

def solve_euler_816(k=2000000):
    # 1. Generate the pseudo-random sequence elements
    # Since each point P_n requires two elements (s_2n, s_2n+1), 
    # we need a total of 2 * k elements.
    num_elements = 2 * k
    s = np.empty(num_elements, dtype=np.int64)
    
    current_s = 290797
    modulus = 50515093
    
    for i in range(num_elements):
        s[i] = current_s
        current_s = (current_s * current_s) % modulus

    # 2. Reshape into 2D points: P_n = (s_2n, s_2n+1)
    points = s.reshape((k, 2))

    # 3. Build a fast spatial KDTree using SciPy
    tree = KDTree(points)

    # 4. Query the 2 nearest neighbors for each point
    # k=2 returns the point itself (distance 0) and its true closest neighbor
    distances, _ = tree.query(points, k=2)

    # 5. Extract the second column (distance to nearest neighbor)
    min_distances = distances[:, 1]
    
    # Get the overall shortest Euclidean distance
    shortest_distance = np.min(min_distances)
    
    # 6. Format to 9 decimal places as specified by the problem
    print(f"d({k}) = {shortest_distance:.9f}")

if __name__ == "__main__":
    solve_euler_816()
