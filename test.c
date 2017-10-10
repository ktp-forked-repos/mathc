/*
Copyright (C) 2016 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
     that you wrote the original software. If you use this software in a
     product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include "mathc.h"

const float epsilon = FLT_EPSILON;
const float epsilon_greater = FLT_EPSILON * 10.0f;

struct cerror {
	int32_t failed;
	int32_t passed;
	int32_t passed_with_greater_error_margin;
};

void printf_1f_test(struct cerror *error, char *msg, float e1, float r1)
{
	printf("%s:\n\tExpected % .4f\n\t  Actual  % .4f\t", msg, e1, r1);
	if (nearly_equal(e1, r1, epsilon)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		/* Try with greater error margin */
		if (nearly_equal(e1, r1, epsilon_greater)) {
			error->passed_with_greater_error_margin = error->passed_with_greater_error_margin + 1;
			printf("~passed with greater error margin~\n\n");
		} else {
			error->failed = error->failed + 1;
			printf("~failed~\n\n");
		}
	}
}

void printf_2f_test(struct cerror *error, char *msg, float e1, float e2, float r1, float r2)
{
	printf("%s:\n\tExpected % .4f, % .4f\n\t  Actual % .4f, % .4f\t", msg, e1, e2, r1, r2);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		/* Try with greater error margin */
		if (nearly_equal(e1, r1, epsilon_greater) && nearly_equal(e2, r2, epsilon_greater)) {
			error->passed_with_greater_error_margin = error->passed_with_greater_error_margin + 1;
			printf("~passed with greater error margin~\n\n");
		} else {
			error->failed = error->failed + 1;
			printf("~failed~\n\n");
		}
	}
}

void printf_3f_test(struct cerror *error, char *msg, float e1, float e2, float e3, float r1, float r2, float r3)
{
	printf("%s:\n\tExpected % .4f, % .4f, % .4f\n\t  Actual % .4f, % .4f, % .4f\t", msg, e1, e2, e3, r1, r2, r3);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon) && nearly_equal(e3, r3, epsilon)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		/* Try with greater error margin */
		if (nearly_equal(e1, r1, epsilon_greater) && nearly_equal(e2, r2, epsilon_greater) && nearly_equal(e3, r3, epsilon_greater)) {
			error->passed_with_greater_error_margin = error->passed_with_greater_error_margin + 1;
			printf("~passed with greater error margin~\n\n");
		} else {
			error->failed = error->failed + 1;
			printf("~failed~\n\n");
		}
	}
}

void printf_4f_test(struct cerror *error, char *msg, float e1, float e2, float e3, float e4, float r1, float r2, float r3, float r4)
{
	printf("%s:\n\tExpected % .4f, % .4f, % .4f, % .4f\n\t  Actual % .4f, % .4f, % .4f, % .4f\t", msg, e1, e2, e3, e4, r1, r2, r3, r4);
	if (nearly_equal(e1, r1, epsilon) && nearly_equal(e2, r2, epsilon) && nearly_equal(e3, r3, epsilon)) {
		error->passed = error->passed + 1;
		printf("~passed~\n\n");
	} else {
		/* Try with greater error margin */
		if (nearly_equal(e1, r1, epsilon_greater) && nearly_equal(e2, r2, epsilon_greater) && nearly_equal(e3, r3, epsilon_greater) && nearly_equal(e4, r4, epsilon_greater)) {
			error->passed_with_greater_error_margin = error->passed_with_greater_error_margin + 1;
			printf("~passed with greater error margin~\n\n");
		} else {
			error->failed = error->failed + 1;
			printf("~failed~\n\n");
		}
	}
}

void vector2_tests(struct cerror *error)
{
	cvector a;
	cvector b;
	cvector r;
	float p;
	printf("\n# Making tests with 2D vectors...\n");
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_add(a, b);
	printf_2f_test(error, "Add two vectors", 2.01f, 3.8f, r.x, r.y);
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_subtract(a, b);
	printf_2f_test(error, "Subtract two vectors", 0.21f, 1.2f, r.x, r.y);
	a = to_vector2(1.11f, 2.5f);
	r = vector2_scale(a, 3.3f);
	printf_2f_test(error, "Scale vector", 3.663f, 8.25f, r.x, r.y);
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_multiply(a, b);
	printf_2f_test(error, "Multiply two vectors", 0.999f, 3.25f, r.x, r.y);
	a = to_vector2(1.11f, 2.5f);
	b = to_vector2(0.9f, 1.3f);
	r = vector2_divide(a, b);
	printf_2f_test(error, "Divide two vectors", 1.2333333333f, 1.9230769231f, r.x, r.y);
	a = to_vector2(1.11f, 2.5f);
	r = vector2_negative(a);
	printf_2f_test(error, "Negative vector", -1.11f, -2.5f, r.x, r.y);
	a = to_vector2(-3.33f, 1.1f);
	r = vector2_abs(a);
	printf_2f_test(error, "Absolute vector", 3.33f, 1.1f, r.x, r.y);
	a = to_vector2(1.11f, -2.5f);
	r = vector2_floor(a);
	printf_2f_test(error, "Floor vector", 1.0f, -3.0f, r.x, r.y);
	a = to_vector2(-0.00011f, 3.999999f);
	r = vector2_floor(a);
	printf_2f_test(error, "Floor vector", -1.0f, 3.0f, r.x, r.y);
	a = to_vector2(1.11f, -2.5f);
	r = vector2_ceil(a);
	printf_2f_test(error, "Ceil vector", 2.0f, -2.0f, r.x, r.y);
	a = to_vector2(-0.00011f, 3.999999f);
	r = vector2_ceil(a);
	printf_2f_test(error, "Ceil vector", 0.0f, 4.0f, r.x, r.y);
	a = to_vector2(1.11f, -2.55f);
	r = vector2_round(a);
	printf_2f_test(error, "Round vector", 1.0f, -3.0f, r.x, r.y);
	a = to_vector2(4.31f, -6.65f);
	b = to_vector2(-3.41f, 2.7f);
	r = vector2_max(a, b);
	printf_2f_test(error, "Maximum of vectors", 4.31f, 2.7f, r.x, r.y);
	a = to_vector2(4.31f, -6.65f);
	b = to_vector2(-3.41f, 2.7f);
	r = vector2_min(a, b);
	printf_2f_test(error, "Minimum of vectors", -3.41f, -6.65f, r.x, r.y);
	a = to_vector2(4.31f, -6.65f);
	b = to_vector2(-3.41f, 2.7f);
	p = vector2_dot(a, b);
	printf_1f_test(error, "Dot value of vectors", -32.6521f, p);
	a = to_vector2(2.0f, 2.0f);
	p = vector2_angle(a);
	printf_1f_test(error, "Angle (radians) of vector", 0.78539816339745f, p);
	a = to_vector2(4.31f, -6.65f);
	p = vector2_angle(a);
	printf_1f_test(error, "Angle (radians) of vector", -0.99574364682817f, p);
	a = to_vector2(-5.31f, -7.33f);
	p = vector2_angle(a);
	printf_1f_test(error, "Angle (radians) of vector", -2.1977243674756f, p);
	a = to_vector2(3.33f, 2.0f);
	p = vector2_length_squared(a);
	printf_1f_test(error, "Length squared of vector", 15.0889f, p);
	a = to_vector2(3.33f, 2.0f);
	p = vector2_length(a);
	printf_1f_test(error, "Length of vector", 3.8844433321f, p);
	a = to_vector2(3.33f, 2.0f);
	r = vector2_normalize(a);
	printf_2f_test(error, "Normalize vector", 0.8572664271f, 0.514874731f, r.x, r.y);
	a = to_vector2(1.0f, -1.0f);
	b = to_vector2(0.0f, 1.0f);
	r = vector2_slide(a, b);
	printf_2f_test(error, "Slide vector by normal", 1.0f, 0.0f, r.x, r.y);
	a = to_vector2(-2.0f, 0.0f);
	b = vector2_normalize(to_vector2(1.0f, 1.0f));
	r = vector2_slide(a, b);
	printf_2f_test(error, "Slide vector by normal", -1.0f, 1.0f, r.x, r.y);
	a = to_vector2(1.0f, -1.0f);
	b = to_vector2(-1.0f, 0.0f);
	r = vector2_reflect(a, b);
	printf_2f_test(error, "Reflect vector by another", -1.0f, -1.0f, r.x, r.y);
	a = to_vector2(1.0f, 1.0f);
	b = to_vector2(0.0f, -1.0f);
	r = vector2_reflect(a, b);
	printf_2f_test(error, "Reflect vector by another", 1.0f, -1.0f, r.x, r.y);
	a = to_vector2(2.0f, 1.0f);
	r = vector2_tangent(a);
	printf_2f_test(error, "Vector tangent", 1.0f, -2.0f, r.x, r.y);
	a = to_vector2(1.0f, 0.0f);
	r = vector2_rotate(a, 90.0f * M_PIF / 180.0f);
	printf_2f_test(error, "Rotate vector", 0.0f, 1.0f, r.x, r.y);
	a = to_vector2(1.0f, 0.0f);
	r = vector2_rotate(a, 45.0f * M_PIF / 180.0f);
	printf_2f_test(error, "Rotate vector", 0.707106781f,0.707106781f, r.x, r.y);
	a = to_vector2(1.0f, 0.0f);
	r = vector2_rotate(a, 130.0f * M_PIF / 180.0f);
	printf_2f_test(error, "Rotate vector", -0.64278761f,0.766044443f, r.x, r.y);
	a = to_vector2(-7.0f, -4.0f);
	b = to_vector2(17.0f, 6.5f);
	p = vector2_distance_to(a, b);
	printf_1f_test(error, "Distance between vector", 26.196374f, p);
	a = to_vector2(-7.0f, -4.0f);
	b = to_vector2(17.0f, 6.5f);
	p = vector2_distance_squared_to(a, b);
	printf_1f_test(error, "Distance squared between vector", 686.2500107479f, p);
	a = to_vector2(-7.0f, -4.0f);
	b = to_vector2(17.0f, 6.5f);
	r = vector2_linear_interpolation(a, b, 0.33f);
	printf_2f_test(error, "Linear interpolation between vectors", 0.92f, -0.535f, r.x, r.y);
}

void vector3_tests(struct cerror *error)
{
	cvector a;
	cvector b;
	cvector r;
	float p;
	printf("\n# Making tests with 3D vectors...\n");
	a = to_vector3(1.11f, 2.5f, 0.0003f);
	b = to_vector3(0.9f, 1.3f, 3.999999f);
	r = vector3_add(a, b);
	printf_3f_test(error, "Add two vectors", 2.01f, 3.8f, 4.000299f, r.x, r.y, r.z);
	a = to_vector3(1.11f, 2.5f, 0.0003f);
	b = to_vector3(0.9f, 1.3f, 3.999999f);
	r = vector3_subtract(a, b);
	printf_3f_test(error, "Subtract vectors", 0.21f, 1.2f, -3.999699f, r.x, r.y, r.z);
	a = to_vector3(1.11f, 2.5f, 0.0003f);
	r = vector3_scale(a, 3.3f);
	printf_3f_test(error, "Scale vector", 3.663f, 8.25f, 0.000990f, r.x, r.y, r.z);
	a = to_vector3(1.11f, 2.5f, 0.0003f);
	b = to_vector3(0.9f, 1.3f, 3.999999f);
	r = vector3_multiply(a, b);
	printf_3f_test(error, "Multiply vectors", 0.999f, 3.25f, 0.001200f, r.x, r.y, r.z);
	a = to_vector3(1.11f, 2.5f, 0.0003f);
	b = to_vector3(0.9f, 1.3f, 3.999999f);
	r = vector3_divide(a, b);
	printf_3f_test(error, "Divide vectors", 1.2333333333f, 1.9230769231f, 0.000075f, r.x, r.y, r.z);
	a = to_vector3(1.11f, 2.5f, 0.0003f);
	r = vector3_negative(a);
	printf_3f_test(error, "Negative vector", -1.11f, -2.5f, -0.0003f, r.x, r.y, r.z);
	a = to_vector3(-3.33f, 1.1f, -0.00001f);
	r = vector3_abs(a);
	printf_3f_test(error, "Absolute vector", 3.33f, 1.1f, 0.00001f, r.x, r.y, r.z);
	a = to_vector3(1.11f, -2.5f, 0.0003f);
	r = vector3_floor(a);
	printf_3f_test(error, "Floor vector", 1.0f, -3.0f, 0.0f, r.x, r.y, r.z);
	a = to_vector3(-0.00011f, 3.999999f, -0.99999f);
	r = vector3_floor(a);
	printf_3f_test(error, "Floor vector", -1.0f, 3.0f, -1.0f, r.x, r.y, r.z);
	a = to_vector3(1.11f, -2.5f, 9.99999f);
	r = vector3_ceil(a);
	printf_3f_test(error, "Ceil vector", 2.0f, -2.0f, 10.0f, r.x, r.y, r.z);
	a = to_vector3(-0.00011f, 3.999999f, 0.0000001f);
	r = vector3_ceil(a);
	printf_3f_test(error, "Ceil vector", 0.0f, 4.0f, 1.0f, r.x, r.y, r.z);
	a = to_vector3(1.11f, -2.55f, 3.50000001f);
	r = vector3_round(a);
	printf_3f_test(error, "Round vector", 1.0f, -3.0f, 4.0f, r.x, r.y, r.z);
	a = to_vector3(544.00001f, -233333.51f, 7999.50000001f);
	r = vector3_round(a);
	printf_3f_test(error, "Round vector", 544.0f, -233334.0f, 8000.0f, r.x, r.y, r.z);
	a = to_vector3(4.31f, -6.65f, 4.5f);
	b = to_vector3(-3.41f, 2.7f, -5.0f);
	r = vector3_max(a, b);
	printf_3f_test(error, "Maximum between vectors", 4.31f, 2.7f, 4.5f, r.x, r.y, r.z);
	a = to_vector3(4.31f, -6.65f, 4.5f);
	b = to_vector3(-3.41f, 2.7f, -5.0f);
	r = vector3_min(a, b);
	printf_3f_test(error, "Minimum between vectors", -3.41f, -6.65f, -5.0f, r.x, r.y, r.z);
	a = to_vector3(4.31f, -6.65f, 1.0f);
	b = to_vector3(-3.41f, 2.7f, 2.0f);
	p = vector3_dot(a, b);
	printf_1f_test(error, "Dot value of vectors", -30.652100f, p);
	a = to_vector3(3.33f, 2.0f, 3.0f);
	p = vector3_length_squared(a);
	printf_1f_test(error, "Length squared of vector", 24.088900f, p);
	a = to_vector3(3.33f, 2.0f, 3.0f);
	p = vector3_length(a);
	printf_1f_test(error, "Length of vector", 4.908044f, p);
	a = to_vector3(3.33f, 2.0f, 5.0f);
	r = vector3_normalize(a);
	printf_3f_test(error, "Normalize vector", 0.525935f, 0.315877f, 0.789692f, r.x, r.y, r.z);
	a = to_vector3(-7.0f, -4.0f, 99.9f);
	b = to_vector3(17.0f, 6.5f, 103.33f);
	p = vector3_distance_to(a, b);
	printf_1f_test(error, "Distance between vectors", 26.419971f, p);
	a = to_vector3(-7.0f, -4.0f, 99.9f);
	b = to_vector3(17.0f, 6.5f, 103.33f);
	p = vector3_distance_squared_to(a, b);
	printf_1f_test(error, "Distance squared between vectors", 698.014893f, p);
	a = to_vector3(-7.0f, -4.0f, 99.9f);
	b = to_vector3(17.0f, 6.5f, 103.33f);
	r = vector3_linear_interpolation(a, b, 0.33f);
	printf_3f_test(error, "Linear interpolation between vectors", 0.92f, -0.535f, 101.031898f, r.x, r.y, r.z);
}

void quaternion_tests(struct cerror *error)
{
	cvector a;
	cvector b;
	cvector r;
	float p;
	printf("\n# Making tests with quaternions...\n");
	a = to_quaternion(1.0f, 1.0f, 1.0f, 1.0f);
	b = to_quaternion(1.0f, 1.0f, 1.0f, 1.0f);
	r = quaternion_add(a, b);
	printf_4f_test(error, "Add two quaternions", 2.0f, 2.0f, 2.0f, 2.0f, r.x, r.y, r.z, r.w);
}

void matrix_tests(struct cerror *error)
{
	cmatrix a;
	cmatrix b;
	cmatrix r;
	float p;
	printf("\n# Making tests with matrices...\n");
	a = matrix_identity();
	b = matrix_identity();
	r = matrix_multiply_matrix(a, b);
}

int main(int argc, char **args)
{
	struct cerror error = {0};
	vector2_tests(&error);
	vector3_tests(&error);
	quaternion_tests(&error);
	matrix_tests(&error);
	printf("\nTotal of failed tests: %d\n", error.failed);
	printf("Total of tests that passed: %d\n", error.passed);
	printf("Total of tests that passed with greater error margin: %d\n", error.passed_with_greater_error_margin);
	return error.failed;
}
