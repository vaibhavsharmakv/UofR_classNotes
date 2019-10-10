import bge
import math
from classes.vect import Vector
from classes.mobject import Mobject

# Get our keyboard input
keyboard = bge.logic.keyboard

t_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.TKEY]

scene = bge.logic.getCurrentScene()
cont = bge.logic.getCurrentController()
own = cont.owner

objList = scene.objects
obj_name = "Camera"
cam = objList[obj_name]


def seek(mobject, target, maxForce):
    desired = target.sub(own.position)
    desired = desired.div(2.0)
    steer = desired.sub(mobject.vely)

    if steer.x > maxForce:
        steer.x = maxForce
    if steer.y > maxForce:
        steer.y = maxForce
    if steer.z > maxForce:
        steer.z = maxForce
    
    mobject.applyForce(steer)

def main():

    m = 1.0
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
    
    target = Vector(0, 0, 5)
    player = Vector(cam.position.x, cam.position.y, cam.position.z)
    proximity = target.sub(player).mag()
    seek(mobject, target, 100)

    if proximity <= 8:
        seek(mobject, player, 3)
    

# Update physics and set position
    mobject.log()
    mobject.update()
    mobject.setPos(own)

# Save values to global dictionary
    own["mobject"] = mobject



main()


