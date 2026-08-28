from sage.all import *

def solve_euler_96(filename='sudoku.txt'):
    total_sum = 0
    
    with open(filename, 'r') as f:
        lines = [line.strip() for line in f if line.strip()]
        
    # Process 50 grids (each grid consists of 1 header line + 9 rows of digits)
    for i in range(0, len(lines), 10):
        # Skip the header line (e.g., "Grid 01")
        grid_rows = lines[i+1 : i+10]
        
        # Flatten the 9x9 grid into a single string of 81 characters
        grid_string = "".join(grid_rows)
        
        # Initialize and solve the Sudoku puzzle using SageMath
        puzzle = Sudoku(grid_string)
        solution_obj = next(puzzle.solve())
        
        # Convert the Sudoku object to a Sage matrix for array-like indexing
        sol_matrix = solution_obj.to_matrix()
        
        # Extract the top-left 3 digits from the first row (row index 0)
        top_left_3_digits = sol_matrix[0, 0]*100 + sol_matrix[0, 1]*10 + sol_matrix[0, 2]
        
        total_sum += top_left_3_digits
        
    return total_sum

# Run the solution script
print("Total Sum:", solve_euler_96())
