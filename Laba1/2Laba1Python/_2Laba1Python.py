import Func

n = int(input("Enter n: ")) # Максимальна кількість повторюваних слів
File1 = "FileOne.txt"
File2 = "FileTwo.txt"   
flag = True   
print("Enter text(Ctrl + T to finish): ")
Func.inpt(File1)
Func.inputPlus(File1, File2, n)
while flag:  # Перевірка чи хоче користувач дописати у файл якщо введено +
    a = input("Enter '+' if you want to continue: ")
    if a == "+":
        print("Enter text(Ctrl + T to finish): ")
        Func.MoreInpt(File1)
        Func.inputPlus(File1, File2, n)
    else:
        flag = False
