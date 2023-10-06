/*
    จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
    
    หมายเหตุ: ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
    153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
    370 = 3^3 + 7^3 + 0^3

    Test Case:
        Enter Number:
            153
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            370
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            372
    Output:
        Not Pass.
*/

#include <stdio.h>
int main() {

    int num ;
    printf( "Enter Number:\n\t" ) ;
    scanf( "%d\n" , &num ) ;


    // หาหลักเลข
    int count = 0 ;
    if ( num / 1000 >= 1 ) {
        count = 4 ;
    } else if ( num / 100 >= 1 ) {
        count = 3 ;
    } else if ( num / 10 >= 1 ) {
        count = 2 ;
    } // end if


     // หาเลขในแต่ละหลัก
    int d = num / 1000 ; // หาเลขหลักพัน
    int c = ( num - d * 1000 ) / 100 ; // หาเลขหลักร้อย
    int b = ( num - ( d * 1000 + c * 100  ) ) / 10 ; // หาเลขหลักสิบ
    int a = ( num - ( d * 1000 + c * 100  +  b * 10  ) ) / 1 ; // หาเลขหลักหน่วย


    int aa = a , bb = b , cc = c , dd = d ;
    for ( int i = 1 ; i < count ; i++ ) {
        aa = aa * a ;
        bb = bb * b ;
        cc = cc * c ;
        dd = dd * d ;
    }  // end for

    int ans = aa + bb + cc + dd ;

    if ( num == ans ) {
        printf( "\tPass." ) ;
    } else {
        printf( "\tNot Pass." ) ;
    }

    return 0 ;
}//end main function