# 22.02

* parsing header

```
x = position_x + (cos(rotAngle) * ud_direction * playerSpeed);
y = position_y + (sin(rotAngle) * ud_direction * playerSpeed);

rotAngle += turn_Direction * rot_Speed;

x += cos(rotAngle + pi / 2) * lr_direction * playerSpeed;
y += sin(rotAngle + pi / 2) * lr_direction * playerSpeed;

```
lr_direction: -1 0 1 (gauche , aucun , droite)
ud_direction: -1 0 1 (bas , aucun , haut)
turn_direction: -1 0 1 (gauche , aucun, droite)

* make DIR  & anchor dir to player
* rotate DIR if changing
*
* apply N S E W orientation
* implement first ray


* error message to clean with intro "Error\n"
