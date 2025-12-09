#include "out.h"



int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00101020(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



void FUN_00101140(void)

{
  __cxa_finalize();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = putchar(__c);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fclose(__stream);
  return iVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fgetc(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fgetc(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strcspn(char *__s,char *__reject)

{
  size_t sVar1;
  
  sVar1 = strcspn(__s,__reject);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void srand(uint __seed)

{
  srand(__seed);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int getchar(void)

{
  int iVar1;
  
  iVar1 = getchar();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = time(__timer);
  return tVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n)

{
  int iVar1;
  
  iVar1 = setvbuf(__stream,__buf,__modes,__n);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(__filename,__modes);
  return pFVar1;
}



void __isoc99_scanf(void)

{
  __isoc99_scanf();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
                    // WARNING: Subroutine does not return
  exit(__status);
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int rand(void)

{
  int iVar1;
  
  iVar1 = rand();
  return iVar1;
}



void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_8 [8];
  
  __libc_start_main(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x001012a3)
// WARNING: Removing unreachable block (ram,0x001012af)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x001012e4)
// WARNING: Removing unreachable block (ram,0x001012f0)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_0 != '\0') {
    return;
  }
  FUN_00101140(__dso_handle);
  deregister_tm_clones();
  completed_0 = 1;
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



void init_users(void)

{
  int local_c;
  
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    memset(users + (long)local_c * 0x50,0,0x40);
    *(undefined8 *)(users + (long)local_c * 0x50 + 0x40) = 0;
    users[(long)local_c * 0x50 + 0x48] = 1;
    users[(long)local_c * 0x50 + 0x49] = 0;
  }
  return;
}



void login(void)

{
  int iVar1;
  size_t sVar2;
  long in_FS_OFFSET;
  int local_30;
  int local_2c;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter your user ID (0-9): ");
  __isoc99_scanf(&DAT_00102023,&local_30);
  getchar();
  if ((local_30 < 0) || (9 < local_30)) {
    puts("Invalid user ID!");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  if (users[(long)local_30 * 0x50 + 0x48] == '\0') {
    printf("Welcome back, %s! Current balance: %lld coins\n",users + (long)local_30 * 0x50,
           *(undefined8 *)(users + (long)local_30 * 0x50 + 0x40));
  }
  else {
    printf("Welcome new user! Please enter your name: ");
    fgets(users + (long)local_30 * 0x50,0x40,stdin);
    iVar1 = local_30;
    sVar2 = strcspn(users + (long)local_30 * 0x50,"\n");
    users[(long)iVar1 * 0x50 + sVar2] = 0;
    printf("Hello, %s\n",users + (long)local_30 * 0x50);
    printf("Enter amount of coins you want: ");
    iVar1 = __isoc99_scanf(&DAT_00102091,&local_28);
    if (iVar1 == 1) {
      getchar();
      *(long *)(users + (long)local_30 * 0x50 + 0x40) =
           local_28 * 8 + *(long *)(users + (long)local_30 * 0x50 + 0x40);
      users[(long)local_30 * 0x50 + 0x48] = 0;
      printf("Account created! Balance: %lld coins\n",local_28);
    }
    else {
      puts("ERROR: Invalid amount");
      do {
        local_2c = getchar();
        if (local_2c == 10) break;
      } while (local_2c != -1);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void win(void)

{
  int iVar1;
  FILE *__stream;
  
  __stream = fopen("flag.txt","r");
  if (__stream == (FILE *)0x0) {
    puts("ERROR: Could not open flag file");
  }
  else {
    puts("Congratulations! Here is your flag:");
    while( true ) {
      iVar1 = fgetc(__stream);
      if ((char)iVar1 == -1) break;
      putchar((int)(char)iVar1);
    }
    fclose(__stream);
  }
  return;
}



void bet(void)

{
  int iVar1;
  long in_FS_OFFSET;
  int local_ac;
  int local_a8;
  char local_a2 [10];
  char local_98 [136];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  builtin_strncpy(local_98,"₹Rupess or $Dollars doesn\'t matter! You are gonna lose it all!\n",
                  0x42);
  printf("Plese enter id to place bet: ");
  __isoc99_scanf(&DAT_00102023,&local_ac);
  getchar();
  if ((local_ac < 0) || (9 < local_ac)) {
    puts("Invalid user ID!");
  }
  else if (users[(long)local_ac * 0x50 + 0x49] == '\0') {
    if (users[(long)local_ac * 0x50 + 0x48] == '\0') {
      users[(long)local_ac * 0x50 + 0x49] = 1;
      memset(local_a2,0,10);
      printf("Enter your bet amount (Please specify Currency): ");
      for (local_a8 = 0; local_a8 < 0x10; local_a8 = local_a8 + 1) {
        iVar1 = getchar();
        if ((char)iVar1 == '\n') break;
        local_a2[local_a8] = (char)iVar1;
      }
      printf(local_98);
    }
    else {
      puts("You need to login first before placing a bet!");
    }
  }
  else {
    puts("Bet already placed for this session!");
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void gamble(void)

{
  int iVar1;
  long in_FS_OFFSET;
  int local_50;
  int local_4c;
  long local_48;
  ulong local_40;
  char *local_38 [4];
  undefined *local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_38[0] = "Luck issue.";
  local_38[1] = &DAT_00102218;
  local_38[2] = "Exception thrown: HorribleFateError.";
  local_38[3] = "Debug your brain and try again.";
  local_18 = &DAT_00102298;
  printf("Enter your user ID to gamble: ");
  __isoc99_scanf(&DAT_00102023,&local_50);
  getchar();
  if ((local_50 < 0) || (9 < local_50)) {
    puts("Invalid user ID!");
  }
  else if (users[(long)local_50 * 0x50 + 0x49] == '\x01') {
    puts("Let\'s go gambling!");
    puts("You have 5 chances. Good luck!");
    iVar1 = rand();
    local_40 = (ulong)iVar1;
    local_48 = local_40 + (ulong)(0xffffffffffffefff < local_40) * 0x1000;
    for (local_4c = 0; local_4c < 5; local_4c = local_4c + 1) {
      puts("Press ENTER to gamble...");
      getchar();
      if ((local_48 < 0xfff) && (-1 < local_48)) {
        puts("Congratulations! You guessed it right!");
        win();
                    // WARNING: Subroutine does not return
        exit(0);
      }
      local_48 = (local_4c + 1) * local_48 + 0x539;
      puts("Awwwww... Dangit!!!!!!!\n");
      puts(local_38[local_4c]);
    }
    puts("Sorry, you\'ve used all your chances.");
    puts("I guess others didn\'t tell you about me before you started gambling?");
    puts("I\'m gonna take all your money including your wallet amount!");
    **(undefined8 **)(users + (long)local_50 * 0x50 + 0x40) = 0;
  }
  else {
    puts("Please place a bet before gambling!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void print_banner(void)

{
  puts(
      "   $$\\            $$\\  $$\\                                                                            $$\\       $$\\ $$\\                     $$\\ \n   $$ |           $$ | $  |                                                                           $$ |      $$ |\\__|                    $$ |\n   $$ | $$$$$$\\ $$$$$$\\\\_/ $$$$$$$\\        $$$$$$\\   $$$$$$\\         $$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\  $$$$$$$\\  $$ |$$\\ $$$$$$$\\   $$$$$$\\  $$ |\n   $$ |$$  __$$\\\\_$$  _|  $$  _____|      $$  __$$\\ $$  __$$\\       $$  __$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ $$ |$$ |$$  __$$\\ $$  __$$\\ $$ |\n   $$ |$$$$$$$$ | $$ |    \\$$$$$$\\        $$ /  $$ |$$ /  $$ |      $$ /  $$ | $$$$$$$ |$$ / $$ / $$ |$$ |  $$ |$$ |$$ |$$ |  $$ |$$ /  $$ |\\__|\n   $$ |$$   ____| $$ |$$\\  \\____$$\\       $$ |  $$ |$$ |  $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$ |  $$ |$$ |$$ |$$ |  $$ |$$ |  $$ |    \n   $$ |\\$$$$$$$\\  \\$$$$  |$$$$$$$  |      \\$$$$$$$ |\\$$$$$$  |      \\$$$$$$$ |\\$$$$$$$ |$$ | $$ | $$ |$$$$$$$  |$$ |$$ |$$ |  $$ |\\$$$$$$$ |$$\\ \n   \\__| \\_______|  \\____/ \\_______/        \\____$$ | \\______/        \\____$$ | \\_______|\\__| \\__| \\__|\\_______/ \\__|\\__|\\__|  \\__| \\____$$ |\\__|\n                                          $$\\   $$ |                $$\\   $$ |                                                    $$\\   $$ |    \n                                          \\$$$$$$  |                \\$$$$$$  |                                                    \\$$$$$$  |    \n                                           \\______/                  \\______/                                                      \\______/     \n"
      );
  return;
}



void setup(void)

{
  long in_FS_OFFSET;
  char local_a8 [152];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  builtin_strncpy(local_a8,
                  "Alright! I will be quick with rules.\n1. You can place a bet only once per login session.\n2. You have 5 chances to win the gamble.\n3. Good luck!\n"
                  ,0x91);
  puts(local_a8);
  print_banner();
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void menu(void)

{
  puts("\n--- Main Menu ---");
  puts("[1] Login");
  puts("[2] Place Bet");
  puts("[3] Gamble");
  puts("[4] Exit");
  printf("> ");
  return;
}



void main(void)

{
  int iVar1;
  time_t tVar2;
  
  setup();
  init_users();
  tVar2 = time((time_t *)0x0);
  srand((uint)tVar2);
LAB_00101e6a:
  puts("\nWelcome Gambler!");
  menu();
  iVar1 = getchar();
  if (iVar1 == 0x34) {
    puts("Goodbye!");
                    // WARNING: Subroutine does not return
    exit(0);
  }
  if (iVar1 < 0x35) {
    if (iVar1 == 0x33) {
      gamble();
      goto LAB_00101e6a;
    }
    if (iVar1 < 0x34) {
      if (iVar1 == 0x31) {
        login();
      }
      else {
        if (iVar1 != 0x32) goto LAB_00101eee;
        bet();
      }
      goto LAB_00101e6a;
    }
  }
LAB_00101eee:
  puts("Invalid choice, please try again.");
  goto LAB_00101e6a;
}



void _fini(void)

{
  return;
}



