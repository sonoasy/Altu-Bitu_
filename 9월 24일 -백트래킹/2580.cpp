#include <iostream>
#include <vector>
using namespace std;

//마지막에 도착지점, 체크해야할것은 아는데 루프를 어떻게 돌릴지 모르겠음->
//함수 인자 인덱스 idx+1  행: idx/9, 열:idx%9  3x3인덱스: r/3*3+c/3(행은+3씩)

//0인부분을 하나씩 탐색하기 보다 모든 좌표를 하나씩 탐색하기 
//가능한지 체크하는걸 입력부분에서 처리해버리기 
//큐..?

//10이 나오는이유...? -> 함수에 &vector<vector<int>> 부분 문제 :
bool rowcheck[9][10]={{false}};
bool colcheck[9][10]={{false}};
bool boxcheck[9][10]={{false}};
bool found=false;

vector<vector<int>>sudoku2;
void go(int idx){//,vector<vector<int>>&sudoku){
	
	int row=idx/9;
	int col=idx%9;
	int box=(row/3)*3+col/3;
	if(idx==81){
		found=true;
		return;
		//return sudoku;
	} 
	if(sudoku2[row][col]) return go(idx+1); //0이 아니면 넘어가기, 리턴 아니면 오류됨, 탐색자체를 하지 말아야 하므로 
	//if(sudoku[row][col]==0){
		for(int i=1;i<=9;i++){
		  if(!rowcheck[row][i] && !colcheck[col][i] && !boxcheck[box][i]){
			//해당 숫자를 체크해줌 
			  rowcheck[row][i]=true;
			  colcheck[col][i]=true;
			  boxcheck[box][i]=true;
			  sudoku2[row][col]=i;
			  go(idx+1);
			 if(found)return;  //이거 안하면 오류뜸 : 중간에 답을 찾았는데 계속 다른 케이스 찾아서 바꾸면 x
			  rowcheck[row][i]=false;
			  colcheck[col][i]=false;
			  boxcheck[box][i]=false;
			  sudoku2[row][col]=0;
	  	}
		
		}
	//}
	//else {
		
	//	return go(idx+1,sudoku); //그 외에는 바로 다음단계로 감 
		
	//}	
}
	
	
	
	

vector<vector<int>> solution(vector<vector<int>>sudoku){
    
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(sudoku[i][j]!=0){
				rowcheck[i][sudoku[i][j]]=true;
				colcheck[j][sudoku[i][j]]=true;
				boxcheck[(i/3)*3+j/3][sudoku[i][j]]=true;
			}
		}
	}
	//하나씩 다 탐색해보기 
	
	vector<vector<int>> answer(9, vector<int>(9, 0));  // 정답 = 현재의 상태를 저장하는 배열
	sudoku2=sudoku;
  go(0);
	  
  return sudoku2;
}
int main(){
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) cin >> sudoku[i][j];
    }
    auto output = solution(sudoku);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) cout << output[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

