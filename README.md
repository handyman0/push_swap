<h1 align="center">
	🔄 push_swap
</h1>

<p align="center">
	<b><i>Because Swap_push isn't as natural</i></b><br>
</p>

<h3 align="center">
	<a href="#-about">About</a>
	<span> · </span>
	<a href="#-algorithm">Algorithm</a>
	<span> · </span>
	<a href="#-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About

> _This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves._

Push Swap is a sorting algorithm project that uses two stacks (A and B) and a limited set of operations to sort random integers. The challenge is to sort the numbers using the fewest possible operations.

The project demonstrates advanced algorithm design and optimization techniques, achieving exceptional performance with **~3900 operations for 1500 numbers**.

## 🧠 Algorithm

### High-Performance Implementation

My implementation features:

- **Turkish Algorithm Variant**: Custom optimized version for maximum efficiency
- **Multi-phase Sorting Strategy**:
  - Initial chunk-based distribution to stack B
  - Smart element selection and positioning
  - Optimized merge back to stack A
- **Advanced Optimization**:
  - Operation combination and elimination
  - Look-ahead decision making
  - Path optimization for minimal moves

### Operations Used

- `sa` : swap a - swap first 2 elements at top of stack A
- `sb` : swap b - swap first 2 elements at top of stack B  
- `ss` : sa and sb at the same time
- `pa` : push a - take first element from B and put it on A
- `pb` : push b - take first element from A and put it on B
- `ra` : rotate a - shift all elements of stack A up by 1
- `rb` : rotate b - shift all elements of stack B up by 1
- `rr` : ra and rb at the same time
- `rra` : reverse rotate a - shift all elements of stack A down by 1
- `rrb` : reverse rotate b - shift all elements of stack B down by 1
- `rrr` : rra and rrb at the same time

## 🛠️ Usage

### Requirements

The project is written in C and requires:

- **`gcc` compiler**
- **Make**
- **Custom Libft** library (included)

### Instructions

**1. Compiling the project**

To compile both the push_swap program and checker:

```shell
$ make
```

For bonus part (checker):

```shell
$ make bonus
```

**2. Running the program**

Basic usage:
```shell
$ ./push_swap 4 2 1 3
```

With random numbers:
```shell
$ ./push_swap $(seq 1 100 | sort -R)
```

Using the checker to validate:
```shell
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

Check operation count:
```shell
$ ARG=$(seq 1 500 | sort -R); ./push_swap $ARG | wc -l
```

### Performance Metrics

- **100 numbers**: ~650-700 operations
- **500 numbers**: ~4800-5200 operations  
- **1500 numbers**: ~3900 operations (highly optimized)

## 📋 Testing

### Included Testers

- [`push_swap_tester/`](https://github.com/handyman0/42-push_swap/tree/main/push_swap_tester) - Custom testing suite
- [`tester.sh`](https://github.com/handyman0/42-push_swap/blob/main/tester.sh) - Automated testing script
- [`checker_linux`](https://github.com/handyman0/42-push_swap/blob/main/checker_linux) - Official checker for Linux

### External Testers

You can also use these popular testers:
* [push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
* [push_swap Tester](https://github.com/LeoFu9487/push_swap_tester)

### Project Structure

- [`src/`](https://github.com/handyman0/42-push_swap/tree/main/src) - Main source files
- [`include/`](https://github.com/handyman0/42-push_swap/tree/main/include) - Header files
- [`libft/`](https://github.com/handyman0/42-push_swap/tree/main/libft) - Custom Libft library
- [`push_swap_tester/`](https://github.com/handyman0/42-push_swap/tree/main/push_swap_tester) - Testing suite
- [`Makefile`](https://github.com/handyman0/42-push_swap/blob/main/Makefile) - Build configuration
- [`checker_linux`](https://github.com/handyman0/42-push_swap/blob/main/checker_linux) - Official checker executable
- [`tester.sh`](https://github.com/handyman0/42-push_swap/blob/main/tester.sh) - Automated testing script

---

<p align="center">
	<em>Achieving sorting excellence through algorithmic optimization</em>
</p>
