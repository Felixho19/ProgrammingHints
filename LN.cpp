#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int max_d = 10;
const int max_length = 18;

LL dp[max_length + 1][max_d + 1][max_d + 1];
int digits[max_length + 1];
int len;

LL rec(int pos, int s1, int s2, int chk)
{
    if(pos == -1){
        if(s2 == 6 || s2 == 8)
            return 1;
        if(s1 == 6)
            return 1;
        if(s1 == 8)
            return 1;  
        return 0;
    }

    if(!chk && dp[pos][s1][s2] != -1)
        return dp[pos][s1][s2];

    LL ans = 0;
    int end = chk ? digits[pos] : 9;

    for(int d = 0 ; d <= end; d++) {
        if(d == 6 && s2 == 8){
            continue;
        }else if(d == 8 && s2 == 6){
            continue;
        }else if(d == 6 || d == 8){
            ans += rec(pos - 1 , d , d , chk && d == end);
        }else{
            ans += rec(pos - 1 , d , s2 , chk && d == end);
        }
    }
    if(!chk)
        dp[pos][s1][s2] = ans;

    return ans;
}

LL get_ans(LL num) {

    if(num == 0)
        return 0;

    len = 0;

    while(num){

        digits[len++] = num % 10;
        num /= 10;
    }

    LL ans = rec(len - 1, 0, 0, 1);
    return ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    LL a, b;
    cin >> a >> b;
    cout << get_ans(b) - get_ans(a - 1) << endl;
    return 0;
}
