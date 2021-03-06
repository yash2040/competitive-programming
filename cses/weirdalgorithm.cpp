#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<cmath>
#include<string>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define deb(x) cerr<<#x<<" "<<x<<"\n"
#define debi cerr<<"hey sparky\n"
#define x first
#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define newline cout<<"\n"
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define INF (int)1e5+5
#define nax (int)1e6+3
#define eps (double)1e-9
#define all(x) x.begin(),x.end()
#define MAX_N (int)1e6+2
//#define int long long
using namespace std;
using namespace __gnu_pbds; 
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pdbs;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
// look for  all edge cases
//search for a pattern
 
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
		vector<int> first(26 , -1) , last(26 , -1);
		for(int i = 0; i < n ;i++){
			int val = (int)(s[i] - 'a');
			if(first[val] == -1){
				first[val] = i;
			} 
			last[val] = i;
		}
		
		vector<pair<int, pair<int,int>>> v(26);
		
		for(int i =0 ; i < 26; i++){
			if(first[i] == -1)
				continue;
			
			int left = first[i] , right = last[i]; 
			for(int j = first[i] ; j<= last[i]; j++){
				left = min(first[j] , left);
				right = max(right , last[j]);
			}
			
			v[i] = {(right - left + 1) , {left , right}};	
		}
		
		sort(v.begin() , v.end());
		
		vector<bool> status(n , false);
		vector<string> ans;
		
		for(int i =0 ; i < 26 ; i++){
			int left = v[i].second.first;
			int right = v[i].second.second;
			bool ok = true;
			for(int j = left ; j <= right ; j++){
				if(status[j] == true){
					ok = false;
					break;
				}
			}
			if(ok){
				string add = "";
				for(int j = left; j <= right ; j++ ){
					status[j] = true;
					add += s[j];
				}
				ans.push_back(add);
			}
			
		}
		
		return ans;
    }
}; 
 
 
	
signed main(){
	fast;
	
	Solution obj;
	
	string s;
	cin >> s;
	
	vector<string> ans = obj.maxNumOfSubstrings(s);
	debug(ans);
	
	return 0;
}
