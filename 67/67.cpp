/* 
USER: u252 
LANG: C++ 
TASK: TRIANGLE 
*/  
#include <cstdio>  
#include <algorithm>  
  
using namespace std;  
  
int main( void )  
{  
    int N;  
    freopen("triangle.txt","rt",stdin);  
    scanf("%d",&N);  
    int tri[N][N],dp[N][N],ans = 0;  
    for(int i = 0; i < N; i++) {  
        for(int j = 0; j<=i; j++ ) {  
            scanf("%d",&tri[i][j]);  
        }  
    }  
    dp[0][0] = tri[0][0];  
    for(int i = 1; i < N; i++ ) {  
        for(int j = 0; j <= i; j++ ) {  
            if( j == 0 ) {  
                dp[ i ][ j ] = dp[ i - 1 ][ j ] + tri[ i ][ j ];  
            }   
            else if( j == i ) {  
                dp[ i ][ j ] = dp[ i - 1][ j - 1] + tri[ i ][ j ];  
            } else {  
                dp[ i ][ j ] = max( dp[ i - 1][ j ], dp[ i -1 ][ j - 1 ] ) + tri[ i ][ j ];  
            }  
        }         
    }  
    for(int i = 0; i < N; i++ ) {  
        ans = max(ans,dp[ N - 1][ i ]);  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
