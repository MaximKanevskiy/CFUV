func fill(maze [][]int) {
	rows := len(maze)
	cols := len(maze[0])

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if maze[i][j] == -1 {
				continue
			}

			count := 0

			// Проверка верхней строки
			if i > 0 {
				// Проверка верхней левой клетки
				if j > 0 && maze[i-1][j-1] == -1 {
					count++
				}
				// Проверка верхней клетки
				if maze[i-1][j] == -1 {
					count++
				}
				// Проверка правой верхней клетки
				if j < cols-1 && maze[i-1][j+1] == -1 {
					count++
				}
			}

			// Проверка средней строки
			// Проверка левой клетки
			if j > 0 && maze[i][j-1] == -1 {
				count++
			}
			// Проверка правой клетки
			if j < cols-1 && maze[i][j+1] == -1 {
				count++
			}

			// Проверка нижней строки
			if i < rows-1 {
				// Проверка нижней левой клетки
				if j > 0 && maze[i+1][j-1] == -1 {
					count++
				}
				// Проверка нижней клетки
				if maze[i+1][j] == -1 {
					count++
				}
				// Проверка нижней правой клетки
				if j < cols-1 && maze[i+1][j+1] == -1 {
					count++
				}
			}

			maze[i][j] = count
		}
	}
}
