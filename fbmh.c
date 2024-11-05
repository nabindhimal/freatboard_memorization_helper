#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char get_natural_notes();
char get_sharp_notes();
char get_flat_notes();
int get_random(int max);

int main()
{

  int position, practice;
  time_t end_time;
  char *mode;

  mode = malloc(sizeof(char));

  printf("Choose a mode(n=natural,f=flat,s=sharp,a=all)\n");
  scanf("%c", mode);

  printf("Please choose a position on the neck.(1-12)\n");
  scanf("%d", &position);

  printf("Please choose your practice time in minutes.\n");
  scanf("%d", &practice);


  end_time = time(NULL) + (practice * 60);

  while(time(NULL) < end_time)
  {
    switch(*mode)
    {
      case 'n':
        printf("\n%c\n", get_natural_notes());
        sleep(5);
        break;

      case 'f':
        printf("\n%cb\n", get_flat_notes());
        sleep(5);
        break;

      case 's':
        printf("\n%c#\n", get_sharp_notes());
        sleep(5);
        break;

      default:
        printf("Invalid mode, Deafaulting to natural.\n");
        *mode = 'n';
        break;

    }

    
  }

	return 0;
}

int get_random(int max)
{
  return ( rand() % max ) + 1;
}

char get_natural_notes()
{
  srand(time(0));
  int x = get_random(7);
  return 64 + x;
}

char get_flat_notes()
{
  srand(time(0));
  int x = get_random(7);
  int note = 64 + x;

  if (note == 67 || note == 70) note++;

  return note;


}

char get_sharp_notes()
{
  srand(time(0));
  int x = get_random(7);
  int note = 64 + x;

  if (note == 66 || note == 69) note++;

  return note;

}



