# Dynamic Virtual Environment: OpenGL-Based 3D Simulation

This project, **Dynamic Virtual Environment**, is a C++ application that utilizes OpenGL and GLUT to create a 3D environment. The simulation features a dynamic path surrounded by fog, walls, and a skybox, offering a virtual exploration experience with real-time interactions and camera controls.

## Features

- **3D Environment**: The application renders a 3D path with fog, walls, a skybox, and a roof.
- **Dynamic Camera Movement**: Supports forward/backward movement, strafing, and adjustable camera angles using keyboard and mouse inputs.
- **Interactive Walls and Path**: Adjust the height of the walls and the width of the path dynamically.
- **Fog Effects**: Adds fog for enhanced depth perception and visual effects.

## Requirements

- **Operating System**: Windows, Linux, or macOS
- **Dependencies**:
  - OpenGL
  - GLUT (e.g., FreeGLUT or similar library)

## Setup

1. **Install Dependencies**:
   - Ensure that OpenGL and GLUT are installed on your system.
   - On Linux, you can install them with:
     ```bash
     sudo apt-get install freeglut3-dev
     ```
   - On Windows, add the appropriate GLUT and OpenGL libraries to your project.

2. **Compile and Build**:
   - Use a C++ compiler (e.g., g++, MSVC) to compile the source files.
   - Example build command with g++:
     ```bash
     g++ main.cpp Dynamo.cpp -o dynamic_env -lGL -lGLU -lglut
     ```

3. **Run the Program**:
   - Run the executable file:
     ```bash
     ./dynamic_env
     ```

## Controls

- **Camera Movement**:
  - **Arrow Keys**:
    - Up: Move forward
    - Down: Move backward
    - Left: Strafe left
    - Right: Strafe right
- **Wall and Path Adjustment**:
  - `A/a`: Lift the right wall
  - `S/s`: Lift the left wall
  - `Z/z`: Lower the right wall
  - `X/x`: Lower the left wall
  - `D/d`: Widen the path
  - `C/c`: Narrow the path
- **Mouse**: Passive mouse movement is used for camera adjustments.

## Example Gameplay

1. **Start the Simulation**:
   - Upon launching, the program creates a window titled "A Path Among the Clouds."
   - The camera is positioned at the start of a dynamic path surrounded by fog and walls.
  
2. **Navigate Through the Environment**:
   - Use the keyboard to move along the path, adjust the walls, and explore the 3D space.
   - The camera responds in real-time to changes in position and direction.

## Code Structure

- **`main.cpp`**:
  - Contains the main entry point and GLUT callback functions for rendering, resizing, keyboard, and mouse events.
  - Responsible for creating the OpenGL window and managing the rendering loop.

- **`Dynamo.cpp`**:
  - Implements the **Dynamo** class, which handles rendering elements like fog, walls, path, roof, and skybox.
  - Manages camera controls, directional inputs, and texture loading.

- **`Dynamo.h`**:
  - Header file for the **Dynamo** class, declaring the methods and variables used for rendering and interaction.

## Notes

- **Texture Files**: The application loads texture files (`rock.tga`, `sky.tga`, `roof.tga`). Ensure that these files are available in the same directory as the executable.
- **Performance**: The application may experience lag when multiple textures are loaded due to OpenGL's processing requirements.

## Limitations

- The simulation currently only supports basic 3D navigation and environment interactions.
- Only TGA textures are supported for the loaded elements.
- It lacks collision detection, so the camera can pass through walls.
