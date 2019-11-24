
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define R 6371
#define TO_RAD (3.1415926536 / 180)
#define V 28
char capital[30][30]={"Agartala","Aizawl","Bengaluru","Bhopal","Bhubaneswar","Chandigarh","Chennai","Dehradun","Dispur",
"Gandhinagar","Gangtok","Hyderabad_Amaravati","Hyderabad_shared_with_Ap","Imphal","Itanagar","Jaipur","Kohima","Kolkata","Lucknow",
"Mumbai","Panaji","Patna","Raipur","Ranchi","Shillong","Shimla","Srinagar","Thiruvananthapuram"};
double hgraph[2][V]={{23.8315,23.7307,12.9716,23.2599,20.2961,
30.7333,13.0827,30.3165,26.1433,23.2156,27.3314,20.9320,17.3850,24.8170,27.0844,26.9214,25.6753,22.5726,
26.8467,19.0760,15.4909,25.5941,21.2333,23.3477,25.5788,31.1048,34.0856,8.2541},
{91.2868,92.7173,77.5946,77.4126,85.8245,76.7794,80.2707,78.0322,91.7898,72.6369,88.6138,77.7523,78.4867,93.9368,93.6053,75.7853,94.1086,88.3639,80.9462,72.8777,73.8278,85.1376,81.6333,85.3385,91.8933,77.1734,74.8055,76.9366}};



double heuristic(double th1, double ph1, double th2, double ph2)
{
	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;
 
	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}
double minarr(double a[], int n) {
  int c, index=0;

  for (c = 1; c < n; c++)
    if (a[c] > a[index])
      index = c;

  return index;
}
   
   
   
  
int Astar(int src,int dest,int graph[V][V])
{
int i,s;					   
int curnode,shortest_node;
int y=1;
int distance=0;
int nextNode[28];
double hdistance[28];
int path[28];
//if(src==dest)
//{printf("source and destination cannot be the same");}
curnode=src;
path[0]=curnode;
while(curnode!=dest)
	{int x=0;
	 for(int j=0;j<28;j++)
	{nextNode[j]=0;hdistance[j]=9999;}
	for(i=0;i<28;i++)
		{
		if((graph[curnode][i])!=0)
			{
			nextNode[x]=i;
			hdistance[x]=(graph[curnode][i]+heuristic(hgraph[0][i],hgraph[1][i],hgraph[0][dest],hgraph[1][dest]));
			x++;
						
			}

		}
		shortest_node=minarr(hdistance,x);
		//path[y]=nextNode[shortest_node];		
		y++;
		
		s=nextNode[shortest_node];
		distance=distance+graph[curnode][s];
		curnode=s;
	}

return distance;

}
int main()
{int i,final;
int source;
int destination;
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
/*char capital[30][30]={"Agartala-1","Aizawl-2","Bengaluru-3","Bhopal-4","Bhubaneswar-5","Chandigarh-6","Chennai-7","Dehradun-8","Dispur-9",
"Gandhinagar-10","Gangtok-11","Hyderabad_Amaravati-12","Hyderabad_shared_with_Ap-13","Imphal-14","Itanagar-15","Jaipur-16","Kohima-17","Kolkata-18","Lucknow-19",
"Mumbai-20","Panaji-21","Patna-22","Raipur-23","Ranchi-24","Shillong-25","Shimla-26","Srinagar-27","Thiruvananthapuram-28"};*/
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
    final=Astar(source-1,destination-1,graph);
    printf("%d",final);
    //for (i=0;i<V;i++)
    //{
    //	printf("%d\n",distance[i]);
	//}
return 0;
}


