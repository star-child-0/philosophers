# 🍝 Philosophers

<p align="center" style="font-style:italic">
I never thought philosophy would be so deadly.
</p>

## 📖 Overview

This project is an implementation of the famous Dining Philosophers Problem in C. The Dining Philosophers Problem is a classic synchronization problem in computer science, where a group of philosophers sit at a table and eat spaghetti. There are as many forks on the table as the number of philosophers, and each philosopher needs two forks to eat. The problem is to design a solution where the philosophers can eat without getting into a deadlock.

<p align="center">
	<img alt="anvannin's 42 philosophers languages" src="https://img.shields.io/github/languages/top/star-child-0/philosophers?color=red">
	<img alt="anvannin's 42 philosophers repo-size" src="https://img.shields.io/github/repo-size/star-child-0/philosophers?color=green">
	<img alt="anvannin's 42 philosophers lines" src="https://img.shields.io/tokei/lines/github.com/star-child-0/philosophers?color=blue">
</p>

<p align="center">
	<a href="https://cdn.intra.42.fr/pdf/pdf/65661/en.subject.pdf"><img alt="Static Badge" src="https://img.shields.io/badge/Subject-v.10-teal" link="https://cdn.intra.42.fr/pdf/pdf/65661/en.subject.pdf"></a>
	<img alt="anvannin's 42 philosophers Score" src="https://badge42.vercel.app/api/v2/cleh36s9k00060fmefi6qv520/project/3036876">
</p>

## ⚙️ Installation

To run this project, you need to have a C compiler and `make` installed on your system. If you're using Linux or macOS, you probably already have them installed.

First, clone this repository by running the following command:
```
git clone
```

Once you have a C compiler and `make` installed, you can clone this repository and compile the program by running the following command/s:

```
cd philo
make
```
for the mandatory part of the project, and
```
cd bonus
make
```
for the bonus part of the project.

This will compile the program and create two executables file called `philo` and `bonus` in the relative directory.

## 🖥️ Usage

To run the program, navigate to the project directory and run the following command/s:

```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```
or, for the bonus part:
```
./bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```

- `number_of_philosophers`: The number of philosophers and forks on the table. This argument must be greater than 1.
- `time_to_die`: The time in milliseconds after which a philosopher dies if they don't start eating.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: The time in milliseconds the philosopher will spend sleeping after they finish eating.
- `number_of_times_each_philosopher_must_eat`: The number of times each philosopher must eat. If this argument is not provided, the program will stop only when a philosopher dies.

## ✅ Mandatory part

The solution is implemented using mutexes and threads. Each philosopher is a thread, and each fork is a mutex. The program is designed ...

## ⭐ Bonus part

The solution is implemented using semaphores and threads. Each philosopher is a thread, and each fork is a semaphore. The program is designed ...

## 🤝 Contributing

Refer to [CONTRIBUTING.md](CONTRIBUTING.md) for information about how to contribute to this project.

## ⚖️ License

This project is licensed under the MIT License. Refer to [LICENSE](LICENSE) for more information.
