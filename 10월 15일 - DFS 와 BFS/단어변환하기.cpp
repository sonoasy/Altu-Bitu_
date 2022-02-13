//테스트케이스 일부 실패

#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<map>
using namespace std;

//단어 유사도 판별문제..?
//words에 있는 문제만 가능
//최소 단계 -> bfs?
vector<int> arr;// begin이 변환가능한 word 내 단어 인덱스 

bool check(vector<string> words, string w,string t){
    int n=0; //target 있는지
    int m=0; //변환가능한 갯수
    
    for(int i=0;i<words.size();i++){
        string tmp=words[i];
        
        if(tmp==t)n++;
        int num=0;
        for(int j=0;j<tmp.size();j++){
            if(tmp[j]==w[j])continue;
            else num++;
        }
        if(num==1){
            m++;
            arr.push_back(i);
        }
        
        
    }
    if(n>0 && m>0) return true;
      
    return false;
}
vector<vector<int>> change(vector<string>words){ //words 내 변환 가능 연결관계 
    
    int len=words.size();
    
    vector<vector<int>> s;
    s.assign(len+1,vector<int>(len+1,0));
    
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            int ch=0;
            if(i==j)continue;
            for(int l=0;l<words[i].size();l++){
                if(words[i][l]==words[j][l])continue;
                else{
                    ch++;
                }
            }
            if(ch==1){
                s[i][j]=1;
                //반대편도 하기 
                s[j][i]=1;
            }
            
        }
        
    }
    return s;
    
}

//1 bfs에서 첫번째 처리, 확인하고 큐
//2 그냥 가고 앞에서 if로 확인하기 
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //begin-> words중 변환 가능한거 있는지, 없으면 0 있으면 큐에 넣기, 계속 반복 해서 target 되면 반복 횟수 리턴하기 
    //변환 가능한지는 단어 한글자 차이만 있어야함,target이 words에 있어야함 
    vector<vector<int>> find=change(words); //단어내 연결관계 벡터
    //vector<vector<int>> visited;
    
    
    if(check(words,begin,target)){
        queue<int>q;
        //vector로..?
        map<int,int>dist;
        //우선 변환가능한 첫번째 words내 단어를 큐에 넣음
        for(int i=0;i<arr.size();i++){
            
            q.push(arr[i]);
            dist[i]=1;
        }
        
        while(!q.empty()){
            int curi= q.front();
            q.pop();
            
            if(words[curi].compare(target)==0)return answer=dist[curi];
            
            for(int u=0;u<find.size();u++){ //변환가능한지
                
                
                if(find[curi][u]&&!dist[u]){ //변환가능한게 있다면 
                    dist[u]=dist[curi]+1;
                    q.push(u);
                    //숫자를 어떻게 세지..? 각 인덱스마다 값을 저장하는게 아니라 단계를 저장하는거?
                    
                }
                
            }
            
            
        }
        
    }
    else{
        return 0;
    }
    
    
    
    //return answer;
}
