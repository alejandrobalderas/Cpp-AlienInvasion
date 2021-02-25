# Alien Invasion Written in C++

In this repo you will find a simple version of the Alien Invasion game written in C++ with the SDL Library.

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
If you are using Ubuntu you can just run the ./configure.sh script which will install vcpkg to manage package dependencies as well as install the sdl2 and sdl2-image libraries

### Installing vcpkg from the Microsoft repository

```bash
$ VCPKGROOT="[path to vcpkg]"
$ git clone https://github.com/microsoft/vcpkg VCPKROOT
$ ./bootstrap-vcpkg.sh
$ export VCPKGROOT
```

### Installing the needed libraries

```bash
$ vcpkg integrate install
$ vcpkg install sdl2 sdl2-image
```

### Configuring and building the project

```bash
$ ./configure.sh
```

### Running the game

```bash
$ ./run.sh
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
