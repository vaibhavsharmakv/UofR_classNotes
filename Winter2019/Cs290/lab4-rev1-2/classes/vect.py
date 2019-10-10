import math

# First, let's define a 2-D vector class:
class Vector():

	# This is a constructor in python:
    def __init__(self, x, y, z):
        self.x = x	# the x value of the vector
        self.y = y	# the y value of the vector
        self.z = z  # the z value of the vector

    # This is for debugging purposes -- gives us info about the class instance
    def get_info(self):
        print(self.x, self.y, self.z)


	# Our vector math routines:
	# Note: we are returning vectors not changing the original!

    def add(self,v):
        return Vector(self.x+v.x, self.y+v.y, self.z+v.z)

    def sub(self,v):
        return Vector(self.x-v.x, self.y-v.y, self.z-v.z)

    def mult(self,s):
        return Vector(self.x*s, self.y*s, self.z*s)

    def div(self,s):
        return Vector(self.x/s, self.y/s, self.z/s)

    def mag(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    def norm(self):

        if self.mag() == 0.0:  # Make sure we don't divide by zero!
            return Vector(0.0, 0.0, 0.0)
        else:
            return Vector(self.x/self.mag(),self.y/self.mag(), self.z/self.mag())
