#include <vector>
#include <string>

// Классы OSUpdater, Alarm и ActivityChecker реализуют интерфейс IRunnable и имеют функцию run(),
// которая просто выводит на экран имя класса. 
class OSUpdater : public IRunnable 
{
public:
    void run() 
    {
        std::cout << "OSUpdater" << std::endl;
    }
};

class Alarm : public IRunnable 
{
public:
    void run() 
    {
        std::cout << "Alarm" << std::endl;
    }
};

class ActivityChecker : public IRunnable 
{
public:
    void run() 
    {
        std::cout << "ActivityChecker" << std::endl;
    }
};

// Класс Clock реализует оба интерфейса. У него есть приватная структура Event, 
// которая содержит указатель на объект, реализующий интерфейс IRunnable, и временную метку. 
// Класс Clock также содержит вектор events, в который можно добавлять события с помощью функции add().
class Clock : public IClock, public IRunnable 
{
private:
    struct Event 
    {
        IRunnable* client;
        Time time;
    };

    std::vector<Event> events;
public:
    // Метод add() создаёт объект Event, заполняет его информацией о клиенте и временной меткой, 
    // и добавляет его в вектор events. 
    void add(IRunnable* client, Time time) 
    {
        Event event;
        event.client = client;
        event.time = time;
        events.push_back(event);
    }

    // Эта функция нужна для добавления нуля к числу в выводе на экран.
    std::string AddZero(short number)
    {
        if (number < 10)
        {
            return "0" + std::to_string(number);
        }
        else
        {
            return std::to_string(number);
        }
    }

    // Функция next() выполняет запуск следующего по времени события. Она выбирает событие с наименьшей временной меткой, 
    // выводит на экран время в формате "часы:минуты:секунды" и вызывает метод run() у объекта-клиента. 
    // Затем выбранное событие удаляется из вектора events. 
    bool next() 
    {
        if (events.empty()) 
        {
            return false;
        }

        int nextIndex = 0;
        Time nextTime = events[0].time;
        for (int i = 1; i < events.size(); i++) 
        {
            if (events[i].time < nextTime) 
            {
                nextIndex = i;
                nextTime = events[i].time;
            }
        }

        std::cout << AddZero(nextTime.hours) << ":" << AddZero(nextTime.minutes) << ":" << AddZero(nextTime.seconds) << " ";
        events[nextIndex].client->run();
        events.erase(events.begin() + nextIndex);

        return true;
    }

    // Метод run() в классе Clock запускает цикл, в котором последовательно вызывается метод next() до тех пор, 
    // пока в векторе events есть события. При каждом вызове метода next() будет выполняться следующее по времени событие.
    void run() 
    {
        while (next()) 
        {
          
        }
    }
};
