#include <tio.h>
#include <tioerror.h>
#include <utf.h>
#include <limits.h>
#include <stdio.h>
//#include <stdio.h>
int main( int argc, const char* argv[] )
{
    int myargc = 6;
    const char* myargv[]  =
    {
        argv[0],
        "-a",
        "1",
        "-b",
        "2",
        "-c",
        "-3"
    };
    tio_param mypar [] = {
        {"a:", "A", "Параметр А"},
        {"b:", "B", "Параметр B"},
        {"c:", "C","Параметр C"},
        {NULL, NULL, NULL}
    };
    //tioInit( "alpha", "This is test", mypar, myargc, myargv );
    puts( "Тест написал: Гусев Михаил" );
    puts( "Короткое описание теста:\nТестирование функции решения квадратного уровнения." );
    tioInit( "alpha", "This is test", mypar, argc, argv );
    void *td = tioTableBegin( "Name&Valume", TIOSTRING, TIOLONG );
    //void *td = tioTableBegin( "Решение уравнения вида&Параметр А&Параметр В&Параметр С&Корень 1&Корень 2", TIOSTRING, TIOLONG, TIOLONG, TIOLONG, TIOLONG, TIOLONG );
    tioTableRecord( td, "Argument A", tioGetL( "A" ) );
    tioTableRecord( td, "Argument B", tioGetL( "B" ) );
    tioTableRecord( td, "Argument C", tioGetL( "C" ) );
    tioTableRecord( td, "The equation root 1", 1 );
    tioTableRecord( td, "The equation root 2", -3 );
    tioTableEnd( td );
    tioFinish( 0 );
    return 0;
    
}
