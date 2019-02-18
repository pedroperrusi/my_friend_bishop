<!-- File written based on GitHub markdown -->
# My Friend Bishop

Simple programming logic exercise based on chess.
Let's get to know our friend bishop and see how it moves!

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
├── data
│   ├── bunny_faces.npy
│   ├── bunny_vertices.npy
│   ├── face_normals.npy
│   └── vertex_normals.npy
├── extern
│   └── cnpy
│       ├── CMakeLists.txt
│       ├── LICENSE
│       ├── README.md
│       ├── cnpy.cpp
│       ├── cnpy.h
│       ├── example1.cpp
│       ├── mat2npz
│       ├── npy2mat
│       └── npz2mat
├── include
│   └── bunny_mesh
│       ├── Mesh.h
│       └── data_io.h
├── python
│   └── visualize_mesh.py
├── scripts
│   ├── build.sh
│   ├── clean.sh
│   ├── cmake.sh
│   ├── run_bunny_mesh_normals.sh
│   └── run_tests.sh
├── src
│   ├── CMakeLists.txt
│   └── Mesh.cc
└── test
    ├── CMakeLists.txt
    ├── data
    │   ├── sequential_double.npy
    │   └── sequential_int.npy
    ├── test_IO.cc
    └── test_Mesh.cc
```