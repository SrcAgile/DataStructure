#include "maze.h"
#define MAXSIZE 100;
#define ROW 10
#define COL 10
typedef struct Pos
{
	int x;
	int y;
}Pos;


typdef struct Path{
	Pos poses[MAXSIZE];
	int length
}Path;

int MazeMap[ROW][COL]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,1,0,0,1,1},
	{0,0,1,1,0,1,0,1,0,1},
	{1,0,1,1,0,1,1,1,1,1},
	{0,0,1,1,1,1,1,1,1,0},
	{1,0,1,0,1,0,0,0,1,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,0,1,1}
}
void GetRoute(int,int,int,int,Path);
void PrintPath(Path path);

void FindAllRouteInMaze(int inrow,int incol,int exrow,int excol){
	Path path;
	path.length=0;
	GetRoute(inrow,incol,exrow,excol,path);
}
void GetRoute(int inrow,int incol,int exrow,int excol,Path path){
	if(inrow==exrow&&incol==excol){
		Pos pos={inrow,incol};
		path.poses[++path.length]=pos;
		PrintPath(path);
		return;
	}
	if(MazeMap[inrow][incol]==0){
		Pos pos={inrow,incol};
		MazeMap[inrow][incol] = -1;
		path.poses[++path.length]=pos;
		int direct=0;//定义方向
		while(direct<4){
			int nextrow = inrow;
			int nextcol = incol;
			switch(direct){
				case 0:
					nextrow = inrow - 1;
					break;
				case 1:
					nextcol = incol + 1;
					break;
				case 2:
					nextrow = inrow + 1;
					break;
				case 3:
					nextcol = incol - 1;
					break;
				default:
					puts("状态异常");
					exit(-1);
			}
			GetRoute(nextrow,nextcol,exrow,excol,path);
			direct++;
		}
		//精彩部分(Awesome part)采用回溯进行回归
		MazeMap[inrow][incol] = 0;
		path.length--;
	}
}

void PrintPath(Path path){
	for(int i = 0 ; i < path.length; i++)
		printf("[%d,%d]-->",path.poses[i].x,path.poses[i].y);
	puts("");
}
