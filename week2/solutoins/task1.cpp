#include <iostream>

enum Subject
{
    UNKNOWN = -1,
    OOP,
    ALGEBRA,
    DATABASES,
    DAA,
    DATASTRUCTURES,
    SUBJECTS_COUNT
};

struct Student
{
    char name[16];
    char egn[10];
    char facultyNumber[10];
    double grades[16];
    size_t countGrades;
    Subject favouriteSubject;
};

struct Classroom
{
    Student students[20];
    size_t countStudents;
};

void initialize(Student &student)
{
    std::cout << "Enter name: ";
    std::cin.getline(student.name, 16);
    std::cout << "Enter EGN: ";
    std::cin.getline(student.egn, 10);
    std::cout << "Enter faculty number: ";
    std::cin.getline(student.facultyNumber, 10);
    size_t gradesCount;
    std::cout << "Enter grades count form 0 to 16: ";
    std::cin >> gradesCount;
    student.countGrades = gradesCount;

    for (size_t i = 0; i < gradesCount; i++)
    {
        std::cin >> student.grades[i];
    }

    char favouriteSubject[32];
    std::cout << "Enter favourite subject: ";
    std::cin.getline(favouriteSubject, 32);
    student.favouriteSubject = Subject::UNKNOWN;

    while (student.favouriteSubject == Subject::UNKNOWN)
    {
        if (strcmp(favouriteSubject, "OOP") == 0)
        {
            student.favouriteSubject = Subject::OOP;
        }
        else if (strcmp(favouriteSubject, "ALGEBRA") == 0)
        {
            student.favouriteSubject = Subject::ALGEBRA;
        }
        else if (strcmp(favouriteSubject, "DATABASES") == 0)
        {
            student.favouriteSubject = Subject::DATABASES;
        }
        else if (strcmp(favouriteSubject, "APIS") == 0)
        {
            student.favouriteSubject = Subject::DAA;
        }
        else if (strcmp(favouriteSubject, "DATASTRUCTURES") == 0)
        {
            student.favouriteSubject = Subject::DATASTRUCTURES;
        }
        else
        {
            std::cout << "Subject does not exist! Try again" << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the stream buffer
    }
}

void print(const Student &student)
{
    std::cout << "Student info: " << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Egn: " << student.egn << std::endl;
    std::cout << "Faculty number : " << student.facultyNumber << std::endl;
    std::cout << "Student grades: " << std::endl;

    for (size_t i = 0; i < student.countGrades; i++)
    {
        std::cout << student.grades[i] << " ";
    }
}

double getAvaregeGrade(double grades[], size_t gradesCount)
{
    double totalSum = 0.0;

    for (size_t i = 0; i < gradesCount; i++)
    {
        totalSum += grades[i];
    }

    return totalSum / gradesCount;
}

void printAverageMarks(Student *students, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << "Student " << students[i].name << " has avarage grade: " << getAvaregeGrade(students[i].grades, students[i].countGrades) << std::endl;
    }
}

Student &getBestStudent(Student *students, size_t count)
{
    double maxAvarageGrade = DBL_MIN;
    size_t bestStudentIndex = -1;

    for (size_t i = 0; i < count; i++)
    {
        double currentAvgGrade = getAvaregeGrade(students[i].grades, students[i].countGrades);

        if (currentAvgGrade > maxAvarageGrade)
        {
            maxAvarageGrade = currentAvgGrade;
            bestStudentIndex = i;
        }
    }

    return students[bestStudentIndex];
}

Subject getHardestSubject(const Classroom &classroom)
{
    // NOTE!!! Every subject's number, let's call it 'i', in grades, grades[i] is the total sum of grades for this subject
    double *grades = new double[Subject::SUBJECTS_COUNT];
    // NOTE!!! Every subject's number, let's call it 'i', in grades, grades[i] is the total count of grades for this subject
    int *countGradesOnSubject = new int[Subject::SUBJECTS_COUNT];

    for (size_t i = 0; i < classroom.countStudents; i++)
    {
        int index = classroom.students[i].favouriteSubject; // cast subject to int

        for (size_t j = 0; j < classroom.students[i].countGrades; j++)
        {
            grades[index] = classroom.students[i].grades[j];
            countGradesOnSubject[index]++;
        }
    }

    double minAvarageGrade = DBL_MAX;
    int index = -1;

    for (size_t i = 0; i < Subject::SUBJECTS_COUNT; i++)
    {
        double currentAvarage = grades[i] / countGradesOnSubject[i];

        if (currentAvarage < minAvarageGrade)
        {
            index = i;
        }
    }

    delete[] countGradesOnSubject;
    delete[] grades;

    return (Subject)(index);
}

void printSubject(Subject subject)
{
    switch (subject)
    {
    case Subject::OOP:
        std::cout << "Subject is OOP!\n";
        break;
    case Subject::ALGEBRA:
        std::cout << "Subject is Algebra!\n";
        break;
    case Subject::DATABASES:
        std::cout << "Subject is Data bases!\n";
        break;
    case Subject::DAA:
        std::cout << "Subject is Design and analyze of algorithms!\n";
        break;
    case Subject::DATASTRUCTURES:
        std::cout << "Subject is Data structures!\n";
        break;
    default:
        std::cout << "Such subject does not exist!";
        break;
    }
}

int main()
{
}