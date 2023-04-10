# <center>Практикум по "Обектно ориентирано програмиране"</center>

## Да си припомним "приятелите"

### Пример №1:

```c++
#include <iostream>

class Number
{
public:

	friend void setToZero(Number& number);

	Number(int number) : number(number) {}

	void print() const
	{
		std::cout << num << std::endl;
	}

private:
	int number;
};

// Забележете, че setToZero не е член-функция(няма Number::setToZero),
// и също, че имаме достъп до private член-данната num
void setToZero(Number& number)
{
	number.number = 0;
}

int main()
{
	Number num(2);

	num.print();// 2
	setToZero(num); // Зануляваме
	num.print();// 0

	return 0;
}
```

### Пример №2

```c++
class RationalNumber;

class IntNumber
{
public:
// Common Function
	friend RationalNumber add(const IntNumber& intNum, const RationalNumber& rationalNum);

	IntNumber(int number) : num(number) {}

	void print() const
	{
		std::cout << num << std::endl;
	}

private:
	int num;
};

class RationalNumber
{
public:
// Common Function
	friend RationalNumber add(const IntNumber& intNum, const  RationalNumber& rationalNum);

	RationalNumber(int numerator, int denumerator)
		: numerator(numerator), denominator(denumerator) {}

private:
	int numerator;
	int denominator;
};

RationalNumber add(const IntNumber& intNum, const RationalNumber& rationalNum)
{
	int newNumerator = rationalNum.numerator + (intNum.num * rationalNum.denominator);
	RationalNumber result(newNumerator, rationalNum.denominator);

	return result;
}
```

## Задача 1

Дефинирайте клас `Pair`, който представлява двойка цели числа. Нека класът да **няма** конструктор по подразбиране. Дефинирайте оператори за сравнение и равенство, както и за работа с потоци `>>` и `<<`.
Уточнение -> Двойка числа се сравняват по следния начин:
Първо се сравняват двата домейна(първи параметър), ако те са еднакви, то се сравняват двата кодомейна(втори параметър). Ако и те са еднакви, имаме равенство.

Да се реализира клас `PairManager`, който пази в себе си масив от двойки числа. Нека този клас поддържа:

- метод, който връща еднаквите двойки.
- метод, който връща сортиран масивa от двойки

## Задача 2

Да се реализира клас `Rational`, който представлява дробно число. Нека класът да **няма** конструктор по подразбиране.
Предефинирайте следните оператори:

```c++
	bool operator==(const Rational& other) const;
	bool operator!=(const Rational& other) const;
	bool operator>(const Rational& other) const;
	bool operator<(const Rational& other) const;

	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);
	Rational& operator*=(const Rational& other);
	Rational& operator/=(const Rational& other);

	friend Rational operator+(const Rational& lhs, const Rational& rhs);
	friend Rational operator-(const Rational& lhs, const Rational& rhs);
	friend Rational operator*(const Rational& lhs, const Rational& rhs);
	friend Rational operator/(const Rational& lhs, const Rational& rhs);
```

# За вкъщи

## Клас `Vector`

Да се имплементира клас **`IntVector`**, който работи само със цели числа(integer). Дефинирайте голяма четворка заедно със конструктор, който създава **`IntVector`** по подаден капацитет на масива. Помислете какво трябва да добавите към този конструктор. Нека класът поддържа следната функционалност:

- метод `add`, който добавя елемент в края на масива
- метод `getSize`, който връща броя на елементите във вектора
- метод `empty`, който връща истина, ако вектора е празен

Нека се дефинират и следните оператори:

- `==` и `!=` за проверка за равенство и различие
- `+=` за събиране на елементите на два вектора. Обърнете внимание, че този оператор трябва да върне като резултат **левия** операнд
- `[]` за достъп на елементите в масива. Да се имплементират двете форми, т.е. **mutable** и **immutable**

## Клас `String`

Да се имплементира клас **`MyString`**, прототип на `std::string`. Да се дефинира голяма четворка. Нека класът поддържа следната функционалност:

- метод `append`, който добавя друг стринг в края низа
- метод `pushBack`, който добавя символ в края на низа
- метод `size`, който връща размера на низа
- метод `getData`, който връща низа. Помислете какъв ще бъде този тип и го съобразете с ООП правилата
- метод `empty`, който връща истина при празен низ
- метод `compare`, който сравнява два стринга лексикографски.
- метод `erase`, който изтрива съдържанието на низа

![compareTable](images/Screenshot%202023-04-09%20175448.png)

Снимката е взета от [тук](https://cplusplus.com/reference/string/string/compare/)

Нека класа дефинира следните оператори:

- `==` и `!=` за проверка за равенство и различие
- `[]` за достъп на елементите в масива. Да се имплементират двете форми, т.е. **mutable** и **immutable**
- оператори за работа със поток `<<` и `>>`
- `+` - събира два стринга и връща резултата
