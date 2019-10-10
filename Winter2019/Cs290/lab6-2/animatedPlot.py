# This is a simple script that will allow you to make live plots in
# python. It requires that you install matplotlib and tkinter -- so
# you'll have to make sure to set those up on your system.

import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

style.use('fivethirtyeight')

fig = plt.figure()

# we can plot multiple "subplots" on the same graph if needed:
ax1 = fig.add_subplot(1,1,1)
#ax2 = fig.add_subplot(1,1,1)
#ax3 = fig.add_subplot(1,1,1)

# change this to wherever your data is stored
readFile = "/home/trevor/Applications/" \
    "blender-2.79-rc2-linux-glibc219-x86_64/data.txt"


def animate(i):
    graph_data = open(readFile,"r").read()
    lines = graph_data.split('\n')
    # Depending on how many lines are to be read from the file,
    # you will want to decalre fewer or more variables here.
    ts = []
    xs = []
    ys = []
    zs = []
    zv = []
    for line in lines:
        if len(line) > 1:
            # again, adjust the following lines for how many variables
            # you need to read in and plot.
            t, x, y, z, vx, vy, vz = line.split('\t')
            ts.append(t)
            xs.append(x)
            ys.append(y)
            zs.append(z)
            zv.append(vz)
    ax1.clear()
    #ax2.clear()
    #ax3.clear()
    ax1.plot(zs, zv)
    #ax2.plot(ts,ys)
    #ax3.plot(ts,zs)

ani = animation.FuncAnimation(fig, animate, interval=10)
plt.show()
