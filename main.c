#include "screen.h"
#include <stdio.h>

#define FALSE 0
#define TRUE 1


char* getDate( int x, int y );
int   leap(int year);
void  init_screen();

int main(){

    char* p;
    init_screen();
    p = getDate(10, 10); 
    return 0;

} // *main()

void init_screen()
{
    int cols;
    int rows;
    int i;

    tc_get_cols_rows( &cols, &rows );
    char linea[cols - 15];

    for (i=0; i < (cols - 15) ; i++){
        linea[i] = '-';
    }
    linea[i] = '\0';
    tc_clear_screen();

    printf("\n\n\t");
    printf("%s", linea);
    tc_move_cursor(0, rows - 3);
    printf("\t%s", linea);

} // init_screen()

int leap(int year)
{
    int is_leap = FALSE;

    if (( year % 400 ) == 0 || ((year % 100 != 0) && (year % 4 == 0))){
            is_leap = TRUE;
    }
    return is_leap;

} // leap()

char* getDate( int x, int y ){
    static char Date[12];
    static char Datef[11];
    int day;
    int month;
    int year;
    int ok = FALSE;

    do {
        tc_move_cursor(x, y);
        printf("Fecha: ");
        scanf("%s", Date);
        sscanf(Date, "%2d%2d%4d", &day, &month, &year);

        // Fixing the century if year has 2 digits 
        if (year < 1900) {
                if (year > 50){
                    year += 1900;
                }
                else{
                    year += 2000;
                }
        }
                      
        if (day > 31||day < 1||month>12||month<1){
            ok = FALSE;
            printf(TC_RED "ERROR en la fecha, intente otra vez..." TC_NRM);
            tc_move_cursor(x+7, y);
            printf("           ");
        }
        else
        {
            ok = TRUE;
            break;
        }

    } while( ok == FALSE);
    
    sprintf(Datef, "%02d/%02d/%4d", day, month, year);
    tc_move_cursor(x+7, y);
    printf("%s\n", Datef);

    return Datef;

} //getDate()
