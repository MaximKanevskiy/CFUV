int count_ones(std::string num)
{
    return std::count(num.begin(), num.end(), '1');
}

bool compare(std::string a, std::string b)
{
    int count_a = count_ones(a);
    int count_b = count_ones(b);

    if (count_a == count_b)
    {
        if (std::stoi(a) < std::stoi(b))
        {
            return true;
        }

        if (std::stoi(a) > std::stoi(b))
        {
            return false;
        }
    }
    else
    {
        if (count_a > count_b)
        {
            return true;
        }

        if (count_a < count_b)
        {
            return false;
        }
    }
}
