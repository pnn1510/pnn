#include <linux/linkage.h>
#include <linux/uaccess.h>
asmlinkage long sys_get_unique_id(int *uuid)
{
   static int pid;
   pid = pid + 31;
   *uuid = pid;
   if(access_ok(VERIFY_WRITE,uuid,4)) return 0;
   return -1;   
}
