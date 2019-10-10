import bge
import math
from classes.vect import Vector
from classes.mobject import Mobject

dataLog = "False"

# Get our keyboard input
keyboard = bge.logic.keyboard
t_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.TKEY]
g_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.GKEY]


def main():

# Get controllers so we can move the object around
    cont = bge.logic.getCurrentController()
    own = cont.owner


    # Routine to initilize global variables
    if 'init' not in own:

        p0 = Vector(own.position.x,own.position.y,own.position.z)
        v0 = Vector(0.0, 0.0, 0.0)
        own['mobject'] = Mobject(p0, v0, 1.0)

        own['gravon'] = False
        own['init'] = False # so this routine runs once

# Load variables from our global dictionary
    mobject = own['mobject']
    gravon = own['gravon']

# Apply forces

    if g_pressed and gravon == False:
        gravon = True
    if gravon:
        mobject.applyForce(Vector(0.0, 0.0, -9.8))
        mobject.applyForce(Vector(0.0, 0.0, 2.0*mobject.vely.z**2))

    
    mobject.log()

# Update physics and set position
    mobject.update()
    mobject.setPos(own)

# Save values back to global dictionary
    own["mobject"] = mobject
    own['gravon'] = gravon
    own["logon"] = logon

main()
