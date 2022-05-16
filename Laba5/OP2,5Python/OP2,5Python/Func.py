import math
from Coordinates import Coordinates
from square import Square
from rectangle import Rectangle
from parallelogram import Parallelogram

def isColiniar(Side1, Side2):
    k1 = Side1.x * Side2.y
    k2 = Side1.y * Side2.x
    return k1 == k2

def isEquel(Side1, Side2):
    len1 = math.sqrt(pow(Side1.x, 2) + pow(Side1.y, 2))
    len2 = math.sqrt(pow(Side2.x, 2) + pow(Side2.y, 2))
    return len1 == len2

def createItem(V):
    sides = []
    for i in range(4):
        x = V[(i+1)%4].x - V[i].x
        y = V[(i+1)%4].y - V[i].y
        Side = Coordinates(x, y)
        sides.append(Side)
    if isColiniar(sides[0], sides[2]) and isColiniar(sides[1], sides[3]):
        if sides[0].x * sides[1].x + sides[0].y * sides[1].y == 0:
            if isEquel(sides[0], sides[1]):
                return Square(V)
            return Rectangle(V)
        return Parallelogram(V)
    return None

def inpt(n):
    Figures = []
    Cords = []
    flag = True
    for i in range (n):
        while flag:
            print("Enter coords of 4 vertices so that thay are creating rectangle/square/parallelogram in format 'x,y': ")
            for j in range (4):
                cord = input("Enter {}: ".format(str(j + 1)))
                x = float(cord[: cord.find(',')])
                y = float(cord[cord.find(',') + 1:])
                c = Coordinates(x, y)
                Cords.append(c)
            Figures.append(createItem(Cords))
            if Figures[i] == None: 
                print("Wrong format!")
                Figures.pop(i)
            else: flag = False
            Cords = []
        flag = True
    return Figures

def output(Obj):
    print("All your figures:")
    for i in range (len(Obj)):
        print("{}. ".format(str(i + 1)), end = " ")
        Obj[i].getAllInfo()

def calculateSum(Obj):
    area = 0;
    perimetr = 0;
    for i in Obj:
        typ = i.type
        if typ == "Square" or typ == "Rectangle": area += i.area
        else: perimetr += i.Per
    print("Sum the areas(aquares, rectangles) = {:.2f}\nSum of perimeters(parallelograms) = {:.2f}".format(area, perimetr))