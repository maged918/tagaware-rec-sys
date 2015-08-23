//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin >> n ;
    int arr[n+10];
    int flag1[n+10];
    int flag2[n+10];
    for(int i=0;i<n;i++){
        flag1[i] = 0;
        flag2[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin >> arr[i] ;
        if(arr[i] < n){
            flag1[arr[i]-1] = 1;
        }
    }
    int start = 0;

    for(int i=0; i<n;i++){
        if(arr[i] > n){
            for(int j=start ;j<n;j++){
                if(flag1[j] == 0){
                    start = j;
                    arr[i] = j+1;
                    flag1[j] =1;
                    flag2[j] = 1;
                    break;
                }
            }
        }

        else if(flag2[arr[i]-1] == 0){
            flag2[arr[i]-1] = 1;
        }

        else{
            for(int j=start ;j<n;j++){
                if(flag1[j] == 0){
                    start = j;
                    arr[i] = j+1;
                    flag1[j] =1;
                    flag2[j] = 1;
                    break;
                }
            }           
        }
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}