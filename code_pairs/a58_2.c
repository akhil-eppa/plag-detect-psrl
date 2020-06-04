 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];//array to keep track of visited elements
 void creategraph();//creates a graph
 void dfs(int);//depth first search
 int a[100][100],n;//a stores the graph
 int component();//to find component
 int label;//label
 int main()//main function
 {
   int i,v,k; 
   printf("Enter the number of vertices..");//accept the number of vertices
   scanf("%d",&n);
   creategraph();//create the graph based on the number of vertices
   int result =component();//components
   printf("the number of components = %d\n",result);//print the number of components
   printf ("\nthe vertices and their component numbers");
   for(i=1;i<=n;i++)//print the vertices along with the component they form
     printf("%d---> %d\n",i,visit[i]);
  }
 void creategraph()//create the graph based on which vertice is connected to which one. 
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==-9)&&(j==-9))//if this entered just break
           break;
        a[i][j]=a[j][i]=1;
     }
  }
  int component()// find the number of components
  {
   int i,j;
   label=0;
   for(i=1;i<=n;i++)//checking label and increment label
   {
     if(visit[i]==0)
     {
       ++label;
       dfs(i);//call depth first search function
     }
  }
  return label;
 }
  void dfs(int v)
  {
    int u;
    visit[v]=label;//label

    for(u=1;u<=n;u++)//looping for depth first search
    {
       if((a[v][u]==1)&&(visit[u]==0))
           dfs(u);
    }
  }