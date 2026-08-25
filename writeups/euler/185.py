from z3 import *

def solve_euler_185():
    # The 22 clues provided by Project Euler 185
    clues = [
        ("5616185650518293", 2),
        ("3847439647293047", 1),
        ("5855462940810587", 3),
        ("9742855507068353", 3),
        ("4296849643607543", 3),
        ("3174248439465858", 1),
        ("4513559094146117", 2),
        ("7890971548908067", 3),
        ("8157356344118483", 1),
        ("2615250744386899", 2),
        ("8690095851526254", 3),
        ("6375711915077050", 1),
        ("6913859173121360", 1),
        ("6442889055042768", 2),
        ("2321386104303845", 0),
        ("2326509471271448", 2),
        ("5251583379644322", 2),
        ("1748270476758276", 3),
        ("4895722652190306", 1),
        ("3041631117224635", 3),
        ("1841236454324589", 3),
        ("2659862637316867", 2),
    ]
    
    solver = Solver()
    
    # 1. Define 16 integer variables (one for each position)
    digits = [Int(f'd_{i}') for i in range(16)]
    
    # 2. Bound constraints: Each digit must be between 0 and 9
    for d in digits:
        solver.add(d >= 0, d <= 9)
        
    # 3. Clue constraints: Track how many characters match the secret string
    for guess, correct_count in clues:
        match_exprs = [If(digits[i] == int(guess[i]), 1, 0) for i in range(16)]
        solver.add(Sum(match_exprs) == correct_count)
        
    # 4. Extract and print the unique solution
    if solver.check() == sat:
        model = solver.model()
        solution = "".join(str(model[d]) for d in digits)
        print(f"Project Euler 185 Solution: {solution}")
    else:
        print("No solution found.")

solve_euler_185()
