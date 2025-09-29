# Maze Generator 

##  Project Description
This project is a **console-based 2D maze generator**.  
The maze is represented as a **2D matrix**, where each cell can be one of the following types:
- **Entrance (E)** → only one, must be on the border of the maze.
- **Exit (X)** → only one, must be on the border of the maze.
- **Road (.)** → a cell that the player can walk through.
- **Wall (#)** → a cell that blocks the way.
- **Trap (T)** (optional) → walkable cell, but if the player passes through 3 of them, they die. There are 0–5 traps on a level.
- **Treasure ($)** (optional) → cell with a treasure. At most 1 treasure per level.

###  Rules
- There must be **at least one valid path** from entrance to exit.  
- The path must be **safe** (not forcing the player to pass through 3 traps).  
- If the treasure exists, it must be **reachable**.  

##  How It Works
1. The program takes **maze size** as input (```rows```, ```cols```).  
2. Generates a maze using randomized algorithms (DFS backtracking / randomized Prim’s algorithm).  
3. Ensures that all conditions are met:
   - Entrance and exit are placed at the outer boundary.
   - At least one solvable path exists.
   - Treasure (if present) is reachable.
   - Traps(if present) are placed but don’t block solvability.  
4. Prints the maze in the console with different **symbols**.
   
---

## Instructions
1. Installation:
   to install clone this repository
```
git clone https://github.com/t1plarnd/dl-test-task.git
```
3. Run this program:
   In case you have Visual Studio 2020, double click on `mazetask.sln`.
   To run from terminal, compile with
   ```
   g++ task/main.cpp -o main
   ```
   and then run the compiled program
   ```
   ./main
   ```

5. Provide input according to instructions in terminal
### Input Format
The program expects input in the following order:
- ```R``` - Rows
- ```C``` - Columns
  
### Output
The program prints maze where 

- ```[]```  - its wall
- ```  ```  - its way


### Example
- ```5``` - Rows
- ```10``` - Columns
  
Resoult:

```text
[][][][][][][][][][]
    []            []
[]  []  [][][][]  []
[]      []        []
[][]  [][][][][][][]
```
