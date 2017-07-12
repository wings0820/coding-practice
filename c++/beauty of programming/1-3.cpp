#include<iostream>
#include<assert.h>

using namespace std;

class CPrefixSorting
{
public:
  CPrefixSorting() //构造函数
  {
    m_nCakeCnt =0;
    m_nMaxSwap =0;
  }
  ~CPrefixSorting()  //析构，释放所有的值
  {
    if(m_CakeArray!=NULL)
    {
      delete m_CakeArray;
    }
    if(m_SwapArray!=NULL)
    {
      delete m_SwapArray;
    }
    if(m_ReverseCakeArray!=NULL)
    {
      delete m_ReverseCakeArray;
    }
    if(m_ReverseCakeArraySwap!=NULL)
    {
      delete m_ReverseCakeArraySwap;
    }
  }
void Run(int* pCakeArray,int nCakeCnt)   //计算烙饼翻转信息
{
  Init( pCakeArray, nCakeCnt);
  m_nSearch =0;
  Search(0);
}

void Output()    //输出烙饼具体的翻转信息
{
  for(int i=0;i<m_nMaxSwap;i++)
  {
    printf("%d",m_SwapArray[i] );
  }
  printf("\n |Search Times| :%d\n",m_nSearch );
  printf("Total Swap tiems = %d\n",m_nMaxSwap );
}
private:
  int* m_CakeArray ;//烙饼信息数组
  int m_nCakeCnt ;    //烙饼个数
  int m_nMaxSwap ;      //最多交换次数，据前面的信息，这里最多为个数的2倍
  int* m_SwapArray;    //交换结果数组
   int* m_ReverseCakeArray  ;// 当前翻转烙饼的信息数组
   int* m_ReverseCakeArraySwap;   //当前翻转烙饼交换结果数组
   int m_nSearch ;    //当前搜索次数信息

  void Init(int* pCakeArray,int nCakeCnt)//初始化数组信息
  {
    assert(pCakeArray!=NULL);
    assert(nCakeCnt>0);

    m_nCakeCnt = nCakeCnt;
    m_CakeArray = new int[m_nCakeCnt];
    assert(m_CakeArray!=NULL);
    for(int i=0;i<m_nCakeCnt;i++)
    {
      m_CakeArray[i]=pCakeArray[i];
    }
    m_nMaxSwap = UpperBound(m_nCakeCnt);

    m_SwapArray =new int[m_nMaxSwap+1];

    assert(m_SwapArray!=NULL);

    m_ReverseCakeArray =new int[m_nCakeCnt];
    for(int i=0;i<m_nCakeCnt;i++)
    {
      m_ReverseCakeArray[i]=m_CakeArray[i];
    }
    m_ReverseCakeArraySwap=new int[m_nMaxSwap];
  }

int UpperBound(int nCakeCnt)
{
  return nCakeCnt*2;
}
int LowerBound(int* pCakeArray,int nCakeCnt)
{
  int t,ret =0;
  for(int i=1;i<nCakeCnt;i++)
  {
    t =pCakeArray[i]-pCakeArray[i-1];
    if((t==1)||(t==-1)){}
    else
    {
      ret++;
    }
  }
  return ret;
}

void Search(int step)
{
  int nEstimate;
  m_nSearch++;

  nEstimate =LowerBound(m_ReverseCakeArray,m_nCakeCnt);
  if(step+nEstimate>m_nMaxSwap)
    return;
  if(IsSorted(m_ReverseCakeArray,m_nCakeCnt))
  {
    if(step<m_nMaxSwap)
    {
      m_nMaxSwap=step;
      for(int i=0;i<m_nMaxSwap;i++)
        m_SwapArray[i]=m_ReverseCakeArraySwap[i];
    }
    return;
  }
  for(int i=1;i<m_nCakeCnt;i++)
  {
    Reverse(0,1);
    m_ReverseCakeArraySwap[step]=i;
    Search(step+1);
    Reverse(0,i);
  }

}

bool IsSorted(int* pCakeArray,int nCakeCnt)
{
  for(int i=1;i<nCakeCnt;i++)
  {
    if(pCakeArray[i-1]>pCakeArray[i])
    {
      return false;
    }
  }
  return true;
}
void Reverse(int nBegin,int nEnd/* arguments */)
{
  assert(nEnd>nBegin);
  int i,j,t;
  for(i=nBegin,j=nEnd;i<j;i++,j--)
  {
    t=m_ReverseCakeArray[i];
    m_ReverseCakeArray[i]=m_ReverseCakeArray[j];
    m_ReverseCakeArray[j]=t;
  }
}
};

int main()
{

  return 0;
}
