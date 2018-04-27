// Main code 2nd iteration

#include <simplecpp>
//#include <conio>

bool Illegal_move=false;
int no_of_turn=0;

//Function to make padding zero
void zerotime(int a[][8],int b[][8])
{
    for(int i=0; i<11; i++)
    {
        a[i][0]=0;
        a[i][7]=0;
        b[i][0]=0;
        b[i][7]=0;
    }
    for(int j=0; j<8; j++)
    {
        a[0][j]=0;
        a[10][j]=0;
        b[0][j]=0;
        b[10][j]=0;
    }
}

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
bool isEnd(int a[][8],int p)
{
  int count=0;
  //int temp=a[1][1];
  for(int i=1;i<10;i++)
  {
    for(int j=1;j<7;j++)
    {
      if(a[i][j]==0 || a[i][j]== p)count++;
      //else{count=0;}
      //temp=a[i][j];
    }
  }
  if (count==54) return true;
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

void addBlobs(int x,int y,int a[][8],int marker[][8],int &player);

//Function for overflow of blobs
void overflow(int a[][8],int marker[][8],int x,int y,int &player)//------------------------------Function to be completed
{
  zerotime(a,marker);
  a[x][y]=0;
  marker[x][y]=0;
  //if(isEnd(marker,1)==true || isEnd(marker,2)==true) return;
  marker[x-1][y]=player;
  marker[x+1][y]=player;
  marker[x][y+1]=player;
  marker[x][y-1]=player;
  addBlobs(x+1,y,a,marker,player);
  addBlobs(x,y+1,a,marker,player);
  addBlobs(x-1,y,a,marker,player);
  addBlobs(x,y-1,a,marker,player);
  if(isEnd(marker,1)==true || isEnd(marker,2)==true) return;
}

//Function to add the blobs
void addBlobs(int x,int y,int a[][8],int marker[][8],int &player)
{
  zerotime(a,marker);
  if(marker[x][y]==0)
  {
    marker[x][y]=player;
    a[x][y]++;
  }
  else 
  {
    if(marker[x][y]==player)
    {
      if(ifAllowed(x,y,a[x][y])==true) a[x][y]++;
      else if(ifAllowed(x,y,a[x][y])==false) overflow(a,marker,x,y,player);
    }
    else if(marker[x][y]!=player)
      {
        cout<<"Illegal move"<<endl;
        cout<<endl;
        if(player==1)player=2;
        else if(player==2) player=1;
        Illegal_move=true;
      }
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
else return 0;
do
{
  addBlobs(x+1,y+1,matrix,marker,player);
  if(Illegal_move==false)displayMatrix(matrix,marker);
  cout<<endl;
  if((isEnd(marker,1)==true || isEnd(marker,2)==true) && no_of_turn>=2)
    {
      cout<<"player "<<player<<" wins!";
      break;
    }
  if(player==1)player=2;
  else if(player==2) player=1;
  cin>>x;
  if(x>=0)cin>>y;
  Illegal_move=false;
  no_of_turn++;
}
while(x>=0 && (isEnd(marker,1)==false || isEnd(marker,2)==false));
//return 0;

}
