PlanckUnit
==========

A simple, small, and extensible unit testing framework for embedded systems
and standard OSs alike. The framework only depends on `stdio.h`, `stdlib.h`,
and `string.h`, and specifically has helper libraries to aid use on
Arduino platforms. The library can be used to output unit test results
in almost any format, and specifically has support for JSON and a
human-friendly formats. For standard operating systems, `planckunit.c` and
`planckunit.h` are the only files necessary for using the library.

License
-------

This code is released under the terms of the Apache License (version 2.0).
Please refer to the `LICENSE` file in the root of this repository.

Contributors
------------

Graeme Douglas, Eliana Wardle

Basic Terminology
-----------------

* An _assertion_ is a check of some condition involving some pieces of data.
* A _test_, _unit test_ or _test case_ is code that executes some
instructions creating data mixed with assertions verifying the integrity
of said data.
* A _suite_ or _test suite_ is an ordered collection of tests.
* An _output style_ or _output format_ is one of the predefined syntax
options to print test results in.

Usage
--------

## Restrictions

* If tests are to be used with [PyPlanck](https://github.com/iondbproject/planck-parser) for verification:
 * Tests must use the XML output format.
 * Avoid use of the following tags in output messages to ensure proper parsing:
  * `<suite>`, `</suite>`
  * `<test>`, `</test>`
  * `<summary>`, `</summary>`
* Some output styles may be too verbose for devices with very small memory.
* File paths are left blank in Arduino builds (and otherwise use the absolute path).

## Configuration

In order to use PlanckUnit, this header file must be included in any source
file that defines test cases or runs test suites:

```c
#include "planck_unit.h"
```

Within `planck_unit.h`, these preprocessor definitions enable particular
output styles in the build when included (only Concise is enabled by default).
For example, to enable the JSON, XML, and Concise output styles:

```c
#define PLANCK_UNIT_OUTPUT_STYLE_JSON
/*#define PLANCK_UNIT_OUTPUT_STYLE_HUMAN*/
#define PLANCK_UNIT_OUTPUT_STYLE_XML
#define PLANCK_UNIT_OUTPUT_STYLE_CONCISE
```

If multiple styles are enabled, the one to use for a suite can be defined
using `planck_unit_init_suite()` (see "Constructing a Test Suite" below).
Otherwise, it will default to the first enabled (from high to low precedence:
JSON, Human, XML, Concise).

## Assertions, Test Cases, Test Suites

#### Assertion Types
| Macro | Usage |
|-------|-------|
| `PLANCK_UNIT_ASSERT_TRUE(state, condition)` | Assert that a condition is true. |
| `PLANCK_UNIT_ASSERT_FALSE(state, condition)` | Assert that a condition is false. |
| `PLANCK_UNIT_SET_FAIL(state)` |  Unconditionally fail the test. |
| `PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(state, expected, actual)`,
`PLANCK_UNIT_ASSERT_INT_ARE_NOT_EQUAL(state, expected, actual)` | Assert that two integers are (or are not) equal. |
| `PLANCK_UNIT_ASSERT_STR_ARE_EQUAL(state, expected, actual)`,
`PLANCK_UNIT_ASSERT_STR_ARE_NOT_EQUAL(state, expected, actual)` | Assert that two null-terminated strings are (or are not) equal. |

#### Constructing a Test Case:

```c
void
test_foo(
	planck_unit_test_t *tc
) {
	// Include any data and assertions here.
}
```

#### Constructing a Test Suite:

```c
planck_unit_suite_t *suite = planck_unit_new_suite();
```

Setting the output style to be used in a suite:

```c
planck_unit_init_suite(
	suite,
	planck_unit_print_funcs_xml
);
```

Adding tests to a suite:

```c
planck_unit_add_to_suite(suite, test_foo);
planck_unit_add_to_suite(suite, test_bar);
// ...
```

#### Running a Test Suite:

```c
planck_unit_run_suite(suite);
planck_unit_destroy_suite(suite);
```

Be sure to destroy the suite after it runs in order to conserve memory.

Output will be generated in `stdout` by default
(usually the console for a workstation, or serial monitor for an Arduino).

## Examples

#### Usage Example

A full code example of PlanckUnit usage is provided in `examples/test_example.c`.

#### Output Syntax Examples

JSON:

```c
{"results":[{"error_at_line":50,"file":"[file path]\test_example.c","function":"test_addstuff1_1","message":"condition was false, expected true"},
{"error_at_line":-1,"file":"","function":"","message":""},{"error_at_line":-1,"file":"","function":"","message":""},
{"error_at_line":70,"file":"[file path]\test_example.c","function":"test_stringequals_failure","message":"expected \"apple\", got \"orange\""},
{"error_at_line":-1,"file":"","function":"","message":""},{"error_at_line":-1,"file":"","function":"","message":""},
{"error_at_line":-1,"file":"","function":"","message":""}],"total_tests":7,"total_passed":5}
```

_NOTE: JSON output does not use line separators._

Human:

```c
in function 'test_addstuff1_1', at [file path]\test_example.c:50: condition was false, expected true
in function 'test_stringequals_failure', at [file path]\test_example.c:70: expected \"apple\", got \"orange\"

F**F***

Total Tests:    7
Total Passed:   5
```

XML:

```c
<suite>
<test>line:"50",file:"[file path]\test_example.c",function:"test_addstuff1_1",mes
sage:"condition was false, expected true"</test>
<test>line:"-1",file:"",function:"",message:""</test>
<test>line:"-1",file:"",function:"",message:""</test>
<test>line:"70",file:"[file path]\test_example.c",function:"test_stringequals_failure",message:"expected \"apple\", got \"orange\""</test>
<test>line:"-1",file:"",function:"",message:""</test>
<test>line:"-1",file:"",function:"",message:""</test>
<test>line:"-1",file:"",function:"",message:""</test>
<summary>total_tests:"7",total_passed:"5"</summary>
</suite>
```

Concise:

```c
[[Results]]
[test_addstuff1_1: 50: condition was false, expected true]
[: pass]
[: pass]
[test_stringequals_failure: 70: expected \"apple\", got \"orange\"]
[: pass]
[: pass]
[: pass]
[[Passed: 5/7]]
```
