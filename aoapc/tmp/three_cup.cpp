#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using  namespace std;
struct Status{
    int water[3];
    int time;
}bg,ed;
int v[3];
bool vis[105][105][105];
int dir[6][3] = {{0, 1, 2}, {1, 0, 2}, {0, 2, 1}, {2, 0, 1}, {1, 2, 0}, {2, 1, 0}};
int d[6] = {1, 0, 2, 0, 2, 1};
void BFS(Status s){
    queue<Status> que;
    que.push(s);
    memset(vis, false, sizeof(vis));
    vis[bg.water[0]][0][0] = true;
    while(que.empty() == false){
        Status s1 = que.front(), s2;
        que.pop();
        if(s1.water[0] == ed.water[0] && s1.water[1] == ed.water[1] && s1.water[2] == ed.water[2]){
            printf("%d\n", s1.time);
            return;
        }
        for(int i=0; i<6; i++){
            if(s1.water[dir[i][0]] != 0 && s1.water[dir[i][1]] != v[d[i]]){// 1 -> 2
                if(s1.water[dir[i][0]] + s1.water[dir[i][1]] > v[d[i]]){//倒不尽 
                    s2.water[dir[i][0]] = s1.water[dir[i][0]] - (v[d[i]] - s1.water[dir[i][1]]);
                    s2.water[dir[i][1]] = v[d[i]];
                }else{//倒得尽 
                    s2.water[dir[i][0]] = 0;
                    s2.water[dir[i][1]] = s1.water[dir[i][0]] + s1.water[dir[i][1]];
                }
                s2.water[dir[i][2]] = s1.water[dir[i][2]]; 
                if(vis[s2.water[0]][s2.water[1]][s2.water[2]] == false){
                    s2.time = s1.time + 1;
                    que.push(s2);
                    vis[s2.water[0]][s2.water[1]][s2.water[2]] = true;
                }
            }
        }
    }
    puts("-1");
}
int main(){
    int T;
    scanf("%d", &T);    
    while(T--){
        for(int i=0; i<3; i++)
            scanf("%d", &v[i]);
        scanf("%d%d%d", &ed.water[0], &ed.water[1], &ed.water[2]);
        if(v[0] != ed.water[0] + ed.water[1] + ed.water[2]){
            puts("-1");
            continue;
        }
        bg.water[0] = v[0];
        bg.water[1] = bg.water[2] = bg.time = 0;
        BFS(bg);
    }
    return 0;
}