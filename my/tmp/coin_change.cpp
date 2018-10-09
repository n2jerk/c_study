#define NUM 7
//int money[NUM] = {1, 2, 5, 10, 20, 50, 100};  
int money[NUM] = {1, 3, 4, 10, 20, 50, 100};
// 动态规划解法(完全背包)   
int NumOfCoins(int value)  
{  
	int dp[7][1010];  
	for(int i = 0; i <= value; ++i)
		dp[0][i] = 1;  //why 1 ? 所有的钱数为i都有一种就是用全1来表示。若果给出的钱不能用money中的钱表示，或者说money中没有为1的零钱呢？
// dp[0][j] = 1 为1是全用1来表示；for循环里会让dp[i][0] = 1 表示money[i] 本身就是一种方案
	// 正是因为有1，所以情况有所不同，因为有1，所以任何钱肯定能有全1来表示，所以dp不会有不可达状态
	for(int i = 1; i < NUM; ++i)
	{
		for(int j = 0; j <= value; ++j)  
		{
			if(j >= money[i])  //money[i] start from 2 
				dp[i][j] = dp[i][j-money[i]] + dp[i-1][j];  
			else  
				dp[i][j] = dp[i-1][j];  
		}  
	}  
	for(int i=0;i<NUM;i++)
	{
		for (int j=0;j<=value;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[6][value];
}
#define NUM2 6
 //int money2[NUM2] = {0 ,4, 5, 10, 20, 50};  // 所给的钱可能破不开
  int money2[NUM2] = {4, 5, 10, 20, 50};  // 真是愚笨呀，完全可以money2从0 开始，只需下面的部分用 money[i-1] 即可。
//int money2[NUM2] = {0 ,50, 20, 10, 5, 4};  // i 可以从大到小
int NumOfCoins2(int value)  
{  
	int dp[7][1010];  
	for(int j = 0; j <= value; ++j)
	{
		dp[0][j] = 0;
	}
	for (int i = 0;i<NUM2;i++)
	{
		dp[i][0] = 1;//money[i]本身。
	}
	//dp[0][0] = 0;
	for(int i = 1; i < NUM2; ++i) // start from 2 
	{
		for(int j = 1; j <= value; ++j)
		{
			/*dp[i][j]=-INF;
			dp[i][j] = 0;
			for (int k = 0; dp[i-1][j]!=-INF;k++)
			{
				if(k*money2[i] <= j && dp[i][j-money2[i]]!=-INF)  //money[i] start from 2 
					dp[i][j] = dp[i][j-money2[i]] + dp[i-1][j];  
				else  
				{
					dp[i][j] = dp[i-1][j];  
					break;
				}
			}*/
			dp[i][j] = 0;//可能破不开，所以初始为0，0代表破不开，为什么不初始化为-INF？
			//如果初始化为-INF那么下面赋值的时候，要判断 dp[i][j-money2[i]]和 dp[i-1][j]是否为-INF，但是dp[i-1][j];参与了计算，即使是不可达状态，也会参与计算当前的方案数;
			//比如dp[i-1][j]是不可达，而dp[i][j-money2[i]]是可达的状态，此时要分别判断。像下面那样
			//for (int k = 0; ;k++)
			//{
				//为什么不用k了呢？因为根本就不用，不同于部分背包问题
				if(money2[i-1] <= j)  //对于money从0开始，而dp从1开始（dp【0】【j】作为了边界了）这部要用 money2[i-1]
					dp[i][j] = dp[i][j-money2[i-1]] + dp[i-1][j];  //dp[i][j] = dp[i][j-money2[i-1]] + dp[i-1][j];
				else  
				{
					dp[i][j] = dp[i-1][j];  
					//break;
				}
				/*如果用-INF表示不可达状态，分这么多情况考虑
				if (money2[i] <= j && dp[i][j-money2[i]] != 0 && dp[i-1][j] != 0)
				{
					dp[i][j] = dp[i][j-money2[i]] + dp[i-1][j];
				}
				if (money2[i] <= j && dp[i][j-money2[i]] != 0 && dp[i-1][j] == 0)
				{
					dp[i][j] = dp[i][j-money2[i]];
				}
				if (money2[i] <= j && dp[i][j-money2[i]] == 0)
				{
					dp[i][j] = dp[i-1][j];
				}
				if (money2[i] > j && dp[i-1][j] != 0)
				{
					dp[i][j] = dp[i-1][j];
				}*/
			//}
		}  
	}  
	for(int i=0;i<NUM2;i++)
	{
		for (int j=0;j<=value;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[NUM2-1][value];
}
#define NUM3 5
int money3[NUM3] = {4, 5, 10, 20, 50};  // 只是起始边界不一样
int NumOfCoins3(int value)  
{  
	int dp[NUM3+1][1010];  
	for(int j = 0; j <= value; ++j)
	{
		dp[NUM3][j] = 0; // i from NUM3 to 0
	}
	for (int i = 0;i<=NUM3;i++)
	{
		dp[i][0] = 1;//money[i]本身。j from 0 to value
	}
	for(int i = NUM3-1; i >= 0; --i) // start from 2 
	{
		for(int j = 1; j <= value; ++j)
		{
			dp[i][j] = 0;
			if(money3[i] <= j)  //money[i] start from 2 
				dp[i][j] = dp[i][j-money3[i]] + dp[i+1][j];  
			else  
			{
				dp[i][j] = dp[i+1][j];  
			}
		}  
	}  
	for(int i=0;i<=NUM3;i++)
	{
		for (int j=0;j<=value;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[0][value];
}