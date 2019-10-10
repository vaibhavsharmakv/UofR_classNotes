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
    m = 1.0
    b = 0.8
    k = 14.0
    g = -9.8
    # Routine to initilize global variables
    if 'init' not in own:
        p0 = Vector(own.position.x,own.position.y,own.position.z)
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

    grav = Vector(0.0, 0.0, -9.8).mult(m)
    damp = Vector(mobject.vely.x*-b, mobject.vely.y*-b, mobject.vely.z*-b).mult(m)
    spring = Vector(0.0, 0.0, 5.0-own.position.z).mult(k)

# Add forces

    mobject.applyForce(grav)
    mobject.applyForce(damp)
    mobject.applyForce(spring)


# Update physics and set position
    mobject.log()
    mobject.update()
    mobject.setPos(own)

# Save values to global dictionary
    own["mobject"] = mobject



main()
