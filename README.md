# 🕹️ so_long

![42 Project](https://img.shields.io/badge/42%20Network-so__long-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge)
![Graphics](https://img.shields.io/badge/Graphics-minilibx-yellowgreen?style=for-the-badge)

## 📚 Project Summary

**so_long** is a 2D graphical game project in the 42 curriculum. The goal is to create a small tile-based game using the MiniLibX graphics library. The player must navigate a map, collect all the items (collectibles), and reach the exit — all while avoiding enemies (in the bonus version). The map is read from a `.ber` file, and gameplay is rendered in a window using basic image rendering functions.

This project introduces event-driven programming, keyboard input handling, 2D graphics, map validation, and state management — while strengthening skills in modular design, memory safety, and graphics logic in C.

---

## 🧠 What I Learned in so_long

This project helped solidify multiple essential programming skills:

### 🔹 2D Game Logic
- Implementing player movement (up/down/left/right)
- Handling interactions with walls, collectibles, and the exit
- Creating game win/loss conditions

### 🔹 Map Parsing & Validation
- Reading `.ber` map files with proper formatting
- Checking map rectangularity and wall enclosure
- Ensuring valid element counts (`P`, `E`, `C`, etc.)
- Using flood fill algorithm to validate accessibility

### 🔹 Graphics with MiniLibX (MLX)
- Initializing a window and loading images (tilesets)
- Rendering a 2D grid based on map data
- Handling keyboard inputs and redrawing frames
- Managing image resources and memory cleanup

### 🔹 Event-Driven Programming
- Setting up event hooks for keypresses and window close
- Managing state transitions based on user input

### 🔹 Clean Code & Modular Design
- Separating map logic, rendering, input, and utilities
- Using structs to represent game state and entities
- Norminette-compliant code structure

### 🔹 Bonus Features (Optional)
- Implementing enemies with basic AI movement
- Animating sprites (player or collectibles)
- Displaying move counter on screen
- Using other input types or visual enhancements

---

## 📁 Project Structure

```bash
so_long/
├── src/
│   ├── main.c
│   ├── map.c
│   ├── player.c
│   ├── render.c
│   ├── input.c
│   ├── utils.c
├── includes/
│   └── so_long.h
├── maps/
│   └── example.ber
├── images/
│   ├── player.xpm
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── coin.xpm
│   └── exit.xpm
├── Makefile
└── README.md
