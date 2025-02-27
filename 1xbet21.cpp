#include <bits/stdc++.h>
using namespace std;

// boost & macro
#pragma optimize("O3")
#define nmax 200005
#define pint pair<int, int>
#define pong pair<ll, ll>
#define pool pair<bool, bool>
#define vint vector<int>
#define vong vector<ll>
#define stkii stack<int>
#define stkll stack<long long>
#define fi first
#define se second
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uii;

#define oo ((ll)1e18)

// necessary
ll n = 0, m = 0, k = 0, t = 0, tmp = 0, ans = 0, run = 0, ins = 0;
bool chk = 0;
str s;
ll rr[nmax];

// optional
struct setOfCard{
	str name[9] = {"6", "7", "8", "9", "10", "j", "q", "k", "a"}; // names for cards
	pong val[9] = {
		{6, 4}, 
		{7, 4},
		{8, 4},
		{9, 4},
		{10, 4},
		{2, 4},
		{3, 4},
		{4, 4},
		{11, 4}
	}; // (value, count)
};
setOfCard cardSet;
str fin1, fin2;
vong dealer, player;
ll dealerVal, playerVal;
ll numLose, numWin, numNull;
vong vt;

// funcs
ll getNumCard(str inp){
	for(ll i = 0; i < 9; ++i){
		if(cardSet.name[i] == inp) return i;
	}
}

void recurDealer(ll val, ll node){
	if(val > 21){
		++numWin;
		// for(ll i = 0; i < vt.size(); ++i){
			// cout << cardSet.name[vt[i]] << " ";
		// }
		// cout << val << "lose\n";
		return;
	}
	if(val >= 17 && val < node){
		++numWin;
		// for(ll i = 0; i < vt.size(); ++i){
			// cout << cardSet.name[vt[i]] << " ";
		// }
		// cout << val << "lose\n";
		return;
	}
	if(val >= 17 && val == node){
		++numNull;
		// for(ll i = 0; i < vt.size(); ++i){
			// cout << cardSet.name[vt[i]] << " ";
		// }
		// cout << val << "null\n";
		return;
	}
	if(val >= 17 && val > node){
		++numLose;
		// for(ll i = 0; i < vt.size(); ++i){
			// cout << cardSet.name[vt[i]] << " ";
		// }
		// cout << val << "win\n";
		return;
	}
	for(ll i = 0; i < 9; ++i){
		for(ll j = 0; j < cardSet.val[i].se; ++j){
			--cardSet.val[i].se;
			val += cardSet.val[i].fi;
			vt.emplace_back(i);
			recurDealer(val, node);
			val -= cardSet.val[i].fi;
			++cardSet.val[i].se;
			vt.pop_back();
		}
	}
}

int main(){
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	dealer.emplace_back(0);
	dealer.emplace_back(0);
	player.emplace_back(0);
	player.emplace_back(0);
	
	cout << "Input Dealer cards: (e.g. 8 k)\n";
	cin >> fin1 >> fin2;
	dealer[0] = getNumCard(fin1);
	dealer[1] = getNumCard(fin2);
	--cardSet.val[dealer[0]].se;
	--cardSet.val[dealer[1]].se;
	dealerVal += cardSet.val[dealer[0]].fi;
	dealerVal += cardSet.val[dealer[1]].fi;
	
	cout << "Input Player cards: (e.g. q 6)\n";
	cin >> fin1 >> fin2;
	player[0] = getNumCard(fin1);
	player[1] = getNumCard(fin2);
	--cardSet.val[player[0]].se;
	--cardSet.val[player[1]].se;
	playerVal += cardSet.val[player[0]].fi;
	playerVal += cardSet.val[player[1]].fi;
	
	cout << "Dealer: " << dealerVal << "\n";
	cout << "Player: " << playerVal << "\n";
	
	while(true){
		numLose = 0;
		numWin = 0;
		numNull = 0;
		recurDealer(dealerVal, playerVal); // value
		cout << numWin << " " << numNull << " " << numLose << "\n";
		cout << "If STOP, Win: " << (double ((double (numWin))/(double (numWin+numLose))))*100 << "%" << "\n";
		
		numLose = 0;
		numWin = 0;
		numNull = 0;
		tmp = playerVal;
		for(ll i = 0; i < 9; ++i){
			for(ll j = 0; j < cardSet.val[i].se; ++j){
				tmp += cardSet.val[i].fi;
				if(tmp > 21){
					++numLose;
				}else ++numWin;
				tmp -= cardSet.val[i].fi;
			}
		}
		cout << numWin << " " << numNull << " " << numLose << "\n";
		cout << "If CONTINUE, Safe: " << (double ((double (numWin))/(double (numWin+numLose))))*100 << "%" << "\n";
		cout << "Next card: (If STOP, then -1)\n";
		cin >> s;
		if(s == "-1") break;
		else{
			tmp = getNumCard(s);
			player.emplace_back(tmp);
			playerVal += cardSet.val[tmp].fi;
			--cardSet.val[tmp].se;
		}
	}
	cout << "STOPED\n";
	
	
}

// COMMENT:

/* <<<CODE EXPLANATION>>>



*/


/* <<<CRE>>>

I, Sheyer, guaranteed that the idea for this code is personally made up by me: <Sheyer>
In case it is not, I give credit to the original Author:

I, Sheyer, guaranteed that this code is originally created by me, based on the idea mentioned above: <Sheyer>

In belief of h1a4c3k, a long lost account

*/
