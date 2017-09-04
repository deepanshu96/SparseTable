//Sparse Table implementation
/*

           
     |||||||==== o o 
     |     |
 |||||||||||||||||||
  ||    T-90    || 
   ||   TANK   ||
    |O|O|O|O|O|
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, b, sizeof a)
#define FOR(i, j, k, in) for ( i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for ( i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 100000000
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long ll;
typedef pair<int, int> pii;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
//variables
int a[100];
int n;
int sparse[100][100];
//func
void preprocess()
{
 int i,j;
 FOR(i,0,n,1)
    sparse[i][0]=i;
 for(j=1;(1<<j)<=n;j++)
    {
     for(i=0;i+(1<<j)-1<n;i++)
        {
         if(a[ sparse[i][j-1] ]<a[ sparse[i+(1<<(j-1))][j-1] ])
            sparse[i][j]=sparse[i][j-1];
         else
            sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }
}
int query(int l,int r)
{
 int len=r-l+1;
 int k=log2(len);
 return min(a[sparse[l][k]],a[sparse[l+len-(1<<k)][k]]);
}
//main

int main()
{
 int i,j;
 cin>>n;
 FOR(i,0,n,1)
    cin>>a[i];
 preprocess();
/* FOR(i,0,n,1)
    {
     FOR(j,0,n,1)
         cout<<sparse[i][j]<<" ";
     cout<<endl;
    }
 */
 cout<<query(0,5)<<endl;
 cout<<query(3,5)<<endl;
  return 0;    
}