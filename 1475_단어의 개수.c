/*
dequeue() -> 앞에서 데이터를 꺼내는 함수 [가장 먼저 들어온 데이터가 먼저 나감]
is_empty() -> 큐가 비어있는지 확인 [비어있으면 '1' / 데이터가 존재하면 '0'을 반환]
strlen() -> 문자열의 길이 & 글자 수를 구하는 함수
ceil() -> 올림 함수 [2.1 -> 3 / 4.5 -> 5]

※ 문자 빼기 -> '9' - '0' = [아스키코드] 57 - 48 = 9 [문자 9를 숫자 9로 바꾸는 방법]
*/

// 1. 문자열로 방 번호 입력
// 2. 문자 하나씩 큐에 넣기
// 3. 큐에서 꺼내서 숫자 세기
// 4. 6,9는 서로 바꿔 쓸 수 있음으로 합쳐서 처리
// 5. 가장 많이 나온 숫자의 개수 출력
// 6. 결과 출력

#include <stdio.h>
#include <string.h> // 문자열 함수
#include <math.h> // 수학 함수

#define MAX 10000

// 전역 큐 선언
char queue[MAX]; // 문자형 Q 배열
int front = 0; // 큐를 빼내는 함수 [맨앞]
int rear = 0; // 큐를 삽입하는 함수 [맨뒤]

void enqueue(char date) // 큐에서 데이터 넣기
{
	if (rear >= MAX) // 큐가 가득찼는지 확인
	{
		return;
	}
	queue[rear++] = date; // 끝 위치를 한칸 이동
}

char dataout() // 큐에서 데이터 꺼내기
{
	if (front == rear) // 큐가 비었으면 출력
	{
		return -1; // 큐가 비었다는 신호 -1 값을 반환
	}
	return queue[front++]; // 꺼낼 위치를 다음 칸으로 이동
}

int is_empty() // 큐가 비었는지 확인
{
	return front == rear;
}

int main() 
{
	char room[MAX]; // 방번호 지정 문자열
	int count[10] = { 0 }; // 0 ~ 9까지 각각 몇번 나갔는지 저장하는 배열
	int i, max = 0; // Max 값 0으로 초기화
	int six_nine = 0; // 6,9 합친 값

	scanf("%s", room);

	for (i = 0; i < strlen(room); i++) // 문자 하나씩 Q에 저장
	{
		enqueue(room[i]); // room 길이만큼 반복
	}

	while (!is_empty()) // 비여있지 않으면 반복
	{
		char ch = dataout(); // 데이터 꺼내기
		int change = ch - '0';  // 문자를 숫자로 변환
		count[change]++; // 등장 횟수를 배열로 기록
	}

	six_nine = count[6] + count[9]; // 6, 9를 함께 사용 가능함으로 합쳐서 처리
	count[6] = count[9] = (int)ceil(six_nine / 2.0); // 합친 수를 2로 나누고 올림 - ceil

	for (i = 0; i < 10; i++) 
	{
		if (count[i] > max)
			max = count[i]; // 가장 많이 필요한 갯수를 세트에 저장
	}

	printf("%d\n", max);

	return 0;
}
