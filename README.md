# Some very simple C++ examples

## Tic-tac-toe in terminal

I wrote this code because I saw a lot of people writing it as an exercise.

## How to easily create a file in C++

The create-file.cpp example show the most concise and eye-pleasant way to create a file. The explanation is there: http://stackoverflow.com/a/42767681/4498831

## Temporary variable as unused output parameter

Sometimes, functions use a parameter as output, and sometimes we do not care about this parameter. In this situation, using a previously declared variable is misleading because it is not obvious that the variable will be unused.

The functions `unused_ref` and `unused_ptr` in `unused-param.cpp` are useful in this case.

Compile the file with:

```
c++ -std=c++1z -Wall -Wextra unused-param.cpp -lstdc++fs
```

## Flags in a scoped enum

Scoped enum are cool because they are namespaced and are not silentely casted to their underlying type, but we cannot use them as bitmask for flags because no logical operations exist for the type.

We implement those operations, but they are deactivated by default. The user must activate them with the struct `is_bitmask_enum`.

## Generic trim of a string

Some functions that trim all type of strings in every situation and every locals.

