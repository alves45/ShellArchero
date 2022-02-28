//#include <stdint-gcc.h> Baseado nesta biblioteca
// Alterado os nomes para ficar semelhante a linguagem rust, pelo fato de serem tipos bem organizados (minha opinião)

#ifndef MY_TYPES

#define MY_TYPES 1
#ifdef __INT8_TYPE__
typedef __INT8_TYPE__ i8;
#endif
#ifdef __INT16_TYPE__
typedef __INT16_TYPE__ i16;
#endif
#ifdef __INT32_TYPE__
typedef __INT32_TYPE__ i32;
#endif
#ifdef __INT64_TYPE__
typedef __INT64_TYPE__ i64;
#endif
#ifdef __UINT8_TYPE__
typedef __UINT8_TYPE__ u8;
#endif
#ifdef __UINT16_TYPE__
typedef __UINT16_TYPE__ u16;
#endif
#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ u32;
#endif
#ifdef __UINT64_TYPE__
typedef __UINT64_TYPE__ u64;
#endif
typedef float f32;
typedef double f64;

#define u8MAX 255
#define u16MAX 65535
#define u32MAX 4294967295
#define u64MAX 18446744073709551615

#define u8MIN 0
#define u16MIN 0
#define u32MIN 0
#define u64MIN 0

#define i8MAX 127
#define i16MAX 32767
#define i32MAX 2147483647
#define i64MAX 18446744073709551615

#define i8MIN (-128)
#define i16MIN (-32768)
#define i32MIN (-2147483648)
#define i64MIN (-9223372036854775808)

#define f32MAX __FLT_MAX__
#define f32MIN __FLT_MIN__

#define _IMAGE_TYPE 1

typedef struct size
{
    u16 height;
    u16 width;
} size;

typedef struct pixel
{
    u8 r;
    u8 g;
    u8 b;
} pixel;
typedef struct image
{
    size size;
    pixel *pixels;
} image;

typedef struct position
{
    i16 x;
    i16 y;
} position;

typedef struct object
{
    u8 health;
    u8 speed;
    image *state;
    image *oldState;
    u8 damage;
    position posi;
    position oldPosi;
} object;

typedef struct map
{
    size s;
    pixel color;
} map;

#endif
