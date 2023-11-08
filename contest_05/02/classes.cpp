class Water
{
public:
    int temperature;
    bool boiling;

    Water() // конструктор по умолчанию без аргументов
    {
        temperature = 0;
        boiling = false;
    }

    Water(int temp) // конструктор, принимающий аргумент типа int
    {
        temperature = temp;
        boiling = false;
    }

    bool is_boiling()
    {
        if (temperature >= 100) return true;
        else return false;
    }
};

class Teapot
{
public:
    Water water;

    Teapot() // конструктор по умолчанию без аргументов
    {
        water = Water();
    }

    Teapot(Water& w) // конструктор, принимающий аргумент типа Water&
    {
        water = w;
    }

    int heat_up(int heat)
    {
        water.temperature += heat;
        return water.temperature;
    }

    bool is_boiling()
    {
        if (water.is_boiling())
        {
            water.boiling = true;
            return water.boiling;
        }
        else
        {
            water.boiling = false;
            return water.boiling;
        }
    }
};
