__int64 __fastcall proc_read(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // rax
  _QWORD v5[7]; // [rsp+0h] [rbp-38h] BYREF

  v5[4] = __readgsqword(0x28u);
  if ( a3 > 0x400 )
    return proc_read_cold();
  _memcpy(proc_data, v5, a3);
  LODWORD(result) = copy_to_user(a2, proc_data, a3);
  if ( !(_DWORD)result )
    LODWORD(result) = a3;
  return (int)result;
}

__int64 __fastcall proc_ioctl(file *file, unsigned int cmd, unsigned __int64 arg)
{
  char *v4; // rdi
  __int64 v5; // rcx
  char *v6; // rsi
  __int64 v7; // [rsp+0h] [rbp-28h] BYREF
  char v8; // [rsp+8h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+20h] [rbp-8h]

  v9 = __readgsqword(0x28u);
  if ( cmd != 0x7301 )
    return -22LL;
  v4 = &v8;
  v5 = 6LL;
  v6 = proc_data;
  while ( v5 )
  {
    *(_DWORD *)v4 = 0;
    v4 += 4;
    --v5;
  }
  v7 = 0LL;
  _memcpy(&v7, v6, 1024LL);
  printk(&unk_2F1, &v7);
  return 0LL;
}

void __fastcall proc_write(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // [rsp+0h] [rbp-30h] BYREF
  __int64 v8; // [rsp+8h] [rbp-28h]
  __int64 v9; // [rsp+10h] [rbp-20h]
  __int64 v10; // [rsp+18h] [rbp-18h]
  unsigned __int64 v11; // [rsp+20h] [rbp-10h]

  v11 = __readgsqword(0x28u);
  v7 = 0LL;
  v8 = 0LL;
  v9 = 0LL;
  v10 = 0LL;
  if ( a3 > 0x3FF )
  {
    proc_write_cold();
  }
  else if ( !(unsigned int)copy_from_user(proc_data, a2, a3 - 1, a4, a5, a6, v7, v8, v9, v10, v11) )
  {
    _memcpy(&v7, proc_data, a3);
    proc_data[a3] = 0;
  }
}

int __cdecl proc_init()
{
  char *v1; // rdi
  __int64 i; // rcx

  proc_data = (char *)_vmalloc(1024LL, 3264LL, _default_kernel_pte_mask & 0x163);
  if ( proc_data )
  {
    printk(&unk_2FE, proc_data);
    v1 = proc_data;
    for ( i = 256LL; i; --i )
    {
      *(_DWORD *)v1 = 0;
      v1 += 4;
    }
    if ( proc_create("shellcode_device", 438LL, 0LL, &proc_fops) )
    {
      printk(&unk_32A, 438LL);
      return 0;
    }
    else
    {
      printk(&unk_3B8, 438LL);
      return -12;
    }
  }
  else
  {
    printk(&unk_388, 0LL);
    return -12;
  }
}

void __cdecl proc_exit()
{
  kfree(proc_data);
  proc_data = 0LL;
  remove_proc_entry("shellcode_device", 0LL);
  printk(&unk_341, 0LL);
}