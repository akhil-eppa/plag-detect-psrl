#include <stdio.h>
#include <string.h>
 
 
char numero_saltos(char * cBuffer, char iLen)
{
    char i,cNum = 0;
    
    for(i = 0; i < iLen - 2; i++)
    {
        if(cBuffer[i] != cBuffer[i+2])
        {
            cNum++;
        }
    }
    
    return cNum;
}
 
char sustrae_posicion(char * cBuffer, char iLen,char Pos)
{
    char i = 0;
    
    for(i = Pos; i < iLen - 1;i++)
    {
        cBuffer[i] = cBuffer[i+1];
    }
    
    cBuffer[iLen - 1] = 0;
    
    return iLen - 1;
}
 
 
int main()
{
    unsigned int T;
    char s[51] = {0}, sAux[51] = {0},sMax[51] = {0};
    char t,i,CambiosAct,CambiosMax,Menor,L,Lact;
    
    scanf("%u",&T);
    
    do
    {
        scanf("%s\n",s);
        
        L = strlen(s);
        t = 1;
        
        while((L > 2)&&(t==1))
        {
            t = 0;
            CambiosAct = 0;
            CambiosMax = 0;
            
            for(i = 0; i < L - 2; i++)
            {
                if(s[i]!=s[i+2])
                {
                    t = 1;
                    
                    memset(sAux,0,sizeof(sAux));
                    memcpy(sAux,s,strlen(s));
                    
                    sAux[i+2] = sAux[i];
                    Lact = sustrae_posicion(sAux,L,i);
                    
                    CambiosAct = numero_saltos(sAux,Lact);
            
                    if(CambiosAct >= CambiosMax)
                    {
                        memset(sMax,0,sizeof(sMax));
                        memcpy(sMax,sAux,strlen(sAux));
                        CambiosMax = CambiosAct; 
                    }
 
                    memset(sAux,0,sizeof(sAux));
                    memcpy(sAux,s,strlen(s));
    
                    sAux[i] = sAux[i+2];
                    Lact = sustrae_posicion(sAux,L,i+2);   
 
                    CambiosAct = numero_saltos(sAux,Lact);
            
                    if(CambiosAct >= CambiosMax)
                    {
                        memset(sMax,0,sizeof(sMax));
                        memcpy(sMax,sAux,strlen(sAux));
                        CambiosMax = CambiosAct; 
                    }
                }
            }
            
            if(t == 1)
            {
                L = strlen(sMax);
                memset(s,0,sizeof(s));
                memcpy(s,sMax,L);
            }
        }
        
        printf("%u\n",L);
        
    }while(--T>0);
 
}