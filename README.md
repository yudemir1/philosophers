# Philosophers

A 42 School project implementing the classic **Dining Philosophers Problem** in C using POSIX threads and mutexes, to practice reasoning about concurrency, race conditions, and deadlocks.

## About

`N` philosophers sit around a round table with a fork between each pair of them. Each philosopher alternates between three states: eating, sleeping, and thinking. To eat, a philosopher needs to pick up both the fork on their left and the fork on their right — but forks are shared, so philosophers must compete for them without starving or deadlocking each other, and without dying of hunger before their next meal.

The program simulates this scenario with one thread per philosopher plus a monitor thread that watches for philosophers who haven't eaten in time.

[<img width="708" height="728" alt="image" src="https://github.com/user-attachments/assets/bb755f86-ad8c-413d-a91a-951ba7e52a90" />
](https://alexzhornyak.github.io/SCXML-tutorial/Images/DiningPhilosophers_Img.gif)

## Build

```sh
make
```

This compiles the `philo` binary with `-Wall -Wextra -Werror -pthread`.

Other targets:

```sh
make clean   # remove object files
make fclean  # remove object files and the binary
make re      # rebuild from scratch
```

## Usage

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- **number_of_philosophers** — number of philosophers and forks at the table
- **time_to_die** (ms) — if a philosopher doesn't start eating within this time of their last meal, they die
- **time_to_eat** (ms) — time it takes a philosopher to eat once they have both forks
- **time_to_sleep** (ms) — time a philosopher spends sleeping after eating
- **number_of_times_each_philosopher_must_eat** (optional) — if given, the simulation stops once every philosopher has eaten this many times

### Example

```sh
./philo 5 800 200 200
```

Simulates 5 philosophers where each dies if they go 800ms without eating, eating takes 200ms, and sleeping takes 200ms.

## Project structure

| File | Description |
|---|---|
| `philo.c` | Entry point |
| `init.c` | Initializes philosophers, forks, mutexes, and simulation data |
| `activities.c` | Core philosopher routine (eat / sleep / think loop) |
| `monitor.c` | Monitor thread that detects when a philosopher dies |
| `arg_check.c` | Validates command-line arguments |
| `errors.c` | Error handling/reporting |
| `utils.c` | Utility functions (e.g. timing helpers) |
| `test.c` | Test helper |
| `philo.h` | Shared structs and function prototypes |

## Notes

Implemented with `pthread` mutexes for fork access and shared state (`meal_lock`, `isdead_lock`, `print_lock`), following 42's constraint against using `exit()` for control flow within the simulation logic.
