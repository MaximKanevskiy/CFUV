#include <cmath>

// Супер-класс работника
class Employee 
{
protected:
    std::string _name;     // Имя
    std::string _position; // Должность
    int _base_salary;      // Оклад
    int _bonus_salary;     // Премия
public:
    Employee(std::string name, std::string position, int salary) 
    {
        this->_name = name;
        this->_position = position;
        this->_base_salary = salary;
        this->_bonus_salary = 0;
    }

    // Метод, который можно переопределять, возвращающий премию
    virtual int bonus(double percentage) 
    {
        // Премия считается из округлённого к ближайшему целому произведения оклада и процента
        _bonus_salary = round(_base_salary * percentage);
        return _bonus_salary;
    }

    // Метод возвращающий полную зарплату
    int salary() 
    {
        bonus(bonuses[_position]);
        return _base_salary + _bonus_salary;
    }

    // Реализация оператора ввода в поток
    friend std::ostream& operator<<(std::ostream& os, Employee& employee)
    {
        os << employee._name << " (" << employee._position << "): " << employee.salary();
        return os;
    }
};

// Этот класс принимает новые значения для полей в Employee и переопределяет метод bonus
class Manager : public Employee 
{
public:
    Manager(std::string name, int salary = 16242) : Employee(name, "manager", salary) {}

    int bonus(double percentage) 
    {
        // Проверка на то, что процент бонуса меньше 10
        if (percentage < 0.1)
        {
            // Если меньше, то устанавливается минимальный процент для менеджера
            percentage = 0.1;
            _bonus_salary = round(_base_salary * percentage);
            return _bonus_salary;
        }
        else
        {
            _bonus_salary = round(_base_salary * percentage);
            return _bonus_salary;
        }
    }
};
