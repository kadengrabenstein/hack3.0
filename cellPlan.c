/**
 * Author: Kaden Grabenstein
 * Date: 2020/09/02
 *
 * This program helps customers track their data usage
 **/

 #include <stdlib.h>
 #include <stdio.h>

 int main(int argc, char **argv){

     double gbInPlan = atof(argv[1]); //command line arguments
     int dayInPlan = atoi(argv[2]);
     double gbUsed = atof(argv[3]);

     double aveDailyUse;
     double neededDailyUsage;

     printf("%d days used, %d days remaining\n", dayInPlan, 30 - dayInPlan); //prints days used and remaining
     printf("Average daily use: %f GB/day\n", gbUsed / dayInPlan); // prints average daily usage

     aveDailyUse = gbInPlan / 30; // prints average daily usage based on plan
     neededDailyUsage = (gbInPlan - gbUsed) / (30 - dayInPlan); // prints daily usage based on how much has been used and what day you're on

     if((gbUsed / dayInPlan) > aveDailyUse){
         printf("You are EXCEEDING your average daily use (%f GB/day).\n", aveDailyUse);
         printf("Continuing this high usage, you'll exceed your data plan by %f GB.\n",((gbUsed / dayInPlan) * (30 - dayInPlan) + gbUsed) - gbInPlan); // Prints how far over your plan you are on track to be
         printf("To stay below your data plan, use no more than %f GB/day.\n", neededDailyUsage);
     }
     else if((gbUsed / dayInPlan) < aveDailyUse){
         printf("You are BELOW your average daily use (%f GB/day).\n", aveDailyUse);
         printf("Continuing this low usage you will not exceed your data plan.\n");
         printf("To stay below your data plan, use no more than %f GB/day.\n", neededDailyUsage);
     }
     else{
         printf("You are RIGHT ON TRACK for your average daily use (%f GB/day).\n", aveDailyUse);
         printf("Continuing this usage will not exceed your data plan.\n");
         printf("To stay on track, use no more than %f GB/day.\n", neededDailyUsage);
     }


    return 0;
 }