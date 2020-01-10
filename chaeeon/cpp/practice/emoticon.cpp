#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_NUM 1010

int main(){
    int n;
    int dp[MAX_NUM*2+10]={0};
    dp[1] = 0;
    for (int i=2; i<=MAX_NUM; i++) {
        dp[i] = i;
    }
    scanf("%d", &n);
    for (int i=2; i<=n; i++) {
        int cur=i;
        int cnt=1;

        // dp[S] : 회면에 S개 이모티콘이 있을 때, 최소 횟수
        
        // S 번째 최소 횟수 중에서
        // S+1에서 하나 뺏을 때랑 비교
        dp[cur] = min(dp[cur], dp[cur+1] + 1);

        // S 번째에서, S개를 복사해서 붙여넣기 하면 2번 
        dp[cur+i] = min({dp[cur+i], dp[cur] + 2, dp[cur+i+1] + 1});
        while (cur + i * cnt<MAX_NUM) {
            cnt++;
            // S 번째에서, S개를 복사해서 붙여넣기를 cnt번 하는거
            dp[cur+i*cnt] = min({dp[cur] + cnt - 1 + 2, dp[cur + i * cnt], dp[cur + i * cnt + 1] + 1});
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
