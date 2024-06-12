# 🍝 Philosophers

<p align="center" style="font-style:italic">
I never thought philosophy would be so deadly.
</p>

## 📖 Overview

This project is an implementation of the famous Dining Philosophers Problem in C. The Dining Philosophers Problem is a classic synchronization problem in computer science, where a group of philosophers sit at a table and eat spaghetti. There are as many forks on the table as the number of philosophers, and each philosopher needs two forks to eat. The problem is to design a solution where the philosophers can eat without getting into a deadlock.

<p align="center">
	<img alt="anvannin's 42 philosophers languages" src="https://img.shields.io/github/languages/top/star-child-0/philosophers?color=red">
	<img alt="anvannin's 42 philosophers repo-size" src="https://img.shields.io/github/repo-size/star-child-0/philosophers?color=green">
	<a href="https://cdn.intra.42.fr/pdf/pdf/65661/en.subject.pdf"><img alt="Static Badge" src="https://img.shields.io/badge/Subject-v.10-teal" link="https://cdn.intra.42.fr/pdf/pdf/65661/en.subject.pdf"></a>
	<img alt="anvannin's 42 philosphers grade" src="https://img.shields.io/badge/Firenze-100%25-success?style-fleat&logo=42">
</p>

## ⚙️ Installation

To run this project, you need to have the `gcc` compiler and `make` installed on your system. If you're using a Linux based system or macOS, you probably already have them installed.

First, clone this repository by issuing the following command:
```
git clone https://github.com/star-child-0/philosophers.git
```

Once you have a C compiler and `make` installed, you can clone this repository and compile the program by issuing the following command/s:

```
cd philosopers/philo
make
```

This will compile the program and create an executables file called `philo`.

## 🖥️ Usage

To run the program, navigate to the project directory and issue the following command:

```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```

- `number_of_philosophers`: The number of philosophers and forks on the table. This argument must be greater than 1.
- `time_to_die`: The time in milliseconds after which a philosopher dies if they don't start eating.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: The time in milliseconds the philosopher will spend sleeping after they finish eating.
- `number_of_times_each_philosopher_must_eat`: The number of times each philosopher must eat. If this argument is not provided, the program will stop only when a philosopher dies.

## ✅ Mandatory part

The solution is implemented using mutexes and threads. Each philosopher is a thread, and each fork is a mutex.

The program is designed so that each philosopher only worries about eating, sleeeping and thinking.

Each philosoper is left-handed, meaning that they will attempt to take the fork to their left first (aka. the fork with the same id of the philosopher), and only then try to get the fork to their right.

*Note: the firt philo (the one with id 0), is right-handed, which means they will attempt to take the right fork first, so to avoid deadlocks*

## 🤝 Contributing

Refer to [CONTRIBUTING.md](CONTRIBUTING.md) for information about how to contribute to this project.

## ⚖️ License

This project is licensed under the MIT License. Refer to [LICENSE](LICENSE) for more information.
