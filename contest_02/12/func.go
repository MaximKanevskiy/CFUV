func fill(maze [][]int) {
	rows := len(maze)
	cols := len(maze[0])

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if maze[i][j] == -1 {
				continue
			}

			count := 0
			// Верхние клетки
			if i > 0 {
				if j > 0 && maze[i-1][j-1] == -1 {
					count++
				}
				
				if maze[i-1][j] == -1 {
					count++
				}

				if j < cols-1 && maze[i-1][j+1] == -1 {
					count++
				}
			}

			// Средняя строка
			
			if j > 0 && maze[i][j-1] == -1 {
				count++
			}
			
			if j < cols-1 && maze[i][j+1] == -1 {
				count++
			}

			// Нижние клетки
			if i < rows-1 {
				if j > 0 && maze[i+1][j-1] == -1 {
					count++
				}
				
				if maze[i+1][j] == -1 {
					count++
				}
				
				if j < cols-1 && maze[i+1][j+1] == -1 {
					count++
				}
			}

			maze[i][j] = count
		}
	}
}
