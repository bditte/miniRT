# miniRT
This project is an introduction of the beautiful world of **raytracing**.

The goal is to build a humble and functional raytracer that handles simple objects such as ***planes, triangles, spheres, squares and cylinders***.
It's part of 42 cursus.
# Libraries
miniRT works with **minilibx**, school 42's graphic library. This repository contains the linux version of mlx library.

It also needs some [libft](github.com/bditte/libft) functions. This library is also a school 42 project .
# Usage
### Running miniRT
In order to setup every libraries, you first need to run the **mlx_setup.sh** script by typing `sh mlx_setup.sh` .

You can then compile by running `make` command and then executes with `./miniRT scenes/scene.rt` . 

You can switch with scenes inside the **scenes** folder or creating a new one. Note that the scene file needs to be a **.rt** file.

### Scene format
Every scene file requires a single **resolution** and a single **ambient light**. If the scene does not contains **one and only one** of each of these, an error will be returned.

![Example of scene](https://imgur.com/IVPaq3i.png)

##### Resolution
`R 1920 1080`

`R` : resolution argument. `1920 1080` two integers : width and height of the image.

##### Ambient light
`A  0.5 255,255,255`

`A` : ambient light argument `0.5`  one float **[0;1]** : light intensity  `255,255,255` three floats : light color (RGB).

##### Camera
`c 0,0,0  0,0,1 80`

`*c` : camera argument  `0,0,0`* three floats : camera position  `0,0,1` three floats : camera orientation vector  `80` one integer **[0;180]** : camera FOV (in degrees)

##### Light spot
`l 0.5,1,0  1 255,255,255`

`l` : light spot argument `0.5,1,0` three floats : light position `1` one float **[0;1]** : light intensity `255,255,255` three floats : light color (RGB).

##### Sphere
`sp 1,0,2 0.5 255,0,0`

`sp` : sphere argument `1,0,2` three floats : sphere center postion `0.5` one float : sphere diameter `255,0,0` three floats : sphere color (RGB).

##### Cylinder
`cy 0,02  0,1,0 0.5 0.5 0,255,0`

`cy` : cylinder argument `0,0,2` three floats : cylinder center position `0,1,0` three floats : cylinder orientation vector `0.5` one float : cylinder diameter `0.5` one float : cylinder height `0,255,0` three floats : cylinder color (RGB).

##### Triangle
`tr -0.5,-0.5,2 -1,-0.5,2 -0.75,0.4,2 0,0,255`

`tr` : triangle argument `-0.5,-0.5,2` three floats : first vertex `-1,-0.5,2` three floats : second vertex `-0.75,0.4,2` three floats : third vertex `0,0,255` three floats : triangle color (RGB).


##### Square
`sq 0,0,4 0,0,-1  4 255,255,0`

`sq` : square argument `0,0,4` three floats : square center `0,0,-1` three floats : square normal vector `4` one float : square height `255,255,0` three floats : square color (RGB).

##### Plane
`pl 0,-3,0  0,1,0 255,255,255`

`pl` : plane argument `0,-3,0` three floats : a point of the plane `0,1,0` three floats : plane normal vector `255,255,255` three floats : plane color (RGB).

## Saving into .bmp file

You can save the rendered image in a **.bmp** file which will be stored in the miniRT folder.

This can be done by adding **-save** when executing the program : 

`./miniRT scenes/scene.rt - save`

## Switch cameras
If more than one cameras are declared in the scene, you can switch using `←` and `→` .

# Examples

![scene.rt](https://i.imgur.com/xVZ53Wb.png)

![columns](https://i.imgur.com/YeExZBU.png)

![pyramid](https://i.imgur.com/9rZqcPF.png)

![disks](https://imgur.com/undefined)
