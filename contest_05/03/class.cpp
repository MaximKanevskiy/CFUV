#include <algorithm>
#include <cmath>

class Complex 
{
public:
    // Конструктор класса по умолчанию
    Complex() : re(0.0), im(0.0) {}

    // Конструктор для класса, который принимает строку в 
    // качестве аргумента и преобразует её в комплексное число. 
    Complex(std::string str) 
    {
        // Чтобы избежать ошибки требутеся обработать входную строку, удалив из неё пробелы.
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

        // Инициализируется позицией последнего вхождения символов.
        // Именно последнего, потому что действительная часть может иметь знак.
        // И чтобы избежать этой ошибки нужно первое вхождение считать, как знак самого числа.
        // Нужно для разделения на действительную и мнимую части.
        size_t pos = str.find_last_of("+-");

        // требуется проверка на первый символ
        // если он содержит знак, то его записать в действительную часть,
        // как знак вещественного часла

        double real_part = std::stod(str.substr(0, pos)); // Преобразование действительной части в вещественное число
        double imag_part = std::stod(str.substr(pos));    // Преобразование мнимой части в вещественное число

        re = real_part;
        im = imag_part;
    }

    // Реализация суммы комплексных чисел
    Complex operator+(const Complex& other) const 
    {
        Complex result;
        result.re = re + other.re;
        result.im = im + other.im;
        return result;
    }

    // Реализация разности комплексных чисел
    Complex operator-(const Complex& other) const 
    {
        Complex result;
        result.re = re - other.re;
        result.im = im - other.im;
        return result;
    }

    // Реализация произведения комплексных чисел
    Complex operator*(const Complex& other) const 
    {
        Complex result;
        result.re = re * other.re - im * other.im;
        result.im = re * other.im + im * other.re;
        return result;
    }

    // Реализация частного комплексных чисел
    Complex operator/(const Complex& other) const 
    {
        Complex result;
        double denominator = std::pow(other.re, 2) + std::pow(other.im, 2);
        result.re = (re * other.re + im * other.im) / denominator;
        result.im = (im * other.re - re * other.im) / denominator;
        return result;
    }

    // Реализация оператора ввода в поток
    friend std::ostream& operator<<(std::ostream& out, const Complex& num) 
    {
        out << (num.re == 0.0 ? 0.0 : num.re)
            << (num.im < 0 ? "" : "+")
            << (num.im == 0.0 ? 0.0 : num.im) << 'j';
        return out;
    }
private:
    double re; // Действительная часть комплексного числа
    double im; // Мнимая часть комплексного числа
};
