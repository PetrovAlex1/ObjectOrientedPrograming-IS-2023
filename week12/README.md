# <center>Практикум по "Обектно ориентирано програмиране"</center>

# <center> Templates (Шаблони) </center>

### Основи

Нека имаме функцията `add`, която я overload-ваме до още две форми, с `double` и `std::string`.

```c++
#include <iostream>
#include <string>

int add(int first, int second)
{
	return first + second;
}

double add(double first, double second)
{
	return first + second;
}

std::string add(const std::string& first, const std::string& second)
{
	return first + second;
}

int main()
{
	std::cout << add(1, 2) << std::endl;
	std::cout << add(3.5, 6.5) << std::endl;
	std::cout << add("Obicham", " Stolichno!") << std::endl;

	return 0;
}
```

В случая имаме три функции с еднаква логика, да събират две променливи и да връщат резултата. Единствената разлика между тях е типа, който получава и връща функцията. Можем да се придържаме към [DRY principle](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) като използваме **шаблони(templates)** и си спестим еднаквия код.

```c++
#include <iostream>
#include <string>

template<typename T>
T add(const T& first, const T& second)
{
	return first + second;
}

int main()
{
	std::cout << add(1, 2) << std::endl;
	std::cout << add(3.5, 6.5) << std::endl;
	std::cout << add<std::string>("Obicham", " Stolichno!") << std::endl;

	return 0;
}
```

### Друг начин да използваме шаблони

Можем да подаваме и стойности към шаблонните функции.

```c++
#include <iostream>

template<int N>
void add(int& value)
{
	value += N;
}

int main()
{
	int beers = 0;
	add<1>(beers);
	add<2>(beers);
	add<3>(beers);

	std::cout << beers << std::endl;//6

	return 0;
}
```

### Шаблоните имат една особеност. Каква е тя?

### Шаблонни класове(Template classes)

```c++
#include <iostream>

template <typename T, int CAPACITY>
class Array
{
private:
	T* arr;
public:

	Array()
	{
		this->arr = new T[CAPACITY];
	}

	~Array()
	{
		delete[] this->arr;
	}

	int getCapacity() const
	{
		return CAPACITY;
	}
};

int main()
{
	Array<double, 3> arr;

	std::cout << arr.getCapacity() << std::endl;

	return 0;
}
```

### Защо имплементацията на един шаблонен клас трябва да бъде само в хедъра? Има ли друг начин?

## Задачата за днес

Да се имплементира шаблонен клас вектор, който поддържа следния интерфейс:

- конструктор по подразбиране(size = 0, capacity = 8)
- конструктор (size_t n)-сърздава вектор с капацитет n
- конструктор (size_t n, const T& elem) всеки елемент има стойност elem
- push_back() - добавя елемент в края
- pop_back() - премахва последния елемент
- operator[](size_t index) - достъпва елемент на позиция(в двете му форми)
- empty()-проверява дали е празен вектора
- size() връща размера
- capacity() връща капацитет
- clear() - премахва всички елементи. size = 0, capacity остава непроменено.
