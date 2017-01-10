#include <stdio.h>
#define N 10
int main()
{
   int over_eighty =0, over_sixty =0, over_fourty =0, fourty_less =0;
   int eighty_hundred =0, sixty_eighty =0, fourty_sixty =0, zero_fourty=0;
   int not_inrange=0;
   int list[N];
   list[0] = 88; list[1] = 66; list[2] = 45; list[3] = 35;
   list[4] = 90; list[5] = 70; list[6] = 50; list[7] = 20;
   list[8] = 58; list[9] = 60;
   int i=0;
   for (i; i<N; i++)
   {
     if(list[i] <= 40)
       {
         fourty_less++;
         zero_fourty++; 
       }
     else if(list[i] <= 60 && list[i] > 40)
       {
         over_fourty++;
         fourty_sixty++;
       }
     else if(list[i] <= 80 && list[i] > 60)
       {
         over_fourty++;
         over_sixty++;
         sixty_eighty++;
       }
     else if(list[i] <= 100 && list[i] > 80)
       {
         over_fourty++;
         over_sixty++;
         over_eighty++;
         eighty_hundred++;
       }
     else
      not_inrange++;
   }
   printf("Student with over eighty: %d\n", over_eighty);
   printf("Student with over sixty: %d\n", over_sixty);
   printf("Student with over forty: %d\n", over_fourty);
   printf("Student with 40 and less: %d\n", fourty_less);
   printf("Student between 81 to 100: %d\n", eighty_hundred);
   printf("Student between 61 to 80: %d\n", sixty_eighty);
   printf("Student between 41 to 60: %d\n", fourty_sixty);
   printf("Student between 0 to 40: %d\n", zero_fourty);
   printf("Student without the range : %d\n", not_inrange);
}
