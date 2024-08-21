# This code is diffeerent from Mr. Carlisle's because his code had some errors and I fixed them. I also added some comments to make things a little bit clearer.

#!/usr/bin/python3
import string
import itertools

from wasmtime import Store, Module, Instance

store = Store()
module = Module.from_file(store.engine, "assembly4.wat")
instance = Instance(store, module, [])

exports = instance.exports(store)
memory = exports["memory"]
check_flag = exports["check_flag"]

def init_flag(pair):
   for i in range(len(flag)):
      memory.data_ptr(store)[1072+i]=ord(flag[i])
   for j in range(len(flag_so_far)):
      memory.data_ptr(store)[1072+8+j]=ord(flag_so_far[j])
   memory.data_ptr(store)[1072+8+len(flag_so_far)]=ord(pair[0])
   memory.data_ptr(store)[1072+8+len(flag_so_far)+1]=ord(pair[1])

def print_test_flag():
   g=''
   for j in range(1072,1072+8+2+len(flag_so_far)):
      g=g+chr(memory.data_ptr(store)[j])
   print(g)

def count_match():
   count = 0
   while(memory.data_ptr(store)[1024+count]==memory.data_ptr(store)[1072+count]):
      count=count+1
   return count

flag="picoCTF{0123456789abcdef0123456789abcdef}"
flag_chars=string.ascii_lowercase+"_"+string.digits+"}\x00"
flag_so_far=""
# flag has 33 characters, ignoring "picoCTF{", so 16 pairs and 1 leftover (17 pairs)
for i in range(17):
   # repeat=2 because we want to try all possible pairs
   for j in itertools.product(flag_chars,repeat=2):
      init_flag(j)
      check_flag(store)
      if(count_match()>=10+len(flag_so_far)):
         flag_so_far+=(j[0]+j[1])
         print("picoCTF{"+flag_so_far)
         break
