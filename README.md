<!-- File written based on GitHub markdown -->
# My Friend Bishop

Simple programming logic exercise based on chess.
Let's get to know our friend bishop and see how it moves!

While the main executable file remain simple, I invite you to review the unit testing cases considered for the challenge.

## The Challenge

Given an starting position in chess board for the bishop, we must:

- Determine if the ending position is reachable for a bishop;
- Determine in how many movements will he arrive there.

## The approach

A chess board of fixed length and height size was considered to solve the challenge.
A bishop object is defined with a given starting point in the board. 
If none is specified, defaults to 0.

```(C++)
// defines a bishop in the default position (x = 0, y = 0)
Bishop bishop(0, 0);
```

There are two possible space representations for the bishops position:

- As a 2D point in the chess board
    - So, defined by an x (cols) and y (rows)

- As a 1D vector where each element is defined by an index number

You may use any of these representations accordingly to your needs:

```(C++)
// defines a bishop object in the starting position (x = 5, y = 5)
Bishop bishop2D(5, 5);

// defines a bishop position in the starting position defined by a vector index
Bishop bishop1D(10); // equivalent to (x = 2, y = 1)
```

### Dependencies

* [CMake](https://cmake.org)

### External Libraries

* Google Tests (Gtest): Basic testing functionalities. The CMake and Gtest integration was based on the [gtest-demo](https://github.com/bast/gtest-demo) repository.

### Usage

In order to perform the basic interface with the my_friend_bishop project, you may use the helping bash scripts of the folder [scripts](scripts/). Their names are mostly self explanatory.

In order to generate the CMake files:

```(bash)
bash scripts/cmake.sh
```

In order to build and compile:

```(bash)
bash scripts/build.sh
```

Finally you may run the project:

```(bash)
bash scripts/run_bishop.sh
```

* Other commands:

To remove the build folder:

```(bash)
bash scripts/clean.sh
```

To run unit tests:

```(bash)
bash scripts/run_tests.sh
```

## Project Structure

The project structure is based on [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/).
Some adjustments would also be interesting, such as downloading the external dependency CNPY from a CMake file.

```
.
├── CMakeLists.txt
├── LICENSE
├── README.md
├── app
│   ├── CMakeLists.txt
│   └── main.cc
├── cmake
│   ├── googletest-download.cmake
│   └── googletest.cmake
├── include
│   └── my_friend_bishop
│       └── Bishop.h
├── scripts
│   ├── build.sh
│   ├── clean.sh
│   ├── cmake.sh
│   ├── run_bishop.sh
│   └── run_tests.sh
├── src
│   ├── Bishop.cc
│   └── CMakeLists.txt
└── test
    ├── CMakeLists.txt
    └── test_Bishop.cc
```
