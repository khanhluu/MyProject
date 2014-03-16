#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int pow_processing(int base, int exp)
{
   int ret = 1;
   if(exp == 0)
      return ret;
   return (base * pow_processing(base, exp-1) );
}

int sum_processing(char STR[], int len)
{
   static int sum = 0;
   static int a = 0;
   static int count = 0;
   char cc = STR[len-1];

   if(len <= 0)
   {
      int temp  = sum;
      a = 0;
      count =0;
      sum = 0;
      return temp;
   }
   switch(cc)
   {
      case '-':
         a = 0;
         count = 0;
         break;
      case ' ':
         sum = sum + a*a;
         a = 0;
         count = 0;
         break;
      default:
         a = a + atoi(&cc) * pow_processing(10, count);
         if(len == 1)
         {
            sum = sum + a*a;
         }
         ++count;
         break;
   }
   sum_processing(STR, len-1);
}
void input_elements_on_line(int x, int *output)
{
   int len = 0;
   char STR[100];
   if(x < 1)
   {
      return ;
   }
   scanf(" %[^\n]s", STR);
   len = strlen(STR);
   *output = sum_processing(STR, len);
}

void sum_square(int n, int *output)
{
   int x = 0;
   static int element = 0;
   if( n <= 0 || n > 100)
   {
      return ;
   }

   scanf("%d", &x);
   if(x <= 0 || x > 100)
   {
      return ;
   }
   input_elements_on_line(x, &output[element]);
   sum_square(n-1, &output[++element]);
}

void show_result(int len, int *output)
{
   static int i = 0;
   if(len == 0)
      return;

  printf("%d\n", output[i]);
  show_result(len - 1, &output[++i]);
}
int main()
{
   int n = 0;
   int output[100] = {0};

   scanf("%d", &n);

   sum_square(n, output);

   show_result(n, output);

   return 0;
}
