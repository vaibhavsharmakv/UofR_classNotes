'''
A Mobject is a motion object that takes an initial location, velocity
and mass and sets a final position for each timestep.

Once a Mobject is defined it should only be addressed through its
methods.
'''

from classes.vect import Vector
class Mobject():    # Mobject = Motion + Object
    def __init__(self, location, velocity, mass):
        self.dt = 1.0/60.0  # This is the inverse of the framerate.
        self.t = 0.0

        self.mass = mass
        self.loc = location
        self.vely = velocity

        self.acc = Vector(0.0, 0.0, 0.0)

        self.logInit = False
        self.output = open('data.txt','w')

    def setPos(self,own):
        own.position.x = self.loc.x
        own.position.y = self.loc.y
        own.position.z = self.loc.z

    def applyForce(self, force):
	    self.acc = self.acc.add(force.div(self.mass))

    def update(self):
        self.t += self.dt
        #self.loc = self.vely.mult(self.dt).add(self.acc.mult(0.5*self.dt**2.0))
        self.loc = self.loc.add(self.vely.mult(self.dt).add(self.acc.mult(0.5*self.dt**2.0)))
        self.vely = self.vely.add(self.acc.mult(self.dt))
        # Zero acc. as it is calculated every dt by forces applied.
        self.acc = Vector(0.0, 0.0, 0.0)

    def log(self):
        # initialize file operation
        if self.logInit == False:
            lineout = "time \t pos.x \t pos.y \t pos.z \t vely.x \t vely.y \t vely.z \n"
            self.output.write(str(lineout))
            self.logInit = True

        lineout = "%02f\t%02f\t%02f\t%02f\t%02f\t%02f\t%02f\n" % (self.t,
                    self.loc.x, self.loc.y, self.loc.z,
                    self.vely.x, self.vely.y, self.vely.z)

        self.output.write(str(lineout))
