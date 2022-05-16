from TQuadrangle import TQuadrangle
import math
class Parallelogram(TQuadrangle):
    def __init__(self, Coords):
        super().__init__(Coords, "Parallelogram")
        self.area = self.countArea()

    def countArea(self):
        Side1 = math.sqrt(pow(self.Coords[1].x - self.Coords[0].x, 2) + pow(self.Coords[1].y - self.Coords[0].y, 2))
        Side2 = math.sqrt(pow(self.Coords[2].x - self.Coords[1].x, 2) + pow(self.Coords[2].y - self.Coords[1].y, 2))
        sina = math.sin(math.acos(math.fabs(((self.Coords[0].x - self.Coords[1].x)*(self.Coords[2].x - self.Coords[1].x) + (self.Coords[0].y - self.Coords[1].y)*(self.Coords[2].y - self.Coords[1].y))/(Side1*Side2))))
        return sina * Side1 * Side2