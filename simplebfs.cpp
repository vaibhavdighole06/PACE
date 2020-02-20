#include<bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
 
bool vis[10001];
ll dist[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        vector<ll> v[10001];
        queue<ll> q;
        memset(vis,false,sizeof vis);
        memset(dist,0,sizeof dist);
        ll n,m;
        cin>>n>>m;
        while(m--)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);v[y].push_back(x);
        }
        q.push(1);
       // ll cnt=0;,
    //   for(ll i=0;i<100;i++)
    //   cout<<vis[i]<<" ";
        while(!q.empty())
        {
            ll p = q.front();
            q.pop();
            if(!vis[p])
            vis[p]=true;
            
            for(auto it :v[p])
            {
                if(vis[it]==false)
                {
                    //cout<<p<<" "<<it<<"\n";
                    dist[it] = dist[p]+1;
                    vis[it]=true;
                    q.push(it);
                    
                }
            }
        }
        //cout<<"\n";
        cout<<dist[n]<<"\n";
    }
}