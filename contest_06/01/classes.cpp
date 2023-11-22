#define _USE_MATH_DEFINES // Для использования числа Пи
#include <cmath>

// Базовый класс для фигуры
class Shape 
{
public:
	// Метод, возвращающий значение периметра фигуры.
	// 0 для задания значения по умолчанию
	virtual double getPerimeter() = 0;
};

// Класс-наследник для прямоугольника
class Rectangle : public Shape 
{
public:
	// Конструктор класса, заполняющий поля значениями 
	Rectangle(int a, int b) : length(a), width(b) {}
	
	// Переопределение метода из класса Shape
	double getPerimeter() 
	{
		return 2 * (length + width);
	}
private:
	int length; // Длина
	int width; // Ширина
};

// Класс-наследник для круга
class Circle : public Shape 
{
public:
	Circle(int r) : radius(r) {}
	
	double getPerimeter() 
	{
		// M_PI - константа для числа Пи
		return 2 * M_PI * radius;
	}
private:
	int radius;
};

// Класс-наследник для треугольника
class Triangle : public Shape 
{
public:
	Triangle(int a, int b, int c) : side1(a), side2(b), side3(c) {}

	double getPerimeter() 
	{
		if (is_exists) 
		{
			return side1 + side2 + side3;
		}
		else 
		{
			return 0;
		}
	}
private:
	int side1;
	int side2;
	int side3;
	// Проверка на существование треугольника
	bool is_exists = side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1;
};
