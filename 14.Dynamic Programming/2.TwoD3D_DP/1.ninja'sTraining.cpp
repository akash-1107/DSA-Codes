#include <bits/stdc++.h>
using namespace std;
// macros
#define lli long long
#define f(i, x) for (int i = 0; i < (int)x; i++)
#define f1(i, x) for (int i = 1; i <= (int)x; i++)
#define rep(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
#define all(arr) arr.begin(), arr.end()
#define print(arr)   for (auto &i : arr)  cout << i << " "

//1.Recursive
//day is taken as index
int fxn(int day , int lastTask ,vector<vector<int>> &pts){
//base case
if(day == 0){
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
       if(i != lastTask) maxi = max(maxi ,pts[0][i]);
    }
return maxi;
}

int maxi2 = 0;
for (int i = 0; i < 3; i++)
{
    if(i != lastTask){
       int a = fxn(day-1 , i , pts) + pts[day][i];
       maxi2 = max(maxi2 , a);
    }
}
return maxi2;
}

int ninjaTraining(int n, vector<vector<int>> &pts)
{ //points is N*3 array N days har day ka all 3 task(0,1,2) ka associated points
    return fxn(n-1 , 3 , pts);//n-1->0
    //pts -> N*3 matrix
}


// 2.Memomization
int fxn(int day, int lastTask, vector<vector<int>> &pts, vector<vector<int>> &dp)
{      
    
    // base case
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != lastTask)
                maxi = max(maxi, pts[0][i]);
        }
        return maxi;
    }

    if (dp[day][lastTask] != -1) return dp[day][lastTask];

    int maxi2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i != lastTask)
        {
            int a = fxn(day - 1, i, pts, dp) + pts[day][i];
            maxi2 = max(maxi2, a);
        }
    }
    return dp[day][lastTask] = maxi2;
}

int ninjaTraining(int n, vector<vector<int>> &pts)
{ // points is N*3 array N days har day ka all 3 task(0,1,2) ka associated points
    vector<vector<int>> dp(n, vector < int > (4, -1)); //aise declare krna hoga size proper
    return fxn(n - 1, 3, pts, dp); // n-1->0
}


//3.Tabulation
int fxn(int day, int lastTask, vector<vector<int>> &pts)
{     vector<vector<int>> dp(day, vector < int > (4, -1)); 
    // base cases
    dp[0][0] = max(pts[0][1] , pts[0][2]); //day 0 wala elements hi lena h
    dp[0][1] = max(pts[0][0] , pts[0][2]);
    dp[0][2] = max(pts[0][0] , pts[0][1]);
    dp[0][3] = max(pts[0][0] ,max(pts[0][1] , pts[0][2]));


    for (int i = 1; i < day; i++) //i = day
    {
        for(int j = 0 ; j <= 3 ; j++ ){       //j = lastTask
        int maxi2 = 0; //ye pura recurrence ka part h
         for (int k = 0; k < 3; k++) {
            if (k != j)
            { 
                int a = dp[i-1][k] + pts[i][k];
                maxi2 = max(maxi2, a);
                dp[i][j] = maxi2;  
            }
        
               
        }
        }
      
    }
 return dp[day-1][3];//lasttask = 3 yhi dena h
}

int ninjaTraining(int n, vector<vector<int>> &pts)
{ 
   
    return fxn(n, 3, pts); // n-1->0
}


//4.Space Optimization
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++){
    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}







int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = 3;
        vector<vector<int>> points(n, vector<int>(m, 0));
        f(i, n)
        {
            f(j, m)
            {
                cin >> points[i][j];
            }
        }
        cout << ninjaTraining(n, points) << endl;
    }
}
