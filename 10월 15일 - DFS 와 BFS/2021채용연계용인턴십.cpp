#include <string>
#include <vector>
#include<queue>
using namespace std;

//처음 생각한 방법: 맨해튼 거리가 2인 지점이면 체크해서 1로 지정-> 파티션,테이블 처리 어떻게?
//bottom-up? 맨해튼 거리1부터 체크 상하좌우,그다음 자리 원래위치 제외 상하좌우 체크하면 멘해튼 거리2임!!!
//bsf+dp문제?
//맨해튼 거리가 2=> 대각선 + 같은 행열 2칸 위 x 
//두 응시자 주위에 파티션 있으면 ok
//p:응시자 o:빈테이블 x: 파티션

//int dr[8]={1,1,-1,-1,2,-2,0,0};//대각선 왼위,오위,왼아,오아, 상2,하2,좌2,우2
//int dc[8]={-1,1,-1,1,0,0,-2,2};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};



string cases[5];

bool bfsdp(int k,int s){ //거리두기가 되어는지 체크하는 함수, 맨해튼 거리2 내이고, p가 있는지를 탐색해서 결과리턴  

    queue<pair<int,int>>q; //응시자 위치 저장
    int check[5][5]={{0}};
    q.push({k,s});
    check[k][s]=1; //다녀간거 체크해주려고
    
    while(!q.empty()){
            
        
            int curr=q.front().first;
            int curc=q.front().second;
            q.pop();
            if(check[curr][curc]>=3)continue;//return true; //맨해튼거리 3되도록 아무 문제 없으면 1     >3하면 틀렸는데 >=3하니까 맞음!!!!3이 되는이유는 이미 맨해튼거리2에서 통과된 큐이기때문인듯   
             //모든방면이므로 return true보다 continue가 더 적
            for(int w=0;w<4;w++){
                
                int nextr=curr+dx[w];
                int nextc=curc+dy[w];
                
                //주변 +1이 엉망인 느낌.. 큐 초기화해서 사용 
                if(nextr>=0 && nextr<5 && nextc>=0 && nextr<5 &&!check[nextr][nextc] ){//아직 안간데면
                    check[nextr][nextc]=check[curr][curc]+1;
                    if(cases[nextr][nextc]=='P'){
                        return false;
                    }   
                    if(cases[nextr][nextc]=='O' )q.push({nextr,nextc});            
                    
                }
                   
            }
                
            
        }
        
     return true;
}

bool distances(){
    for(int k=0;k<5;k++){
            for(int s=0;s<5;s++){
                if(cases[k][s]=='P'){
                    if(!bfsdp(k,s)){return false;} //주변을 탐색하려는 응시자, 큐를 각각마다 초기화하기 
                    else continue;
                }
            }
        }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    
    //각 케이스당 탐색해서 answer에 저장하기
    vector<int> answer;
   
  
    
    for(int i=0;i<places.size();i++){//대기실 상태 입력
        int res=0;
        
        for(int j=0;j<5;j++){
            cases[j]=places[i][j];
            
        } 
        res+=distances();
       
        if(res){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
       
    }
    
    return answer;
}
