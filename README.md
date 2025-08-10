# Philosophers

## 🧠 Project Overview

This project implements the classic **Dining Philosophers Problem** using C, focusing on concurrency and synchronization. It was developed as part of the 42 school curriculum to deepen understanding of multithreading, mutexes, and process management.

## ⚙️ Key Features

- **Concurrency**: Utilizes POSIX threads (`pthread`) to simulate philosophers' actions.
- **Synchronization**: Employs mutexes to manage access to shared resources (forks), preventing data races.
- **Process Management**: Implements process handling to simulate philosophers' behaviors accurately.
- **Deadlock Prevention**: Ensures that all philosophers can eat without causing deadlocks or starvation.

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/alphbarry/Philosophers.git
cd Philosophers
Compile the project:

make
🚀 Usage
Run the program with the following syntax:
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

Example:
./philo 5 800 200 200 5
This command simulates 5 philosophers, each having 5 meals, with specified time intervals for eating, sleeping, and dying.

🛠️ Technologies Used
C Programming Language

POSIX Threads (pthread)

Mutexes for synchronization

Process Management

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

👨‍💻 Author
alphbarry – GitHub Profile
