// https://lightoj.com/problem/back-to-underworld

#include <bits/stdc++.h>
using namespace std;
vector<int>edges[20005];
queue<int>q;
long long int color[20005],visited[20005],tn,c,d,x,j,ch,s,i,sum;

int bipartite()
{
    long long int k,fr;
    sum=0;
    for(tn=1;tn<=20005;tn++)
    {
        ch=edges[tn].size();
        c=0;
        d=0;
        if(visited[tn]==0 && ch>=1)
        {
            s=tn;
            color[s]=1;
            d=d+1;
            q.push(s);
            visited[s]=1;

            while(!q.empty())
            {
                fr=q.front();

                for(k=0;k<edges[fr].size();k++)
                {

                    if(visited[edges[fr][k]]==0 && color[edges[fr][k]]==-1)
                    {
                         q.push(edges[fr][k]);
                         visited[edges[fr][k]]=1;
                         color[edges[fr][k]]=1-color[fr];
                         if(color[edges[fr][k]]==0)
                         {
                             c++;

                         }
                         else if(color[edges[fr][k]]==1)
                         {
                             d++;
                         }

                    }


                }
                q.pop();
                x=max(c,d);


            }
                sum=sum+max(c,d);
        }

    }




}


int main()
{
    long long int e,p,n,u,v,f,m,t,z,y,tf;
    cin>>t;
    for(y=1;y<=t;y++)
    {
        cin>>e;
        memset(edges,0,sizeof edges);
        memset(visited,0,sizeof visited);
        memset(color,-1,sizeof color);
        for(tf=0;tf<e;tf++)
        {
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);


        }
        bipartite();

        cout<<"Case "<<y<<": "<<sum<<endl;

    }

    return 0;
}




