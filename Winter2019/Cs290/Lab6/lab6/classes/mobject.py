from classes.vect import Vector
from math import sqrt
method = "euler"


class Mobject():    # Mobject = Motion + Object
    def __init__(self, location, velocity, mass):
        self.dt = 1.0/60.0  # This is the inverse of the framerate.
        self.t = 0.0

        self.mass = mass
        self.loc = location
        self.vely = velocity

        self.acc = Vector(0.0, 0.0, 0.0)

        self.logInit = False
        self.output = open('C:\\Users\\Zengar User\\Google Drive\\Education\\University\\Undergrad\\URegina\\Classes\\Computer Science\\CS290AJ\\Labs\\lab 6\\data.txt','w')

    def setPos(self,own):
        own.position.x = self.loc.x
        own.position.y = self.loc.y
        own.position.z = self.loc.z

    def applyForce(self, force):
        self.acc = self.acc.add(force.div(self.mass))

    def update(self):
        self.t += self.dt
        #self.loc = self.vely.mult(self.dt).add(self.acc.mult(0.5*self.dt**2.0))
        if method == euler: 
        euler(f,y0,a,b,h)
        #self.loc = self.loc.add(self.vely.mult(self.dt).add(self.acc.mult(0.5*self.dt**2.0)))
        #self.vely = self.vely.add(self.acc.mult(self.dt))
        # Zero acc. as it is calculated every dt by forces applied.
        self.acc = Vector(0.0, 0.0, 0.0)

    def rk4(f, x0, y0, x1, n):
        vx = [0] * (n + 1)
        vy = [0] * (n + 1)
        h = (x1 - x0) / float(n)
        vx[0] = x = x0
        vy[0] = y = y0
        for i in range(1, n + 1):
            k1 = h * f(x, y)
            k2 = h * f(x + 0.5 * h, y + 0.5 * k1)
            k3 = h * f(x + 0.5 * h, y + 0.5 * k2)
            k4 = h * f(x + h, y + k3)
            vx[i] = x = x0 + i * h
            vy[i] = y = y + (k1 + k2 + k2 + k3 + k3 + k4) / 6
        return vx, vy

    def f(x, y):
        return x * sqrt(y)
        vx, vy = rk4(f, 0, 1, 10, 100)
        for x, y in list(zip(vx, vy))[::10]:
             print ("%4.1f %10.5f %+12.4e" % (x, y, y - (4 + x * x)**2 / 16))

    def euler(f,y0,a,b,h):
        t,y = a,y0
        while t <= b:
            print ("%6.3f %6.3f" % (t,y))
            t += h
            y += h * f(t,y)

    def log(self):
        # initialize file operation
        if self.logInit == False:
            self.logInit = True

        lineout = "%02f\t%02f\t%02f\t%02f\t%02f\t%02f\t%02f\n" % (self.t,
                    self.loc.x, self.loc.y, self.loc.z,
                    self.vely.x, self.vely.y, self.vely.z)

        self.output.write(str(lineout))

