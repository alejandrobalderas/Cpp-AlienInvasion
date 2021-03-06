# Alien Invasion Written in C++

In this repo you will find a simple version of the Alien Invasion game written in C++ with the SDL Library.

## How to play

Move using your left and right arrow keys. Shoot with space bar. Quit game by pressing the "q" key in your keyboard.

![plot](./assets/gameplay.png)

## Project Structure

    ├── build                   # Compiled files
    ├── src                     # Source files
        ├── images/             # PNG Images of Assets
        ├── Alien               # Controls Alien movement
        ├── AlienInvasion       # Game File. All the logic is located here
        ├── Bullet              # Controls Bullet movement and updates
        ├── Controller          # Handles User Input
        ├── main                # Main file. Calls AlienInvasion::run()
        ├── Renderer            # Initializes the SDL Library
        ├── Settings            # Class with all game settings
        ├── Ship                # Controls Ship movement and updates
        ├── Sprite              # Parent Class to all figures. Defines basic rendering behaviour
    └── README.md

## Build from source and running

Running on linux please install vcpkg
If you are using Ubuntu you can just run the `./configure.sh` script which will install vcpkg to manage package dependencies as well as install the sdl2 and sdl2-image libraries

### Installing vcpkg from the Microsoft repository

This installs and configures vcpkg inside of the home directory of the current user and exports the path.

```bash
$ VCPKGROOT="/home/$(whoami)/vcpkg"
$ export VCPKGROOT
$ export PATH="$PATH:$VCPKGROOT"
$ git clone https://github.com/microsoft/vcpkg $VCPKGROOT
$ $VCPKGROOT/bootstrap-vcpkg.s
$ vcpkg integrate install
```

### Installing the needed libraries

Install SDL2 and SDL2-image to be able to compile the programm

```bash
$ vcpkg install sdl2 sdl2-image
```

## Build Project

Clears the build directory if it exists, creates it and calls the cmake command with the needed flag -DCMAKE_TOOLCHAIN_FILE. It then compiles all files for the project

```bash
rm -rf build/
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKGROOT}/scripts/buildsystems/vcpkg.cmake
make
```

### Configuring and building the project

This script runs all the steps above in one go.

```bash
./configure.sh
```

### Running the game

Just calls the excecutable inside the build directory

```bash
./run.sh
```

## Criteria For Udacity Project

### OOP

- [x] Project users OOP techniques :heavy_check_mark:
- [x] Classes use appropriate access specifiers for class members :heavy_check_mark:
- [x] Class constructors utilize member initialization lists :heavy_check_mark:
- [x] Classes abstract implementation details from their interfaces. :heavy_check_mark:
- [x] Classes follow an appropriate inheritance hierarchy :heavy_check_mark:
- [x] Derived class functions override virtual base class functions :heavy_check_mark:
- [x] The project makes use of references in function declarations :heavy_check_mark:
- [x] The project uses smart pointers instead of raw pointers. :heavy_check_mark:
- [x] The project uses multithreading. (Just for fun in AllienInvasion starting on line 51.) :heavy_check_mark:
