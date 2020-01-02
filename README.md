# Thumb War 
Elias, Jason, and Joseph's final project for MKS65
Period 10

## Project Statement
The project is a simple turn-based RPG game. It follows a linear story. It will use two main c files: one that the player will execute, and one that controls the enemies of the game, but many more C files that the user does . The game will also integrate simple graphics, via sprites and **SDL**.

## Roles
**Elias**  will write the story for the game as well as the code for random item drops after defeating an enemy.
**Jason** will create the simple graphics.
**Joseph** will write the code used by the player.
The CPU algorithm code will be a combined effort of all members of the team.

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

## Timeline
**Week 1 Goals** : 2019-01-05 to 2019-01-11
* Bare-bones GUI in working condition
* Hero / Monster / Item structs in working condition
* User creation and save slots using JSON files.
* Basic fighting functionality in working condition
* Random monster generation
* CPU fighting algorithm in place

**Week 2 Goals** : 2019-01-12 to 2019-01-17
* Level-up system
* Navigation with mouse and keyboard (click on a region to travel to it)
* Item shop before every battle
* Class system where user can select a class with each new character
