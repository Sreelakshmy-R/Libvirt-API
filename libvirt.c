/* C Program to implement API using Libvirt */

#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

int main()
{

    int i,val=-1,choice,ID,ch=0;
    virConnectPtr conn;
    virDomainPtr vdp;
    char domname[10];
    conn = virConnectOpen("xen:///");
    if (conn == NULL) {
        fprintf(stderr, "Error opening connection to XEN:///  \n");
        return 1;
    }
    else
    {
       printf("\n Active domain IDs are : \n");
       system("sudo xm list");

        while(1)
        {
            
            printf("\n1.Start an existing DomU\n2.Suspend an existing DomU\n3.Resume an existing DomU\n4.stop an exixsting DomU\n5.exit ");
            scanf("%d",&choice);        
            switch(choice)
            {
                case 1:
                       printf("\nEnter the domain name  :  ");
                       scanf("%s",&domname);
                       vdp=virDomainLookupByName(conn,domname);
		       val=virDomainCreate(vdp);
                       if(val==0)      
                       {
                           printf("\nSuccessfully Created DomU");
                           system("sudo xm list");
 		       }
                       else
                           printf("\nFailed"); 
                       break;
                case 2:
                       printf("\n To view active Domain ID's enter '1':");
                       scanf("%d",&ch);
                       printf("\n For Active domain IDs : \n");

                       if(ch==1)
                       {
   		      	       system("sudo xm list");
		       }
 		       printf("\n Please Insert the Active Domain ID ");
                       scanf("%d",&ID);
                       vdp=virDomainLookupByID(conn,ID);
		       val=virDomainSuspend(vdp);
                       if(val==0)
                           printf("\nSuccess Suspended DomU");
                       else
                           printf("\nFailed");   
                       break;
                case 3:
                       printf("\n To view active Domain ID's enter '1':");
                       scanf("%d",&ch);
                       printf("\n For Active domain IDs : \n");
                       if(ch==1)
                       {
   		      	       system("sudo xm list");
		       } 
           		printf("\n Please Insert the Active Domain ID ");
	                scanf("%d",&ID);
   		        vdp=virDomainLookupByID(conn,ID);
		        val=virDomainResume(vdp);
                        if(val==0)                     
                            printf("\nSuccessfully Resume DomU");
                        else
                            printf("\nFailed");   
                        break;

                case 4: 
		       printf("\n To view active Domain ID's enter '1':");
                       scanf("%d",&ch);
                       printf("\n For Active domain IDs : \n");                     
                       if(ch==1)
                       {
   		      	       system("sudo xm list");
		       }
	                printf("\n Please Insert the Active Domain ID ");
          	        scanf("%d",&ID);
   	                vdp=virDomainLookupByID(conn,ID);
			val=virDomainShutdown(vdp);
                        if(val==0)                     
                            printf("\nSuccessfully Shutdown DomU");
                        else
                            printf("\nFailed");   
                        break;
                default:
 			exit(1);
            }
        }
        virConnectClose(conn);
    }
}
