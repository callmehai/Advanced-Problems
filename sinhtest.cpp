#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#include <cstring>
#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <span>
#include <semaphore>
#include <version>
#endif

#if __cplusplus > 202002L
#include <spanstream>
#endif
// #include<bits/stdc++.h>
using namespace std;
// ************ start coding ************
const int N=2e6+5;
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
int main()
{
    char x[]="out000.txt";
    int num_test=50;
    for(int ii=1;ii<=num_test;ii++)
    {
        string s=to_string(ii);
        int k=5;
        int u=(int)s.size()-1;
        while(u>=0)
        {
            x[k--]=s[u--];
        }
        freopen(x, "w", stdout);
        int n,d,z;
        if(ii<=10)
        {
            z=500;
            n=rand()%100+100;
            d=min(n-1,z/n);
        }
        else if(ii<=20)
        {
            z=2000;
            n=rand()%500+1000;
            d=min(n-1,z/n);
        }
        else if(ii<=30)
        {
            z=20000;
            n=rand()%5000+10000;
            d=min(n-1,z/n);
        }
        else if(ii<=40)
        {
            z=200000;
            n=rand()%50000+100000;
            d=min(n-1,z/n);
        }
        else
        {
            z=2000000;
            n=200000;
            d=10;
        }
        cout<<n<<' '<<d<<'\n';
        cout<<1;
        for(int i=2;i<n;i++) cout<<((rand()%100)<80);
        cout<<1;
    }
}
