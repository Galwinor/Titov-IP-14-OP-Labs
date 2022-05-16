from Coordinates import Coordinates
import math
class TQuadrangle:
    def __init__(self, Coords, typ):
        self.Coords = Coords;
        self.type = typ;
        self.Per = self.countPer();
        self.area = 0
    def countPer(self):
        Perim = 0;
        Side = Coordinates(0, 0);
        for i in range(4):
            Side.x = self.Coords[(i+1)%4].x - self.Coords[i].x
            Side.y = self.Coords[(i+1)%4].y - self.Coords[i].y
            Perim += math.sqrt(pow(Side.x, 2) + pow(Side.y, 2))
        return Perim
    def countArea(self):
        pass
    def getAllInfo(self):
        print("{:<13s} Perimetr: {:<6.2f} Area: {:<6.2f}".format(self.type, self.Per, self.area))