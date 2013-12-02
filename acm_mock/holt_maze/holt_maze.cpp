#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point{
  char ch;
  int x;
  int y;
  bool visited;
};


void bfs(vector<vector<Point> > floor, Point start) {
  queue<Point> ptq;
  ptq.push(start);

  while(!ptq.empty()) {
    Point cur = ptq.front();
    if(cur.ch == 'E') {
      cout << "found" << endl;
      break;
    } else if (cur.ch != '#' && !cur.visited) {
      cur.visited = true;

    }
  }
}

int main() {
  int W, H;
  cin >> W >> H;
  vector<vector<Point> > floor; 
  Point start;
  
  char ch;
  for (int i = 0; i < H; ++i) {
    vector<Point> points_col;
    for (int j = 0; j < W; ++j) {
      cin >> ch;
      Point point = {ch, i, j, false};
      if (ch == 'S') start = point;
      points_col.push_back(point);
    }
    floor.push_back(points_col);
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cout << floor[i][j].ch;
    }
    cout << endl;
  }
  return 0;
}
