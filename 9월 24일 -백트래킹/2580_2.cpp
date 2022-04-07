#include <iostream>
#include <vector>
using namespace std;



bool found=false;

vector<vector<int>>sudoku3(9, vector<int>(9, 0)); 

bool promising(int r,int c, int n){
	for(int i=0;i<9;i++){ //행,렬 확인
		if(sudoku3[i][c]==n || sudoku3[r][i]==n) return false;
	}
	//3x3구역 확인
  int row_area=r/3;
	int col_area=c/3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(sudoku3[(row_area*3)+i][col_area*3+j]==n)return false;
		}
	}
	return true;
	
}

void go(int idx){
	
	

	if(idx==81){
		found=true;
		return ;
		//return sudoku;
	}
	int r=idx/9;
	int c=idx%9;
	if(sudoku3[r][c]) return go(idx+1); //0이 아니면 넘어가기, 리턴 아니면 오류됨, 탐색자체를 하지 말아야 하므로 
	//if(sudoku3[row][col]==0){
		for(int i=1;i<=9;i++){
		  if(promising(r,c,i)){
				sudoku3[r][c]=i;
				go(idx+1);
				if(found)return;
				sudoku3[r][c]=0;
				
			}
		
		}

}
	
vector<vector<int>> solution(vector<vector<int>>sudoku){
    
	sudoku3=sudoku;
  //go(0,sudoku2);
	go(0);
  return sudoku3;
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

