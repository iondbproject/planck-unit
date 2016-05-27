/******************************************************************************/
/**
@file
@author		Graeme Douglas
@brief		A simple examples of how to use PlanckUnit.
@details	We create a single suite and create a number of success and
			failure cases for your viewing pleasure.
@copyright	Copyright 2015 Graeme Douglas
@license	Licensed under the Apache License, Version 2.0 (the "License");
			you may not use this file except in compliance with the License.
			You may obtain a copy of the License at
				http://www.apache.org/licenses/LICENSE-2.0

@par
			Unless required by applicable law or agreed to in writing,
			software distributed under the License is distributed on an
			"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
			either express or implied. See the License for the specific
			language governing permissions and limitations under the
			License.
*/
/******************************************************************************/

#include <stdio.h>
#include "../src/planck_unit.h"

int
add_stuff1(
	int a,
	int b
) {
	return a + b;
}

int
add_stuff2(
	int a,
	int b
) {
	return 2 + a + b;
}

void
test_addstuff1_1(
	planck_unit_test_t *tc
) {
	int a	= 10;
	int b	= 3;

	PLANCK_UNIT_ASSERT_TRUE(tc, a + b == 2 + b);
}

void
test_addstuff1_2(
	planck_unit_test_t *tc
) {
	int a	= 10;
	int b	= 3;

	PLANCK_UNIT_ASSERT_TRUE(tc, a + b == add_stuff1(a, b));
}

void
test_stringequals_failure(
	planck_unit_test_t *tc
) {
	char	*a	= "apple";
	char	*b	= "orange";

	PLANCK_UNIT_ASSERT_STR_ARE_EQUAL(tc, a, b);
}

void
test_stringequals_success(
	planck_unit_test_t *tc
) {
	char	*a	= "apple";
	char	*b	= "apple";

	PLANCK_UNIT_ASSERT_STR_ARE_EQUAL(tc, a, b);
}

void
test_stringnotequals_success(
	planck_unit_test_t *tc
) {
	char	*a	= "apple";
	char	*b	= "orange";

	PLANCK_UNIT_ASSERT_STR_ARE_NOT_EQUAL(tc, a, b);
}

void
test_intequals_success(
	planck_unit_test_t *tc
) {
	int a	= 10;
	int b	= 10;

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, a, b);
}

void
test_intnotequals_success(
	planck_unit_test_t *tc
) {
	int a	= 10;
	int b	= -10;

	PLANCK_UNIT_ASSERT_INT_ARE_NOT_EQUAL(tc, a, b);
}

int
main(
	void
) {
	planck_unit_suite_t *suite;

	suite = planck_unit_new_suite();
	/* Include this code, with only one of the print function sets,
	   in order to set a particular output style for this test suite. */
	/*planck_unit_init_suite(
		suite,
		planck_unit_print_funcs_human
		planck_unit_print_funcs_json
		planck_unit_print_funcs_xml
		planck_unit_print_funcs_concise
	);*/
	planck_unit_add_to_suite(suite, test_addstuff1_1);
	planck_unit_add_to_suite(suite, test_addstuff1_2);
	planck_unit_add_to_suite(suite, test_stringequals_success);
	planck_unit_add_to_suite(suite, test_stringequals_failure);
	planck_unit_add_to_suite(suite, test_stringnotequals_success);
	planck_unit_add_to_suite(suite, test_intequals_success);
	planck_unit_add_to_suite(suite, test_intnotequals_success);
	planck_unit_run_suite(suite);
	planck_unit_destroy_suite(suite);
	return 0;
}

