int __fastcall main(int argc, const char **argv, const char **envp)
{
  int v4; // [rsp+4h] [rbp-Ch] BYREF
  unsigned __int64 v5; // [rsp+8h] [rbp-8h]

  v5 = __readfsqword(0x28u);
  setbuf(stdin, 0LL);
  setbuf(stdout, 0LL);
  setbuf(stderr, 0LL);
  puts(aYou);
  firstMalloc();
  do
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          menu();
          v4 = 0;
          if ( (int)__isoc99_scanf("%d", &v4) <= 0 )
            puts("Invalid input detected.");
          while ( getchar() != 10 )
            ;
          if ( v4 != 1 )
            break;
          callMalloc();
        }
        if ( v4 != 2 )
          break;
        callFree();
      }
      if ( v4 != 3 )
        break;
      callLeak();
    }
  }
  while ( v4 != 4 );
  return 0;
}

ssize_t firstMalloc()
{
  ssize_t result; // rax
  void *buf; // [rsp+8h] [rbp-8h]

  buf = malloc(0x409uLL);
  if ( !buf )
  {
    puts("Allocation failed.");
    exit(1);
  }
  mallocArray[0] = (__int64)buf;
  mallocSizes[0] = 1033;
  ++mallocCounter;
  puts("Please list all the items you are bringing inside for security screening.");
  fwrite("List of items > ", 1uLL, 0x10uLL, stdout);
  result = read(0, buf, 0x409uLL);
  if ( result <= 0 )
  {
    puts("Failed to read.");
    exit(1);
  }
  return result;
}

unsigned __int64 callMalloc()
{
  unsigned int v1; // [rsp+4h] [rbp-1Ch] BYREF
  int v2; // [rsp+8h] [rbp-18h] BYREF
  int v3; // [rsp+Ch] [rbp-14h]
  void *buf; // [rsp+10h] [rbp-10h]
  unsigned __int64 v5; // [rsp+18h] [rbp-8h]

  v5 = __readfsqword(0x28u);
  if ( mallocCounter <= 4 )
  {
    fwrite("Choose the crate slot (1-4) > ", 1uLL, 0x1EuLL, stdout);
    v1 = 0;
    if ( (int)__isoc99_scanf("%d", &v1) <= 0 )
      goto LABEL_4;
    if ( v1 > 4 )
    {
      puts("That crate slot is not valid.");
      return __readfsqword(0x28u) ^ v5;
    }
    if ( mallocArray[v1] )
    {
      puts("That crate slot is already in use.");
      return __readfsqword(0x28u) ^ v5;
    }
    fwrite("Enter crate size > ", 1uLL, 0x13uLL, stdout);
    v2 = 0;
    if ( (int)__isoc99_scanf("%d", &v2) <= 0 )
    {
LABEL_4:
      puts("Invalid input detected.");
    }
    else
    {
      v3 = v2 - 1;
      puts("One byte was reserved from the total size to prevent poisoning other crates.");
      if ( v3 <= 40 )
      {
        buf = malloc(v3);
        if ( !buf )
        {
          puts("Allocation failed.");
          exit(1);
        }
        mallocArray[v1] = (__int64)buf;
        mallocSizes[v1] = v3;
        ++mallocCounter;
        fwrite("Load the crate with your evidence > ", 1uLL, 0x24uLL, stdout);
        if ( read(0, buf, v2) <= 0 )
        {
          puts("Failed to read crate contents.");
          exit(1);
        }
        puts("Crate successfully quarantined for further analysis.");
      }
      else
      {
        puts("That crate size is too large for safety regulations.");
      }
    }
  }
  else
  {
    puts("The quarantine facility can only hold a limited number of crates.");
  }
  return __readfsqword(0x28u) ^ v5;
}

unsigned __int64 callFree()
{
  unsigned int v1; // [rsp+4h] [rbp-Ch] BYREF
  unsigned __int64 v2; // [rsp+8h] [rbp-8h]

  v2 = __readfsqword(0x28u);
  fwrite("Select crate slot to free (1-4) > ", 1uLL, 0x22uLL, stdout);
  v1 = 0;
  if ( (int)__isoc99_scanf("%d", &v1) <= 0 )
  {
    puts("Invalid input detected.");
    exit(1);
  }
  if ( v1 <= 4 )
  {
    if ( mallocArray[v1] )
    {
      free((void *)mallocArray[v1]);
      mallocArray[v1] = 0LL;
      mallocSizes[v1] = 0;
      --mallocCounter;
      puts("Crate successfully freed from quarantine.");
    }
    else
    {
      puts("This crate slot is already empty.");
    }
  }
  else
  {
    puts("That crate slot is not valid.");
  }
  return __readfsqword(0x28u) ^ v2;
}

unsigned __int64 callLeak()
{
  unsigned int v1; // [rsp+4h] [rbp-Ch] BYREF
  unsigned __int64 v2; // [rsp+8h] [rbp-8h]

  v2 = __readfsqword(0x28u);
  fwrite("Select crate slot to inspect (1-4) > ", 1uLL, 0x25uLL, stdout);
  v1 = 0;
  if ( (int)__isoc99_scanf("%d", &v1) <= 0 )
  {
    puts("Invalid input detected.");
    exit(1);
  }
  if ( v1 <= 4 )
  {
    if ( mallocArray[v1] )
    {
      fwrite((const void *)mallocArray[v1], mallocSizes[v1], 1uLL, stdout);
      putchar(10);
      puts("Inspection successfully completed.");
    }
    else
    {
      puts("This crate slot is empty.");
    }
  }
  else
  {
    puts("That crate slot is not valid.");
  }
  return __readfsqword(0x28u) ^ v2;
}