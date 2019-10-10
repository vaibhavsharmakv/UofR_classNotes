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
t_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.TKEY]


def main():

    # Get controllers so we can move the object around
    cont = bge.logic.getCurrentController()
    own = cont.owner
    dataLog = "TRUE"

    # Routine to initilize global variables
    if 'init' not in own:
        p0 = Vector(own.position.x,own.position.y,own.position.z)
        v0 = Vector(0.0, 0.0, 0.0)
        own['mobject'] = Mobject(p0, v0, 1.0)
        mobject = own['mobject']
        own['logon'] = False
        own['init'] = False # so this routine runs once

# Load variables from global dictionary
    mobject = own['mobject']
    logon = own['logon']

# Apply forces

    # Define the coefficient of friction
    coeff = 0.7

    #applyForce(Vector(0.0,))

    if j_pressed:
        mobject.applyForce(Vector(0.0, 1.0, 0.0))
    if l_pressed:
        mobject.applyForce(Vector(0.0,-1.0,0.0))
    if i_pressed:
        mobject.applyForce(Vector(1.0,0.0,0.0))
    if k_pressed:
        mobject.applyForce(Vector(-1.0,0.0,0.0))

    friction = mobject.vely.norm().mult(-1.0).mult(coeff)
   
    mobject.applyForce(friction)

    mobject.applyForce(Vector(0.0,-20.0,4.0))
    mobject.applyForce(Vector(0.0,-20.0,-8.0)) 
   

    
    




# Toggle logging
    if t_pressed:
        logon = not logon

    if logon:
        mobject.log()

# Update physics and set position
    mobject.update()
    mobject.setPos(own)

# Save values to global dictionary
    own["mobject"] = mobject
    own["logon"] = logon



main()
