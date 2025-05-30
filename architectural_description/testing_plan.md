This test plan aims to verify the core functionality of a simplified RPG game system consisting of three main components: MiniAbility, MiniPlayer, and MiniEffect. The testing focuses on ensuring that constructors and getter methods return the expected values, and that interactions between objects behave correctly in both normal and edge-case scenarios.

The MiniAbility class is tested for correct initialization and retrieval of its attributes, including name, damage, and mana cost. Test cases include abilities with typical values, zero values, empty strings, and even negative numbers, ensuring that the class handles a wide range of input without malfunction.

The MiniPlayer class is tested more extensively. The tests cover player initialization, the ability to add abilities to a player, and the logic of using those abilities. Specific attention is given to verifying mana reduction after using abilities, handling of insufficient mana, and boundary conditions like invalid ability indexes. Damage mechanics are tested by applying various amounts of damage to a player, checking that HP decreases correctly and does not go below zero. There is also a test case that confirms the system correctly handles abilities that restore health through negative damage.

The MiniEffect class is tested for correct storage of name and duration values. Effects with short and long durations are included to check the robustness of the class under varying input sizes.

Overall, the test suite is designed to validate the basic behaviors and state transitions of the game's core objects, ensuring stability, consistency, and correctness. It provides confidence that the system can handle both standard gameplay scenarios and unexpected or invalid input gracefully.
