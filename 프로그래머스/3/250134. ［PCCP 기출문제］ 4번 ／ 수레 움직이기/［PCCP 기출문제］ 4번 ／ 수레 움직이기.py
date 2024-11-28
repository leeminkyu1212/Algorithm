def solution(maze):
    from collections import deque

    n = len(maze)
    m = len(maze[0])

    def pos_to_idx(x, y):
        return x * m + y

    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    red_start = red_goal = blue_start = blue_goal = None
    walls = set()

    for i in range(n):
        for j in range(m):
            if maze[i][j] == 1:
                red_start = (i, j)
            elif maze[i][j] == 2:
                blue_start = (i, j)
            elif maze[i][j] == 3:
                red_goal = (i, j)
            elif maze[i][j] == 4:
                blue_goal = (i, j)
            elif maze[i][j] == 5:
                walls.add((i, j))

    if not (red_start and red_goal and blue_start and blue_goal):
        return 0

    from collections import deque

    queue = deque()
    visited_states = set()

    red_visited = 1 << pos_to_idx(*red_start)
    blue_visited = 1 << pos_to_idx(*blue_start)

    initial_state = (red_start, red_visited, blue_start, blue_visited)
    queue.append((initial_state, 0))
    visited_states.add((red_start, red_visited, blue_start, blue_visited))

    while queue:
        (red_pos, red_visited, blue_pos, blue_visited), steps = queue.popleft()

        red_at_goal = red_pos == red_goal
        blue_at_goal = blue_pos == blue_goal
        if red_at_goal and blue_at_goal:
            return steps

        red_moves = []
        if red_at_goal:
            red_moves.append(red_pos)
        else:
            for dx, dy in dirs:
                nx, ny = red_pos[0] + dx, red_pos[1] + dy
                if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in walls:
                    idx = pos_to_idx(nx, ny)
                    if not (red_visited & (1 << idx)):
                        red_moves.append((nx, ny))

        blue_moves = []
        if blue_at_goal:
            blue_moves.append(blue_pos)
        else:
            for dx, dy in dirs:
                nx, ny = blue_pos[0] + dx, blue_pos[1] + dy
                if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in walls:
                    idx = pos_to_idx(nx, ny)
                    if not (blue_visited & (1 << idx)):
                        blue_moves.append((nx, ny))

        for red_next in red_moves:
            for blue_next in blue_moves:
                if red_next == blue_next:
                    continue 
                if red_next == blue_pos and blue_next == red_pos:
                    continue

                red_next_visited = red_visited
                blue_next_visited = blue_visited

                if not red_at_goal:
                    red_idx = pos_to_idx(*red_next)
                    red_next_visited |= (1 << red_idx)
                if not blue_at_goal:
                    blue_idx = pos_to_idx(*blue_next)
                    blue_next_visited |= (1 << blue_idx)

                state = (red_next, red_next_visited, blue_next, blue_next_visited)
                if state not in visited_states:
                    visited_states.add(state)
                    queue.append((state, steps + 1))

    return 0
