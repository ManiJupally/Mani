#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int vehicle;
#define MAX_VEHCL 50
int enter=0;
struct directn
{
  int vid,orgn,destinatn;
};
struct directn object[MAX_VEHCL];
void *intersection(void *args)
{
	int a;
   	struct directn *obj=args;
 	for(a=1;a<=vehicle;a++)
	{
	printf("\n\n***Vehicle %d and %d Enter the intersection***",a,a+1);
	if(obj[a].orgn==obj[a+1].destinatn && obj[a].destinatn==obj[a+1].orgn)
    	{
      	printf("\nOK To pass the vehicles(%d and %d) through intersection: ",a,a+1);
    	}
    	else if(obj[a].orgn==obj[a+1].orgn)
    	{
      	printf("\nOK To pass the vehicles through intersection: ");
    	}
    	else if(obj[a].destinatn!=obj[a+1].destinatn)
    	{
      	switch(obj[a].orgn)
      	{
        case 0:
          printf("\nvehicle %d take right turn ie goes to east to north",a);
          break;
          case 1:
          printf("\nvehicle %d take right turn ie goes to west to south",a);
          break;
        case 2:
          printf("\nvehicle %d take right turn ie goes to north to west",a);
          break;
        case 3:
          printf("\nvehicle %d take right turn ie goes to south to east",a);
          break;
      }
      switch(obj[a+1].orgn)
      {
        case 0:
          printf("\nvehicle %d take right turn ie goes to east to north",a+1);
          break;
          case 1:
          printf("\nvehicle %d take right turn ie goes to west to south",a+1);
          break;
        case 2:
          printf("\nvehicle %d take right turn ie goes to north to west",a+1);
          break;
        case 3:
          printf("\nvehicle %d take right turn ie goes to south to east",a+1);
          break;
      }
    }a++;
}
}
enum dir{East=0,West=1,North=2,South=3};
void *genrateVehicle(void *vehicleInfo)
{
  struct directn *obj=vehicleInfo;
  int c,d;
  while(1)
  {
    c=rand()%4;
    d=rand()%4;
    if(c!=d)
    break;
  }
  obj->orgn=c;
  obj->destinatn=d;
  
    printf("\nvehicle %d goes from %d ----> %d\n\n",obj->vid,obj->orgn,obj->destinatn);
    //intersection((void*)(obj->vid));
}
int main()
{
  printf("\n\n***TRAFIC INTERSECTION PROBLEM ***\n\n");
  printf("East : 0\nWest : 1\nNorth : 2\nSouth : 3\n");
  printf("\nEnter Number of vehicle in a traffic : ");
  scanf("%d",&vehicle);
  pthread_t vehicle_id[vehicle];
  struct directn object[vehicle];
  pthread_t inter;
	int temp=0;  
pthread_mutex_t l; 
if(temp==0)
	{ int a;
//pthread_mutex_lock(&l);
 for(a=1;a<=vehicle;a++)
  {
    object[a].vid=a;
    pthread_create(&vehicle_id[a],NULL,genrateVehicle,(void*)&object[a]);
  }
	
  for(a=1;a<=vehicle;a++)
  {
    pthread_join(vehicle_id[a],NULL);
  }
//pthread_mutex_unlock(&l);
temp+=1;
}
if(temp+=1)
{
//pthread_mutex_lock(&l);
pthread_create(&inter,NULL,intersection,&object);
  pthread_join(inter,NULL);
//pthread_mutex_unlock(&l);
}
 
  return 0;
}
