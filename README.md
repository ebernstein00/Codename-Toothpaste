<img src="https://fontmeme.com/permalink/200121/43f14fdf3c348ef341e62bd11e1c7543.png" alt="kirby-super-star-font" border="0"> <br>
<img src="https://raw.githubusercontent.com/ebernstein00/Codename-Toothpaste/master/static/kirby.png" alt="Not Kirby"
	title="Not Kirby" width="40%" height="auto" />

### **Elias, Jason, and Joseph's final project for MKS65, Period 10**
### Team Adrionicle

# Project Statement/Proposal
The project is a simple turn-based RPG game, where us It will use two main c files: one that the player will execute, and one that controls the enemies of the game, but many more C files that the user does. In order to interact with the game, SDL2 is used to create a GUI that allows the player to make decisions, and for visual representation of combat.
Keep all of your Kirbys alive, and crush your opponents with style!

# Roles
**Elias** will write the characters, enemies, and random encounter and drop code.  
**Jason** will write the code for windowing, animation, and GUIs.   
**Joseph** will write the code used for networking and combat flow.

# Design

## Structs:
* **Being**: Holds information about each being in the game, including monsters and players.
    * Health
    * Attack
    * Damage
    * Backpack
    * Type
    * ID
    * Guarding Status
* **Backpack**: A collection of items that are attibuted to a player. Monsters have `NULL` backpacks
* **Item**: An item with an id, type, and modifiers for each being stat. Only players may have items.
* **Game**: A game struct will hold the game information, including multiple instances of the **Being** struct.

## Gameflow:
* **characters.c/h**:
    * Functions to instantiate, print, and free characters
    * Functions to add and remove items from a characters' backpack.
    * Functions to get and set every attribute of the being struct.
* **items.c/h**:
    * Fucntions to instantiate, print, and free items
    * Functions to instantiate, print, and free backpacks
    * Function to randomly generate an item to be dropped to the user in playerturn.
* **gameflow.c/h**:
    * Functions to instantiate, populate, print, and free game structs.
    * Functions to execute a player turn and a monster turn
    * Helper functions to the pleyerturn and monsterturn functions, such as:
        * attack()
        * guard_start()
        * guard_end()
        * use_item()
        * add_item() 

## Windowing:
Uses SDL2 to generate a window to play the game. Also uses the command prompt for text processing and input. Separate viewports for GUI and game
* **window.c**: Generate the SDL window object.
* **background.c/h**: Render background tiles in the GUI

## Graphics:
Uses SDL2 to render sprites against a background. Animates sprites based on frames that have passed using VSync. Renders a background using SDL's built in stretching functions
* **display.c/h**: Renders Character sprites and handles animations
    * Responsive Health bars
    * Idle animations (i.e. blinking, shaking, etc.)
    * Opens and interacts with bitmap and PNG spritesheets to animate sprite movement.

## GUI:
Uses SDL to render buttons that can be clicked. Reads mouse input to show pressed buttons and to send signals to the gameflow. Reads keyboard input to pick up or leave items
* **gui.c/h**: Renders and handles GUI buttons by means of which the user interacts with the game
    * Attack, Guard, Potion 1, Potion 2, Potion 3.
    * Tracks mouse position using SDL Rectangles

# Systems (MKS65) Components:
## Allocating Memory:
* Each item, being, backpack, and game exists within a piece of allocated memory.
* Each type of item, being, and backpack has its own create() function (ex. `create_strengthened_mithril_armor()`)
* Each struct has its own free function.   
* **AS OF 2020-01-20 21:00**: Valgrind --leak-check=full reports no memory leaks.
## Processes:
* `execvp()` is used to use Ubuntu-native *aplay* to play the game soundtrack
* PIDs are used in conjunction with signals to perpetuate soundtrack indefinitely. 
* Soundtrack runs as another process in the background, whose PID is kept track of. 
## Working with Files:
* `bitmap` and `.png` files are used to render and animate spirtes.
* Pixel Mapping is done to generate states for each sprite, and these sprites are then bound to beings by being ID.
* Background and button images are loaded using SDL Textures.
* Soundtrack is loaded using a `.wav` file.
## Signals:
* Signals Handlers are used to propogate the game soundtrack after it has elapsed, as well as killing it off after the game has ended.


# Timeline
**Week 1 Goals** : 2020-01-05 to 2020-01-11
* Bare-bones GUI in working condition :white_check_mark:
* Hero / Monster / Item structs in working condition :white_check_mark:
* Basic fighting functionality in working condition :white_check_mark:
* Random monster generation :white_check_mark:
* CPU fighting algorithm in place :white_check_mark:

**Week 2 Goals** : 2020-01-12 to 2020-01-17
* Visual representation of combat through images :white_check_mark:
* Animation of sprites along a background :white_check_mark:
* Tactile buttons that progress the game state :white_check_mark:
* Checking for proper allocation and freeing of memory :white_check_mark:

**Week 2(1/2) Goals** : 2020-01-18 to 2020-01-21
* Using signals and processes to render game soundtrack, refresh it periodically, and kill it once the game has ended. :white_check_mark:
* Mouse targeting of monsters using the GUI :white_check_mark:
* Finishing Touches (Obliterating Last-minute segfaults, `h4xr-style`) :white_check_mark:



# Launch Instructions
* Make, and then make run.
* Make sure you have the graphics window and the command prompt window open side by side.
* For best experience, neither should overlap.
* When the graphics show up, you can click a button to take an action.
* If you select attack, you also have to click an enemy to choose them as your target.
* Attack obviously attacks an enemy, and Guard will increase your defense.
* Damage is calculated by attacker's attack - defender's defense.
* Players also have items in your inventory. Consumables can be used based on the slot they are in with the right button.
* If commands aren't going through, then click back onto the graphical window and make sure you keep it in focus.
* The game continues until either one of the players is dead, or both of the opponents are dead.
* You can also exit the game by clicking the red X in the graphical window.
* Have fun in Dreamland!

## Libraries Required
* SDL2   
`$ sudo apt-get install libsdl2-dev`
* SDL2 Dev   
`$ sudo apt-get install libsdl2-2.0`
* SDL2 Image   
`$ sudo apt-get install libsdl2-image-dev`
* You must also have a windowing system (such as X11) on your operating system, therefore this project is not compatable with non-gui subsystems such as Ubuntu for Windows (UFW)

# Changes from Project Proposal
* Switched from GTK to SDL2
* Held off on attack animations
* Favored one-off gameplay rather than a linear set of battles
* Removed item shops in favor of procedurally-generated drops

## Future Additions
* More enemies
* More drops
* More classes
* Variety of attacks and items, not just the default ones
* Attack and damage animations (need to draw custom pixel art!)
* More characters in combat at once
* Networking / Multiplayer capabilities

# Bugs
* Makefile sometimes compiles to root directory. Has no effect on actual compiling.
* Signal Handler can be strange with process ID, leading to the soundtrack sometimes playing after the game has elapsed.
* Button presses don't always register on the first time, meaning the user must occasionally press a button a second time to get their desired action.
* Compiling errors occur on macOS Catalina, but do not occur on Ubuntu 18.04.


# Credits
* Nintendo for Kirby, Kirby's likeness, and all other Kirby-related characters
* Nintendo for Kirby soundtrack "Green Greens"
* The Spriters' Resource for all of the spritesheets ripped directly from Kirby Superstar Ultra
* Odicia for the grassy game background
* Nintendo LINE for the GUI background
* Spluff5 for the buttons as a base, and then modified with text later on
* LazyFoo's SDL2 Tutorial for a crash course on SDL    

<br>
<br>
Copyright &copy; 2020 Team Adrionicle. All Rights Reserved

