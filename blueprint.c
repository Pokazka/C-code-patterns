#include <location file / libs>
#include "location file"
#define NAME MAKRO value / ""
#define NAME FUNC(x) ((x)*(x))
#define NAME FUNC(a, b) ((a) > (b) ? (a) : (b))
#define NAME MAKRO/FUNC(..., ...) ...##... / #...
#define NAME func(...) NAME func(...)
#define NAME MAKRO NAME func(variable)
#define NAME MAKRO value
#define	CCP_VSIZE 16
#define	CCP_VMASK		((unsigned int)((1 << CCP_VSIZE) - 1))
#define	CCP_VERSION(v, r)	((unsigned int)((v << CCP_VSIZE) \
					       | (r & CCP_VMASK)))
// Makro zwracające wskaźnik do funkcji
#define URUCHOM_DLA(x) funkcja_docelowa
// Wywołanie w kodzie wygląda tak:
URUCHOM_DLA(x)(y); 
#define NAME MAKRO value/FUNC(..., ...) printf(..., __VA_ARGS__)
#define NAME MAKRO value/FUNC(..., ...) kprintf("... " ... "...", __FILE__, __LINE__, ##__VA_ARGS__)
#define NAME MAKRO value/FUNC(...) fprintf(..., __VA_ARGS__)
#define putchar(A) putc(A, stdout)

#define NAME FUNC(..., ...) do { \ ...; \ ...; \ ...; \ } while (...)
#undef NAME MAKRO value

#ifdef NAME MAKRO value
#ifndef NAME MAKRO value
#elifdef NAME MAKRO value
#elifndef NAME MAKRO value

#embed "location file" limit(...) prefix(..., ) suffix(, ...)
#embed <location file> limit(...) prefix(..., ) suffix(, ...)

#if condition
#elif condition
#else condition
#endif condition

#pragma GCC warning "..."
#pragma once
#pragma STDC FP_CONTRACT on-off-switch
#pragma STDC FENV_ACCESS on-off-switch
#pragma STDC FENV_DEC_ROUND dec-direction
#pragma STDC FENV_ROUND direction
#pragma STDC CX_LIMITED_RANGE on-off-switch

#error "comment"

#line 100

#warning "..." / ...

#define X defined(DEBUG)
#if defined(DEBUG)

#ifndef NAME MAKRO value
#define cbrt(X) _Generic((X), \
	long double: cbrtl, \
	default: cbrt, \
	float: cbrtf \
	)(X)
#endif

#define EMPTY
EMPTY # include <file.h>

#if __has_embed(__FILE__ ext::token(0xB055))
#define DESCRIPTION "Supports extended token embed parameter"
#else
#define DESCRIPTION "Does not support extended token embed parameter"
#endif

#if __has_c_attribute(fallthrough)
/* Standard attribute is available, use it. */
#define FALLTHROUGH [[fallthrough]]
#elif __has_c_attribute(vendor::fallthrough)
/* Vendor attribute is available, use it. */
#define FALLTHROUGH [[vendor::fallthrough]]
#else
/* Fallback implementation. */
#define FALLTHROUGH
#endif

#define identifier replacement-list new-line
#define identifier ( identifier-list(opt) )
replacement-list newline
#undef identifier newline

#define H2(X, Y, ...) __VA_OPT__(X ## Y,) __VA_ARGS__
#define H2(X, Y, ...) __VA_OPT__(X ## Y,) __VA_ARGS__(Z, X, ...)

#define F(...) f(0 __VA_OPT__(,) __VA_ARGS__)
#define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)
#define SDEF(sname, ...) S sname __VA_OPT__(= { __VA_ARGS__ })
#define EMP
F(a, b, c) // replaced by f(0, a, b, c)
F() // replaced by f(0)
F(EMP) // replaced by f(0)
G(a, b, c) // replaced by f(0, a, b, c)
G(a, ) // replaced by f(0, a)
G(a) // replaced by f(0, a)
SDEF(foo); // replaced by S foo;
SDEF(bar, 1, 2); // replaced by S bar = { 1, 2 };

#define hash_hash # ## #
#define mkstr(a) # a
#define in_between(a) mkstr(a)
#define join(c, d) in_between(c hash_hash d)
char p[] = join(x, y); // equivalent to
// char p[] = "x ## y";
join(x, y)
in_between(x hash_hash y)
in_between(x ## y)
mkstr(x ## y)
"x ## y"

#define f(a) a*g
#define g(a) f(a)
f(2)(9)
2*f(9)
2*9*g

#ifndef
#define
#endif

#ifdef
#define
#else
#define
#endif

#define __name(x) __phys((unsigned)(x))
#define __name(x) __phys(__phys_reloc_hide((unsigned long)(x)))
#define name1(x) name2(name3(x) >> NAME_OFFSET)
#define __va(x) ((void *)((unsigned long)(x)+PAGE_OFFSET))
#define __name1(x) __name2(x)
#define name1(x) __name2((unsigned long) (x))

#define PFN_MASK (((1ULL << 40) - 1) << 12)
#define PFN_MASK ((1ULL << 52) - (1ULL << 12))
#define PFN_MASK 0x000FFFFFFFFFF000ULL

auto extern restrict thread_local static
register nullptr const volatile static
constexpr static volatile
static_assert

// Storage-class specifiers

struct s { void *p; };
constexpr struct s A = { nullptr };
constexpr struct s B = A;

constexpr int *p = {}; // Default initialization with a null pointer

void f (void) {
	constexpr float f = 1.0f;
	constexpr float g = 3.0f;
	fesetround(FE_TOWARDSZERO); // does not affect
	// the following initialization
	// of "h"
	constexpr float h = f / g;
}

constexpr unsigned int minusOne = -1; // constraint violation
constexpr unsigned int uint_max = -1U; // ok
constexpr double onethird = 1.0/3.0; // possible constraint violation
constexpr double onethirdtrunc = (double)(1.0/3.0); // ok
constexpr _Decimal32 small = DEC64_TRUE_MIN * 0; // constraint violation

constexpr char string[] = { -1, 0, }; // ok
constexpr char8_t u8string[] = { 255, 0, }; // ok
constexpr unsigned char ucstring[] = { -1, 0, }; // constraint violation

constexpr char string[] = { 255, 0, }; // ok
constexpr char8_t u8string[] = { 255, 0, }; // ok
constexpr unsigned char ucstring[] = { 255, 0, }; // ok

constexpr int K = 47;
enum {
A = K, // valid, constant initialization
};
constexpr int L = K; // valid, constexpr initialization
static int b = K + 1; // valid, static initialization
int array[K]; // not a VLA

#include <float.h>
#include <complex.h>
constexpr float _Complex fc1 = 1.0; // ok
constexpr float _Complex fc2 = 0.1; // constraint violation, unless double
// has the same precision as float
// and is evaluated with the same
// precision
constexpr float _Complex fc3 = 3*I; // ok
constexpr double d1 = (double _Complex)1.0; // constraint violation
constexpr float f1 = (long double)INFINITY; // ok
constexpr float f2 = (long double)NAN; // ok, quiet NaNs in real floating
// types are considered the same
// value, regardless of payloads
constexpr double d2 = DBL_SNAN; // ok
constexpr double d3 = FLT_SNAN; // constraint violation, even if float
// and double have the same format
constexpr double _Complex dc1 = DBL_SNAN; // ok
constexpr double _Complex dc2 = CMPLX(DBL_SNAN, 0.); // ok
constexpr double _Complex dc3 = CMPLX(0., DBL_SNAN); // ok
constexpr _Decimal32 d321 = 1.0; // ok
constexpr _Decimal32 d322 = 1; // ok
constexpr _Decimal32 d323 = INFINITY; // ok
constexpr _Decimal32 d324 = NAN; // ok
constexpr _Decimal64 d641 = DEC64_SNAN; // ok
constexpr _Decimal64 d642 = DEC32_SNAN; // constraint violation
constexpr float f3 = 1.DF; // constraint violation
constexpr float f4 = DEC_INFINITY; // constraint violation
constexpr double d4 = DEC_NAN; // constraint violation
constexpr _Decimal32 d325 = DEC64_TRUE_MIN * 0; // constraint violation,
// quantum not preserved
#ifdef __STDC_IEC_60559_COMPLEX__
constexpr double d5 = (double _Imaginary)0.0; // constraint violation
constexpr double d6 = (double _Imaginary)0.0; // constraint violation
constexpr double _Imaginary di1 = 0.0*I; // ok
constexpr double _Imaginary di2 = 0.0; // constraint violation
#endif

#include <float.h>
constexpr int A = 42LL; // valid, 42 always fits in an int
constexpr signed short B = ULLONG_MAX; // constraint violation, value never
// fits
constexpr float C = 47u; // valid, exactly representable
// in float
#if FLT_MANT_DIG > 24
constexpr float D = 536900000; // constraint violation if float is
// ISO/IEC 60559 binary32
#endif
#if (FLT_MANT_DIG == DBL_MANT_DIG) \
&& (0 <= FLT_EVAL_METHOD) \
&& (FLT_EVAL_METHOD <= 1)
constexpr float E = 1.0 / 3.0; // only valid if double expressions
// and float objects have the same
// precision
#endif
#if FLT_EVAL_METHOD == 0
constexpr float F = 1.0f / 3.0f; // valid, same type and precision
#else
constexpr float F = (float)(1.0f / 3.0f); // needs cast to truncate the
// excess precision
#endif

constexpr static unsigned short array[] = {
3000, // valid, fits in unsigned short range
300000, // constraint violation if short is 16-bit
-1 // constraint violation, target type is unsigned
};
struct S {
int x, y;
};
constexpr struct S s = {
.x = INT_MAX, // valid
.y = UINT_MAX, // constraint violation
};

// End Storage-class specifiers

const int MAX_USERS = 100;
const int *ptr = &x;
ptr = &y;
int * const ptr = &x;
*ptr = 5; 
const int * const ptr = &x;
void print_message(const char *msg) {
    printf("%s\n", msg);
};
constexpr int MAX_ITEMS = 50 + 50; 
int inventory[MAX_ITEMS];
constexpr int MAX_SPEED = 120;
int current_speed = MAX_SPEED;
constexpr int CODE_ID = 999;
const int *ptr = &CODE_ID;

alignas
alignas(double) char array[sizeof(double)];
alignof
alignof(array) == 4;

int
float
float _Complex
double
double _Complex
double d;
char array[sizeof(double)];
double *pd = static_cast<double *>(array);
double long
double long _Complex
double long long
bool
char
long
long long
long int
long long int
short
short int
sizeof
size_t
ssize_t //
signed
signed int
signed short
signed char
signed short int
signed long
signed long int
signed long long
signed long long int
signed _BitInt
unsigned
unsigned int
unsigned short
unsigned char
unsigned short int
unsigned long
unsigned long long
unsigned long int
unsigned long long int
unsigned _BitInt
_Decimal32
_Decimal128
//— atomic type specifier
//— struct or union specifier
//— enum specifier
//— typedef name
//— typeof specifier


typeof
typeof_unqual

int //
int8_t i8; //
int8_t //
int16_t //
int32_t //
int64_t //
intmax_t i8_max; //
int_least8_t i8_least; //
int_least16_t //
int_least32_t //
int_least64_t //
int_least*_t //
int_fast8_t i8_fast; //
int_fast16_t //
int_fast32_t //
int_fast64_t //
int_fast*_t i8_fast; //
intptr_t //

#include <stdint.h>
typedef /* ... */ intptr_t;
typedef /* ... */ uintptr_t;
#define INTPTR_WIDTH  /* ... */
#define UINTPTR_WIDTH INTPTR_WIDTH
#define INTPTR_MAX    /*  2**(INTPTR_WIDTH - 1) - 1  */
#define INTPTR_MIN    /*  - 2**(INTPTR_WIDTH - 1)    */
#define UINTPTR_MAX   /*  2**UINTPTR_WIDTH - 1       */

uint //
uint8_t u8; //
uint8_t //
uint16_t //
uint32_t //
uint64_t //
uint_least8_t ui8_least; //
uint_least16_t //
uint_least32_t //
uint_least64_t //
uint_least*_t ui8_least //
uint_fast8_t ui8_fast; //
uint_fast16_t //
uint_fast32_t //
uint_fast64_t //
uint_fast*_t ui8_fast //
uintmax_t //
uintptr_t //

#include <stdint.h>
typedef /* ... */ intptr_t;
typedef /* ... */ uintptr_t;
#define INTPTR_WIDTH  /* ... */
#define UINTPTR_WIDTH INTPTR_WIDTH
#define INTPTR_MAX    /*  2**(INTPTR_WIDTH - 1) - 1  */
#define INTPTR_MIN    /*  - 2**(INTPTR_WIDTH - 1)    */
#define UINTPTR_MAX   /*  2**UINTPTR_WIDTH - 1       */

nullptr //

#include <stddef.h>
int *p1 = nullptr;
char *p2 = nullptr;
int x = nullptr;

#include <stddef.h>
nullptr_t my_null = nullptr;

#include <stdio.h>
#include <stddef.h>
#define OPIS_TYPU(x) _Generic((x), \
	nullptr_t: "Pusty wskaznik (nullptr)", \
	int*: "Wskaznik na int", \
	int: "Liczba calkowita int", \
	default: "Inny typ" \
)
int main(void) {
	int a = 0;
	printf("%s\n", OPIS_TYPU(nullptr));
	printf("%s\n", OPIS_TYPU(a));
	printf("%s\n", OPIS_TYPU(&a));
}

int *ptr = pobierz_dane();
if (ptr == nullptr) {
	// Wskaznik jest pusty
}
if (ptr != nullptr) {
	// Wskaznik wskazuje na pamiec
}

nullptr_t //

#include <stddef.h>
nullptr_t my_null = nullptr;

#include <stdio.h>
#include <stddef.h>
#define OPIS_TYPU(x) _Generic((x), \
	nullptr_t: "Pusty wskaznik (nullptr)", \
	int*: "Wskaznik na int", \
	int: "Liczba calkowita int", \
	default: "Inny typ" \
)
int main(void) {
	int a = 0;
	printf("%s\n", OPIS_TYPU(nullptr));
	printf("%s\n", OPIS_TYPU(a));
	printf("%s\n", OPIS_TYPU(&a));
}

nullptr_t n = nullptr;
if (n) {
	// Kod sie NIE wykona
}

ptrdiff_t //

#include <stdio.h>
#include <stddef.h>
int main(void) {
	int tab[10] = {0};
	int *p1 = &tab[2];
	int *p2 = &tab[7];
	ptrdiff_t diff1 = p2 - p1;
	ptrdiff_t diff2 = p1 - p2;
	printf("Roznica (p2 - p1): %td\n", diff1);
	printf("Roznica (p1 - p2): %td\n", diff2);
}

int a = 10;
int b = 20;
ptrdiff_t diff = &b - &a; // BŁĄD! Undefined Behavior (nieznany układ w pamięci)

typedef typeof((int*)nullptr - (int*)nullptr) ptrdiff_t;

unsigned char //
uchar_t //
uchar_t ui8_fast; //
uchar8_t ui8; //
...
uchar8_t u8 //
...
uchar_least_t ui8_least; //
...
uchar_least8_t ui8_least; //
...
uchar_least*_t ui8_least; //
uchar_fast_t ui8_fast; //
...
uchar_fast8_t ui8_fast; //
...
uchar_fast*_t ui8_fast; //
ucharmax_t ui8_max; //

char8_t //
...
char8_t i8 //
...
char_least_t i8_least; //
...
char_least8_t i8_least; //
...
char_least*_t i8_least; //
char_fast8_t ui8_fast; //
...
char_fast*_t i8_fast_least; //
...
wchar_t //

function(function()) {
	function();
	if () {};
	else if () {};
	else () {};
	for () {};
	while () {};
	do {} while ();
	break;
	continue;
	goto label;
	label: ;
	return value;

	auto extern restrict thread_local static
	register nullptr const volatile static
	constexpr static volatile
	static_assert

	int
	float
	double
	double long
	double long long
	bool
	char
	long
	long long
	long int
	long long int
	short
	sizeof
	size_t
	ssize_t
	signed
	unsigned

	sizeof array / sizeof array[0];

	#include <stddef.h>
	size_t fsize3(int n)
	{
		char b[n+3];
		return sizeof b;
	}
	int main(void)
	{
		size_t size;
		size = dsize3(10); // fsize3 returns 13
		return 0;
	}

	int a = 10;
	double b = 3.14;
	size_t s1 = sizeof(int);
	size_t s2 = sizeof a;
	size_t s3 = sizeof(b + 5);

	int tab[10];
	size_t calkowity_rozmiar = sizeof(tab); // 10 * 4 = 40 bajtow
	size_t ilosc_elementow = sizeof(tab) / sizeof(tab[0]); // 40 / 4 = 10

	int *ptr;
	size_t s_ptr = sizeof(ptr);
	size_t s_val = sizeof(*ptr);
	int *p = malloc(10 * sizeof(*p));

	struct Test {
		char c;
		int i;
	};
	size_t s_struct = sizeof(struct Test);

	size_t s1 = sizeof("C23"); // Zwraca 4 (trzy znaki + '\0')

	void funkcja(int n) {
		int vla[n];
		size_t s = sizeof(vla);
	}

	int x = 5;
	size_t s = sizeof(x++); // x++ NIE zostanie wykonane!, xnadal to 5

	void test(int tab[100]) {
		// BŁĄD! 'tab' tutaj jest tylko wskaźnikiem (int*)
		size_t s = sizeof(tab); // Zwróci rozmiar wskaźnika (4 lub 8 bajtów), NIE 400!
	}

	struct Flagi {
		unsigned int flag1 : 1;
		unsigned int flag2 : 3;
	};
	struct Flagi f;
	// size_t s = sizeof(f.flag1); // BŁĄD KOMPILACJI! Nie można pobrać rozmiaru pola bitowego.
	size_t s = sizeof(f); // Poprawne: pobiera rozmiar całej struktury.

	// size_t s1 = sizeof(void); // Błąd w standardowym C
	// Rozszerzenia kompilatorów (np. GCC) mogą zwracać 1 jako rozszerzenie niestandardowe.

	size_t // Bez znaku (unsigned)
	ssize_t // Ze znakiem (signed)

	#include <stdio.h>
	#include <stddef.h>
	#include <string.h>
	size_t len = strlen("Tekst");     // Zwraca size_t
	size_t s = sizeof(int);          // Zwraca size_t
	printf("Długość: %zu\n", len);   // Poprawny format to %zu

	#include <unistd.h>
	#include <sys/types.h>
	#include <stdio.h>
	char bufor[100];
	// read() zwraca ssize_t
	ssize_t bajty = read(STDIN_FILENO, bufor, sizeof(bufor));
	if (bajty == -1) {
	    perror("Błąd odczytu");
	} else {
	    printf("Odczytano %zd bajtów.\n", bajty); // Poprawny format to %zd
	}

	ssize_t odebrane = read(fd, buf, 100); // Wyobraźmy sobie, że zawiodło i odebrane = -1
	size_t oczekiwane = 10;
	// BŁĄD! odebrane (-1) zostanie przekształcone na ogromną liczbę dodatnią w size_t
	if (odebrane < oczekiwane) { 
	    // Warunek NIE ZOSTANIE spełniony, bo (size_t)(-1) > 10 !
	}

	if (odebrane < 0) {
	    // Obsługa błędu
	} else if ((size_t)odebrane < oczekiwane) {
	    // Poprawne porównanie
	}

	#if defined(_MSC_VER)
	    #include <BaseTsd.h>
	    typedef SSIZE_T ssize_t; // MSVC udostępnia wielką literą SSIZE_T w BaseTsd.h
	#else
	    #include <sys/types.h>
	#endif

	typeof /*pobiera dokładny typ x, zachowując wszystkie kwalifikatory (const, volatile, restrict, _Atomic).*/
	typeof_unqual /*pobiera typ x, ale usuwa z niego wszystkie kwalifikatory najwyższego poziomu (const, volatile, restrict, _Atomic).*/
	
	const volatile int x = 10;
	typeof(x) a = 5;
	typeof_unqual(x) b = 5;
	b = 20;

	int x = 42;
	typeof(x) a = 10;
	typeof_unqual(x) b = 10;
	volatile unsigned long long c = 1;
	typeof(unsigned long long) c = 100ULL;
	const float d = 2;
	typeof_unqual(const float) d = 3.14f;
	typeof(x + 3.14) e = 5.5;

	int x = 10;
	const int cx = 10;
	const typeof(x) a = 5;
	typeof_unqual(cx)* ptr = &x;

	int x = 10;
	int *ptr = &x;
	typeof(ptr) p1 = &x; // int* p1
	typeof(*ptr) val = *ptr; // int val (pobiera typ wskazywanej wartosci)
	typeof(x) *p2 = &x; // int* p2 (tworzy wskaznik na typ zmiennej x)

	const int tab[5] = {1, 2, 3, 4, 5};
	typeof(tab) a;
	typeof_unqual(tab) b;
	typeof(tab[0]) elem1;
	typeof_unqual(tab[0]) elem2;
	typeof(x) nowa_tablica[10];

	struct {
		int x;
		int y;
	} punkt1 = {1, 2};
	typeof(punkt1) punkt2;
	punkt2.x = 10;
	typeof(punkt1)* ptr_punkt = &punkt1;

	int dodaj(int a, double b) { return a + b; }
	typeof(dodaj(1, 1.0)) wynik;
	typeof(dodaj) *fn_ptr = dodaj;
	typeof(dodaj) inna_funkcja;

	double d = 9.99;
	const int c = 5;
	int x = (typeof(c))d;
	int y = (typeof_unqual(c))d;

	#define SWAP(a, b) do { \
		typeof_unqual(a) __tmp = (a); \
		(a) = (b); \
		(b) = __tmp; \
	} while(0)
	int main(void) {
		const int x = 10;
		int y = 20;
	}

	int i = 5;
	typeof(i++) j = 10; // 'i++' NIE zostanie wykonane!
	// i nadal wynosi 5, a j ma typ int.
};
void function(function()) {
	function();
};
inline function(function()) {
	function();
};
static function(function()) {
	function();
};
static inline void zone_statistics(struct zone *preferred_zone, struct zone *z, long nr_account) {};
static __name1 void *name2(unsigned long x) { return __name3(x << name4); }

outb(ATA_PRIMARY_DRIVE_HEAD, 0xE0 | ((lba >> 24) & 0x0F)); // Master drive + LBA bits 24-27
outb(ATA_PRIMARY_SECCOUNT, 1); // Liczba sektorów: 1
outb(ATA_PRIMARY_LBA_LO, (uint8_t) lba);
outb(ATA_PRIMARY_LBA_MID, (uint8_t)(lba >> 8));
outb(ATA_PRIMARY_LBA_HIGH, (uint8_t)(lba >> 16));
outb(ATA_PRIMARY_COMM_STAT, 0x20);

enum Day {monday};
int function(void){
	enum Day today = monday;
};

typedef unsigned long ulong;
typedef struct {double variable; double variable;}Point;

typedef int digit;
typedef unsigned long ulong;
typedef double vectors;

typedef int* ptrint;
ptrint p, q;
typedef void* ptrvoid;

typedef int table10int[10];
typedef char buforwords[256];
typedef float matrix3x3[3][3];
table10int t;
matrix3x3 m;

struct Punkt {
	int x;
	int y;
};
typedef struct Punkt Punkt;
Punkt p1;

typedef struct {
	int x;
	int y;
} Punkt;
Punkt p1;

typedef struct Wezel {
	int dane;
	struct Wezel* nastepny;
} Wezel;
Wezel w1;

typedef union {
	int i;
	float f;
	char c;
} Dane;
Dane d;
d.f = 3.14f;

typedef enum {
	STAN_IDLE,
	STAN_RUNNING,
	STAN_STOPPED
} Stan;
Stan aktualnyStan = STAN_RUNNING;

typedef void (*Callback)(void);
void myFunction(void) {}
Callback cb = myFunction;

typedef int (*OperationMath)(int, int);
int add(int a, int b) { return a + b; }
OperationMath op = add;
int result = op(5, 3);

typedef int (*ptrontable10)[10];
int t[10];
ptrontable10 ptr = &t;

typedef void (*Handler)(int);
typedef Handler TabelaHandlerow[5];
// Zamiast pisać: void (*TabelaHandlerow[5])(int);

typedef const char* StalyNapis;
typedef volatile int* RejestrSprzetowy;
StalyNapis s ="Tekst";

typedef char* String;
void function(const String s) {
	s[0] = 'X';
}

typedef volatile uint32_t* RegPtr;

typedef struct Punkt Punkt;
const Punkt *p1;
Punkt *const p2;

struct {
	char a;
	int b:5, c:11, :0, d:8;
	struct { int ee:8; } e;
};

struct s { int i; const int ci; };
struct s s;
const struct s cs;
volatile struct s vs;
/*
s.i int
s.ci const int
cs.i const int
cs.ci const int
vs.i volatile int
vs.ci volatile const int
*/

union {
	struct { int alltypes; } n;
	struct { int type; int intnode; } ni;
	struct { int type; double doublenode; } nf;
} u;
u.nf.type = 1;
u.nf.doublenode = 3.14;
if (u.n.alltypes == 1)
	if (sin(u.nf.doublenode) == 0.0)

struct t1 { int m; };
struct t2 { int m; };
int f(struct t1 *p1, struct t2 *p2) {
	if (p1->m < 0)
		p2->m = -p2->m;
	return p1->m;
};
int g() {
	union { struct t1 s1; struct t2 s2; } u;
	return f(&u.s1, &u.s2);
};

union functions {
	double function;
	bool function;
	void function;
} function();

switch (choice) {
	case choice: break;
	case choice: continue;
	default: printf();
};

T *addr = &E;
T old = *addr;
T new;
do { new=old+1; } while (!atomic_compare_exchange_strong(addr,&old,new));

SC typeof(T) ID = { IL };

struct int_list { int car; struct int_list *cdr; };
struct int_list endless_zeros = {0, &endless_zeros};
eval(endless_zeros);
struct s { int i; };
int f (void) {
	struct s *p = 0, *q;
	int j = 0;
again:
	q = p, p = &((struct s){j++});
	if (j<2) goto again;
	return p == q && q->i == l;
};
struct page *rmqueue_buddy(struct zone *preferred_zone, struct zone *zone, unsigned int order, unsigned int alloc_flags, int migratetype) { struct page *page; };
struct zone {
	unsigned long watermark[NR_WMARK];
	unsigned long nr_reserved_highatomic;
	struct per_cpu_pages __percpu *per_cpu_pageset;
	struct free_area free_area[NR_PAGE_ORDERS];
	unsigned long zone_start_pfn;
	unsigned long managed_pages;
	unsigned long spanned_pages;
	unsigned long present_pages;
	const char *name;
};

float *p, **pp; // p is a pointer to float
                // pp is a pointer to a pointer to float
int (*fp)(int); // fp is a pointer to function with type int(int)

int n;
const int * pc = &n; // pc is a non-const pointer to a const int
// *pc = 2; // Error: n cannot be changed through pc without a cast
pc = NULL; // OK: pc itself can be changed
int * const cp = &n; // cp is a const pointer to a non-const int
*cp = 2; // OK to change n through cp
// cp = NULL; // Error: cp itself cannot be changed
int * const * pcp = &cp; // non-const pointer to const pointer to non-const int

int n;
int *np = &n; // pointer to int
int *const *npp = &np; // non-const pointer to const pointer to non-const int
int a[2];
int (*ap)[2] = &a; // pointer to array of int
struct S { int n; } s = {1}
int* sp = &s.n; // pointer to the int that is a member of s

int n;
int* p = &n; // pointer p is pointing to n
*p = 7; // stores 7 in n
printf("%d\n", *p); // lvalue-to-rvalue conversion reads the value from n

int a[2];
int *p = a; // pointer to a[0]
int b[3][3];
int (*row)[3] = b; // pointer to b[0]

void f(int);
void (*pf1)(int) = &f;
void (*pf2)(int) = f; // same as &f

#include <stdio.h>
int f(int n)
{
    printf("%d\n", n);
    return n * n;
}
int main(void)
{
    int (*p)(int) = f;
    int x = p(7);
}

int f();
int (*p)() = f;    // pointer p is pointing to f
(*p)(); // function f invoked through the function designator
p();    // function f invoked directly through the pointer

int f(int), fc(const int);
int (*pc)(const int) = f; // OK
int (*p)(int) = fc;       // OK
pc = p;                   // OK

int n=1, *p=&n;
void* pv = p; // int* to void*
int* p2 = pv; // void* to int*
printf("%d\n", *p2); // prints 1

char *str = "abc"; // "abc" is a char[4] array, str is a pointer to 'a'

int main(int argc, char *argv[]) {}

int f(int*);
int g(char * para[f((int[27]){ 0, })]) { return 0; }

int *p = (int []){2,4};
void f(void)
{
	int *p;
	p=(int [2]){*p};
}

drawline((struct point){.x=1, .y=1},(struct point){.x=3, .y=4});

drawline(&(struct point){.x=1, .y=1},&(struct point){.x=3, .y=4});

(const float []){1e0,1e1,1e2,1e3,1e4,1e5,1e6}

(const char []){"abc"} == "abc"

struct int_list { int car; struct int_list *cdr; };
struct int_list endless_zeros = {0, &endless_zeros};
eval(endless_zeros);

struct s { int i; };
int f (void) {
	struct s *p = 0, *q;
	int j = 0;
again:
	q= p, p = &((struct s){ j++ });
	if (j<2) goto again;
	return p == q && q->i ==1;
}

~E; // Equivalent to the maximum value repres. in that type minus E
!E; // Equivalent to (0==E)

&*E; //equivalent to E (even if E is a null pointer)
&(E1[E2]); // equivalent to ((E1)+(E2))
*&E; // is a function designator or an lvalue equal to E
*P;
*(T)P; // is an lvalue that has a type compatible with that to which T points.

extern void *alloc(size_t);
double *dp = alloc(sizeof *dp);

{
	int n=4, m=3;
	int a[n][m];
	int (*p)[m]=a; // p == &a[0]
	p+=1; // p == &a[1]
	(*p)[2]=99; // a[1][2]==99
	n=p-1; // n == 1
}

const void *c_vp;
void *vp;
const int *c_ip;
volatile int *v_ip;
int *ip;
const char *c_cp;
/*
c_vp c_ip const void *
v_ip 0 volatile int *
c_ip v_ip const volatile int *
vp c_cp const void *
ip c_ip const int *
vp ip void *
*/

const char **cpp;
char *p;
const char c = 'A';
cpp = &p; // constraint violation
*cpp = &c; // valid
*p = 0; // valid