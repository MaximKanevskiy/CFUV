Student make_student(std::string line) 
{
    Student student;
    size_t semicolonIndex;

    semicolonIndex = line.find(';');
    student.name = line.substr(0, semicolonIndex);
    line.erase(0, semicolonIndex + 1);

    semicolonIndex = line.find(';');
    student.group = line.substr(0, semicolonIndex);
    line.erase(0, semicolonIndex + 1);

    while (!line.empty()) 
    {
        Course course;
        semicolonIndex = line.find(';');
        course.name = line.substr(0, semicolonIndex);
        line.erase(0, semicolonIndex + 1);

        course.semester = line[0] - '0';
        line.erase(0, 2);

        course.finished = line[0] - '0';
        line.erase(0, 2);

        student.courses.push_back(course);
    }

    return student;
}

bool is_upper(Student st1, Student st2) 
{
    if (st1.group == st2.group) 
    {
        return st1.name < st2.name;
    }

    return st1.group < st2.group;
}

bool is_debtor(Student student, int currentSemester, int maxDebts) 
{
    int counter = 0;

    for (Course course : student.courses) 
    {
        if (course.semester < currentSemester && !course.finished) 
        {
            counter++;
        }
    }

    return counter > maxDebts;
}

void print(std::vector<Student> students) 
{
    if (students.empty()) 
    {
        std::cout << "Empty list!";
        return;
    }

    std::cout << students[0].group << std::endl;
    std::cout << "- " << students[0].name << std::endl;

    for (size_t i = 1; i < students.size(); i++) 
    {
        if (students[i].group != students[i - 1].group) 
        {
            std::cout << students[i].group << std::endl;
        }

        std::cout << "- " << students[i].name << std::endl;
    }
}
