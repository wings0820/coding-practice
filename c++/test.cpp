#include<iostream>

using namespace std;

int main()
{
  for(int i=1;i<10;i++)
     for(int j=1;j<i;j++)
       for(int k=1;k<10;k++)
         
          if((10*j+i)*k==(10*i+k)*j)
             if(i!=j)cout<< 10*j+i<<'/'<<10*i+k<<endl; 
          


return 0;
}
