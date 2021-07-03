#define ll long long
#define M 1000000007
vector<vector<ll int>>nCrdp(101,vector<ll int>(101,-1));


ll int choose(ll int n, ll int r){
    if(r > n){
        return 0;
    }
    if(n <= 1) return 1;
    if(r == 0) return 1;
    if(r == 1) return n;
    if(nCrdp[n][r] != -1){
        return nCrdp[n][r];
    }
    ll int res = (choose(n-1,r-1) + choose(n-1,r))%M;
    nCrdp[n][r] = res;
    return res;
    
}
int NumOfNodesOnLeft(ll int A){
    int h = log2(A);
    int x = ((1<<(h-1)) - 1);
    int y = min((1LL<<(h-1)), (A - ((1<<h)-1)));
    return x+y;
}

ll int getNumOfMaxHeaps(int A, vector<ll int> &dp){
    if(A <= 1){
        return 1;
    }
    if(dp[A] != -1){
        return dp[A];
    }
    ll int L = NumOfNodesOnLeft(A);
    ll int waysToChooseL = choose(A-1,L)%M;
    ll int maxHeapsUsingL = getNumOfMaxHeaps(L,dp)%M;
    ll int maxHeapsUsingR = getNumOfMaxHeaps(A-1-L,dp)%M;
    ll int ans = ((waysToChooseL%M)*((maxHeapsUsingL*maxHeapsUsingR)%M))%M;
    dp[A] = ans;
    return ans;
}
int Solution::solve(int A) {
    vector<ll int> dp(101,-1);
    return getNumOfMaxHeaps(A,dp);
}
