from datetime import date
import pickle
from autoBase import AutoBase
from date import Date

def inpt(flag): 
    k = '+'
    if flag: File = open("AutoBase.txt", "wb") # Відкриття файла для запису
    else: File = open("AutoBase.txt", "ab") # Відкриття файла для дозапису
    while k == "+":
        Name = input("Enter name: ")
        Data = input("Enter Release date with point '10.10.2010': ")
        DateR = Date(int(Data[:Data.find('.')]), int(Data[Data.find('.') + 1: Data.rfind('.')]), int(Data[Data.rfind('.') + 1:]))
        Data = input("Enter Sale Release date with point '10.10.2010': ")
        DateSR = Date(int(Data[:Data.find('.')]), int(Data[Data.find('.') + 1: Data.rfind('.')]), int(Data[Data.rfind('.') + 1:]))
        auto = AutoBase(Name, DateR, DateSR)
        k = input("\nEnter '+' in case you want to contnue: ")
        pickle.dump(auto, File)
    File.close()
    
def ReadF(name): # Читання з файла у список
    File = open(name, "rb") # Відкриття файла для читання
    list =[]
    flag = True 
    while flag:
        try:
            list.append(pickle.load(File))
        except EOFError: # Поки не дійшло до кінця файла
            flag = False
    File.close()
    return list

def outpt(name): # Вивід файла
    list = ReadF(name)
    for auto in list:
        print("Name: {:<15} Release Date: {!s:0>2}.{!s:0>2}.{!s:<9} Sale Release Date: {!s:0>2}.{!s:0>2}.{!s}".format(auto.Name, auto.DateR.day, auto.DateR.mounth, auto.DateR.year, 
                        auto.DateSR.day, auto.DateSR.mounth, auto.DateSR.year))

def CreateList(): 
    date_now = date.today() # Зчитування поточної дати
    File = open("AutoList.txt", "wb")
    list = ReadF("AutoBase.txt")
    flag = True
    for auto in list:
        if auto.DateSR.day <= date_now.day and date_now.month == auto.DateSR.mounth or auto.DateSR.day > date_now.day and date_now.month - auto.DateSR.mounth == 1 or date_now.year - auto.DateSR.year == 1 and auto.DateSR.mounth == 12 and auto.DateSR.dat > date_now.day:
            flag = False
            pickle.dump(auto, File)
    File.close()
    print("\nCars on Sale in last mounth: ")
    if flag: print("No cars!")
    else: outpt("AutoList.txt")

def UseedAuto():
    print("\nSaled after >1 year after Release: ")
    File = open("AutoBase.txt", "rb")
    flag = True
    list = ReadF("AutoBase.txt") # Читання з файла у список
    for auto in list:
        if auto.DateSR.year - auto.DateR.year == 1 and auto.DateSR.mounth == auto.DateR.mounth and auto.DateSR.day >= auto.DateR.day or auto.DateSR.year - auto.DateR.year == 1 and auto.DateSR.mounth > auto.DateR.mounth or auto.DateSR.year - auto.DateR.year > 1:
            flag = False
            print("Name: {:<15} Release Date: {!s:0>2}.{!s:0>2}.{!s:<9} Sale Release Date: {!s:0>2}.{!s:0>2}.{!s}".format(auto.Name, auto.DateR.day, auto.DateR.mounth, auto.DateR.year, 
                        auto.DateSR.day, auto.DateSR.mounth, auto.DateSR.year))
    File.close()
    if flag: print("No cars!")

            
