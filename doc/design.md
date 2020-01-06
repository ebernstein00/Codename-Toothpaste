# Thumb War 
Elias, Jason, and Joseph's final project for MKS65
Period 10

## Project Statement
The project is a simple turn-based RPG game. It follows a linear story. It will use two main c files: one that the player will execute, and one that controls the enemies of the game, but many more C files that the user does. In order to interact with the game, GTK is used to create a gui that allows the player to make decisions, and for visual representation of combat. 

## Roles
**Elias** will write the characters, enemies, and random encounter and drop code.
**Jason** will write the code for battling, along with windowing and GUIs.
**Joseph** will write the code used for networking and out of combat game flow.
The CPU algorithm code will be a combined effort of all members of the team.
If time allows, we can use SDL to implement a basic 

## Design
Multiple data structures will be used.
### Arrays: 
* Backpack storage. 
* Random item drops.
* Potential Enemies
* Items to be bought in Shops distributed across the map.
### Structs: 
* An enemy struct will be used to create enemies. 
* An item struct will be used to create items.
* A Hero struct will be made to create protagonist classes.
### Methods:
* Hero / Monster attack method.
* Hero /  Monster defend method.
* Hero / Monster heal method.
* Hero purchase method.
### Files:
* All character and item information will be stored in files
* Uses save files in order to save data
### Windowing:
* Uses GTK to create a window with buttons to make decisions during combat
* Visual representations of combat within the window (HP bars, static sprites)
### Networking:
* Up to three players can play at the same time.
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
* User creation and save slots using files.
* Progression and difficulty implementation
* Checking for proper allocation and freeing of memory
