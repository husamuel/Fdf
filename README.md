# FdF
<img width="2472" height="1200" alt="image" src="https://github.com/user-attachments/assets/58cb2238-728d-4cf8-a07e-2f3d31e6336f" />

### Description

FdF (Fil de Fer) is a 42 project that involves creating a 3D wireframe representation of a map defined by a file containing altitude values. The program renders a 3D model using isometric projection (or similar) and displays it graphically using the MiniLibX library.

#### Allowed Functions
`open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`, MiniLibX functions, and math functions (`math.h`)


### Features

- Reads a map file containing integers representing heights (e.g., `42.fdf`).
- Renders a 3D wireframe model using isometric projection.
- Supports basic user interactions (e.g., zoom, rotation, translation) via keyboard/mouse.
- Draws lines between points using a line-drawing algorithm (e.g., Bresenham's).

### Usage

#### Requirements
- **gcc compiler**
- Standard C libraries
- MiniLibX library (provided by 42)
- X11 or equivalent for graphical display (depending on the OS)

#### Compilation
Compile the `fdf` program:
```shell
cd path/to/fdf && make
```

This generates the `fdf` executable. You may need to link MiniLibX and required frameworks:
```shell
cc -Wall -Wextra -Werror *.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o fdf
```

#### Running
Run `fdf` with a map file:
```shell
./fdf maps/42.fdf
```

Example map files are typically provided in a `maps/` directory, with each line containing space-separated integers representing heights.

#### Makefile Commands
- `make` or `make all`: Builds the `fdf` executable.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Recompiles the project.

### Implementation Notes

- Parses the input file to create a 2D array of points with x, y, z coordinates.
- Uses isometric projection to convert 3D coordinates to 2D for rendering.
- Implements a line-drawing algorithm (e.g., Bresenham's) to connect points.
- Handles user inputs for transformations (e.g., zoom, rotation) using MiniLibX event handlers.
- Compliant with 42's Norm:
  - Functions limited to 25 lines.
  - Variables declared at the top.
  - Only allowed functions used.

### Example
An example map file (`42.fdf`):
```
0  0  0  0  0
0 10 10 10  0
0 10 20 10  0
0 10 10 10  0
0  0  0  0  0
```

Running `./fdf maps/42.fdf` will display a wireframe model of this map.

### Disclaimer

This project adheres to 42's Norm, which may result in unconventional code structure to meet requirements such as function length limits and restricted function usage.

