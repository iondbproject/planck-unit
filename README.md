PlanckUnit
==========

A simple, small, and extensible unit testing framework for embedded systems
and standard OSs alike. The framework only depends on `stdio.h`, `stdlib.h`,
and `string.h`, and specifically has helper libraries to aid use on
Arduino platforms. The library can be used to output unit test results
in almost any format, and specifically has support for JSON and a
human-friendly formats. For standard operating systems, `planckunit.c` and
`planckunit.h` are the only files necessary for using the library.

Basic Terminology
-----------------

An _assertion_ is a check of some condition involving some pieces of data.
A _test_, _unit test_ or _test case_ is code that executes some
instructions creating data mixed with assertions verifying the integrity
of said data. A _suite_ or _test suite_ is an ordered collection of tests.

Examples
--------

To see example code using the library, see the `examples` directory.

License
-------

This code is released under the terms of the Apache License (version 2.0).
Please refer to the `LICENSE` file in the root of this repository.

Contributors
------------

Graeme Douglas
