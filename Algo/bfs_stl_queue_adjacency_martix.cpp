#include <iostream>
#include <queue>
using namespace std;

// http://en.wikipedia.org/wiki/Incidence_matrix

int n;// число вершин графа
int mass[1000][1000];//матрица смежности
 
void BFS()
{
      queue<int> q; //очередь 
      int met[1000]; //массив меток
      q.push(0); //помещаем первую вершину в очередь
      met[0] = 1; //помечаем ее как просмотренную
 
      while (q.size() > 0) //пака не просмотрели все вершины
      {
            int u = q.front(); //извлекаем из очереди вершину
            q.pop();
            cout << u+1 << " "; //выводим ее
            for (int i = 0; i < n; ++i) //цикл по всем вершинам
                  if (mass[u][i] == 1 && met[i] != 1)//если вершина смежна с данной и непросмотрена 
                  {
                        q.push(i); //помещаем ее в очередь
                        met[i] = 1; //помечаем
                  }
      }
}

int main()
{
      freopen("input.txt", "r", stdin);
      cin >> n;
      for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                  cin >> mass[i][j];
      cout << "One of the wyas: " << endl;
      BFS();
      return 0;
}

/*
6
0 1 0 0 1 0
1 0 0 0 1 1
0 0 0 1 1 0
0 0 1 0 1 0
1 1 1 1 0 0
0 1 0 0 0 0
*/
