Student make_student(const std::string& line)
{
    std::string name, group;
    size_t pos = line.find(';');
    name = line.substr(0, pos);
    group = line.substr(pos + 1);

    Student student;
    student.name = name;
    student.group = group;

    return student;
}

bool is_upper(const Student& student1, const Student& student2)
{
    if (student1.group.compare(student2.group) < 0)
        return true;
    else if (student1.group.compare(student2.group) == 0)
    {
        if (student1.name.compare(student2.name) < 0)
            return true;
    }

    return false;
}

void print(const std::vector<Student>& students)
{
    if (students.empty())
    {
        std::cout << "Empty list!" << std::endl;
        return;
    }

    std::string current_group = students[0].group;
    std::cout << current_group << std::endl;

    for (const Student& student : students)
    {
        if (student.group != current_group)
        {
            current_group = student.group;
            std::cout << current_group << std::endl;
        }

        std::cout << "- " << student.name << std::endl;
    }
}
