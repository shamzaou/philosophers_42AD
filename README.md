# Philosophers Project

## Description

The Philosophers project is a multi-threading and synchronization project aimed at simulating the classical dining philosophers problem. The goal is to implement a solution in which a set of philosophers seated at a round table engage in actions of thinking and eating while avoiding deadlock and starvation.

## Requirements

To run the Philosophers project, you need:

- A C compiler (such as GCC or Clang)
- Basic understanding of concurrency and synchronization techniques
- Familiarity with POSIX threads and mutexes

## Installation

1. Clone the repository:

   ```bash
   git clone <repository_url>
   ```

2. Navigate to the project directory:

   ```bash
   cd philosophers
   ```

3. Compile the program:

   ```bash
   make
   ```

## Usage

To execute the program, run the following command:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

Replace the placeholders with appropriate values:

- `[number_of_philosophers]`: The number of philosophers seated at the table.
- `[time_to_die]`: The time (in milliseconds) after which a philosopher dies if they haven't eaten.
- `[time_to_eat]`: The time (in milliseconds) it takes for a philosopher to finish eating.
- `[time_to_sleep]`: The time (in milliseconds) a philosopher spends sleeping after eating or thinking.
- `[number_of_times_each_philosopher_must_eat]`: The number of times each philosopher must eat before the simulation ends.

Example:

```bash
./philo 5 800 200 200 7
```

This will run the simulation with 5 philosophers, a time to die of 800ms, time to eat of 200ms, time to sleep of 200ms, and each philosopher must eat 7 times.

## Contributing

Contributions to the project are welcome! If you have any ideas, enhancements, or bug fixes, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
```
