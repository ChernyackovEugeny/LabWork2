1. Game (Main Game Logic)
Role: This is the central class that manages the entire game process: initialization, updates, and termination.
Responsibilities:
It creates and coordinates instances of other classes such as Player, Door, Cam, Energy, Phone, Picture, Random, and the animatronic classes (Animatronic, Fox, Fredd).
It continuously updates each component within the game loop.
Interactions:
It communicates with almost all other classes to process game events.

2. Menu
Role: Provides the user interface for starting the game.
Responsibilities:
It sends commands to the Game class.
Interactions:
Directly connected to Game, as it triggers state changes.

3. Player
Role: Represents the user playing the game.
Responsibilities:
Stores player-specific information.
Interactions:
Does not interact directly with Door; door control is managed by Game based on the player's input.

4. Door
Role: Represents a door within the game that can be opened or closed.
Responsibilities:
Maintains its state (open/closed).
When closed, it triggers energy consumption.
Interactions:
Methods in Door are called by the Game class rather than directly by Player.

5. Cam
Role: Allows the player to switch between different rooms to monitor the game.
Responsibilities:
Handles the switching of views between different game areas.
Utilizes Picture for rendering the ASCII visuals.
Interactions:
Managed by Game.

6. Energy
Role: Manages the limited energy resource in the game.
Responsibilities:
Energy is consumed when doors are closed or when cameras are in use.
Keeps track of the remaining energy.
Interactions:
Works primarily with Game and Player to regulate energy consumption.

7. Phone
Role: Displays tips to the player.
Responsibilities:
Provides guidance and important information at specific game moments.
Interactions:
Invoked by Game at the start of the night.

8. Picture
Role: Responsible for rendering ASCII-based images.
Responsibilities:
Contains methods to show static images.
Interactions:
Mainly used by Game to display images.

9. Random
Role: Handles random number generation and event randomness.
Responsibilities:
Provides randomness for animatronic's movement.
Interactions:
Utilized by Animatronic, Fox, Fredd, and even Game when a random event is needed.

10. Animatronic
Role: Represents one type of animatronic entity in the game.
Responsibilities:
Manages movement and positional checks relative to the player.
Uses Random to generate delays and movement routes.
Interactions:
Communicates with Game to signal critical situations (e.g., when reaching a door).

11. Fox and Fredd
Role: Separate classes for animatronics that operate independently.
Responsibilities:
They implement their own movement and behavior logic using randomness.
May feature unique behaviors.
Interactions:
Both are directly connected to Game to report their status and trigger game events.
Note: They do not inherit from Animatronic but share similar logic.

Menu → Game:
The Menu sends commands to start the game, which Game processes to change the current state.

Game ↔ Player:
The Player performs actions, and Game responds by updating the game state accordingly.

Game ↔ Door:
When a door needs to be operated, Game calls the appropriate methods in Door, and energy consumption is managed through Energy.

Game ↔ Cam ↔ Picture:
When the camera is switched, Game updates the Cam, which then uses Picture to render the ASCII graphics.

Game ↔ Energy:
Game continuously monitors the energy levels, especially during door operations or camera use.

Game ↔ Phone:
At critical moments, such as the beginning of a game night, Game invokes Phone to display messages to the player.

Game ↔ Animatronic, Fox, Fredd:
In the game loop, Game updates each animatronic’s status using randomness from Random. If an animatronic (whether an instance of Animatronic, Fox, or Fredd) reaches a critical point, it notifies Game which then determines the outcome.

Random:
Serves as a utility class providing randomness across several classes, ensuring unpredictable behavior.
