#ifndef MY_COMMON_H
#define MY_COMMON_H
#include <cstdlib>
#include <cstdio>
#include <inttypes.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <cassert>
#include <x86intrin.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdarg.h>

typedef uint8_t byte;
typedef unsigned int uint;
typedef uint8_t uint8;
using ptrdiff = std::ptrdiff_t;

struct BufferContext {
    uint32_t length = 0;
    uint32_t capacity = 0;
};
void* array_allocate_size(uint32_t count, size_t size);
void internal_array_free(void* array);
uint32_t array_length(void* array);
uint32_t array_capacity(void* array);


template <typename Type>
Type& array_get(Type* array, uint32_t index);

bool internal_array_grow(void** base, uint32_t count, size_t size);
bool internal_array_append(void** base, void* data, uint32_t count, size_t size);


template <typename Type>
bool array_push(Type*& array, const Type& data);

#define array_buffer_hdr(x) (((BufferContext*)x) - 1)
#define ARRAY_MIN_BUFFER_COUNT 16
#define array_allocate(type, count, allocator) \
(type*)array_allocate_size(count, sizeof(type) )

#define array_make( type ) \
array_allocate(type, ARRAY_MIN_BUFFER_COUNT )

#define array_free(x) internal_array_free(x), x = NULL
#define array_fits( array, n ) ( array_length( array ) + ( n ) <=  array_capacity( array )  )

#define array_append(x, y, c) \
(internal_array_append((void**)&x, y, c, sizeof(*x)))

// either array is null or invalid or index is out of range is asserted
template <typename Type>
Type& array_get(Type* array, uint32_t index) {
    assert((array) != 0);
    assert(array_buffer_hdr(array)->capacity >= array_buffer_hdr(array)->length);
    assert(index < array_buffer_hdr(array)->length);
    return array[index];
}


template <typename Type>
bool array_push(Type*& array, const Type& data) {
    if ( !array_fits( array, 1 )  ){
        internal_array_grow((void**)&array, 1, sizeof(Type));
    }

    array[array_buffer_hdr(array)->length++] = data;
    return true;
}
inline void* array_allocate_size(uint32_t count, size_t size){
    assert(size && count);  // invalid usage, *count* and *size* MUST not be 0
    assert(size <= (SIZE_MAX- sizeof(BufferContext)) / count);

    void *buff = NULL;
    internal_array_grow( &buff, count, size );
    return buff;
}

inline void internal_array_free(void* array) {
    if (array) {
        BufferContext* bfc = (BufferContext*)array - 1;
        free(bfc);
    }
}

inline uint32_t array_length(void* array) {
    if (!array)
        return 0;
    return array_buffer_hdr(array)->length;
}

inline uint32_t array_capacity(void* array) {
    if (!array)
        return 0;
    return array_buffer_hdr(array)->capacity;
}


#define IS_POW2( x ) ( ( x ) && !( ( x ) & ( ( x ) - 1 ) ) )

#define ALIGN_DOWN(n,a) ( ( ( n ) & ~(( a )-1) ) )
#define ALIGN_UP(n,a) ( ALIGN_DOWN(( n ) + ( a ) - 1,( a )) )
#define ALIGN_DOWN_PTR(p,a) ( (void *)ALIGN_DOWN( (uintptr_t)( p ),( a )) )
#define ALIGN_UP_PTR(p,a) ( (void *)ALIGN_UP((uintptr_t)( p ),(uintptr_t)( a )) ) 


#define MB_TO_BYTES(x) ( ( x ) * 1024 * 1024 )
typedef struct Arena {
  void **buff;
  size_t *buff_len;
  size_t *buff_capacity;
} Arena;


void *arena_alloc( Arena *arena, size_t size, size_t align );
Arena new_arena( void );
void arena_free( Arena * );
int read_text_file_to_buffer( const char *path, char **buffer );




typedef struct strHdr {
     size_t cap; // The total number of bytes the current buffer can hold ( not inc. size of struct )
     size_t len; // The length of the string in the buffer
     char str[0];
} strHdr;
#ifndef MAX
  #define MAX(x,y) ( ( ( x ) > ( y ) ) ? ( x ) : ( y ) )
#endif

#ifndef MIN
  #define MIN(x,y) ( ( ( x ) < ( y ) ) ? ( x ) : ( y ) )
#endif
enum { MIN_SIZE = 256 };

#define str_hdr(x) ( (strHdr *)( (char *)x  - offsetof( strHdr , str ) ) )
#define str_len(x) ( ( x )?( str_hdr(x)->len ):0 ) // the string length i.e. w/o NULL character
#define str_size(x)  ( ( x )?( str_hdr(x)->len + 1 )*sizeof(*x): 0 ) // the string size i.e w/ NULL character
#define str_cap(x) ( ( x )?str_hdr(x)->cap:0 )
#define str_free(x) ( free( str_hdr(x) ), x = NULL )
#define str_init(x) ( x = _init_string( x ) )
#define str_init_size( x, size ) ( x = _init_string_with_size( x, size ) )
#define str_append(x,y) ( x = _string_append(x,y) )
#define str_print(x,y,...) ( x = _string_print(x, y, __VA_ARGS__ ) )
#define str_append_print(x, y , ... ) ( x = _string_app_print( x, y , __VA_ARGS__ ) )
#define strn_append( x, n , y ) ( x = _strn_append( x, n , y ) )
//#define strn_app_print(x,n, y , ... ) ( x = _stringn_app_print( x,n, y , __VA_ARGS__ ) )
#define str_app_char( x, c ) ( x = _string_app_char( x, c ) )
#define str_insert_char(x,c,pos) ( (x) = _insert_char( x, c, pos ) ) 
#define str_delete_char_pos( x, pos ) ( _delete_char_pos(x, pos ) ) 
#define str_insert_str( x, y, pos ) ( ( x ) = _insert_string( x, y, pos ) )
#define str_delete_range( x, start, end ) ( ( x ) = string_delete_range( x, start, end ) )

char *_init_string( char *str );
char *_init_string_with_size( char *str, size_t size );
char *string_grow( strHdr *x, size_t n);
char *_string_append( char *x, const char *y );
char *_string_print( char *x, const char *fmt, ... );
char *_string_app_print( char *x, const char *fmt, ... );
char *_strn_append( char *dest, size_t n, char *src );
//char *_stringn_app_print( char *x, size_t n, const char *fmt, ... );
char *_string_app_char( char *x, char c ); // append a single character at the end of string
char *_insert_char( char *str, char c, size_t pos );
void _delete_char_pos(char *str, size_t pos );
char *_insert_string( char *x, char *y, int pos );
void str_test( void );

#endif