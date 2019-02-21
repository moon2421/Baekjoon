#include <cstdio>
#include <iostream>
#include <algorithm>


//연속합
//1. 이전꺼랑 더했을떄의값(나올수가없음 dp[i - 1]은 이전까지더한값의 연속합의최대값이므로)
//2. 이전 최대비용값 + 현재비용 이거나 현재값
//
//3.dp안에는 현재인덱스까지의 가장큰 연속합이 들어있음

using namespace std;
int dp[100001];
int arr[100001];


int main() {
	int n;

	cin >> n;//테스트케이스 수입력

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	//각 dp안에는 현재인덱스까지의 가장큰 연속합이들어있음
	for (int i = 2; i <= n; i++) {
		dp[i] = arr[i];
		if (dp[i - 1] + arr[i] > dp[i])
			dp[i] = dp[i - 1] + arr[i];
	
	}
	int m = dp[1];
	for (int i = 2; i <= n; i++) {
		m=max(m, dp[i]);
	}

	cout << m << '\n';


}

