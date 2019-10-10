import bge
import math
from classes.vect import Vector
from classes.mobject import Mobject

# Get our keyboard input
keyboard = bge.logic.keyboard

i_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.IKEY]
j_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.JKEY]
k_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.KKEY]
l_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.LKEY]
o_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.OKEY]
p_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.PKEY]

t_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.TKEY]


def main():

    # Get controllers so we can move the object around
    cont = bge.logic.getCurrentController()
    own = cont.owner
    m = 0.8
    # Routine to initilize global variables
    if 'init' not in own:
        own.position.x += 0.1 # avoid divide by zero!
        own.position.y += 0.1
        p0 = Vector(own.position.x, own.position.y, own.position.z)
        own['p0'] = p0
        v0 = Vector(0.0, 0.0, 0.0)
        own['mobject'] = Mobject(p0, v0, m)
        mobject = own['mobject']
        own['init'] = False # so this routine runs once

# Load variables from global dictionary
    mobject = own['mobject']
# Apply forces

    if i_pressed:
        mobject.applyForce(Vector(0.0, 0.0, 1.0))
    if k_pressed:
        mobject.applyForce(Vector(0.0,0.0,-1.0))
    if j_pressed:
        mobject.applyForce(Vector(1.0,0.0,0.0))
    if l_pressed:
        mobject.applyForce(Vector(-1.0,0.0,0.0))

    if o_pressed:
        mobject.applyForce(Vector(0.0,1.0,0.0))

    if p_pressed:
        mobject.applyForce(Vector(0.0,-1.0,0.0))


    k = 5.0
    b = 0.1

    p1 = Vector(3.0, 5.0, 0.0)
    p2 = Vector(7.0, 5.0, 0.0)
    p3 = Vector(0.0, 0.0, 0.0)

    r = math.sqrt((0.0-own.position.x)**2+(0.0-own.position.y)**2)

    f1x = (p1.x-own.position.x)/(((p1.x-own.position.x)**2)+((p1.y-own.position.y)**2)**(3/2))
    f1y = (p1.y-own.position.y)/(((p1.x-own.position.x)**2)+((p1.y-own.position.y)**2)**(3/2))

    f2x = (p2.x-own.position.x)/(((p2.x-own.position.x)**2)+((p2.y-own.position.y)**2)**(3/2))
    f2y = (p2.y-own.position.y)/(((p2.x-own.position.x)**2)+((p2.y-own.position.y)**2)**(3/2))

    f3x = (p3.x-own.position.x)/(((p3.x-own.position.x)**2)+((p3.y-own.position.y)**2)**(3/2))
    f3y = (p3.y-own.position.y)/(((p3.x-own.position.x)**2)+((p3.y-own.position.y)**2)**(3/2))


    if r > 10: # to make sure that our forceball doesn't get away!
        if own.position.x > 0:
            mobject.applyForce(Vector(-0.1*r, 0.0, 0.0))
        elif own.position.x < 0:
            mobject.applyForce(Vector(0.1*r,0.0,0.0))

        if own.position.y > 0:
            mobject.applyForce(Vector(0.0, -0.1*r, 0.0))
        elif own.position.y < 0:
            mobject.applyForce(Vector(0.0, 0.1*r, 0.0))


    mobject.applyForce(Vector(f1x,f1y,0.0).mult(k))
    mobject.applyForce(Vector(f2x,f2y,0.0).mult(k))
    mobject.applyForce(Vector(f3x, f3y,0.0).mult(k))



# Update physics and set position
    mobject.log()
    mobject.update()
    mobject.setPos(own)

# Save values to global dictionary
    own["mobject"] = mobject



main()
