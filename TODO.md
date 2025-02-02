# TODO

## Stockage externe

### sprites
  - ./assets/textures

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
- step
- pillar
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

-> add fog on 3d view for better ambiance

## Upgrade

Differentiate line 2D and 3D

*May be a complex idea to implement* :
***Gilbert Johnson Keerthi (GJK) algorithm***

[yt link](https://www.youtube.com/watch?v=ajv46BSqcK4)

[wiki link](https://www.youtube.com/watch?v=ajv46BSqcK4)

Be aware that Domm use BSP Trees for colisions (not sure about that)

### Bugs to fix

