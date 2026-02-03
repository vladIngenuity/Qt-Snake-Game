Snake Game (Qt/C++)
A classic Snake game implementation built with C++ and the Qt framework. This project focuses on clean object-oriented logic, smooth rendering, and robust input handling.

 Technical Features
Graphics: Rendered using QPainter. The game field is managed as a coordinate grid where each snake segment and food item is mapped to specific cells.

Game Loop: Managed via QTimer, ensuring consistent frame rates and responsive gameplay.

Smart Input Handling: Features an input buffering system. The game captures the latest key press and validates it against the current direction to prevent illegal 180-degree "self-turn" collisions.

User Interface: Includes dynamic score tracking in the window title and a customized QMessageBox on game over, allowing for an instant restart without reloading the app.

 Controls
W / A / S / D — Move Up, Left, Down, and Right.

The game ends if the snake hits the wall or its own tail.

 How to Run
Install Qt Creator and a C++ compiler (e.g., MinGW or MSVC).

Open the .pro project file.

Build and run the project.
