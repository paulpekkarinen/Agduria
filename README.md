# Agduria

Roguelike game using curses library for ASCII graphics. This project started as a joke in 2009 and was buried in the pile of unfinished projects until someone reminded me about it. I found the source code and decided to release it as open source project with an idea to improve it when I have the time.

## Installation

### Requirements

You need some type of compatible curses library (curses.h) to compile and run this game. The terminal must support 16 or more colors and 80 x 24 characters size. The minimum required C++ version is C++20.

### Linux

Go to the root directory of the project and type these commands:

```
make
./agduria
```

### Windows

Using an IDE create a console project, add all source files to the project and compile. You need to add curses library for the linker, details vary depending on your IDE.

## Coding style

Agduria is object-oriented C++ with some C-style functions. The preferred tab size is 4, using a tab character. Naming conventions are:

```
enum, class, struct, member functions: Title_Case
define: MACRO_CASE
everything else: lowercase or snake_case
```

## More information

The official homepage of Agduria is at [https://www.kriceland.fi/agduria](https://www.kriceland.fi/agduria) where you can find more information about this project.
