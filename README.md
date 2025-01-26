# Project : Pacman-like

Project for school - IMT Nord Europe

## Object

Make a Doom-like in C - Name : Tiim

## How to play ?

### On Windows or Mac

I don't have any idea :(

### On Linux

- Open terminal and go to *./tiim*
- Write the command : ```$make all```
- Enjoy :)

## Add/Change maps

### How they are stored

One CSV file for a level :
Each line as one object stored with parameters.

- **Variation** determine for exemple for an item if it is an item of munition, health boost, ...
- **Style** determine the texture to apply to the object
- **Trigger** link objects triggered by the corresponding Activator
- **x**, **y**, **z** are the coordonates of the object
- **R** is the radius of the object
- **dz** is the hight of the 3D object
- **dx1**,**dy1** are, for 3D objects, the coordonates of the second point
- **dx2**,**dy2** are, for 3D objects, the coordonates of the third point (forth being (dx1, dy2))
- **Vx**,**Vy**, **Vz** is, for moving object, the translation vector


|Type|Variation|Style|Trigger|x|y|z|R|dz|dx1|dy1|dx2|dy2|Vx|Vy|Vz|
|---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|W=wall         |❌|✅|❌|✅|✅|✅|❌|✅|✅|✅|✅|✅|❌|❌|❌|
|S=Step         |✅|✅|❌|✅|✅|✅|❌|✅|✅|✅|✅|✅|❌|❌|❌|
|R=pillar       |❌|✅|❌|✅|✅|✅|❌|✅|✅|✅|✅|✅|❌|❌|❌|
|C=Ceiling      |❌|✅|❌|✅|✅|✅|❌|❌|✅|✅|✅|✅|❌|❌|❌|
|P=Player       |❌|❌|❌|✅|✅|✅|❌|✅|❌|❌|❌|❌|❌|❌|❌|
|E=Ennemy       |✅|✅|✅|✅|✅|✅|❌|✅|❌|❌|❌|❌|❌|❌|❌|
|I=Item         |✅|✅|✅|✅|✅|✅|✅|❌|❌|❌|❌|❌|❌|❌|❌|
|L=elevator=Door|✅|✅|✅|✅|✅|✅|✅|✅|✅|✅|✅|✅|✅|✅|✅
|A=activator    |❌|✅|✅|✅|✅|✅|❌|✅|✅|✅|❌|❌|❌|❌|❌|
|B=Barrel       |❌|✅|✅|✅|✅|✅|✅|✅|❌|❌|❌|❌|❌|❌|❌|

// for Later
- Add trees

#### Redondancy for optimisation
Step and Wall redondancy is used as optimisation.
A wall is used when nothing can go through / on top of the wall
A step is used to make a step, a window, or a walkable plateform. Therefore, checks are needed to see if the player can step on it, shoot over or under it, ...
Vz for wall is only used when displaying 3D walls if the player is in an outside zone

A pillar is a round wall

#### Variation
A Wall can be a rectangular cuboid or a cylinder
Ennemy = Shooter, fire balls, vers de terre
Item = heath boost, shield boost, munitions, 
 fullx(heath boost, shield boost, munitions),
 gum (on floor) -> pistol, pompe, mitraillette, boule
A step can make (or not) damages if walken on it


