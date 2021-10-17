#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<char> vc;
typedef std::vector<long long> vl;
#define f first 
#define s second

//based on Colin
//commented by Mello



using namespace std;


void test(){

	string g[25]; //the grid consisting of characters (char) of two types '*' and '.'
	ll best[25][25]; //this associates for each cell a number which is the distance
	//from the center measured as d, this is, as units from row of center and column of it
	//being the least distance from it 

	int n,m, k;
	cin >> n >> m >> k;

	//given a cell, we want to find the tick that painted that cell, with distance at least d
	//from this center, even though the distance can be longer than d
	for(ll i = 0; i < n; i++) cin >> g[i];
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			ll d = 0; //for each grid cell we associate a "tick distance"
			while(1){
				if(i - d < 0 || j - d < 0 || j + d >= m) break; 

				if(g[i-d][j-d] != '*') break;
				if(g[i-d][j+d] != '*') break;
				

				++d; //we sum to d each time we find something painted
				//for an arbitrary cell
			}
			best[i][j] = d - 1; //we subtract one for the center

		}
	}
	bool pos = 1;

	//for each grid cell verify if painted 
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(g[i][j] == '*'){
				bool f = 0; //f determines whether we will find or not a center
				ll d = 0;
				while(1){

					if(i + d >= n)break; //out of the grid

					if(j-d >= 0 && j - d < m){ //in the grid

						if(best[i+d][j-d] >= k && best[i+d][j-d] >= d){// we go bottom left
							f = 1;
							break;
						}
					}
					if(j+d >=0 && j+d < m){ //in the grid
						if(best[i+d][j+d] >= k && best[i + d][j + d] >= d){ // we go bottom right
							f = 1;
							break;
						}
					}
					++d;

				}

				pos &= f; //this is pos = pos && f, if f is false so is pos
			}
		}
	}
	cout << (pos ? "YES\n" : "NO\n");
}

int main(){

  int t;
    cin >> t;
    while(t--){
        
        test();
    }
    

}
