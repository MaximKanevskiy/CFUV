class Point 
{
private:
    double x, y, r, a;

public:
    // Конструктор класса
    Point(double x, double y) : x(x), y(y) 
    {
        // Формула радиус-вектора
        r = sqrt(x * x + y * y);
        // Формула угла в полярных координатах которая вызывает функцию арктангенса
        // и возвращает отношение координат точки y и x в радианах от в диапазоне [-pi, pi].
        a = atan2(y, x);
    }

    // Геттеры имеют ключевое слово const, чтобы случайным образом 
    // функции никак не повлияли на объекты полей private
    double get_x() const 
    {
        return x;
    }

    double get_y() const 
    {
        return y;
    }

    double get_r() const 
    {
        return r;
    }

    double get_a() const 
    {
        return a;
    }

    // Сеттеры устанавливают новые значения для объектов
    void set_x(double new_x) 
    {
        x = new_x;
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }

    void set_y(double new_y) 
    {
        y = new_y;
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }

    void set_r(double new_r) 
    {
        r = new_r;

        // Две последующие формулы пересчитывают значения x и y
        // с использование формул для преобразования полярных координат в декартовы.
        x = r * cos(a);
        y = r * sin(a);
    }

    void set_a(double new_a) 
    {
        a = new_a;
        x = r * cos(a);
        y = r * sin(a);
    }
};
