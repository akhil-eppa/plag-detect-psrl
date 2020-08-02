 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int vis[100];
 void creategraph();
 void dfs(int);
 int arr[100][100],num;
 int component();
 int label;
 int main()
 {
   int i_index,v_index,k_index; 
   printf("Enter the number of vertices..");
   scanf("%d",&num);
   creategraph();
   int result =component();
   printf("the number of components = %d\num",result);
   printf ("\nthe vertices and their component numbers");
   for(i_index=1;i_index<=num;i_index++)
     printf("%d---> %d\num",i_index,vis[i_index]);
  }
 void creategraph()
  {
    int i_index,j_index;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i_index,&j_index);
        if((i_index==-9)&&(j_index==-9))
           break;
        arr[i_index][j_index]=arr[j_index][i_index]=1;
     }
  }
  int component()
  {
   int i_index,j_index;
   label=0;
   for(i_index=1;i_index<=num;i_index++)
   {
     if(vis[i_index]==0)
     {
       ++label;
       dfs(i_index);
     }
  }
  return label;
 }
  void dfs(int v_index)
  {
    int u;
    vis[v_index]=label;

    for(u=1;u<=num;u++)
    {
       if((arr[v_index][u]==1)&&(vis[u]==0))
           dfs(u);
    }
  }