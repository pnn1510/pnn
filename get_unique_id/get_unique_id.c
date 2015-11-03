#include <linux/linkage.h>
#include <linux/uaccess.h>
asmlinkage long sys_get_unique_id(int *uuid)
{
   static int pid;
<<<<<<< HEAD
   pid = pid + 31;
   *uuid = pid;
   if(access_ok(VERIFY_WRITE,uuid,4)) return 0;
   return -1;   
=======
   pid = pid + 37;
   int err = 0;
   err = put_user(pid, uuid);
   return err ? -EFAULT : 0; 
>>>>>>> 9375fc9421181b9cbdafe6665200015c2da2dfdc
}
