Component Structure Description

The system consists of the following main components:
Game: The core of the system, managing all interactions between components.
Player: Represents the user.
Animatronic: AI-controlled entities that move towards the player based on predefined rules.
Cam (Camera System): Allows the player to monitor different rooms in the game.
Door: Can be opened or closed by the player to prevent animatronics from entering.
Energy: A limited resource that depletes when using cameras and doors.
Menu: Handles game start.
Phone: Provides in-game instructions and guidance.
Picture: Used for rendering ASCII-based visuals in the game.
Random: Manages random events, including animatronic movement timings.

Component Interactions
The Game component coordinates all others, ensuring smooth operation.
Animatronic moves periodically, utilizing the Random component for unpredictable behavior.
Menu communicates with Game to handle state transitions.
