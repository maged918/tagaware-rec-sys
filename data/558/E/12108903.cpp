//Language: MS C++


#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const int CN=26, CN1=25;

int A[CN], A1[CN];


void NeedFun(map<int,pair<int,pair<bool,int*>>>::iterator &p, int &l, int t1, int t2, int t3)
{
	int last, beg, endd, order;
	beg = p->first;
	endd = p->second.first;
	last =  l - p->first;
	order = p->second.second.first;
	int i=t1;
	for(i; i!=t2; i+=t3)
	{
		//cout<<p->second.second.second[i]<<' '<<last<<endl;
		if(p->second.second.second[i]<last)
		{
			A[i] = p->second.second.second[i];
			last-= p->second.second.second[i];
		}
		else
		{
			A[i] = last;
			p->second.second.second[i]-=last;
			break;
		}
	}
	for(i; i!=t2; i+=t3)
	{	
		//cout<<p->second.second.second[i]<<' '<<last<<endl;
		A1[i] = p->second.second.second[i];				
	}
}

void NeedFun2(map<int,pair<int,pair<bool,int*>>> &m1, int beg, int t1, int t2, int t3, int *A)
{
	for(int i=t1; i!=t2; i+=t3)
	{
		m1[beg].second.second[i] = A[i];
		//cout<<A[i]<<' ';
	}
}


void Fun_Main(map<int,pair<int,pair<bool,int*>>> &m1, int l)
{
	map<int,pair<int,pair<bool,int*>>>::iterator p, p1;
	int last, beg, endd, order;
	p = m1.upper_bound(l);
	p--;
	order = p->second.second.first;
	if(order==1)
	{
		NeedFun(p,l,0,CN,1);
	}
	else
	{
		NeedFun(p,l,CN1,-1,-1);
	}
	
	beg = p->first;
	endd = p->second.first;
	last =  l - p->first;
	

	//delete [] p->second.second.second;
	m1.erase(p);

	m1[beg].first = l-1;
	m1[beg].second.second = new int[CN];
	memset(m1[beg].second.second,0,CN*4);
	m1[beg].second.first = order;
	if(order==1)
	{
		NeedFun2(m1,beg,0,CN, 1, A);
	}
	else
	{
		NeedFun2(m1,beg, CN1,-1,-1, A);
	}

	m1[l].first = endd;
	m1[l].second.second = new int[CN];
	m1[l].second.first = order;
	memset(m1[l].second.second,0,CN*4);

	if(order==1)
	{
		NeedFun2(m1,l,0,CN, 1, A1);
	}
	else
	{
		NeedFun2(m1,l,CN1,-1,-1, A1);
	}

}


int main()
{
	int n, q;
//	ifstream ff("file.txt");
	cin>>n>>q;
	int N = n+1;
	map<int,pair<int,pair<bool,int*>>>m1;
	map<int,pair<int,pair<bool,int*>>>::iterator p0;
	cin.ignore();
	for(int i=1; i<N; i++)
	{
		char C;
		C= getchar();
		//cin>>C;
		m1[i].first = i;
		m1[i].second.second = new int[CN];
		memset(m1[i].second.second,0,CN*4);
		m1[i].second.second[C-'a']++;
		m1[i].second.first = 0;
	}
/////
	map<int,pair<int,pair<bool,int*>>>::iterator p, p1, p2;
	while(q--)
	{	
		int l, r, z;
		//ff>>l>>r>>z;
		scanf("%d%d%d", &l, &r, &z);
		memset(A1,0,CN*4);
		memset(A,0,CN*4);
		//�������� �� ����� ����� �����
		p = m1.find(l);
		if(p==m1.end())
		{
			Fun_Main(m1,l);
		}
		memset(A1,0,CN*4);
		memset(A,0,CN*4);
		p = m1.begin();
		//�������� �� ����� ������ �����
		p1 = m1.find(r+1);
		if(p1==m1.end() && r!=n)
		{
			Fun_Main(m1,r+1);
		}

		////////
		p = m1.find(l);
		p1 = m1.find(r+1);
		memset(A1,0,CN*4);
		for(p; p!=p1; )
		{
			for(int i=0; i<CN; i++)
			{
				A1[i] += p->second.second.second[i];
				//cout<<A1[i]<<' ';
			}
			//cout<<endl;
			//delete [] p->second.second.second;
			m1.erase(p++);
		}
		m1[l].first = r;
		m1[l].second.second = new int[CN];
		p = m1.find(l);
		for(int i=0; i<CN; i++)
		{
			p->second.second.second[i] = A1[i];
		}


		if(z==0)
		{
			p->second.second.first = 0;
		}
		else
		{
			p->second.second.first = 1;
		}	
	}

	///////

	//���������
	p = m1.begin();
	for(p; p!=m1.end(); p++)
	{
		
		if(p->second.second.first==1)
		{
			for(int i=0; i<CN; i++)
			{
				for(int j=0; j<p->second.second.second[i]; j++)
				{
					cout<<(char)(i+'a');
				}
			}
		}
		else
		{
			for(int i=CN1; i>=0; i--)
			{
				for(int j=0; j<p->second.second.second[i]; j++)
				{
					cout<<(char)(i+'a');

					//cin>>n;
				}
			}
		}

	}
	//cin>>n;
	return 0;
}