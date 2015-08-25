//Language: GNU C++11


#include <cstdio>
#include <cmath>

double cosine ( double a, double b ){
    return sqrt( a * a + b * b + a * b );
}

double heron ( double a, double b, double c ){
    double p = ( a + b + c ) / 2;
    return sqrt ( p * ( p - a ) * ( p - b ) * ( p - c ) );
}

int main(){
    int s1, s2, s3, s4, s5, s6;
    scanf("%d %d %d %d %d %d",&s1,&s2,&s3,&s4,&s5,&s6);
    double A,B,C,S;
    A = cosine( s2,s3 );
    B = cosine( s4,s5 );
    C = cosine( s6,s1 );
    S = heron(A,B,C) + sqrt(3) / 4 * ( s2 * s3 + s4 * s5 + s6 * s1 );
    long ans = long( 4 * S / sqrt(3) );
    printf("%I32d",ans);
    return 0;
}