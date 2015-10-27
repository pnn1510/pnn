#include <linux/linkage.h>
#include <linux/uaccess.h>
asmlinkage long sys_get_unique_id(int *uuid)
{
   static int pid;
   pid = pid + 37;
   int err = 0;
   err = put_user(pid, uuid);
   return err ? -EFAULT : 0; 
}
