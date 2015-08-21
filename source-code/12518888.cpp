//Language: GNU C++11


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <cstdio>
//#include <vector>
//#include <cmath>
//#include <stdio.h>
//#include <algorithm>
//#include <set>
//#include <map>
//#include <fstream>
#include <string>

using namespace std;

int main() {
    //ifstream cin("in.txt");
    //ofstream cout("ou.txt");
    int n, m;
    //cin>>n>>m;    
    scanf("%d %d", &n, &m);
    char buffer[300100];
    scanf("%s", &buffer);
    string s(buffer);
    int dot=0, c = 0, otr = 0;  
    for (int i=0; i<n; i++){
        if (s[i]=='.'){         
            c++;
            dot++;
        } else {
            if (c > 0) otr++;
            c = 0;
        }
    }
    if (c > 0) otr++;
    
    for (int i=0; i<m; i++){
        int x; char c;
        //cin>>x>>c;
        scanf("%d %c", &x, &c);
        x--;
        if (s[x]!='.' && c!='.') { /*cout<<dot-otr<<endl;*/ printf("%d\n", dot-otr); continue; } // obe bukv
        if (s[x]==c) { /*cout<<dot-otr<<endl;*/ printf("%d\n", dot-otr); continue; } // odinakov
        if (c=='.'){ // vstavit tochky
            s[x] = c;
            if (x==0){
                if (n>1){
                    if (s[1]=='.'){
                        dot++;
                    } else{
                        dot++;
                        otr++;
                    }
                } else{
                    otr++;
                    dot++;
                }
            } else{
                if (x==n-1){
                    if (n>1){
                        if (s[n-2]=='.'){
                            dot++;
                        } else{
                            dot++;
                            otr++;
                        }
                    } else{
                        otr++;
                        dot++;
                    }
                } else{
                    if (s[x+1]=='.' && s[x-1]=='.'){
                        dot++;
                        otr--;
                    } else{
                        if (s[x+1]=='.' || s[x-1]=='.'){
                            dot++;
                        } else{
                            dot++;
                            otr++;
                        }
                    }
                }
            }
            //cout<<dot-otr<<endl;
            printf("%d\n", dot-otr);
            continue;
        }
        //vstavit bukvy         
        s[x] = c;
        if (x==0){
            if (n>1){
                if (s[1]!='.'){
                    otr--;
                    dot--;
                } else{
                    dot--;
                }
            } else{
                otr--;
                dot--;
            }
        } else{
            if (x==n-1){
                if (n>1){
                    if (s[n-2]!='.'){
                        otr--;
                        dot--;
                    } else{
                        dot--;
                    }
                } else{
                    otr--;
                    dot--;
                }
            } else{
                if (s[x+1]!='.' && s[x-1]!='.'){
                    otr--;
                    dot--;
                } else{
                    if (s[x+1]!='.' || s[x-1]!='.'){
                        dot--;
                    } else{
                        otr++;
                        dot--;
                    }
                }
            }
        }
        //cout<<dot-otr<<endl;
        printf("%d\n", dot-otr);
    }
    
}