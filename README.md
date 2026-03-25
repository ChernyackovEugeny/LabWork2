# Five Nights at Freddy's (C++ Terminal Implementation)

## Author
Черняков Евгений Олегович, группа 24.Б82-ММ

## Contacts
st128891@student.spbu.ru

---

## Description

A terminal-based C++ implementation of the classic survival horror game **Five Nights at Freddy's**. You play as a security guard working the night shift at Freddy Fazbear's Pizza, tasked with surviving until 6 AM while four animatronic characters roam the building.

The game is rendered entirely in ASCII art and runs in the terminal. It faithfully recreates the core mechanics of the original: energy management, camera surveillance, door control, and animatronic AI.

---

## Gameplay

### Objective
Survive **6 in-game minutes** (one full night) without running out of power or being caught by an animatronic.

### Controls

| Command | Shortcut | Action |
|---|---|---|
| `cams on` / `cams off` | `con` / `cof` | Toggle camera view |
| `light left door` | `lld` | Toggle left door light |
| `light right door` | `lrd` | Toggle right door light |
| `close left door` | `cld` | Close/open left door |
| `close right door` | `crd` | Close/open right door |
| `fan on` / `fan off` | — | Toggle the office fan |

### Energy System
- You start each night with **100 units** of power.
- Power drains continuously at a base rate of **0.08 units/second**.
- Every active system (cameras, door lights, closed doors) multiplies the drain rate:

| Active Systems | Multiplier |
|---|---|
| Nothing (idle) | ×1 |
| Cameras | ×2 |
| One closed door | ×3 |
| Both doors closed + cameras | ×6 |

- If power reaches **0**, all systems shut down — doors open, lights go out, and Freddy attacks.

### Camera System
There are **11 cameras** spread across the building:

| Camera | Location |
|---|---|
| CAM 1A | Show Stage |
| CAM 1B | Dining Area |
| CAM 1C | Pirate Cove |
| CAM 2A | West Hall |
| CAM 2B | West Hall Corner |
| CAM 3 | Supply Closet |
| CAM 4A | East Hall |
| CAM 4B | East Hall Corner |
| CAM 5 | Backstage |
| CAM 6 | Kitchen |
| CAM 7 | Restrooms |

Use cameras to track animatronic positions and decide when to close doors.

---

## Animatronics

### Bonnie
Travels down the **left side** of the building: Show Stage → Dining Area → Backstage → Supply Closet → West Hall → West Hall Corner. Approaches through the **left door**.

### Chica
Travels down the **right side**: Show Stage → Dining Area → Restrooms → Kitchen → East Hall → East Hall Corner. Approaches through the **right door**.

### Foxy
Operates from **Pirate Cove (CAM 1C)**. Has 5 visible stages of increasing aggression. At stage 4, he sprints down the West Hall to the left door — if it is open, he attacks. Watching CAM 2A during his run is the key to stopping him.

### Freddy
Follows the same right-side path as Chica but is far more patient. He primarily moves when the cameras are **not** being watched. He can linger at **CAM 4B** (East Hall Corner) for up to 30 seconds. Monitoring that camera resets his approach timer. He becomes the dominant threat on later nights.

---

## Nights

There are **5 nights** with progressively aggressive animatronic behavior.

| Night | Difficulty | Notes |
|---|---|---|
| 1 | Beginner | Animatronics barely move; tutorial night |
| 2 | Easy | Bonnie and Chica become active |
| 3 | Medium | Freddy begins to move |
| 4 | Hard | All animatronics significantly more aggressive |
| 5 | Expert | Maximum intelligence; all animatronics are a constant threat |

Each animatronic has an **intelligence** value per minute of the night. Higher intelligence means shorter intervals between movement checks and a higher probability of advancing toward the player.

---

## Win / Lose Conditions

- **Win:** Survive until the 6-minute mark with power remaining.
- **Lose (caught):** An animatronic reaches your door and the door is open — a jumpscare plays and the game ends.
- **Lose (power out):** Energy drops to 0 — doors open, Freddy's laugh plays, and he attacks shortly after.

---

## Architecture

The project is built with C++17 and follows an object-oriented design.

```
include/        Header files for all classes
src/            Implementation files + Makefile
src/arts/       ASCII art assets (rooms, animatronics, screamers)
tests/          Google Test unit tests
docs/           Doxygen-generated HTML/LaTeX documentation
architectural_description/  Design documents and UML diagrams
```

### Key Classes

| Class | Responsibility |
|---|---|
| `Game` | Main game loop, threading, win/lose logic |
| `Player` | Player state (cameras, fan) |
| `Energy` | Power tracking and drain calculation |
| `Animatronic` | Base class for all animatronics (pathfinding, door logic) |
| `Fox` | Foxy-specific stage and sprint logic |
| `Fredd` | Freddy-specific patience and blackout logic |
| `Cam` | Camera state and display |
| `Door` | Door open/close and light state |
| `Menu` | Main menu and night selection |
| `Phone` | In-game phone call instructions at night start |
| `Picture` | ASCII art rendering and terminal display |
| `Random` | Mersenne Twister RNG for movement timing |

Game updates run on a **background thread** at 1-second intervals, keeping animatronic logic and energy drain independent of player input.

---

## Build

Navigate to the `src/` directory before running make.

```bash
cd src
```

**Build the game:**
```bash
make
```

**Build tests:**
```bash
make test
```

---

## Run

```bash
./mikmik
```

> Note: The game uses ASCII art and requires a terminal with sufficient width. If the display looks incorrect, the menu will prompt you to adjust your terminal size.

---

## Tests

```bash
./testik
```

Tests are written with **Google Test** and cover core game logic including energy calculations, animatronic state transitions, door mechanics, and camera behavior.

---

## CI

Automated builds and tests run via GitHub Actions on every push. See `.github/workflows/ci.yml`.
