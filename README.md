## So_long

### Description
"so_long" is a 2D game developed using the MiniLibX (mlx) library, where players navigate a character through a map, collecting items and reaching the exit.

### Code Overview
- **Structures**:
  - **t_player**: Stores the coordinates (`x`, `y`) of the player.
  - **t_exit**: Stores the coordinates (`x`, `y`) of the exit.
  - **t_data**: Encapsulates the game state including the map, player and exit positions, remaining coins, and moves.
  - **t_img**: Manages graphics with MiniLibX pointers, window dimensions, and textures.

- **Core Functions**:
  - **check_all**: Validates the map's integrity.
  - **store_map** and **mesure**: Read and initialize the game map.
  - **count_elem**, **check_rec**, **check_walls**, **check_components**: Ensure map integrity and component presence.
  - **dup_map** and **flood_fill**: Validate map connectivity.
  - **init_so_long**: Initializes the game.
  - **moves_drawing**, **handle_key**, **draw_my_images**: Manage gameplay and rendering.
  - **print_error**, **free2d**, **starting_map**: Handle errors, memory, and setup.
