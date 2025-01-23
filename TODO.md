# TODO

## Stockage externe

### sprites
  - ./assets/textures

### levels
  - ./levels

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

## Redondancy for optimisation
Step and Wall redondancy is used as optimisation.
A wall is used when nothing can go through / on top of the wall
A step is used to make a step, a window, or a walkable plateform. Therefore, checks are needed to see if the player can step on it, shoot over or under it, ...
Vz for wall is only used when displaying 3D walls if the player is in an outside zone

A pillar is a round wall

## Variation
A Wall can be a rectangular cuboid or a cylinder
Ennemy = Shooter, fire balls, vers de terre
Item = heath boost, shield boost, munitions, 
 fullx(heath boost, shield boost, munitions),
 gum (on floor) -> pistol, pompe, mitraillette, boule
A step can make (or not) damages if walken on it

### Later :
- (score)

## Structure

- main
- physic / collisions
  - line
  - circle
  - . - . - . - .
  - line-line
  - circle-line
  - line-plan (line1 x11,y11, x12,y12 + plan=(line2 x21,y21, x22,y22, line3 x31,y31, x32,y32) )
  - circle-circle (x1,y1,R1, x2,y2,R2) => sqrt((x1-x2)^2 + (y1-y2)^2) < R1+R2
  - ...
- board (map of walls, and objects)
  - import level
- graphics 2d
- graphics 3d
- menus
- status bar
- wall
  - 4 lines
- player
  - circle
- ennemy
  - circle
- projectiles (x, y, z, dx, dy, dz, size, speed) -> Z ?? 
- elevators / doors
- items (heals, shield, munitions, dead body)
- barels
- guns
- activator
- ceiling

### SOUND

Add sound :
- Ambiants sounds
- action sounds

## TODO

MAKE TESTS

- 2D game (2.5, floors)
  - [ ] player
  - [ ] walls
  - [ ] collisions
  - [ ] ennemies (circle)
  - [ ] shooting
  - [ ] doors
  - [ ] elevators
  - [ ] stairs

store elements :
- 2d + floor information

-> A level is design with no possibilities to be on the same x, y and differents floors

-> when displaying the 2d map. Only display seen objects, walls, ... So each object shold have a state value (not seen, seen, consumed / destroyed)

### Bugs to fix

