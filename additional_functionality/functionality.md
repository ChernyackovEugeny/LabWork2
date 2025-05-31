This game implements several advanced features that enhance the gameplay experience and increase its realism:

Dual Feedback Mode (ASCII/Plain Text):
The game supports two types of player feedback: visual ASCII art and plain text. Depending on the selected mode (show_pict_ flag), all game events—such as animatronic appearances, door/light status, and jumpscares—are rendered either as detailed ASCII images or described with concise text. This allows the game to run in both graphical terminal environments and purely textual ones.

Multithreaded Architecture:
The game's logic is split into two separate threads:

One thread (updateGame) continuously updates the internal state of the game in real time, including animatronic movement, energy depletion, time tracking, and win/loss conditions.

The main thread handles player input and interaction (e.g., toggling lights, viewing cameras, managing doors).
This separation ensures responsive gameplay and concurrent state updates.

Real-Time Progression:
The game uses the system's real time (std::chrono::steady_clock) to simulate the passage of time in-game. One minute of gameplay corresponds to one minute of real time, with game events (e.g., night progression, animatronic behavior) tied directly to elapsed time.

Randomized Animatronic Behavior:
Animatronic movement is not scripted but instead relies on pseudorandom number generation (gen_rand_), making each playthrough unique. Randomness affects timing, aggression, and jump scare conditions, increasing replay value and unpredictability.

Difficulty Levels (Five Nights):
The game supports five difficulty levels (nights 1 through 5). The selected level (num_night_) affects the frequency and aggressiveness of animatronic activity. Higher levels increase challenge by making the animatronics more active and unpredictable.
