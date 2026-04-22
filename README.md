# Pi from Collisions (Raylib Simulation)

This project simulates elastic collisions between two blocks and a wall.

Surprisingly, the total number of collisions corresponds to digits of π
when the mass ratio is chosen as 100^n.

Inspired by 3Blue1Brown.

[GIF]()

## How it works

- Two blocks collide elastically in 1D
- One block also collides with a wall
- The number of collisions is counted

For mass ratio:

    m2 = 100^n

The number of collisions ≈ first n digits of π

## Notes

- Uses substepping for collision accuracy
- Large masses require higher precision

## Build & Run

Requires gcc (MinGW) and Raylib.

Build and run:
```
mingw32-make run
```
> Note: `raylib.dll` must be inside the `build/` folder