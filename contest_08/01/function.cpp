int hack_it(Keeper& keeper)
{
    // Указатель на объект класса Keeper
    // reinterpret_cast - оператор преобразования указателя из одного типа в другой.
    // Стоит использовать с осторожностью, потому что в результате может быть
    // неккоректное поведение программы.
    int* ptr_secret = reinterpret_cast<int*>(&keeper);

    // Смещение до поля secret на 4 байта (предполагается, что trash и secret занимают одинаковое количество памяти)
    ptr_secret++;

    // Возвращаем значение secret
    return *ptr_secret;
}
