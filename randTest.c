#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


// Random nuumber Generator function
int
randGenerator()
{

  /* Intializes random number generator */


  int number = (int)(10.0 * rand() / (RAND_MAX + 1.0));

  return number;
}


double
MeanTest()
{
  int total = 0;
  for (size_t i = 0; i < 1000; i++)
  {
    int number = randGenerator();
    
    total =total+ number;
  }
  double mean = total / 1000;
  printf("Mean: %f \n", mean);

  return total;
}


void
FrequencyTest()
{
  int total = 0;
  int numbers[10000] = { 0 };
  for (size_t i = 0; i < 10000;i++)
  {
     numbers[i] = randGenerator();

   
  }

  for (size_t i = 0; i < 10; i++)
  {
    int occr = 0;
    for (size_t i2 = 0; i2 < 10000; i2++)
    {
      if (numbers[i2] == i)
      {
        occr++;
      }
    }
    double percentage = (occr / 100);
    printf("Percentage of occurnces of %d is %f\n", i, percentage);

  }

}


void
SerialTest()
{
  int numbers[10000] = { 0 };
  int numbers2[10000] = { 0 };
  for (size_t i = 0; i < 10000; i++)
  {
    numbers[i] = randGenerator();
    numbers2[i] = randGenerator();
  }

  for (size_t i1 = 0; i1 < 10; i1++)
  {
    for (size_t i2 = 0; i2 < 10; i2++)
    {
      int count = 0;
      for (size_t i = 0; i < 10000; i++)
      {
        //comparing numbers
        if (numbers[i] == i1 && numbers2[i] == i2)
        {
          count++;
        }

      }
      double percentage = count/100;
      printf("Percentage of occurnces of %d %d is %f\n", i1,i2, percentage);
    }
  }
}

void
pokerTest()
{
  int allthesame = 0;
  int threesame = 0;
  int onepair = 0;
  int twopair = 0;
  int nosame = 0;
  for (size_t i = 0; i < 1000; i++)
  {
    int similarities = 0;
    //Generating four random numbers
    int number1 = randGenerator();
    int number2 = randGenerator();
    int number3 = randGenerator();
    int number4 = randGenerator();

    if (number1 == number2)
    {
      similarities++;
    }
    if (number1 == number3)
    {
      similarities++;
    }
    if (number1 == number4)
    {
      similarities++;
    }
    if (number2 == number3)
    {
      similarities++;
    }
    if (number2 == number4)
    {
      similarities++;
    }
    if (number3 == number4)
    {
      similarities++;
    }

    //checking how many simillar pairs there is
    if (similarities == 0)
    {
      nosame++;
    }
    if (similarities == 1)
    {
      onepair++;
    }
    else if (similarities == 2)
    {
      twopair++;
    }
    else if (similarities==3)
    {
      threesame++;
    }
    else if (similarities == 6)
    {
      allthesame++;
    }

    
  }

  printf("All The same:%d \n", allthesame);
  printf("Three digits same:%d\n", threesame);
  printf("two pairs same:%d\n", twopair);
  printf("One Pair same:%d\n", onepair);
  printf("None Identical:%d\n", nosame);
 
}



void
pokerTestUsingFile()
{

FILE *file1, *file2;
char  str[60];

  int allthesame = 0;
  int threesame = 0;
  int onepair = 0;
  int twopair = 0;
  int nosame = 0;

  errno_t error_code;
  error_code = fopen_s(&file2, "./cache.txt", "w+");
  if (error_code != 0)
  {
    printf("Error! Failed to open file in w+ mode!");
  }
  else
  {
    printf("Now I have opened txt in write+ mode!");
    
  }
  for (size_t i = 0; i < 1000; i++)
  {



   
    // Generating four random numbers
    int number1 = randGenerator();
    int number2 = randGenerator();
    int number3 = randGenerator();
    int number4 = randGenerator();
    //wrinting to  file cache.txt
    fprintf(file2, "%d%d%d%d ", number1, number2, number3, number4);
  }
  _fcloseall();


    // Opening file in r mode


  error_code = fopen_s(&file2, "./cache.txt", "r");
  
  if (error_code != 0)
  {
    printf("Error! Failed to open file in r mode!");
  }
  else
  {
    printf("I opened txt file in r mode!\n");

    int number = 0;

    while (fscanf_s(file2, "%d ",&number )!=EOF)
    {

      //seperating each digit from number
     
        int number1 = number % 10;       
        number /= 10;

        int number2 = number % 10;
        number /= 10;

        int number3 = number % 10;
        number /= 10;

        int number4 = number % 10;
        number /= 10;


        int similarities = 0;

        if (number1 == number2)
        {
          similarities++;
        }
        if (number1 == number3)
        {
          similarities++;
        }
        if (number1 == number4)
        {
          similarities++;
        }
        if (number2 == number3)
        {
          similarities++;
        }
        if (number2 == number4)
        {
          similarities++;
        }
        if (number3 == number4)
        {
          similarities++;
        }

        // checking how many simillar pairs there is
        if (similarities == 0)
        {
          nosame++;
        }
        if (similarities == 1)
        {
          onepair++;
        }
        else if (similarities == 2)
        {
          twopair++;
        }
        else if (similarities == 3)
        {
          threesame++;
        }
        else if (similarities == 6)
        {
          allthesame++;
        }


      
      /* do something with the value */
    }
  }
   
   
   printf("All The same:%d \n", allthesame);
  printf("Three digits same:%d\n", threesame);
  printf("two pairs same:%d\n", twopair);
  printf("One Pair same:%d\n", onepair);
  printf("None Identical:%d\n", nosame);
}
  // Main Function
int main(int argc, // Number of strings in array argv
char *argv[],      // Array of command-line argument strings
char **envp )      // Array of environment variable strings
{
  printf("Rand Test.c !\n");
 
  int arg = atoi(argv[1]);

  if (arg == 1)
  {
    printf("Test 1: Mean Test \n");
    double test = MeanTest();
  }
  else if (arg == 2)
  {
    printf("Test 2: Frequency Test \n");
    FrequencyTest();
  }
  else if (arg == 3)
  {
    printf("Test 3: Serial Test \n");
    SerialTest();
  }
  else if (arg == 4)
  {
    printf("Test 4: Poker Test \n");
    pokerTest();
  }
  else if (arg == 5)
  {
    printf("Test 5: Poker Test Using File \n");
    pokerTestUsingFile();
  }
  else
  {
    printf("Plase choose valid Test(1-5)!");
  }
  

  return 0;
}

