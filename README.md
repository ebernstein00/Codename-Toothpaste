# Definitely Not Kirby
Elias, Jason, and Joseph's final project for MKS65
Period 10

## Project Statement/Proposal
The project is a simple turn-based RPG game, where us It will use two main c files: one that the player will execute, and one that controls the enemies of the game, but many more C files that the user does. In order to interact with the game, SDL2 is used to create a GUI that allows the player to make decisions, and for visual representation of combat.
Keep all of your Kirbys alive, and crush your opponents with style!

## Roles
**Elias** will write the characters, enemies, and random encounter and drop code.
**Jason** will write the code for windowing, animation, and GUIs.
**Joseph** will write the code used for networking and combat flow.

## Design
Multiple data structures will be used.

### Arrays:
* Backpack storage.
* Random item drops.
* Potential Enemies

### Structs:
* A character struct will hold enemies and protagonists.
* An item struct will be used to create items.
* A game struct will hold the game information.

### Methods:
* Hero / Monster attack method.
* Hero /  Monster defend method.
* Hero / Monster using item method.
* Hero / Monster combat method, and so on and so forth
### Files:
* All character and item information will be stored in files
* Uses subdirectories to contain information
* Renders sprites from .png files
### Windowing:
* Uses SDL2 to generate a window to play the game
* Also uses the command prompt for text processing and input
* Separate viewports for GUI and game

### Graphics:
* Uses SDL2 to render sprites against a background
* Animates sprites based on frames that have passed using VSync
* Renders a background using SDL's built in stretching functions

### GUI
* Uses SDL to render buttons that can be clicked
* Reads mouse input to show pressed buttons and to send signals to the gameflow
* Reads keyboard input to pick up or leave items

### Networking:
* Up to two players can play at the same time.
* The GUI and any information given will be mirrored onto all computers.
* All central information will be calculated on one computer and then sent.

## Timeline
**Week 1 Goals** : 2020-01-05 to 2020-01-11
* Bare-bones GUI in working condition
* Hero / Monster / Item structs in working condition
* Basic fighting functionality in working condition
* Random monster generation
* CPU fighting algorithm in place

**Week 2 Goals** : 2020-01-12 to 2020-01-17
* Networking between computers (host and clients)
* Visual representation of combat through images
* Animation of sprites along a background
* Tactile buttons that progress the game state
* Checking for proper allocation and freeing of memory

## How To Use
* Make, and then make run.
* Client stuff goes here
* Make sure you have the graphics window and the command prompt window open side by side.
* For best experience, neither should overlap.
* When the graphics show up, you can click a button to take an action.
* If you select attack, you also have to click an enemy to choose them as your target.
* Attack obviously attacks an enemy, and Guard will increase your defense.
* Damage is calculated by attacker's attack - defender's defense.
* Players also have items in your inventory. Consumables can be used based on the slot they are in with the right button.
* Once a player chooses their action, the client waits for the server to send back a response and then the game continues.
* The server sends an item, and you can choose to pick it up with ENTER or leave it with SPACE.
* If commands aren't going through, then click back onto the graphical window and make sure you keep it in focus.
* The game continues until either one of the players is dead, or both of the opponents are dead.
* You can also exit the game by clicking the red X in the graphical window.
* Have fun in Dreamland!

## Libraries Required
* SDL2
* sudo apt-get install libsdl2-dev
* SDL2 Dev
* sudo apt-get install libsdl2-2.0
* SDL2 Image
* apt-get install libsdl2-image-dev
* You must also have a valid network setup, and a graphics interface (so it won't work with subsystems)

## Changes from Project Proposal
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

# Bugs
* Makefile sometimes compiles to root directory. Has no effect on actual compiling.
*
## Credits
* Nintendo for the character of Kirby and all other Kirby-related characters
* The Spriters' Resource for all of the spritesheets ripped directly from Kirby Superstar Ultra
* Odicia for the grassy game background
* Nintendo LINE for the GUI background
* Spluff5 for the buttons as a base, and then modified with text later on
* LazyFoo's SDL2 Tutorial for a crash course on SDL
* Beej's Guide to Networking for a crash course on networking
