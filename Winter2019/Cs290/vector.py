#
#
#
########################
import math


class Vector():
	"""docstring for Vector"""
	def __init__(self, x , y ,z ):
		super(Vector, self).__init__()
		self.x = x
		self.y = y 
		self.z = z

	def get_info(self):
		print(self.x, self.y, self.z)


	def addVector(self, SecondVector):
		return Vector(self.x+SecondVector.x, self.y + SecondVector.y, self.z + SecondVector.z)

	def mult(self, s):
		return Vector(self.x*s, self.y*s, self.z*s)


	def magnitudeVector(self, SecondVector):
		
		x1 = self.x + SecondVector.x
		y1 = self.y + SecondVector.y
		z1 = self.z + SecondVector.z
		
		x2 = x1 * x1
		y2 = y1 * y1
		z2 = z1 * z1
		
		f = math.sqrt(x2 + y2 +z2)
		print (f)
		return (f, x2, y2, z2)

	def unitvector(self, magnitude):
		xUnit = self.x/magnitude
		yUnit = self.y/magnitude
		zUnit = self.z/magnitude

		return Vector(xUnit, yUnit, zUnit)

			
def main():
	"""First vector """
	v = Vector(2,5,3)

	"""Second vector """ 
	sv = Vector(5,5,3)

	"""Resulting vector"""

	magnitude, x3 , y3, z3 = v.magnitudeVector(sv)

	nv = Vector(x3, y3, z3)

	UV = nv.unitvector(magnitude)
	
	UV.get_info()
	


main()

		