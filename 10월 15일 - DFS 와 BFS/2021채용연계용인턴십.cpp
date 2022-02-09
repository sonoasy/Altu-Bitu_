#include <string>
#include <vector>
#include<queue>
using namespace std;

//처음 생각한 방법: 맨해튼 거리가 2인 지점이면 체크해서 1로 지정-> 파티션,테이블 처리 어떻게?
//bottom-up? 맨해튼 거리1부터 체크 

//맨해튼 거리가 2=> 대각선 + 같은 행열 2칸 위 x 
//두 응시자 주위에 파티션 있으면 ok
//p:응시자 o:빈테이블 x: 파티션

int dr[8]={1,1,-1,-1,2,-2,0,0};//대각선 왼위,오위,왼아,오아, 상2,하2,좌2,우2
int dc[8]={-1,1,-1,1,0,0,-2,2};

int x[4]={1,-1,0,0};
int y[4]={0,0,-1,1};
queue<pair<int,int>>q; //응시자 위치 저장
vector<int> solution(vector<vector<string>> places) {
    
    //각 케이스당 탐색해서 answer에 저장하기
    vector<int> answer;
    //vector<string>case;
    string cases[5];
    
    for(int i=0;i<places.size();i++){//대기실 상태 입력
        int res=0;
        
        for(int j=0;j<5;j++){
            cases[j]=places[i][j];
            
        } 
        for(int k=0;k<5;k++){
            for(int s=0;s<5;s++){
                if(cases[k][s]=='P')q.push({k,s});
            }
        }
        while(!q.empty()){
            
            int curr=q.front().first;
            int curc=q.front().second;
            q.pop();
            
            
            for(int w=0;w<8;w++){
                if(res)continue;
                int nextr=curr+dr[w];
                int nextc=curc+dc[w];
                
                if(nextr>=0 && nextr<5 && nextc>=0 && nextr<5){
                   if(cases[nextr][nextc]=='P'){
                      res=1; 
                        
                   }    
                }
                
               
            }
            
        
        }
        //answer.push_back(res);
    }
    
    return answer;
}
