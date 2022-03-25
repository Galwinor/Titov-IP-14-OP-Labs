import Func

cont = "+"
flag = True # Зберігає значення про дописування у файл
while cont == "+":
    Func.inpt(flag) # Введення інформації про машини
    print("\nList of cars: ")
    Func.outpt("AutoBase.txt") # Виведення вмісту файла 
    Func.CreateList() # Інформація про автомобілі куплені за останній місяць
    Func.UseedAuto() # Інформація про автомобілі продані більше ніж через рік після створення
    cont = input("\nIf you want to add info. write '+': ")
    if cont == "+": flag = False