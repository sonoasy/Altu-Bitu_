#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//백준 20923번

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int>& deck, deque<int>& ground) { //deck, ground는 2개씩 있으므로 선택되는 deck-ground 간 카드 이동
    
    //그라운드에 카드가 있는동안
    while (!ground.empty()) {
        
        //기본덱 맨 뒤로, ground를 뒤집어서 옮기므로 바닥에 있는 카드부터 올김
        deck.push_back(ground.back());
        ground.pop_back(); //옮겼으므로 ground에서 카드 제거
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>>& deck, vector<deque<int>>& ground) {
    bool turn = false; //도도부터 시작 (도도가 deck,ground 0번째, 수연이 1번째)

    while (m--) { //m번 횟수가 끝나면 종료

        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front(); //기본 덱 맨 앞의 인덱스에 맨 위의 카드가 있음
        ground[turn].push_front(card);//그라운드에 올려놓기
        deck[turn].pop_front(); //덱의 맨 위의 카드 없애기

        //게임 진행 도중 둘 중 한 명의 덱에 있는 카드의 수가 0개가 되는 즉시 게임 종료
        if (deck[turn].empty())
            //종 치는것도 하지 않고 모든 게임 규칙 종료
            break;

        //이번에 종을 칠 사람

        int bell = -1;
        if (card == 5)//지금 차례 사람이 그라운드에 올려놓은 카드가 5라면
            bell = 0;  //도도가 종을 울림
        //모든 그라운드에 카드가 비지 않고, 현재 차례 사람이 자신의 그라운드 맨위에 올려놓은 카드와 상대방 그라운드 맨위 카드와의 합이 5라면
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5))
            bell = 1; //수연이 종을 울림


        //위의 두가지 경우로 종을치면 종을 친사람의 기본덱으로 상대방 그라운드카드를 가져가고, 자신의 그라운드카드도 가져간다
        if (bell != -1) { //누군가가 종을 쳤다면
            moveCard(deck[bell], ground[!bell]);
            moveCard(deck[bell], ground[bell]);
        }
        turn = !turn; //차례 바꾸기
    }

    //게임이 끝났으면 도도,수연의 덱 사이즈를 리턴한다
    return make_pair(deck[0].size(), deck[1].size());
}

/**
 * 1. 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 * 2. 게임을 진행하던 도중 언제든지 누군가의 카드 덱이 비게되면 게임을 종료
 */
int main() {

    //도도,수연이 가지는 카드갯수 n, 게임 진행하는 횟수 m, 중간 값 저장 매개변수num1,num2
    int n, m, num1, num2;

    //도도,수연의 기본 덱카드와 그라운드 카드 저장 
    vector<deque<int>> deck(2), ground(2);
    //n,m 입력
    cin >> n >> m;
    //카드갯수 만큼 도도,수연의 기본 덱에 값을 저장해준다
    while (n--) {
        //중간 매개변수 num1,num2를 사용
        cin >> num1 >> num2;
        //기본 덱 맨 아래부터 있는 값부터 입력받음(최종 입력 끝나면 0인덱스에는 맨 위에 있는 덱카드가 있음)
        deck[0].push_front(num1); //도도의 기본 덱
        deck[1].push_front(num2); //수연의 기본 덱
    }

    //게임 종료 후 도도,수연의 기본 덱의 크기를 result로 반환받는다
    pair<int, int> result = playGame(m, deck, ground);

   //크기가 같으면
    if (result.first == result.second)
        cout << "dosu\n"; //비김
    else if (result.first > result.second) //도도의 카드갯수가 많으면
        cout << "do\n"; //도도가 승리
    else if (result.first < result.second)//수연의 카드갯수가 많으면 
        cout << "su\n"; //수연이 승리
}
