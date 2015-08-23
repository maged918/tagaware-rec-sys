//Language: GNU C++


#include <iostream>

using namespace std;

int n,mid,k;
long int pos[120],nr[120],aux;
long long sum;

int main()
{
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>pos[i]>>nr[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(pos[j]<pos[i]){
                aux=pos[i];
                pos[i]=pos[j];
                pos[j]=aux;

                aux=nr[i];
                nr[i]=nr[j];
                nr[j]=aux;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        if(pos[i]<0 && pos[i+1]>0)
            mid=i;
    }

    if(pos[0]>=0){
        mid=-1;
        sum=nr[0];
    }
    if(pos[n-1]<0){
        mid=-1;
        sum=nr[n-1];
    }

    while(mid+k+1<n && mid-k>=0){
        sum+=nr[mid-k]+nr[mid+k+1];
        k++;
    }
    if(pos[0]<0 && pos[n-1] > 0 && mid-k<0){
        sum+=nr[mid+k+1];
    }

    if(pos[0]<0 && pos[n-1] > 0 && mid+k+1>=n){
        sum+=nr[mid-k];
    }

    cout<<sum;


    return 0;
}
