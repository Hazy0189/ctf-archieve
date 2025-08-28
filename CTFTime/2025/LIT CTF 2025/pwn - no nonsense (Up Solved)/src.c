#include <defs.h>
// Data declarations

void *_dso_handle = &_dso_handle; // idb
FILE *_bss_start; // idb
FILE *stderr; // idb
char completed_0; // weak
char leet[280]; // weak

//----- (00000000000011E9) ----------------------------------------------------
void __noreturn panic()
{
  signed __int64 v0; // rax

  v0 = sys_exit(0);
}

//----- (0000000000001204) ----------------------------------------------------
int __fastcall __noreturn main(int argc, const char **argv, const char **envp)
{
  char v3; // [rsp+Bh] [rbp-15h]
  int v4; // [rsp+Ch] [rbp-14h] BYREF
  int i; // [rsp+10h] [rbp-10h]
  int v6; // [rsp+14h] [rbp-Ch]
  unsigned __int64 v7; // [rsp+18h] [rbp-8h]

  v7 = __readfsqword(0x28u);
  setbuf(_bss_start, 0);
  setbuf(stderr, 0);
  puts("Welcome to LITter (aka L)!");
  puts("Please speak English!");
  puts("Any connection with suspicious behavior will be terminated immediately");
  puts("Where are you beginning your leet?");
  __isoc99_scanf("%i%*c", &v4);
  puts("What do you want to leet?");
  v6 = read(0, &leet[v4], 0x118u);
  leet[v4 - 1 + v6] = 0;
  for ( i = v4; i < v4 + v6 - 1; ++i )
  {
    v3 = leet[i];
    if ( v3 <= 0x1f || v3 == 0x7f )
      panic();
  }
  if ( strstr(&leet[v4], "TIL") )
  {
    puts("Your message contains banned words.");
    exit(0);
  }
  puts("Goodbye");
  exit(0);
}
