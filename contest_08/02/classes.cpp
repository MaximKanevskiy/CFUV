// Заранее объявлен класс вектора, чтобы можно было его использовать в классе точки.
class Vector;

class Point 
{
public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // Объявлена функция сдвижения координат точки, чтобы потом определить её, так как класс вектора пока не определён.
    void move(Vector& direction);
};

class Vector 
{
public:
    int x;
    int y;

    // Конструктор принимает точку начала вектора и точку конца. 
    // Координаты вектора считаются как x = Xb - Xa, y = Yb - Ya
    Vector(const Point& start, const Point& end) 
    {
        x = end.x - start.x;
        y = end.y - start.y;
    }
};

void Point::move(Vector& direction)
{
    this->x += direction.x;
    this->y += direction.y;
}
