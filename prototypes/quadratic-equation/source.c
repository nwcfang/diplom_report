#include <tio.h>
#include <tioerror.h>
#include <utf.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
/*#include <stdio.h>*/

typedef struct _SRoots {
    long root1;
    long root2;
} SRoots;

/*Решение квадратного уравнения*/
int quad( long a, long b, long c, SRoots* Roots ) {
    long d = b * b - 4 * a * c;
    Roots->root1 = ( -b + sqrt( (double)d ) ) / ( 2 * a );
    Roots->root2 = ( -b - sqrt( (double)d ) ) / ( 2 * a );
    return 0;
}


int main( int argc, const char* argv[] ) {
    SRoots *Roots = malloc( sizeof(SRoots) ); 
    //SRoots *RootsEtalon = malloc( sizeof(SRoots) ); 
    
    //int myargc = 6;

    //const char* myargv[] = {
        //argv[0],
        //"-a",
        //"1",
        //"-b",
        //"2",
        //"-c",
        //"-3"
    //};

    tio_param mypar [] = {
        {"a:", "A", "Параметр А"},
        {"b:", "B", "Параметр B"},
        {"c:", "C","Параметр C"},
        {"root1:", "ROOT1", "Первый корень"},
        {"root2:", "ROOT2", "Второй корень"},
        {NULL, NULL, NULL}
    };

    //puts( "Тест написал: Гусев Михаил" );
    //puts( "Короткое описание теста:\nТестирование функции решения квадратного уровнения." );
    tioInit( "v0.9 alpha", "This is test", mypar, argc, argv );

    quad( tioGetL( "A" ),tioGetL( "B" ),tioGetL( "C" ), Roots );
    void *td = tioTableBegin( "Имя параметра&Значение", TIOSTRING, TIOLONG );

    tioTableRecord( td, "Аргумент A", tioGetL( "A" ) );
    tioTableRecord( td, "Аргумент B", tioGetL( "B" ) );
    tioTableRecord( td, "Аргумент C", tioGetL( "C" ) );
    /*tioTableRecord( td, "The equation root 1", Roots->root1 );*/
    /*tioTableRecord( td, "The equation root 2", Roots->root2 );*/
    tioTableEnd( td );

    puts( "Сравнение эталонных и возвращаемых функцией корней" ); 
    td = tioTableBegin( "Эталонные корни&Корни, посчинанные функцией", TIOLONG, TIOLONG );
    tioTableRecord( td, tioGetL( "ROOT1" ), Roots->root1 );
    tioTableRecord( td, tioGetL( "ROOT2" ), Roots->root2 );
    tioTableEnd( td );

    free(Roots);
    tioFinish( 0 );
    return 0;
    
}
