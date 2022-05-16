import math
from TQuadrangle import TQuadrangle
class Rectangle(TQuadrangle):
    def __init__(self, Coords, typ = "Rectangle"):
        super().__init__(Coords, typ)
        self.area = self.countArea()
    def countArea(self):
        Side1 = math.sqrt(pow(self.Coords[1].x - self.Coords[0].x, 2) + pow(self.Coords[1].y - self.Coords[0].y, 2))
        Side2 = math.sqrt(pow(self.Coords[2].x - self.Coords[1].x, 2) + pow(self.Coords[2].y - self.Coords[1].y, 2))
        return Side1 * Side2
