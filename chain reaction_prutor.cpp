// Main code 1st attempt

#include <simplecpp>
//#include <conio>

//Function to make Matrix null
void makeNull(int a[][8])
{
  for(int i=0;i<11;i++)
  {
    for(int j=0;j<8;j++)
    {
      a[i][j]=0;
    }
  }
}

//Function to mark end of the game
bool isEnd(int a[][8])
{
  int count=0;
  int temp=a[1][1];
  for(int i=1;i<10;i++)
  {
    for(int j=1;j<7;j++)
    {
      if(a[i][j]==temp)count++;
      else{count=0;}
      temp=a[i][j];
    }
  }
  if (count==53) return true;
  else return false;
}


//Function to check weightage of each cell
bool ifAllowed(int x,int y,int value)
{
  if((x==1 && y==1) || (x==9 && y==6) || (x==1 && y==6) || (x==9 && y==1))
  {
    if(value<1) return true;
    else return false;
  }
  else if(x==1 || x==9 || y==1 || y==6)
  {
    if(value<2) return true;
    else return false;
  }
  else
  {
    if(value<3) return true;
    else return false;
  }
}

//Function to display the matrix
void displayMatrix(int a[][8],int marker[][8])
{
  for(int i=1;i<10;i++)
  {
    for(int j=1;j<7;j++)
    {
      if(marker[i][j]==2) cout<<'-';
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  return;
}

void addBlobs(int x,int y,int a[][8],int marker[][8],int player);

//Function for overflow of blobs
void overflow(int a[][8],int marker[][8],int x,int y,int player)//------------------------------Function to be completed
{
  a[x][y]=0;
  if(isEnd(a)) return;
  marker[x-1][y]=player;
  marker[x+1][y]=player;
  marker[x][y+1]=player;
  marker[x][y-1]=player;
  addBlobs(x+1,y,a,marker,player);
  addBlobs(x,y+1,a,marker,player);
  addBlobs(x-1,y,a,marker,player);
  addBlobs(x,y-1,a,marker,player);
}

//Function to add the blobs
void addBlobs(int x,int y,int a[][8],int marker[][8],int player)
{
  if(marker[x][y]==0)
  {
    marker[x][y]=player;
    a[x][y]++;
  }
  else if(marker[x][y]!=0)
  {
    if(marker[x][y]==player)
    {
      if(ifAllowed(x,y,a[x][y])==1) a[x][y]++;
      if(ifAllowed(x,y,a[x][y])==0) overflow(a,marker,x,y,player);
    }
    if(marker[x][y]!=player)cout<<"Illegal move"<<endl;
  }
}

 main_program
{
using namespace std;
int x,y,marker[11][8],matrix[11][8],player=1;
makeNull(marker);
makeNull(matrix);
cin>>x;
if(x>=0)cin>>y;
while(x>=0 && isEnd(matrix)==0)
{
  addBlobs(x+1,y+1,matrix,marker,player);
  displayMatrix(matrix,marker);
  cout<<endl;
  if(player==1)player=2;
  else if(player==2) player=1;
  cin>>x;
  if(x>=0)cin>>y;
}
//return 0;

}
