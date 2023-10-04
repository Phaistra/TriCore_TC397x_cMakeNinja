# Cmake/Ninja Build toolchain for TriCore TX39xx projects

## Project dependencies
To run this project, the following must be installed and added to your `PATH` environment variable:
- [Just, a cross platform command runner][1]
- [CMake][2]
- Powershell (installed and available on all Windows systems by default)

### Using Chocolatey
If you have [Chocolatey][3] installed, then run: 
```
just install_deps
```
This will install the latest [CMake][2] on your system. You can [Install chocolatey from here][4].

## Command reference

### Before you build
Before you build, if you change your project name in the `CMakeLists.txt` file, you need to update the `NinjaCmakeTaskingTriCoreProject.elf` in the justfile aswell! Otherwise, the post build scripts will fail.

### Creating build.ninja

Run the command:
```
just gen
```

### Building using Ninja (debug)
Run the following from root dir:
```
just build
```
Building release only:
```
just buildr
```

### Building Debug & Release
Run the following from root dir:
```
just buildall
```

### Full clean
A full clean will delete `bin` folder, Ninja files and all temporary Cmake related files.
```
just clean
```
## Powershell permissions
Running for the first time, you might get powershell permission problems. Run `just pwr_permissions` to gain proper security permissions. Then you can run everything like normal.


## Clang format
You can run `just fmt` to run the clang formatter, but you need to add `clang-format.exe` to your environment PATH, otherwise the powershell will complain.

## Build warnings
You will see some build warnings regarding incompatible enum types for stuff inside the iLLD. I left this as is so that the project matches as close as possible to what AURIX Studio provides. Fixing these warnings should be trivial and is left as an exercise for the reader.


[1]: https://github.com/casey/just
[2]: https://cmake.org/
[3]: https://chocolatey.org
[4]: https://chocolatey.org/install
