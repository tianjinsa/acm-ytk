#include <iostream>
#include <vector>
#include <numeric>
#include <map>
using namespace std;
long long MOD = 1e9 + 7;
long long qpow(long long a, long long b)
{
    // cout<<"qpow(" << a << ", " << b << ") = " ;
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    // cout<< res << endl;
    return res;
}
long long total_mystic_count = 0, total_ways = 1, num[3];
int n, m ,arrsize;
vector<int> a,mpow;
vector<int> minus_one_indices;

void generate_and_check(int k_idx)
{
    int &original_pos = minus_one_indices[k_idx];

    for (int val = 0; val <= 2; ++val)
    {
       //  cout << string(k_idx * 3, ' ')<< "(Try " << val << " at " << original_pos+1 << ')' << endl;
        a[original_pos] = val;
        long long tt = total_ways;
        total_ways = (total_ways * num[val]) % MOD;
       //  cout << string(k_idx * 3, ' ')<< " tw * " << num[val] << endl;
        if (val == 0 || (val == 1 && ((original_pos > 0 && a[original_pos - 1] == 1)||(original_pos < n-1&& a[original_pos + 1] == 1)|| original_pos == n-1|| original_pos == 0 )))
        {
            long long ts = (total_ways * mpow[arrsize - k_idx - 1] )% MOD;
             //cout << string(k_idx * 3, ' ')<< "@ ts add <" << ts << "> from " << total_ways << endl;
            total_mystic_count = (total_mystic_count + ts) % MOD;
        }
        else if (k_idx + 1 != arrsize)
        {
            // cout << string(k_idx * 3, '>')<< ">>>" <<" tw = "<<total_ways<<endl;
            generate_and_check(k_idx + 1);
            // cout << string(k_idx * 3, '<')<< "=< tw 还原到 " << tt << endl;
        }
        total_ways = tt;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    num[0] = n - 2;
    num[1] = 1;
    num[2] = m - n + 1;
    a.resize(n);
    int fl = 0, num1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == -1)
        {
            minus_one_indices.emplace_back(i);
        }
        else if (a[i] == 1)
        {
            num1++;
            if (i > 0 && a[i - 1] == 1)
            {
                fl = 2;
            }
        }
        else if ((1 < a[i] && a[i] <= n - 1))
        {
            fl = 1;
        }
    }
    arrsize=minus_one_indices.size();
    mpow.resize(arrsize+1);
    long long tpow=1;
    for(int i=0;i<=arrsize;i++){
        mpow[i]=tpow;
        tpow=(tpow*m)%MOD;
    }
    if (((a[0] == 1 || a[n - 1] == 1)))
    {
        if (n % 2 == 0)
            fl = 1;
        else
            fl = 2;
    }
    if (fl == 2)
    {
        if (num1 + arrsize != n)
        {
            fl = 1;
        }
    }
    if(!arrsize){
    cout<<0;
    return 0;}
    if (fl == 1)
    {
        cout <<mpow[arrsize]<< endl;
        return 0;
    }
    else if (fl == 2)
    {
        cout << (mpow[arrsize] - 1 + MOD) % MOD << endl;
        return 0;
    }
    else
    {
        generate_and_check(0);
        
        cout << (total_mystic_count + MOD) % MOD << endl;
    }

    return 0;
}