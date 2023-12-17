def is_valid_move(maze, row, col, visited):
    return 0 <= row < len(maze) and 0 <= col < len(maze[0]) and maze[row][col] != 1 and not visited[row][col]

def maze_runner(maze, start, target):
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    queue = [(start[0], start[1], 0, 0)]  
    visited = [[False] * len(maze[0]) for _ in range(len(maze))]

    while queue:
        current_row, current_col, distance, num_of_3_blocks = queue.pop(0)
        visited[current_row][current_col] = True

        if (current_row, current_col) == target:
            return distance

        for dr, dc in directions:
            new_row, new_col = current_row + dr, current_col + dc

            if is_valid_move(maze, new_row, new_col, visited):
                if maze[new_row][new_col] == 3:
                    if num_of_3_blocks < 1:
                        queue.append((new_row, new_col, distance + 1, num_of_3_blocks + 1))
                else:
                    queue.append((new_row, new_col, distance + 1, num_of_3_blocks))

    return "STUCK"


rows, cols = map(int, input().split())
maze = [list(map(int, input().split())) for _ in range(rows)]
start = tuple(map(int, input().split()))
target = tuple(map(int, input().split()))


result = maze_runner(maze, start, target)
print(result)