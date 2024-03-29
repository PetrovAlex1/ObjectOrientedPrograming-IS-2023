﻿# <center>Практикум по "Обектно ориентирано програмиране"</center>

### <center> Използвайте разделна компилация </center>

## Задача 1

Да се дефинира клас **`Time`**, който определя момент от денонощието по зададен час и минути. Да се напишат подходящи конструктори, селектори и мутатори. Нека за класът да важи свойството да **НЕ** може да се създава инстанция само чрез едно число. Нека класът да съдържа методи за:

- добавяне към времето цяло число минути
- достъп до броя минути, изминали от началото на денонощието

## Задача 2

Да се дефинира клас **`Device`**, описващ устройство. Едно устройство се характеризира със:

- тип {компютър, лаптоп, телефон, слушалки}
- марка (симвлен низ)
- модел (символен низ)
- цена (число с плаваща запетая)

Дефинирайте голяма четворка със селектори и мутатори. Нека член-данните бъдат достъпни за четене, но само полето `цена` да има възможност да бъде променяно след създаването на обект.

Да се дефинира клас `DeviceWriter`, който записва обект от тип **`Device`** във файл. Нека информацията се записва във файла според следния шаблон:
{<тип>|<марка>|<модел>|<цена>}.

Да се дефинира `DeviceReader`, който чете обект от тип **`Device`** от файл, констрyира обект и го връща.

Използвайте добри ООП практики.

### Задачата е подобна на първо домашно по ООП И/ИС 2022
