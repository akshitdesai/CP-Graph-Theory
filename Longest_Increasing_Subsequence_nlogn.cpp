/* Author :- codestromer */




#include<bits/stdc++.h>
#define ll long long
using namespace std;
//only length
ll lenofLIS(vector<ll> v,ll n){
    vector<ll> temp(n,0);
    ll length = 1;
    temp[0]=v[0];
    for(int i = 0; i < n; i++){
        //return pointer to
        //(the position of Biggest small number then v[i] + 1 )
        //instead you can do binary search in the array
        auto it = lower_bound(
            temp.begin(),temp.begin()+length,v[i]);
        //if it's largest then increase the length of LIS
        if(it == temp.begin() + length)
            length++;
        //update the value
        *it = v[i];
    }
    return length;
}
// Binary search
int GetCeilIndex(vector<ll> v, vector<ll>& T, ll l, ll r,
                 ll key){
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[T[m]] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}
//Construction save
ll constructLIS(vector<ll> v,ll n){
    vector<ll> tailIndex(n,0);
    vector<ll> prevIndex(n,-1);
    ll length = 1;
    for(int i = 1; i < n; i++){
        if (v[i] < v[tailIndex[0]]) {
            // new smallest value
            tailIndex[0] = i;
        }else if (v[i] > v[tailIndex[length - 1]]){
            //new biggest value
            //expand the LIS
            prevIndex[i] = tailIndex[length - 1];
            tailIndex[length++] = i;
        }else{
            int pos = GetCeilIndex(v,tailIndex,-1,length-1,v[i]);
            prevIndex[i] = tailIndex[pos - 1];
            tailIndex[pos] = i;
        }
    }
    for (int i = tailIndex[length - 1]; i >= 0; i = prevIndex[i])
        cout << v[i] << " ";
    cout<<'\n';
    return length;
}
int main(){
    ll n,temp;
    cin>>n;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        cin>>temp;
        v.push_back(temp);
    }
    cout<<constructLIS(v,n)<<'\n';
}
