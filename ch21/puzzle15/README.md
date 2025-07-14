# 15 Puzzle Game

C++ implementation of the classic 15 Puzzle tile game.

## Requirements

### Board

- display the board game
- display an individual tile
- randomize starting state
- slide tiles
- determine if win condition is met

### User

- get commands from user
- handle invalid input
- allow user to quit before winning

## Primary Classes / Namespaces

- function main
    - main game logic loop
- class Board
    - display game board
    - display game tiles
    - generate random starting boards
    - slide tiles
    - determine if win condition is met
    - 2d array of tiles
- namespace UserInput
    - handle user input
    - handile input validation
- class Tile
    - display individual tile
- class Point
    - indexing game board tiles
- class Direction
    - enum for working with directions
