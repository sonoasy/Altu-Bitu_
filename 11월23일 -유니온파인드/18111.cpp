#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; 

int mineLand(int n, int m, int b, int height, vector<vector<int>>& land) {//땅고르기 작업
    int tot_time = 0; //0부터 시작
    for (int i = 0; i < n; i++) {//n개의
        for (int j = 0; j < m; j++) {//m개에 대하여
            if (land[i][j] > height) { //블록 제거
                b += (land[i][j] - height);//작업갯수 갱신
                tot_time += 2 * (land[i][j] - height);//2초 걸림
            }
            else if (land[i][j] < height) { //블록 쌓기
                b -= (height - land[i][j]);//작업갯수 갱신
                tot_time += (height - land[i][j]);//1초걸림
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1;//무한대 리턴
    return tot_time;//그외에는 총 시간 리턴
}

/**
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */
int main() {
    int n, m, b, min_height = 256, max_height = 0; //n개의 줄 m개의 땅 높이 , 높이 최대/ 최소

    //입력
    cin >> n >> m >> b;
    vector<vector<int>> land(n, vector<int>(m, 0)); //land 벡터
    for (int i = 0; i < n; i++) {//n개의 줄에 
        for (int j = 0; j < m; j++) {//m개 입력
            cin >> land[i][j];//입력
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0;
    for (int i = min_height; i <= max_height; i++) {//최소 높이-최대 높이 탐색
        int t = mineLand(n, m, b, i, land); //탐색
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t;//시간
            height = i;//높이
        }
    }

    //출력
    cout << min_time << ' ' << height;
}
