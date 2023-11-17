class Cat
{
public:
    bool isAlive;
    bool isOpen;

    Cat()
    {
        this->isAlive = rand() % 2;
        this->isOpen = false;
    }

    bool is_alive()
    {
        if (this->isOpen)
        {
            return this->isAlive;
        }
        else
        {
            return rand() % 2;
        }
    }
};

class Box
{
public:
    Cat open()
    {
        Cat cat;
        cat.isOpen = true;
        return cat;
    }
};
