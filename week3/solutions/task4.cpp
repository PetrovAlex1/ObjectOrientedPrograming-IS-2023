#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning(disable : 4996)

enum AnimalType
{
    UNKNOWN,
    DOG,
    CAT,
    RABBIT,
    ANIMALTYPE_COUNT
};

struct Animal
{
    char name[32];
    AnimalType type;
    size_t age;
    bool gender; // 0-female, 1-male
};

bool readFromFile(Animal &animal, std::ifstream &in)
{
    if (!in.good())
    {
        std::cout << "There is problem with the stream!\n";
        in.clear();
        return 0;
    }

    in.getline(animal.name, 32, '\n');
    char buffer[32];
    in.getline(buffer, 32, '\n');

    if (strcmp(buffer, "DOG") == 0)
    {
        animal.type = AnimalType::DOG;
    }
    else if (strcmp(buffer, "CAT") == 0)
    {
        animal.type = AnimalType::CAT;
    }
    else if (strcmp(buffer, "RABBIT") == 0)
    {
        animal.type = AnimalType::RABBIT;
    }
    else
    {
        animal.type = AnimalType::UNKNOWN;
        std::cout << "Wrong animal type!\n";
        return 0;
    }

    in >> animal.age;
    in >> animal.gender;

    return 1;
}

bool writeToFile(const Animal &animal, std::ofstream &out)
{
    if (!out.good())
    {
        std::cout << "Problem with writing in file!\n";
        out.clear();
        return 0;
    }

    out << animal.name << '\n';

    switch (animal.type)
    {
    case AnimalType::DOG:
        out << "DOG\n";
        break;
    case AnimalType::CAT:
        out << "CAT\n";
        break;
    case AnimalType::RABBIT:
        out << "RABBIT\n";
        break;
    default:
        out << "UNKNOWN\n";
        break;
    }

    out << animal.age;
    out << '\n';
    out << animal.gender;
    out << '\n';

    return 1;
}

struct ZooMag
{
    char name[32];
    Animal list[16];
    size_t count;
};

void save(const char *filename, const ZooMag &zoo)
{
    std::ofstream out(filename, std::ios::out | std::ios::trunc);

    if (!out.is_open())
    {
        std::cout << "Problem with openig the stream!\n";
        out.clear();
        out.close();
        return;
    }

    for (size_t i = 0; i < zoo.count; i++)
    {
        writeToFile(zoo.list[i], out);
    }

    out.close();
}

void append(const char *filename, const ZooMag &zoo)
{
    std::ofstream out(filename, std::ios::out | std::ios::app);

    if (!out.is_open())
    {
        std::cout << "Problem with opening file for writing!\n";
        out.clear();
        out.close();
        return;
    }

    writeToFile(zoo.list[zoo.count - 1], out);
    out.close();
}

int main()
{
    // Read information for dog
    Animal dog;
    std::ifstream in("test.txt", std::ios::in);
    readFromFile(dog, in);
    in.close();

    // Read information for cat
    Animal cat;
    in.open("test1.txt", std::ios::in);
    readFromFile(cat, in);
    in.close();

    // Read information for rabbit
    Animal rabbit;
    in.open("test2.txt", std::ios::in);
    readFromFile(rabbit, in);
    in.close();

    ZooMag zoo;
    zoo.list[0] = dog;
    zoo.list[1] = cat;
    zoo.list[2] = rabbit;
    zoo.count = 3;

    save("saveAnimals.txt", zoo);

    Animal anotherDog;
    strcpy(anotherDog.name, "Krasimir");
    anotherDog.type = AnimalType::DOG;
    anotherDog.age = 10;
    anotherDog.gender = 1;

    zoo.list[3] = anotherDog;
    zoo.count++;

    append("saveAnimals.txt", zoo);

    // Animal dog;
    // strcpy(dog.name, "Nola");
    // dog.type = AnimalType::DOG;
    // dog.age = 8;
    // dog.gender = 0;

    // zoo.list[0] = dog;
    // zoo.count = 1;

    // append("saveAnimals.txt", zoo);

    return 0;
}