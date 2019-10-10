import bge
import math
from classes.vect import Vector
from classes.mobjectEulerRK4 import Mobject

# Get our keyboard input
keyboard = bge.logic.keyboard

t_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.TKEY]
#k_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.KKEY]
#l_pressed = bge.logic.KX_INPUT_ACTIVE == bge.logic.keyboard.events[bge.events.LKEY]


scene = bge.logic.getCurrentScene()
cont = bge.logic.getCurrentController()
own = cont.owner


objList = scene.objects
obj_name = "Camera"
cam = objList[obj_name]


def seek(mobjectEulerRK4, target, maxForce):
    desired = target.sub(own.position)
    desired = desired.div(2.0)
    steer = desired.sub(mobjectEulerRK4.vely)

    if steer.x > maxForce:
        steer.x = maxForce
    if steer.y > maxForce:
        steer.y = maxForce
    if steer.z > maxForce:
        steer.z = maxForce

    mobjectEulerRK4.applyForce(steer)

def main():

    m = 1.0
    # Routine to initilize global variables
    if 'init' not in own:
        p0 = Vector(own.position.x,own.position.y,own.position.z)
        own['p0'] = p0
        v0 = Vector(0.0, 0.0, 0.0)
        own['mobjectEulerRK4'] = Mobject(p0, v0, m)
        mobjectEulerRK4 = own['mobjectEulerRK4']
        own['init'] = False # so this routine runs once

# Load variables from global dictionary
    mobjectEulerRK4 = own['mobjectEulerRK4']

# Apply forces

    
    mobjectEulerRK4.applyForce(euler) = True

    #    mobjectEulerRK4.applyForce(euler) = True

    target = Vector(0, 0, 5)
    player = Vector(cam.position.x, cam.position.y, cam.position.z)
    proximity = target.sub(player).mag()
    slowDown = player.sub(target)
    seek(mobjectEulerRK4, target, 90)
    

    if proximity <= 8:
        seek(mobjectEulerRK4, player, 3)

# Update physics and set position
    mobjectEulerRK4.log()
    mobjectEulerRK4.update()
    mobjectEulerRK4.setPos(own)

# Save values to global dictionary
    own["mobjectEulerRK4"] = mobjectEulerRK4



main()

