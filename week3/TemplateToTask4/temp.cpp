#include <iostream>
#include <fstream>

struct Animal
{
    // enum TypeAnimal
    char name[32];
    size_t age;
    bool gender;
};

void saveAnimalToFile(std::ofstream &out, const Animal &animal)
{
    // TODO Implement logic
}

void readFromFile(std::ifstream &in, Animal &animal)
{
    // TODO Implement logic
}

struct ZooMag
{
    char name[32];
    Animal listOFAnimals[8];
    size_t countAnimals;
};

void save(char *filename, const ZooMag &zoo)
{
    std::ofstream outStream(filename, std::ios::out);

    for (size_t i = 0; i < zoo.countAnimals; i++)
    {
        saveAnimalToFile(outStream, zoo.listOFAnimals[i]);
    }

    outStream.close();
}

void append(char *filename, const ZooMag &zoo)
{
    std::ofstream outStream(filename, std::ios::out);
    saveAnimalToFile(outStream, zoo.listOFAnimals[zoo.countAnimals - 1]);
}

int main()
{
    
}