/*
 * https://github.com/thecodingwizard/competitive-programming/blob/master/Infoarena/mexc.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int N , n , m , k ;
vpi v [100009] ;
int p [800009] , sum [800009] , a [809][809] , done [809][809] , ans [809][809] ;
int X [] = { -1 , 0 , 1 , 0 } ;
int Y [] = { 0 , 1 , 0 , -1 } ;
struct cell {
	int x , y , val ; 
} ord [800009] ;
bool cmp ( cell x , cell y ) {
	return x .val < y .val ;
}
int f ( int x , int y ) {
	return x * m + y ;
}
int get ( int node ) {
	if ( node == p [node] ) return node ;
	return p [node] = get ( p [node] ) ;
}
void merge ( int a , int b ) {
	a = get ( a ) , b = get ( b ) ;
	if ( a == b ) return ;
	sum [a] += sum [b] ;
	p [b] = a ;
}
void add ( int x , int y ) {
	done [x][y] = 1 ;
	for ( int i = 0 ; i < 4 ; i ++ ) {
		int nx = x + X [i] ;
		int ny = y + Y [i] ;
		if ( nx < n && nx >= 0 && ny < m && ny >= 0 && done [nx][ny] ) {
			merge ( f ( x , y ) , f ( nx , ny ) ) ;
		}
	}
}
int loc ( pi x ) {
	return get ( f ( x .fi , x .se ) ) ;
}
int main () {
	ifstream fin ("mexc.in") ;
	ofstream fout("mexc.out");
	fin >> n >> m >> k ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			fin >> a [i][j] ;
			v [ a[i][j] ] .pb ( { i , j } ) ;
			p [ f (i,j) ] = f (i,j) ;
			N = max ( N , a [i][j] ) ;
		}
	}
	int it = N ;
	for ( int i = N ; i >= 0 ; i -- ) {
		while ( it >= 0 && it >= i - k ) {
			for ( auto u : v [it] ) {
				add ( u.fi , u.se ) ;
			}
			it -- ;
		}
		for ( auto u : v [i] ) {
			sum [ loc ( u ) ] ++ ;
		}
		for ( auto u : v [i] ) {
			ans [ u.fi ] [ u.se ] = sum [ loc ( u ) ] ;
		}
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			fout << ans [i][j] << " " ;
		}
		fout << endl ; 
	}
}
