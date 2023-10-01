#include <queue>

// Номера строк и столбцов
struct Coordinate 
{
    int row;
    int col;
};

// Проверяет, находится ли ячейка в пределах лабиринта, не содержит символ '#' и ещё не посещена
bool is_valid(const std::vector<std::string>& maze, int row, int col, std::vector<std::vector<bool>>& visited) 
{
    int rows = maze.size();
    int cols = maze[0].size();

    return row >= 0 && row < rows && col >= 0 && col < cols && maze[row][col] != '#' && !visited[row][col];
}

bool is_can_exit_from_maze(const std::vector<std::string>& maze, int row, int col) 
{
    int rows = maze.size();
    int cols = maze[0].size();

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    std::queue<Coordinate> queue;
    queue.push({ row, col });
    visited[row][col] = true;

    // Извлекается каждая ячейка очереди, пока не найдётся символ 'E'
    while (!queue.empty()) {
        Coordinate current = queue.front();
        queue.pop();

        if (maze[current.row][current.col] == 'E') 
        {
            return true;
        }

        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        // Проверка соседних ячеек
        for (int i = 0; i < 4; i++) 
        {
            int newRow = current.row + dx[i];
            int newCol = current.col + dy[i];

            if (is_valid(maze, newRow, newCol, visited)) 
            {
                queue.push({ newRow, newCol });
                visited[newRow][newCol] = true;
            }
        }
    }

    return false;
}
