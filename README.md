##So_long
#Description
"so_long" is a simple 2D game where the player navigates a character through a map, collecting items and reaching the exit. The game is developed using the MiniLibX (mlx) library for graphics and input handling.

##Code Overview
The game is built around several key structures and functions. t_player and t_exit store the x and y coordinates of the player and exit respectively, while t_data encapsulates the entire game state, including the map, player and exit positions, 
remaining coins, and moves. t_img manages image rendering, holding pointers for the mlx instance, window, and textures for various game elements. Core functions include check_all, which validates the game map, store_map and mesure, which read and 
initialize the map, and count_elem, check_rec, check_walls, and check_components, which ensure the map's integrity and component presence. Additional functions like dup_map and flood_fill validate map connectivity, while init_so_long initializes the game, 
and moves_drawing, handle_key, and draw_my_images manage gameplay and rendering. Utility functions such as print_error, free2d, and starting_map handle error messaging, memory management, and initial setup.

#Installation
Clone the repository:
  git clone https://github.com/yourusername/so_long.git
  
Navigate to the project directory:
  cd so_long
  
Compile the project:
  make
  
Run the game:
./so_long maps/...

Use the arrow keys to move the character, collect all items, and reach the exit.

#Requirements :
  MiniLibX library
  Make
  gcc
