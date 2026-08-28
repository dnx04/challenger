def solve_crack_free_walls(W, H):
    # Step 1: Find all valid gap configurations for a single layer
    layers = []
    
    def build_layer(current_length, current_gaps):
        # Base cases
        if current_length == W:
            layers.append(set(current_gaps))
            return
        if current_length > W:
            return
            
        # Add a brick of length 2
        next_len_2 = current_length + 2
        if next_len_2 < W:
            build_layer(next_len_2, current_gaps + [next_len_2])
        else:
            build_layer(next_len_2, current_gaps)
            
        # Add a brick of length 3
        next_len_3 = current_length + 3
        if next_len_3 < W:
            build_layer(next_len_3, current_gaps + [next_len_3])
        else:
            build_layer(next_len_3, current_gaps)

    # Start building from length 0 with empty gaps
    build_layer(0, [])
    num_layers = len(layers)
    
    # Step 2: Build the adjacency list (compatibility graph)
    # Two layers are compatible if their intersection of gaps is empty
    adj = [[] for _ in range(num_layers)]
    for i in range(num_layers):
        for j in range(i, num_layers):  # Check symmetric pairs to save time
            if not layers[i].intersection(layers[j]):
                adj[i].append(j)
                if i != j:
                    adj[j].append(i)
                    
    # Step 3: Dynamic Programming
    # dp[i] stores the number of valid walls ending with layer configuration `i`
    # Base case: Height 1 wall has exactly 1 valid state for each configuration
    dp = [1] * num_layers
    
    # Build up the wall layer by layer up to height H
    for _ in range(H - 1):
        next_dp = [0] * num_layers
        for u in range(num_layers):
            # The number of ways to build a wall ending in layer `u` 
            # is the sum of ways to build previous walls ending in any compatible layer `v`
            for v in adj[u]:
                next_dp[u] += dp[v]
        dp = next_dp
        
    # Step 4: Sum all possibilities at the final height
    return sum(dp)

if __name__ == "__main__":
    W, H = 32, 10
    total_walls = solve_crack_free_walls(W, H)
    print(f"Total crack-free {W}x{H} walls: {total_walls}")
