import math #importing math library for all trigonometric functions
import random #importing random library for generating random numbers

# define any function here!
def f(x):  #function defination
    return math.sin(x)**3+math.cos(x) 

# define any xmin-xmax interval here! (xmin < xmax)
xmin = 0.0   #calculating minimum number of steps in the x axis 
xmax = 3.0 * math.pi #calculating maximum number of steps in the x axis

# find ymin-ymax
numSteps = 1000000 # bigger the better but slower!  
ymin = f(xmin) #calculating the minimum number of steps in the y axis
ymax = ymin 
for i in range(numSteps):  #loop runs from 0 to number of steps
    x = xmin + (xmax - xmin) * float(i) / numSteps 
    y = f(x)
    if y < ymin: ymin = y   
    if y > ymax: ymax = y

# Monte Carlo
rectArea = (xmax - xmin) * (ymax - ymin) #calculating the rectangle area 
numPoints = 1000000 # bigger the better but slower! This is the maximum number of steps
ctr = 0 #assigning the counter to zero
for j in range(numPoints):  #loop runs from 0 to number of points
    x = xmin + (xmax - xmin) * random.random() #finding the x coordinate
    y = ymin + (ymax - ymin) * random.random() #finding the y coordinate
    if math.fabs(y) <= math.fabs(f(x)): #calculates the absolute value of y and f(x)
        if f(x) > 0 and y > 0 and y <= f(x):
            ctr += 1 # area over x-axis is positive 
        if f(x) < 0 and y < 0 and y >= f(x):
            ctr -= 1 # area under x-axis is negative

fnArea = rectArea * float(ctr) / numPoints #calculating the area around the number of points
print("Numerical integration = " + str(fnArea)) #printing the numeric value of area