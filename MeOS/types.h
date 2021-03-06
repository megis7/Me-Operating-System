#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#else
#define bool uint8
#define true 1
#define false 0
#endif

typedef signed char int8;
typedef unsigned char uint8;

typedef signed short int16;
typedef unsigned short uint16;

typedef signed int int32;
typedef unsigned int uint32;

typedef signed long long int64;
typedef unsigned long long uint64;

typedef float float32;
typedef double float64;

typedef uint32 size_t;
typedef int32 ssize_t;

typedef uint32 error_t;

typedef uint8 BYTE;
typedef uint16 WORD;
typedef uint32 DWORD;
typedef uint64 QWORD;
typedef void   VOID;

typedef uint32 virtual_addr;
typedef uint32 physical_addr;

#define CHK_BIT(x, bit) ( ( (x) & (bit) ) == (bit) )

#define KB *1024
#define MB KB*1024
#define GB MB*1024

#define PTR *
#define REF &

#define NULL 0
#define INVALID_FD -1
#define MAX_IO (size_t)-1 - 1
#define INVALID_IO (size_t)-1

#define cast(type, param) ((type)param)

typedef uint8* va_list;

#define sz(arg_type) ( sizeof(arg_type) % 4 != 0 ? sizeof(arg_type) + 4 - sizeof(arg_type) % 4 : sizeof(arg_type) )

//#define va_start2(pointer, last_arg) (  pointer = ( (va_list)&last_arg + sizeof(last_arg) )  )
#define va_start(pointer, last_arg) (  pointer = ( (va_list)&last_arg + sz(last_arg) )  )
#define va_end(pointer) (  pointer = (va_list) 0x0  )

//#define va_arg(pointer, arg_type) (uint8 sz = 4 - sizeof(arg_type) % 4, pointer += sz, *((arg_type *)(pointer - sz)); )

//#define sz2(arg_type) (4 - sizeof(arg_type) % 4)
#define va_arg(pointer, arg_type) ( *(arg_type*)( (pointer += sz(arg_type)) - sz(arg_type) ) )

// returns the current instruction pointer
extern uint32 get_eip(void);

#ifdef __cplusplus
}
#endif

#endif