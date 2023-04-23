#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define ALL(v) v.begin(), v.end()
#define sz(arr) ((int) arr.size())

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9; // INF + INF = overflow --> 1e9/2-1;
const ll INFL = 1e18; // INF + INF = overflow --> 1e18/2-1;
const ll PI = acos(-1);
const int MOD = 1e9+7;
const ll EPS= 1e-9;
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
char dirT[4] = { 'L', 'D', 'U', 'R'};

#endif
