pygems
=====================================================

## Introduction

Python Generic Embedded System for C++

## Dependencies

* Required dependencies:
    * eigen3
    * Python
    * Boost    
* Optional dependencies:
    * nsol

Note: nsol library is automatically downloaded and built if not found by cmake.

## Building

pygems has been successfully built and used on Ubuntu 16.04 LTS and Windows 10 64-bits with Visual Studio 2013. 


```bash
git clone https://github.com/gmrvvis/pygems
mkdir pygems/build && cd pygems/build
cmake .. -DCLONE_SUBPROJECTS=ON
make
```
