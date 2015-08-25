//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _node
{
    int value;
    int start;
    int length;
    bool started;
    _node(int s,int value)
    {
        start=s;
        this->value=value;
        started=true;
    }
    _node()
    {
        start=0;
        started=false;
    }
}Node;

vector <Node> container;
int last_end[1000001];
int cnt[1000001];

bool my_compare(Node a,Node b)
{
    if (cnt[a.value]>cnt[b.value])
        return true;
    else if (cnt[a.value]<cnt[b.value])
        return false;
    else
        return a.length<b.length;
}

int main(void)
{
    int N,tmp;
    cin>>N;

    for (int i=1;i<=N;i++)
    {
        cin>>tmp;
        if (last_end[tmp]==0)
            container.push_back(Node(i,tmp));
        last_end[tmp]=i;
        cnt[tmp]++;
    }

    for (int i=0;i<container.size();i++)
    {
        Node tmp=container[i];
        tmp.length=last_end[tmp.value]-tmp.start;
        container[i]=tmp;
    }

    sort(container.begin(),container.end(),my_compare);
    Node last=container[0];

    cout<<last.start<<" "<<last.start+last.length<<endl;

    return 0;
}