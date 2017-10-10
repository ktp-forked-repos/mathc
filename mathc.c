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

#include <math.h>
#include <float.h>
#include "mathc.h"

/* Check C standard */
#ifdef __STDC__
  #define PREDEF_STANDARD_C89
  #ifdef __STDC_VERSION__
    #if __STDC_VERSION__ >= 199901L
      #define PREDEF_STANDARD_C99
    #endif
    #if __STDC_VERSION__ >= 201112L
      #define PREDEF_STANDARD_C11
    #endif
  #endif
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
#define MATHC_EXTERN_INLINE extern inline
#else
#define MATHC_EXTERN_INLINE
#endif

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/* Utils */
int nearly_equal(float a, float b, float epsilon)
{
	int result = FALSE;
	float abs_a = fabsf(a);
	float abs_b = fabsf(b);
	float diff = fabsf(a - b);
	if (a == b) {
		result = TRUE;
	} else if (a == 0.0f || b == 0.0f || diff < FLT_EPSILON) {
		result = diff < epsilon;
	} else {
		result = diff / fminf(abs_a + abs_b, FLT_MAX) < epsilon;
	}
	return result;
}

/* Vector 2D */
cvector to_vector2(float x, float y)
{
	cvector result;
	result.x = x;
	result.y = y;
	result.z = 0.0f;
	result.w = 1.0f;
	return result;
}

void pvector2_add(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
}

MATHC_EXTERN_INLINE cvector vector2_add(cvector a, cvector b)
{
	cvector result;
	pvector2_add(&a, &b, &result);
	return result;
}

void pvector2_subtract(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x - b->x;
	result->y = a->y - b->y;
}

MATHC_EXTERN_INLINE cvector vector2_subtract(cvector a, cvector b)
{
	cvector result;
	pvector2_subtract(&a, &b, &result);
	return result;
}

void pvector2_scale(cvector *a, float scale, cvector *result)
{
	result->x = a->x * scale;
	result->y = a->y * scale;
}

MATHC_EXTERN_INLINE cvector vector2_scale(cvector a, float scale)
{
	cvector result;
	pvector2_scale(&a, scale, &result);
	return result;
}

void pvector2_multiply(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x * b->x;
	result->y = a->y * b->y;
}

MATHC_EXTERN_INLINE cvector vector2_multiply(cvector a, cvector b)
{
	cvector result;
	pvector2_multiply(&a, &b, &result);
	return result;
}

void pvector2_divide(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x / b->x;
	result->y = a->y / b->y;
}

MATHC_EXTERN_INLINE cvector vector2_divide(cvector a, cvector b)
{
	cvector result;
	pvector2_divide(&a, &b, &result);
	return result;
}

void pvector2_negative(cvector *a, cvector *result)
{
	result->x = -a->x;
	result->y = -a->y;
}

MATHC_EXTERN_INLINE cvector vector2_negative(cvector a)
{
	cvector result;
	pvector2_negative(&a, &result);
	return result;
}

void pvector2_abs(cvector *a, cvector *result)
{
	result->x = fabsf(a->x);
	result->y = fabsf(a->y);
}

MATHC_EXTERN_INLINE cvector vector2_abs(cvector a)
{
	cvector result;
	pvector2_abs(&a, &result);
	return result;
}

void pvector2_floor(cvector *a, cvector *result)
{
	result->x = floorf(a->x);
	result->y = floorf(a->y);
}

MATHC_EXTERN_INLINE cvector vector2_floor(cvector a)
{
	cvector result;
	pvector2_floor(&a, &result);
	return result;
}

void pvector2_ceil(cvector *a, cvector *result)
{
	result->x = ceilf(a->x);
	result->y = ceilf(a->y);
}

MATHC_EXTERN_INLINE cvector vector2_ceil(cvector a)
{
	cvector result;
	pvector2_ceil(&a, &result);
	return result;
}

void pvector2_round(cvector *a, cvector *result)
{
	result->x = roundf(a->x);
	result->y = roundf(a->y);
}

MATHC_EXTERN_INLINE cvector vector2_round(cvector a)
{
	cvector result;
	pvector2_round(&a, &result);
	return result;
}

void pvector2_max(cvector *a, cvector *b, cvector *result)
{
	result->x = fmaxf(a->x, b->x);
	result->y = fmaxf(a->y, b->y);
}

MATHC_EXTERN_INLINE cvector vector2_max(cvector a, cvector b)
{
	cvector result;
	pvector2_max(&a, &b, &result);
	return result;
}

void pvector2_min(cvector *a, cvector *b, cvector *result)
{
	result->x = fminf(a->x, b->x);
	result->y = fminf(a->y, b->y);
}

MATHC_EXTERN_INLINE cvector vector2_min(cvector a, cvector b)
{
	cvector result;
	pvector2_min(&a, &b, &result);
	return result;
}

float pvector2_dot(cvector *a, cvector *b)
{
	return a->x * b->x + a->y * b->y;
}

MATHC_EXTERN_INLINE float vector2_dot(cvector a, cvector b)
{
	return pvector2_dot(&a, &b);
}

float pvector2_angle(cvector *a)
{
	return atan2f(a->y, a->x);
}

MATHC_EXTERN_INLINE float vector2_angle(cvector a)
{
	return pvector2_angle(&a);
}

float pvector2_length_squared(cvector *a)
{
	return a->x * a->x + a->y * a->y;
}

MATHC_EXTERN_INLINE float vector2_length_squared(cvector a)
{
	return pvector2_length_squared(&a);
}

float pvector2_length(cvector *a)
{
	return sqrtf(a->x * a->x + a->y * a->y);
}

MATHC_EXTERN_INLINE float vector2_length(cvector a)
{
	return pvector2_length(&a);
}

void pvector2_normalize(cvector *a, cvector *result)
{
	float length = a->x * a->x + a->y * a->y;
	if (length != 0.0f) {
		length = sqrtf(length);
		result->x = a->x / length;
		result->y = a->y / length;
	} else {
		result->x = 0.0f;
		result->y = 0.0f;
	}
}

MATHC_EXTERN_INLINE cvector vector2_normalize(cvector a)
{
	cvector result;
	pvector2_normalize(&a, &result);
	return result;
}

void pvector2_slide(cvector *a, cvector *normal, cvector *result)
{
	float d = pvector2_dot(a, normal);
	result->x = a->x - normal->x * d;
	result->y = a->y - normal->y * d;
}

MATHC_EXTERN_INLINE cvector vector2_slide(cvector a, cvector normal)
{
	cvector result;
	pvector2_slide(&a, &normal, &result);
	return result;
}

void pvector2_reflect(cvector *a, cvector *normal, cvector *result)
{
	float d = 2.0f * pvector2_dot(a, normal);
	result->x = a->x - normal->x * d;
	result->y = a->y - normal->y * d;
}

MATHC_EXTERN_INLINE cvector vector2_reflect(cvector a, cvector normal)
{
	cvector result;
	pvector2_reflect(&a, &normal, &result);
	return result;
}

void pvector2_tangent(cvector *a, cvector *result)
{
	result->x = a->y;
	result->y = -a->x;
}

MATHC_EXTERN_INLINE cvector vector2_tangent(cvector a)
{
	cvector result;
	pvector2_tangent(&a, &result);
	return result;
}

void pvector2_rotate(cvector *a, float angle, cvector *result)
{
	float cs = cosf(angle);
	float sn = sinf(angle);
	result->x = a->x * cs - a->y * sn;
	result->y = a->x * sn + a->y * cs;
}

MATHC_EXTERN_INLINE cvector vector2_rotate(cvector a, float angle)
{
	cvector result;
	pvector2_rotate(&a, angle, &result);
	return result;
}

float pvector2_distance_to(cvector *a, cvector *b)
{
	return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

MATHC_EXTERN_INLINE float vector2_distance_to(cvector a, cvector b)
{
	return pvector2_distance_to(&a, &b);
}

float pvector2_distance_squared_to(cvector *a, cvector *b)
{
	return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

MATHC_EXTERN_INLINE float vector2_distance_squared_to(cvector a, cvector b)
{
	return pvector2_distance_squared_to(&a, &b);
}

void pvector2_linear_interpolation(cvector *a, cvector *b, float p, cvector *result)
{
	result->x = a->x + (b->x - a->x) * p;
	result->y = a->y + (b->y - a->y) * p;
}

MATHC_EXTERN_INLINE cvector vector2_linear_interpolation(cvector a, cvector b, float p)
{
	cvector result;
	pvector2_linear_interpolation(&a, &b, p, &result);
	return result;
}

/* Vector 3D */
cvector to_vector3(float x, float y, float z)
{
	cvector result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 1.0f;
	return result;
}

void pvector3_add(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
}

MATHC_EXTERN_INLINE cvector vector3_add(cvector a, cvector b)
{
	cvector result;
	pvector3_add(&a, &b, &result);
	return result;
}

void pvector3_subtract(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
}

MATHC_EXTERN_INLINE cvector vector3_subtract(cvector a, cvector b)
{
	cvector result;
	pvector3_subtract(&a, &b, &result);
	return result;
}

void pvector3_scale(cvector *a, float scale, cvector *result)
{
	result->x = a->x * scale;
	result->y = a->y * scale;
	result->z = a->z * scale;
}

MATHC_EXTERN_INLINE cvector vector3_scale(cvector a, float scale)
{
	cvector result;
	pvector3_scale(&a, scale, &result);
	return result;
}

void pvector3_multiply(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x * b->x;
	result->y = a->y * b->y;
	result->z = a->z * b->z;
}

MATHC_EXTERN_INLINE cvector vector3_multiply(cvector a, cvector b)
{
	cvector result;
	pvector3_multiply(&a, &b, &result);
	return result;
}

void pvector3_divide(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x / b->x;
	result->y = a->y / b->y;
	result->z = a->z / b->z;
}

MATHC_EXTERN_INLINE cvector vector3_divide(cvector a, cvector b)
{
	cvector result;
	pvector3_divide(&a, &b, &result);
	return result;
}

void pvector3_negative(cvector *a, cvector *result)
{
	result->x = -a->x;
	result->y = -a->y;
	result->z = -a->z;
}

MATHC_EXTERN_INLINE cvector vector3_negative(cvector a)
{
	cvector result;
	pvector3_negative(&a, &result);
	return result;
}

void pvector3_abs(cvector *a, cvector *result)
{
	result->x = fabsf(a->x);
	result->y = fabsf(a->y);
	result->z = fabsf(a->z);
}

MATHC_EXTERN_INLINE cvector vector3_abs(cvector a)
{
	cvector result;
	pvector3_abs(&a, &result);
	return result;
}

void pvector3_floor(cvector *a, cvector *result)
{
	result->x = floorf(a->x);
	result->y = floorf(a->y);
	result->z = floorf(a->z);
}

MATHC_EXTERN_INLINE cvector vector3_floor(cvector a)
{
	cvector result;
	pvector3_floor(&a, &result);
	return result;
}

void pvector3_ceil(cvector *a, cvector *result)
{
	result->x = ceilf(a->x);
	result->y = ceilf(a->y);
	result->z = ceilf(a->z);
}

MATHC_EXTERN_INLINE cvector vector3_ceil(cvector a)
{
	cvector result;
	pvector3_ceil(&a, &result);
	return result;
}

void pvector3_round(cvector *a, cvector *result)
{
	result->x = roundf(a->x);
	result->y = roundf(a->y);
	result->z = roundf(a->z);
}

MATHC_EXTERN_INLINE cvector vector3_round(cvector a)
{
	cvector result;
	pvector3_round(&a, &result);
	return result;
}

void pvector3_max(cvector *a, cvector *b, cvector *result)
{
	result->x = fmaxf(a->x, b->x);
	result->y = fmaxf(a->y, b->y);
	result->z = fmaxf(a->z, b->z);
}

MATHC_EXTERN_INLINE cvector vector3_max(cvector a, cvector b)
{
	cvector result;
	pvector3_max(&a, &b, &result);
	return result;
}

void pvector3_min(cvector *a, cvector *b, cvector *result)
{
	result->x = fminf(a->x, b->x);
	result->y = fminf(a->y, b->y);
	result->z = fminf(a->z, b->z);
}

MATHC_EXTERN_INLINE cvector vector3_min(cvector a, cvector b)
{
	cvector result;
	pvector3_min(&a, &b, &result);
	return result;
}

float pvector3_dot(cvector *a, cvector *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

MATHC_EXTERN_INLINE float vector3_dot(cvector a, cvector b)
{
	return pvector3_dot(&a, &b);
}

void pvector3_cross(cvector *a, cvector *b, cvector *result)
{
	result->x = a->y * b->z - a->z * b->y;
	result->y = a->z * b->x - a->x * b->z;
	result->z = a->x * b->y - a->y * b->x;
}

MATHC_EXTERN_INLINE cvector vector3_cross(cvector a, cvector b)
{
	cvector result;
	pvector3_cross(&a, &b, &result);
	return result;
}

float pvector3_length_squared(cvector *a)
{
	return a->x * a->x + a->y * a->y + a->z * a->z;
}

MATHC_EXTERN_INLINE float vector3_length_squared(cvector a)
{
	return pvector3_length_squared(&a);
}

float pvector3_length(cvector *a)
{
	return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
}

MATHC_EXTERN_INLINE float vector3_length(cvector a)
{
	return pvector3_length(&a);
}

void pvector3_normalize(cvector *a, cvector *result)
{
	float length = a->x * a->x + a->y * a->y + a->z * a->z;
	if (length != 0.0f) {
		length = sqrtf(length);
		result->x = a->x / length;
		result->y = a->y / length;
		result->z = a->z / length;
	} else {
		result->x = 0.0f;
		result->y = 0.0f;
		result->z = 0.0f;
	}
}

MATHC_EXTERN_INLINE cvector vector3_normalize(cvector a)
{
	cvector result;
	pvector3_normalize(&a, &result);
	return result;
}

void pvector3_slide(cvector *a, cvector *normal, cvector *result)
{
	float d = pvector3_dot(a, normal);
	result->x = a->x - normal->x * d;
	result->y = a->y - normal->y * d;
	result->y = a->z - normal->z * d;
}

MATHC_EXTERN_INLINE cvector vector3_slide(cvector a, cvector normal)
{
	cvector result;
	pvector3_slide(&a, &normal, &result);
	return result;
}

void pvector3_reflect(cvector *a, cvector *normal, cvector *result)
{
	float d = 2.0f * pvector3_dot(a, normal);
	result->x = a->x - normal->x * d;
	result->y = a->y - normal->y * d;
	result->z = a->z - normal->z * d;
}

MATHC_EXTERN_INLINE cvector vector3_reflect(cvector a, cvector normal)
{
	cvector result;
	pvector3_reflect(&a, &normal, &result);
	return result;
}

float pvector3_distance_to(cvector *a, cvector *b)
{
	return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
}

MATHC_EXTERN_INLINE float vector3_distance_to(cvector a, cvector b)
{
	return pvector3_distance_to(&a, &b);
}

float pvector3_distance_squared_to(cvector *a, cvector *b)
{
	return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z);
}

MATHC_EXTERN_INLINE float vector3_distance_squared_to(cvector a, cvector b)
{
	return pvector3_distance_squared_to(&a, &b);
}

void pvector3_linear_interpolation(cvector *a, cvector *b, float p, cvector *result)
{
	result->x = a->x + (b->x - a->x) * p;
	result->y = a->y + (b->y - a->y) * p;
	result->z = a->z + (b->z - a->z) * p;
}

MATHC_EXTERN_INLINE cvector vector3_linear_interpolation(cvector a, cvector b, float p)
{
	cvector result;
	pvector3_linear_interpolation(&a, &b, p, &result);
	return result;
}

/* Quaternion */
cvector to_quaternion(float x, float y, float z, float w)
{
	cvector result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

void pquaternion_add(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	result->w = a->w + b->w;
}

MATHC_EXTERN_INLINE cvector quaternion_add(cvector a, cvector b)
{
	cvector result;
	pquaternion_add(&a, &b, &result);
	return result;
}

void pquaternion_subtract(cvector *a, cvector *b, cvector *result)
{
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->y = a->z - b->z;
	result->y = a->w - b->w;
}

MATHC_EXTERN_INLINE cvector quaternion_subtract(cvector a, cvector b)
{
	cvector result;
	pquaternion_subtract(&a, &b, &result);
	return result;
}

void pquaternion_scale(cvector *a, float scale, cvector *result)
{
	result->x = a->x * scale;
	result->y = a->y * scale;
	result->z = a->z * scale;
	result->w = a->w * scale;
}

MATHC_EXTERN_INLINE cvector quaternion_scale(cvector a, float scale)
{
	cvector result;
	pquaternion_scale(&a, scale, &result);
	return result;
}

void pquaternion_multiply(cvector *a, cvector *b, cvector *result)
{
	result->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
	result->x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
	result->y = a->w * b->y + a->y * b->w + a->z * b->x - a->x * b->z;
	result->z = a->w * b->z + a->z * b->w + a->x * b->y - a->y * b->x;
}

MATHC_EXTERN_INLINE cvector quaternion_multiply(cvector a, cvector b)
{
	cvector result;
	pquaternion_multiply(&a, &b, &result);
	return result;
}

void pquaternion_divide(cvector *a, cvector *b, cvector *result)
{
	float x = a->x;
	float y = a->y;
	float z = a->z;
	float w = a->w;
	float n1 = b->x * b->x + b->y * b->y + b->z * b->z + b->w * b->w;
	float n2 = 1.0f / n1;
	float n3 = -b->x * n2;
	float n4 = -b->y * n2;
	float n5 = -b->z * n2;
	float n6 = b->w * n2;
	float n7 = y * n5 - z * n4;
	float n8 = z * n3 - x * n5;
	float n9 = x * n4 - y * n3;
	float n10 = x * n3 + y * n4 + z * n5;
	result->x = x * n6 + n3 * w + n7;
	result->y = y * n6 + n4 * w + n8;
	result->z = z * n6 + n5 * w + n9;
	result->w = w * n6 - n10;
}

MATHC_EXTERN_INLINE cvector quaternion_divide(cvector a, cvector b)
{
	cvector result;
	pquaternion_divide(&a, &b, &result);
	return result;
}

void pquaternion_negative(cvector *a, cvector *result)
{
	result->x = -a->x;
	result->y = -a->y;
	result->z = -a->z;
	result->w = -a->w;
}

MATHC_EXTERN_INLINE cvector quaternion_negative(cvector a)
{
	cvector result;
	pquaternion_negative(&a, &result);
	return result;
}

void pquaternion_abs(cvector *a, cvector *result)
{
	result->x = fabsf(a->x);
	result->y = fabsf(a->y);
	result->z = fabsf(a->z);
	result->w = fabsf(a->w);
}

MATHC_EXTERN_INLINE cvector quaternion_abs(cvector a)
{
	cvector result;
	pquaternion_abs(&a, &result);
	return result;
}

void pquaternion_floor(cvector *a, cvector *result)
{
	result->x = floorf(a->x);
	result->y = floorf(a->y);
	result->z = floorf(a->z);
	result->w = floorf(a->w);
}

MATHC_EXTERN_INLINE cvector quaternion_floor(cvector a)
{
	cvector result;
	pquaternion_floor(&a, &result);
	return result;
}

void pquaternion_ceil(cvector *a, cvector *result)
{
	result->x = ceilf(a->x);
	result->y = ceilf(a->y);
	result->z = ceilf(a->z);
	result->w = ceilf(a->w);
}

MATHC_EXTERN_INLINE cvector quaternion_ceil(cvector a)
{
	cvector result;
	pquaternion_ceil(&a, &result);
	return result;
}

void pquaternion_round(cvector *a, cvector *result)
{
	result->x = roundf(a->x);
	result->y = roundf(a->y);
	result->z = roundf(a->z);
	result->w = roundf(a->w);
}

MATHC_EXTERN_INLINE cvector quaternion_round(cvector a)
{
	cvector result;
	pquaternion_round(&a, &result);
	return result;
}

void pquaternion_max(cvector *a, cvector *b, cvector *result)
{
	result->x = fmaxf(a->x, b->x);
	result->y = fmaxf(a->y, b->y);
	result->z = fmaxf(a->z, b->z);
	result->w = fmaxf(a->w, b->w);
}

MATHC_EXTERN_INLINE cvector quaternion_max(cvector a, cvector b)
{
	cvector result;
	pquaternion_max(&a, &b, &result);
	return result;
}

void pquaternion_min(cvector *a, cvector *b, cvector *result)
{
	result->x = fminf(a->x, b->x);
	result->y = fminf(a->y, b->y);
	result->z = fminf(a->z, b->z);
	result->w = fminf(a->w, b->w);
}

MATHC_EXTERN_INLINE cvector quaternion_min(cvector a, cvector b)
{
	cvector result;
	pquaternion_min(&a, &b, &result);
	return result;
}

float pquaternion_dot(cvector *a, cvector *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

MATHC_EXTERN_INLINE float quaternion_dot(cvector a, cvector b)
{
	return pquaternion_dot(&a, &b);
}

float pquaternion_angle(cvector *a, cvector *b)
{
	float s = sqrtf(pquaternion_length_squared(a) * pquaternion_length_squared(b));
	return acosf(pquaternion_dot(a, b) / s);
}

MATHC_EXTERN_INLINE float quaternion_angle(cvector a, cvector b)
{
	return pquaternion_angle(&a, &b);
}

void pquaternion_inverse(cvector *a, cvector *result)
{
	float n1 = a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w;
	float n2 = 1.0f / n1;
	result->x = -a->x * n2;
	result->y = -a->y * n2;
	result->z = -a->z * n2;
	result->w = a->w * n2;
}

MATHC_EXTERN_INLINE cvector quaternion_inverse(cvector a)
{
	cvector result;
	pquaternion_inverse(&a, &result);
	return result;
}

float pquaternion_length_squared(cvector *a)
{
	return a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w;
}

MATHC_EXTERN_INLINE float quaternion_length_squared(cvector a)
{
	return pquaternion_length_squared(&a);
}

float pquaternion_length(cvector *a)
{
	return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
}

MATHC_EXTERN_INLINE float quaternion_length(cvector a)
{
	return pquaternion_length(&a);
}

void pquaternion_normalize(cvector *a, cvector *result)
{
	float n = 1.0f / pquaternion_length(a);
	result->x = a->x * n;
	result->y = a->y * n;
	result->z = a->z * n;
	result->w = a->w * n;
}

MATHC_EXTERN_INLINE cvector quaternion_normalize(cvector a)
{
	cvector result;
	pquaternion_normalize(&a, &result);
	return result;
}

void pquaternion_conjugate(cvector *a, cvector *result)
{
	result->x = -a->x;
	result->y = -a->y;
	result->z = -a->z;
	result->w = a->w;
}

MATHC_EXTERN_INLINE cvector quaternion_conjugate(cvector a)
{
	cvector result;
	pquaternion_conjugate(&a, &result);
	return result;
}

void pquaternion_power(cvector *a, float exponent, cvector *result)
{
	if (fabsf(a->w) < 0.9999f) {
		float alpha = acosf(a->w);
		float new_alpha = alpha * exponent;
		float s = sinf(new_alpha) / sinf(alpha);
		result->x = result->x * s;
		result->y = result->y * s;
		result->z = result->z * s;
		result->w = cosf(new_alpha);
	} else {
		result->x = a->x;
		result->y = a->y;
		result->z = a->z;
		result->w = a->w;
	}
}

MATHC_EXTERN_INLINE cvector quaternion_power(cvector a, float exponent)
{
	cvector result;
	pquaternion_power(&a, exponent, &result);
	return result;
}

void pquaternion_axis_angle(cvector *a, float angle, cvector *result)
{
	float half = angle * 0.5f;
	float s = sinf(half);
	float c = cosf(half);
	result->x = a->x * s;
	result->y = a->y * s;
	result->z = a->z * s;
	result->w = c;
}

MATHC_EXTERN_INLINE cvector quaternion_axis_angle(cvector a, float angle)
{
	cvector result;
	pquaternion_axis_angle(&a, angle, &result);
	return result;
}

void pquaternion_rotation_matrix(cmatrix *m, cvector *result)
{
	float sr;
	float half;
	float scale = m->m11 + m->m22 + m->m33;
	if (scale > 0.0f) {
		sr = sqrtf(scale + 1.0f);
		result->w = sr * 0.5f;
		sr = 0.5f / sr;
		result->x = (m->m23 - m->m32) * sr;
		result->y = (m->m31 - m->m13) * sr;
		result->z = (m->m12 - m->m21) * sr;
	} else if ((m->m11 >= m->m22) && (m->m11 >= m->m33)) {
		sr = sqrtf(1.0f + m->m11 - m->m22 - m->m33);
		half = 0.5f / sr;
		result->x = 0.5f * sr;
		result->y = (m->m12 + m->m21) * half;
		result->z = (m->m13 + m->m31) * half;
		result->w = (m->m23 - m->m32) * half;
	} else if (m->m22 > m->m33) {
		sr = sqrtf(1.0f + m->m22 - m->m11 - m->m33);
		half = 0.5f / sr;
		result->x = (m->m21 + m->m12) * half;
		result->y = 0.5f * sr;
		result->z = (m->m32 + m->m23) * half;
		result->w = (m->m31 - m->m13) * half;
	} else {
		sr = sqrtf(1.0f + m->m33 - m->m11 - m->m22);
		half = 0.5f / sr;
		result->x = (m->m31 + m->m13) * half;
		result->y = (m->m32 + m->m23) * half;
		result->z = 0.5f * sr;
		result->w = (m->m12 - m->m21) * half;
	}
}

MATHC_EXTERN_INLINE cvector quaternion_rotation_matrix(cmatrix m)
{
	cvector result;
	pquaternion_rotation_matrix(&m, &result);
	return result;
}

void pquaternion_yaw_pitch_roll(float yaw, float pitch, float roll, cvector *result)
{
	float half_roll = roll * 0.5f;
	float half_pitch = pitch * 0.5f;
	float half_yaw = yaw * 0.5f;
	float sin_roll = sinf(half_roll);
	float cos_roll = cosf(half_roll);
	float sin_pitch = sinf(half_pitch);
	float cos_pitch = cosf(half_pitch);
	float sin_yaw = sinf(half_yaw);
	float cos_yaw = cosf(half_yaw);
	result->x = (cos_yaw * sin_pitch * cos_roll) + (sin_yaw * cos_pitch * sin_roll);
	result->y = (sin_yaw * cos_pitch * cos_roll) - (cos_yaw * sin_pitch * sin_roll);
	result->z = (cos_yaw * cos_pitch * sin_roll) - (sin_yaw * sin_pitch * cos_roll);
	result->w = (cos_yaw * cos_pitch * cos_roll) + (sin_yaw * sin_pitch * sin_roll);
}

MATHC_EXTERN_INLINE cvector quaternion_yaw_pitch_roll(float yaw, float pitch, float roll)
{
	cvector result;
	pquaternion_yaw_pitch_roll(yaw, pitch, roll, &result);
	return result;
}

void pquaternion_linear_interpolation(cvector *a, cvector *b, float p, cvector *result)
{
	result->x = a->x + (b->x - a->x) * p;
	result->y = a->y + (b->y - a->y) * p;
	result->z = a->z + (b->z - a->z) * p;
	result->w = a->w + (b->w - a->w) * p;
}

MATHC_EXTERN_INLINE cvector quaternion_linear_interpolation(cvector a, cvector b, float p)
{
	cvector result;
	pquaternion_linear_interpolation(&a, &b, p, &result);
	return result;
}

void pquaternion_spherical_linear_interpolation(cvector *a, cvector *b, float p, cvector *result)
{
	cvector tmp_a = *a;
	cvector tmp_b = *b;
	float cos_theta = pquaternion_dot(a, b);
	float k0;
	float k1;
	/* Take shortest arc */
	if (cos_theta < 0.0f) {
		pquaternion_negative(&tmp_b, &tmp_b);
		cos_theta = -cos_theta;
	}
	/* Check if quaternions are close */
	if (cos_theta > 0.9999f) {
		/* Use linear interpolation */
		k0 = 1.0f - p;
		k1 = p;
	} else {
		float theta = acosf(cos_theta);
		float sin_theta = sinf(theta);
		k0 = sinf((1.f - p) * theta) / sin_theta;
		k1 = sinf(p * theta) / sin_theta;
	}
	result->x = tmp_a.x * k0 + tmp_b.x * k1;
	result->y = tmp_a.y * k0 + tmp_b.y * k1;
	result->z = tmp_a.z * k0 + tmp_b.z * k1;
	result->w = tmp_a.w * k0 + tmp_b.w * k1;
}

MATHC_EXTERN_INLINE cvector quaternion_spherical_linear_interpolation(cvector a, cvector b, float p)
{
	cvector result;
	pquaternion_spherical_linear_interpolation(&a, &b, p, &result);
	return result;
}

/* Matrix */
void pmatrix_identity(cmatrix *result)
{
	result->m11 = 1.0f;
	result->m12 = 0.0f;
	result->m13 = 0.0f;
	result->m14 = 0.0f;
	result->m21 = 0.0f;
	result->m22 = 1.0f;
	result->m23 = 0.0f;
	result->m24 = 0.0f;
	result->m31 = 0.0f;
	result->m32 = 0.0f;
	result->m33 = 1.0f;
	result->m34 = 0.0f;
	result->m41 = 0.0f;
	result->m42 = 0.0f;
	result->m43 = 0.0f;
	result->m44 = 1.0f;
}

MATHC_EXTERN_INLINE cmatrix matrix_identity(void)
{
	cmatrix result;
	pmatrix_identity(&result);
	return result;
}

void pmatrix_ortho(float l, float r, float b, float t, float n, float f, cmatrix *result)
{
	pmatrix_identity(result);
	result->m11 = 2.0f / (r - l);
	result->m22 = 2.0f / (b - t);
	result->m33 = 1.0f / (n - f);
	result->m41 = (l + r) / (l - r);
	result->m42 = (t + b) / (b - t);
	result->m43 = n / (n - f);
}

MATHC_EXTERN_INLINE cmatrix matrix_ortho(float l, float r, float b, float t, float n, float f)
{
	cmatrix result;
	pmatrix_ortho(l, r, b, t, n, f, &result);
	return result;
}

void pmatrix_perspective(float y_fov, float aspect, float n, float f, cmatrix *result)
{
	pmatrix_identity(result);
	/* Right-handed */
	float a = 1.0f / tanf(y_fov * 0.5f);
	result->m11 = a / aspect;
	result->m22 = a;
	result->m33 = f / (n - f);
	result->m34 = -1.0f;
	result->m43 = (n * f) / (n - f);
}

MATHC_EXTERN_INLINE cmatrix matrix_perspective(float y_fov, float aspect, float n, float f)
{
	cmatrix result;
	pmatrix_perspective(y_fov, aspect, n, f, &result);
	return result;
}

void pmatrix_rotation_x(float angle, cmatrix *result)
{
	pmatrix_identity(result);
	float c = cosf(angle);
	float s = sinf(angle);
	result->m22 = c;
	result->m23 = -s;
	result->m32 = s;
	result->m33 = c;
}

MATHC_EXTERN_INLINE cmatrix matrix_rotation_x(float angle)
{
	cmatrix result;
	pmatrix_rotation_x(angle, &result);
	return result;
}

void pmatrix_rotation_y(float angle, cmatrix *result)
{
	pmatrix_identity(result);
	float c = cosf(angle);
	float s = sinf(angle);
	result->m11 = c;
	result->m13 = s;
	result->m31 = -s;
	result->m33 = c;
}

MATHC_EXTERN_INLINE cmatrix matrix_rotation_y(float angle)
{
	cmatrix result;
	pmatrix_rotation_y(angle, &result);
	return result;
}

void pmatrix_rotation_z(float angle, cmatrix *result)
{
	pmatrix_identity(result);
	float c = cosf(angle);
	float s = sinf(angle);
	result->m11 = c;
	result->m12 = -s;
	result->m21 = s;
	result->m22 = c;
}

MATHC_EXTERN_INLINE cmatrix matrix_rotation_z(float angle)
{
	cmatrix result;
	pmatrix_rotation_z(angle, &result);
	return result;
}

void pmatrix_rotation_axis(cvector *a, float angle, cmatrix *result)
{
	pmatrix_identity(result);
	float c = cosf(angle);
	float s = sinf(angle);
	float n1 = a->x * a->x;
	float n2 = a->y * a->y;
	float n3 = a->z * a->z;
	float n4 = a->x * a->y;
	float n5 = a->x * a->z;
	float n6 = a->y * a->z;
	result->m11 = n1 + (c * (1.0f - n1));
	result->m12 = (n4 - (c * n4)) + (s * a->z);
	result->m13 = (n5 - (c * n5)) - (s * a->y);
	result->m21 = (n4 - (c * n4)) - (s * a->z);
	result->m22 = n2 + (c * (1.0f - n2));
	result->m23 = (n6 - (c * n6)) + (s * a->x);
	result->m31 = (n5 - (c * n5)) + (s * a->y);
	result->m32 = (n6 - (c * n6)) - (s * a->x);
	result->m33 = n3 + (c * (1.0f - n3));
}

MATHC_EXTERN_INLINE cmatrix matrix_rotation_axis(cvector a, float angle)
{
	cmatrix result;
	pmatrix_rotation_axis(&a, angle, &result);
	return result;
}

void pmatrix_rotation_quaternion(cvector *q, cmatrix *result)
{
	pmatrix_identity(result);
	float n9 = q->x * q->x;
	float n8 = q->y * q->y;
	float n7 = q->z * q->z;
	float n6 = q->x * q->y;
	float n5 = q->z * q->w;
	float n4 = q->z * q->x;
	float n3 = q->y * q->w;
	float n2 = q->y * q->z;
	float n1 = q->x * q->w;
	result->m11 = 1.0f - 2.0f * (n8 + n7);
	result->m12 = 2.0f * (n6 + n5);
	result->m13 = 2.0f * (n4 - n3);
	result->m21 = 2.0f * (n6 - n5);
	result->m22 = 1.0f - 2.0f * (n7 + n9);
	result->m23 = 2.0f * (n2 + n1);
	result->m31 = 2.0f * (n4 + n3);
	result->m32 = 2.0f * (n2 - n1);
	result->m33 = 1.0f - 2.0f * (n8 + n9);
}

MATHC_EXTERN_INLINE cmatrix matrix_rotation_quaternion(cvector q)
{
	cmatrix result;
	pmatrix_rotation_quaternion(&q, &result);
	return result;
}

void pmatrix_look_at(cvector *pos, cvector *target, cvector *up, cmatrix *result)
{
	cvector v1;
	cvector v2;
	cvector v3;
	pmatrix_identity(result);
	pvector3_subtract(pos, target, &v1);
	pvector3_normalize(&v1, &v1);
	pvector3_cross(up, &v1, &v2);
	pvector3_normalize(&v2, &v2);
	pvector3_cross(&v1, &v2, &v3);
	result->m11 = v2.x;
	result->m12 = v3.x;
	result->m13 = v1.x;
	result->m21 = v2.y;
	result->m22 = v3.y;
	result->m23 = v1.y;
	result->m31 = v2.z;
	result->m32 = v3.z;
	result->m33 = v1.z;
	result->m41 = -pvector3_dot(&v2, pos);
	result->m42 = -pvector3_dot(&v3, pos);
	result->m43 = -pvector3_dot(&v1, pos);
}

MATHC_EXTERN_INLINE cmatrix matrix_look_at(cvector pos, cvector target, cvector up)
{
	cmatrix result;
	pmatrix_look_at(&pos, &target, &up, &result);
	return result;
}

void pmatrix_scale(cvector *v, cmatrix *result)
{
	pmatrix_identity(result);
	result->m11 = v->x;
	result->m22 = v->y;
	result->m33 = v->z;
}

MATHC_EXTERN_INLINE cmatrix matrix_scale(cvector v)
{
	cmatrix result;
	pmatrix_scale(&v, &result);
	return result;
}

void pmatrix_get_scale(cmatrix *m, cvector *result)
{
	result->x = m->m11;
	result->y = m->m22;
	result->z = m->m33;
}

MATHC_EXTERN_INLINE cvector matrix_get_scale(cmatrix m)
{
	cvector result;
	pmatrix_get_scale(&m, &result);
	return result;
}

void pmatrix_translation(cvector *v, cmatrix *result)
{
	pmatrix_identity(result);
	result->m14 = v->x;
	result->m24 = v->y;
	result->m34 = v->z;
}

MATHC_EXTERN_INLINE cmatrix matrix_translation(cvector v)
{
	cmatrix result;
	pmatrix_translation(&v, &result);
	return result;
}

void pmatrix_get_translation(cmatrix *m, cvector *result)
{
	result->x = m->m14;
	result->y = m->m24;
	result->z = m->m34;
}

MATHC_EXTERN_INLINE cvector matrix_get_translation(cmatrix m)
{
	cvector result;
	pmatrix_get_translation(&m, &result);
	return result;
}

void pmatrix_negative(cmatrix *m, cmatrix *result)
{
	result->m11 = -m->m11;
	result->m12 = -m->m12;
	result->m13 = -m->m13;
	result->m14 = -m->m14;
	result->m21 = -m->m21;
	result->m22 = -m->m22;
	result->m23 = -m->m23;
	result->m24 = -m->m24;
	result->m31 = -m->m31;
	result->m32 = -m->m32;
	result->m33 = -m->m33;
	result->m34 = -m->m34;
	result->m41 = -m->m41;
	result->m42 = -m->m42;
	result->m43 = -m->m43;
	result->m44 = -m->m44;
}

MATHC_EXTERN_INLINE cmatrix matrix_negative(cmatrix m)
{
	cmatrix result;
	pmatrix_negative(&m, &result);
	return result;
}

void pmatrix_multiply(cmatrix *m, float s, cmatrix *result)
{
	result->m11 = m->m11 * s;
	result->m12 = m->m12 * s;
	result->m13 = m->m13 * s;
	result->m14 = m->m14 * s;
	result->m21 = m->m21 * s;
	result->m22 = m->m22 * s;
	result->m23 = m->m23 * s;
	result->m24 = m->m24 * s;
	result->m31 = m->m31 * s;
	result->m32 = m->m32 * s;
	result->m33 = m->m33 * s;
	result->m34 = m->m34 * s;
	result->m41 = m->m41 * s;
	result->m42 = m->m42 * s;
	result->m43 = m->m43 * s;
	result->m44 = m->m44 * s;
}

MATHC_EXTERN_INLINE cmatrix matrix_multiply(cmatrix m, float s)
{
	cmatrix result;
	pmatrix_multiply(&m, s, &result);
	return result;
}

void pmatrix_multiply_matrix(cmatrix *a, cmatrix *b, cmatrix *result)
{
	result->m11 = a->m11 * b->m11 + a->m12 * b->m21 + a->m13 * b->m31 + a->m14 * b->m41;
	result->m12 = a->m11 * b->m12 + a->m12 * b->m22 + a->m13 * b->m32 + a->m14 * b->m42;
	result->m13 = a->m11 * b->m13 + a->m12 * b->m23 + a->m13 * b->m33 + a->m14 * b->m43;
	result->m14 = a->m11 * b->m14 + a->m12 * b->m24 + a->m13 * b->m34 + a->m14 * b->m44;
	result->m21 = a->m21 * b->m11 + a->m22 * b->m21 + a->m23 * b->m31 + a->m24 * b->m41;
	result->m22 = a->m21 * b->m12 + a->m22 * b->m22 + a->m23 * b->m32 + a->m24 * b->m42;
	result->m23 = a->m21 * b->m13 + a->m22 * b->m23 + a->m23 * b->m33 + a->m24 * b->m43;
	result->m24 = a->m21 * b->m14 + a->m22 * b->m24 + a->m23 * b->m34 + a->m24 * b->m44;
	result->m31 = a->m31 * b->m11 + a->m32 * b->m21 + a->m33 * b->m31 + a->m34 * b->m41;
	result->m32 = a->m31 * b->m12 + a->m32 * b->m22 + a->m33 * b->m32 + a->m34 * b->m42;
	result->m33 = a->m31 * b->m13 + a->m32 * b->m23 + a->m33 * b->m33 + a->m34 * b->m43;
	result->m34 = a->m31 * b->m14 + a->m32 * b->m24 + a->m33 * b->m34 + a->m34 * b->m44;
	result->m41 = a->m41 * b->m11 + a->m42 * b->m21 + a->m43 * b->m31 + a->m44 * b->m41;
	result->m42 = a->m41 * b->m12 + a->m42 * b->m22 + a->m43 * b->m32 + a->m44 * b->m42;
	result->m43 = a->m41 * b->m13 + a->m42 * b->m23 + a->m43 * b->m33 + a->m44 * b->m43;
	result->m44 = a->m41 * b->m14 + a->m42 * b->m24 + a->m43 * b->m34 + a->m44 * b->m44;
}

MATHC_EXTERN_INLINE cmatrix matrix_multiply_matrix(cmatrix a, cmatrix b)
{
	cmatrix result;
	pmatrix_multiply_matrix(&a, &b, &result);
	return result;
}

void pmatrix_multiply_f4(cmatrix *m, float *result)
{
	float v0 = result[0];
	float v1 = result[1];
	float v2 = result[2];
	float v3 = result[3];
	result[0] = (m->m11 * v0) + (m->m12 * v1) + (m->m13 * v2) + (m->m14 * v3);
	result[1] = (m->m21 * v0) + (m->m22 * v1) + (m->m23 * v2) + (m->m24 * v3);
	result[2] = (m->m31 * v0) + (m->m32 * v1) + (m->m33 * v2) + (m->m34 * v3);
	result[3] = (m->m41 * v0) + (m->m42 * v1) + (m->m43 * v2) + (m->m44 * v3);
}

MATHC_EXTERN_INLINE void matrix_multiply_f4(cmatrix m, float *result)
{
	pmatrix_multiply_f4(&m, result);
}

void pmatrix_to_array(cmatrix *m, float *result)
{
	result[0] = m->m11;
	result[1] = m->m12;
	result[2] = m->m13;
	result[3] = m->m14;
	result[4] = m->m21;
	result[5] = m->m22;
	result[6] = m->m23;
	result[7] = m->m24;
	result[8] = m->m31;
	result[9] = m->m32;
	result[10] = m->m33;
	result[11] = m->m34;
	result[12] = m->m41;
	result[13] = m->m42;
	result[14] = m->m43;
	result[15] = m->m44;
}

MATHC_EXTERN_INLINE void matrix_to_array(cmatrix m, float *result)
{
	pmatrix_to_array(&m, result);
}

/* Easing functions */
float quadratic_ease_in(float p)
{
	return p * p;
}

float quadratic_ease_out(float p)
{
	return -(p * (p - 2.0f));
}

float quadratic_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 2.0f * p * p;
	} else {
		f = (-2.0f * p * p) + (4.0f * p) - 1.0f;
	}
	return f;
}

float cubic_ease_in(float p)
{
	return p * p * p;
}

float cubic_ease_out(float p)
{
	float f = (p - 1.0f);
	return f * f * f + 1.0f;
}

float cubic_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 4.0f * p * p * p;
	} else {
		f = ((2.0f * p) - 2.0f);
		f = 0.5f * f * f * f + 1.0f;
	}
	return f;
}

float quartic_ease_in(float p)
{
	return p * p * p * p;
}

float quartic_ease_out(float p)
{
	float f = (p - 1.0f);
	return f * f * f * (1.0f - p) + 1.0f;
}

float quartic_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 8.0f * p * p * p * p;
	} else {
		f = (p - 1.0f);
		f = -8.0f * f * f * f * f + 1.0f;
	}
	return f;
}

float quintic_ease_in(float p)
{
	return p * p * p * p * p;
}

float quintic_ease_out(float p)
{
	float f = (p - 1.0f);
	return f * f * f * f * f + 1.0f;
}

float quintic_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 16.0f * p * p * p * p * p;
	} else {
		f = ((2.0f * p) - 2.0f);
		f =  0.5f * f * f * f * f * f + 1.0f;
	}
	return f;
}

float sine_ease_in(float p)
{
	return sinf((p - 1.0f) * M_PIF_2) + 1.0f;
}

float sine_ease_out(float p)
{
	return sinf(p * M_PIF_2);
}

float sine_ease_in_out(float p)
{
	return 0.5f * (1.0f - cosf(p * M_PIF));
}

float circular_ease_in(float p)
{
	return 1.0f - sqrtf(1.0f - (p * p));
}

float circular_ease_out(float p)
{
	return sqrtf((2.0f - p) * p);
}

float circular_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 0.5f * (1.0f - sqrtf(1.0f - 4.0f * (p * p)));
	} else {
		f = 0.5f * (sqrtf(-((2.0f * p) - 3.0f) * ((2.0f * p) - 1.0f)) + 1.0f);
	}
	return f;
}

float exponential_ease_in(float p)
{
	float f = p;
	if (p != 0.0f) {
		f = powf(2.0f, 10.0f * (p - 1.0f));
	}
	return f;
}

float exponential_ease_out(float p)
{
	float f = p;
	if (p != 1.0f) {
		f = 1 - powf(2.0f, -10.0f * p);
	}
	return f;
}

float exponential_ease_in_out(float p)
{
	float f = p;
	if (p == 0.0f || p == 1.0f) {
		f = p;
	} else if (p < 0.5f) {
		f = 0.5f * powf(2.0f, (20.0f * p) - 10.0f);
	} else {
		f = -0.5f * powf(2.0f, (-20.0f * p) + 10.0f) + 1.0f;
	}
	return f;
}

float elastic_ease_in(float p)
{
	return sinf(13.0f * M_PIF_2 * p) * powf(2.0f, 10.0f * (p - 1.0f));
}

float elastic_ease_out(float p)
{
	return sinf(-13.0f * M_PIF_2 * (p + 1.0f)) * powf(2.0f, -10.0f * p) + 1.0f;
}

float elastic_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 0.5f * sinf(13.0f * M_PIF_2 * (2.0f * p)) * powf(2.0f, 10.0f * ((2.0f * p) - 1.0f));
	} else {
		f = 0.5f * (sinf(-13.0f * M_PIF_2 * ((2.0f * p - 1.0f) + 1.0f)) * powf(2.0f, -10.0f * (2.0f * p - 1.0f)) + 2.0f);
	}
	return f;
}

float back_ease_in(float p)
{
	return p * p * p - p * sinf(p * M_PIF);
}

float back_ease_out(float p)
{
	float f = (1.0f - p);
	return 1.0f - (f * f * f - f * sinf(f * M_PIF));
}

float back_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 2.0f * p;
		f = 0.5f * (f * f * f - f * sinf(f * M_PIF));
	} else {
		f = (1.0f - (2.0f * p - 1.0f));
		f = 0.5f * (1.0f - (f * f * f - f * sinf(f * M_PIF))) + 0.5f;
	}
	return f;
}

float bounce_ease_in(float p)
{
	return 1.0f - bounce_ease_out(1.0f - p);
}

float bounce_ease_out(float p)
{
	float f = 0.0f;
	if (p < 4 / 11.0f) {
		f = (121 * p * p) / 16.0f;
	} else if (p < 8 / 11.0f) {
		f = (363 / 40.0f * p * p) - (99 / 10.0f * p) + 17 / 5.0f;
	} else if (p < 9 / 10.0f) {
		f = (4356 / 361.0f * p * p) - (35442 / 1805.0f * p) + 16061 / 1805.0f;
	} else {
		f = (54 / 5.0f * p * p) - (513 / 25.0f * p) + 268 / 25.0f;
	}
	return f;
}

float bounce_ease_in_out(float p)
{
	float f = 0.0f;
	if (p < 0.5f) {
		f = 0.5f * bounce_ease_in(p * 2.0f);
	} else {
		f = 0.5f * bounce_ease_out(p * 2.0f - 1.0f) + 0.5f;
	}
	return f;
}
