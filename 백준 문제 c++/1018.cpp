#include <iostream>
#include <vector>
using namespace std;
int boardX, boardY, paintCount, minPaintCount;
//true = white / false = black
bool firstBlockColAry[2] = {true, false};
//true = white / false = black
// board[y][x]
bool board[51][51];
int main()
{
    cin >> boardY >> boardX;
    for (int y = 0; y < boardY; y++)
    {
        string inputLine;
        cin >> inputLine;
        for (int x = 0; x < boardX; x++)
        {
            if (inputLine[x] == 'W')
                board[y][x] = true;
            else
                board[y][x] = false;
        }
    }
    bool notFirstCount = true;
    //x와 y는 왼쪽 위 시작 지점
    for (int y = 0; y + 8 <= boardY; y++)
    {
        for (int x = 0; x + 8 <= boardX; x++)
        {
            for (bool &firstBlockCol : firstBlockColAry)
            {
                bool blockCol = firstBlockCol;
                paintCount = 0;
                for (int cy = 0; cy < 8; cy++)
                {
                    for (int cx = 0; cx < 8; cx++)
                    {
                        if (board[y + cy][x + cx] != blockCol)
                            paintCount++;
                        blockCol = !blockCol;
                    }
                    blockCol = !blockCol;
                }
                if (notFirstCount)
                {
                    minPaintCount = paintCount;
                    notFirstCount = false;
                }
                else if (minPaintCount > paintCount)
                    minPaintCount = paintCount;
            }
        }
    }
    cout << minPaintCount;
}