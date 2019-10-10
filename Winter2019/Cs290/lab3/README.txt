CS290AJ Lab 3
Created by: Trevor Tomesh
Date: September 20th 2017
-------------------------

Manifest (+ user editable / - do not edit):
    +apple.py
     Controls the apple object in the scene
    +book.py 
     Controls the book object in the scene
    -__init__.py 
     Required for python to know where the
     root directory is to look for classes.
    +lab3.blend
     The blender file that contains the scene
    -README.txt
     This file
    -classes
     Directory which contains the class
     definitions
        +mobject.py
         class definition for motion objects
        +vect.py
         class definition for vector objects
        -__pycache__
         Contains cython runtime files
    -2.79
     Blender python language folder

Directions
  To run this lab you must launch lab3.blend and point the in-game scripts to the external
scripts. To do this, simply change:

filename = "/home/trevor/Documents/GitHub/CS290AJ/labs/lab3/book.py"

to

filename = "<your directory>/book.py"

Do the same for the apple object by clicking on the notepad icon on the toolbar at the bottom of the screen and changing to importApple.py

If you have any questions, email me at tmtomesh@gmail.com
