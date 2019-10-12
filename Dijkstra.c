#include<stdio.h>
#include <limits.h>
#define V 28
char capital[30][30]={"Agartala","Aizawl","Bengaluru","Bhopal","Bhubaneswar","Chandigarh","Chennai","Dehradun","Dispur",
"Gandhinagar","Gangtok","Hyderabad_Amaravati","Hyderabad_shared_with_Ap","Imphal","Itanagar","Jaipur","Kohima","Kolkata","Lucknow",
"Mumbai","Panaji","Patna","Raipur","Ranchi","Shillong","Shimla","Srinagar","Thiruvananthapuram"};

int main()
{int i;
int source;
int destination;
int distance[V];
int graph[V][V] ={ { 0   ,349 ,0   ,0   ,0   ,0   ,0   ,0   ,544 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {349 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,462 ,0   ,0   ,0   ,0   ,400 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,347 ,0   ,0   ,0   ,0   ,663 ,569 ,0   ,0   ,0   ,0   ,0   ,0   ,984 ,602 ,0   ,0   ,0   ,0   ,0   ,0   ,723},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,609 ,0   ,0   ,0   ,0   ,0   ,594 ,0   ,0   ,647 ,775 ,0   ,0   ,639 ,1023,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,819 ,0   ,0   ,0   ,0   ,0   ,443 ,0   ,0   ,0   ,0   ,549 ,453 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,205 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,517 ,0   ,0   ,806 ,0   ,0   ,0   ,0   ,0   ,0   ,112 ,562 ,0},
                    {0   ,0   ,347 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,447 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,773},
                    {0   ,0   ,0   ,0   ,0   ,205 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,580 ,0   ,0   ,0   ,0   ,0   ,0   ,228 ,0   ,0},
                    {544 ,462 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,482 ,323 ,0   ,462 ,1149,0   ,0   ,0   ,0   ,0   ,0   ,91  ,0   ,0   ,0},
                    {0   ,0   ,0   ,609 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,662 ,0   ,0   ,0   ,545 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,671 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,663 ,0   ,819 ,0   ,447 ,0   ,0   ,0   ,0   ,0   ,840 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,521 ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,569 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,840 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,711 ,0   ,0   ,779 ,0   ,0   ,0   ,0   ,0},
                    {0   ,400 ,0   ,0   ,0   ,0   ,0   ,0   ,482 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,136 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,323 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,320 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,594 ,0   ,517 ,0   ,0   ,0   ,662 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,574 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,462 ,0   ,0   ,0   ,0   ,136 ,320 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,443 ,0   ,0   ,0   ,1149,0   ,671 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,583 ,0   ,414 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,647 ,0   ,806 ,0   ,580 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,574 ,0   ,0   ,0   ,0   ,0   ,533 ,807 ,741 ,0   ,0   ,0   ,0},
                    {0   ,0   ,984 ,775 ,0   ,0   ,0   ,0   ,0   ,545 ,0   ,0   ,711 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,571 ,0   ,1091,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,602 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,571 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,583 ,533 ,0   ,0   ,0   ,0   ,397 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,639 ,549 ,0   ,0   ,0   ,0   ,0   ,0   ,521 ,779 ,0   ,0   ,0   ,0   ,0   ,807 ,1091,0   ,0   ,0   ,588 ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,1023,453 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,414 ,741 ,0   ,0   ,397 ,588 ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,91  ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0},
                    {0   ,0   ,0   ,0   ,0   ,112 ,0   ,228 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,633 ,0},
                    {0   ,0   ,0   ,0   ,0   ,562 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,633 ,0   ,0},
                    {0   ,0   ,723 ,0   ,0   ,0   ,773 ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0}
					};
/*char capital[30][30]={"Agartala","Aizawl","Bengaluru","Bhopal","Bhubaneswar","Chandigarh","Chennai","Dehradun","Dispur",
"Gandhinagar","Gangtok","Hyderabad_Amaravati","Hyderabad_shared_with_Ap","Imphal","Itanagar","Jaipur","Kohima","Kolkata","Lucknow",
"Mumbai","Panaji","Patna","Raipur","Ranchi","Shillong","Shimla","Srinagar","Thiruvananthapuram"};*/
printf("List of city\n");
for(i=0;i<V;i++)
{
    printf(" %d. %s\n",i+1,capital[i]);
}
    printf("\nSelect your city from the above list\n");
    printf("\nEnter your source NUMBER\n");
    scanf("%d",&source);
    printf("\nEnter your Destination NUMBER\n");
    scanf("%d",&destination);
    printf("\nSource        =   %s\nDestination   =   %s\n",capital[source-1],capital[destination-1]);
    distance[V]=dijkstra(graph, source-1,destination-1,capital);
    //for (i=0;i<V;i++)
    //{
    //	printf("%d\n",distance[i]);
	//}
return 0;
}

int dijkstra(int graph[V][V], int src,int dest,char capital[V][V])
{int i,count,v;
     int dist[V];
    int sptSet[V];
     
//	 for(i=0;i<V;i++)
//{
 //   printf(" %d. %s\n",i+1,capital[i]);
//}
//printf("%d",src);
	 for (i = 0; i < V; i++)
     {
        dist[i] = INT_MAX, sptSet[i] = 0;
     }
     dist[src] = 0;

     for ( count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = 1;
       for (v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
     printSolution(src,dest,dist, V);
     //return(dist[V]);
}
int minDistance(int dist[],int sptSet[])
{
   int min = INT_MAX, min_index,v;

   for ( v = 0;v < V;v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
int printSolution(int src,int dest, int dist[], int n)
{/*char capital[30][30]={"Agartala","Aizawl","Bengaluru","Bhopal","Bhubaneswar","Chandigarh","Chennai","Dehradun","Dispur",
"Gandhinagar","Gangtok","Hyderabad_Amaravati","Hyderabad_shared_with_Ap","Imphal","Itanagar","Jaipur","Kohima","Kolkata","Lucknow",
"Mumbai","Panaji","Patna","Raipur","Ranchi","Shillong","Shimla","Srinagar","Thiruvananthapuram"};*/
//printf("List of city\n");
//int i;
   //printf("\n\n\nDistance from Source to Distination\n\n");
  //for (i = 0; i < V; i++)
      printf("\nDistance From %s to %s = %dKM \n  ",capital[src],capital[dest], dist[dest]);

}
