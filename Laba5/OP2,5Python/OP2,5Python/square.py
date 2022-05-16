import math
from rectangle import Rectangle
class Square(Rectangle):
    def __init__(self, Coords):
        super().__init__(Coords, "Square")
        self.area = self.countArea()
    def countArea(self):
        Side = math.sqrt(pow(self.Coords[1].x - self.Coords[0].x, 2) + pow(self.Coords[1].y - self.Coords[0].y, 2))
        return pow(Side, 2)

