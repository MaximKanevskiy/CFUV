// Динамически создаёт одномерный массив элементов типа int, которые равны value.
int* new_array(int len, int value)
{
    int* array = new int[len];

    for (int i = 0; i < len; i++)
    {
        array[i] = value;
    }
    return array;
}

// Устанавливает новую длину массива.
int set_new_length(int** array, int old_len, int new_len) 
{
    if (new_len < old_len) 
    {
        int* new_array = new int[new_len]; // Новый динамический массив

        for (int i = 0; i < new_len; i++) 
        {
            new_array[i] = (*array)[i]; // Копирование элементов исходного массива в новый
        }

        delete[] *array; // Очистка памяти от данных исходного массива
        *array = new_array; // Перенаправление указателя на новый массив

        return new_len;
    }
    else if (new_len > old_len) 
    {
        // Те же действия, что и в случае, если новый размер меньше старого.
        int* new_array = new int[new_len];

        for (int i = 0; i < old_len; i++) 
        {
            new_array[i] = (*array)[i];
        }

        // Однако здесь новая длина больше, поэтому новые элементы станут равны нулю.
        for (int i = old_len; i < new_len; i++) 
        {
            new_array[i] = 0;
        }

        delete[] *array; 
        *array = new_array;

        return new_len;
    }
    else 
    {
        // Если старая длина массива равна новой, то возвращает старую длину (можно и новую).
        return old_len;
    }
}

// Добавляет элементы из массива-источника в массив-приёмник.
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array) 
{
    int* new_array = new int[len_dest_array + len_src_array];

    for (int i = 0; i < len_dest_array; i++) 
    {
        new_array[i] = (*dest_array)[i]; // Копирование элементов из массива-приёмника в новый.
    }

    for (int i = len_dest_array; i < len_dest_array + len_src_array; i++) 
    {
        // Индекс i - len_dest_array - правильный индекс элемента в массиве-источнике.
        new_array[i] = src_array[i - len_dest_array]; // Копирование элементов из массива-источник в новый.
    }

    delete[] *dest_array;
    *dest_array = new_array;

    return len_dest_array + len_src_array;
}

// Вычисляет скалярное произведение.
// Параллельно перемножает одинаковые по индексу элементы двух массивов и суммирует результат.
int dot(const int* a, const int* b, int len) 
{
    int result = 0;

    for (int i = 0; i < len; i++) 
    {
        result += a[i] * b[i];
    }
    return result;
}

// Находит первое вхождение элемента равного value в массиве по адресу array заданной длины len.
int* find(int* array, int len, int value) 
{
    for (int i = 0; i < len; i++) 
    {
        if (array[i] == value) 
        {
            return &array[i];
        }
    }
    return nullptr;
}

// Удаляет массив. Если указатель не пустой, то очищает память от данных массива и делает указатель нулевым.
void delete_array(int** array) 
{
    if (*array != nullptr) 
    {
        delete[] *array;
        *array = nullptr;
    }
}
