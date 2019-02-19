<!-- File written based on GitHub markdown -->
# My Friend Bishop

Simple programming logic exercise based on chess.
Let's get to know our friend bishop and see how it moves!

While the main executable file remain simple, I invite you to review the unit testing cases considered for the challenge.

## The Challenge

Given an starting position in chess board for the bishop, we must:

- Determine if the ending position is reachable for a bishop;
- Determine in how many movements will he arrive there.

### Dependencies

* [CMake](https://cmake.org)

### External Libraries

* Google Tests (Gtest): Basic testing functionalities. The CMake and Gtest integration was based on the [gtest-demo](https://github.com/bast/gtest-demo) repository.

### Usage

In order to perform the basic interface with the bunny-mesh project, you may use the helping bash scripts of the folder [scripts](scripts/). Their names are mostly self explanatory.

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
bash scripts/run_bunny_mesh_normals.sh
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