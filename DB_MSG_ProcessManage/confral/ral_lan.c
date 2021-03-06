/**********************************************************************
Copyright (c) 2005 Wuhan Tecom Co., Ltd.
All Rights Reserved
No portions of this material may be reproduced in any form without the
written permission of:
Wuhan Tecom Co., Ltd.
#18, Huaguang Road
Wuhan, PR China 430074
All information contained in this document is Wuhan Tecom Co., Ltd.
company private, proprietary, and trade secret.
***********************************************************************
Filename: ral_lan.c
Author: Ken
Date: 2010-08-16
Description: 
 
Histroy: 
    1.  Modification: 
        Author: 
        Date: 
  
    2.  
***********************************************************************/

#include "ral_lan.h"
#include <tcm_util.h>

tcmRet ralLan_doConfig(const char* lanIp, const char* lanMask)
{
    tcmLog_error("Lan ip %s, mask %s", lanIp, lanMask);
    char cmd[BUFLEN_128];

    memset(cmd, 0, sizeof(cmd));
//    sprintf(cmd, "ifconfig lo 127.0.0.1");
sprintf(cmd, "echo ifconfig lo 127.0.0.1" );
    tcm_doSystemAction("ralLan_doConfig", cmd);

    memset(cmd, 0, sizeof(cmd));
//    sprintf(cmd, "ifconfig eth0 %s netmask %s up", lanIp, lanMask);
sprintf(cmd, "echo ifconfig eth0 %s netmask %s up", lanIp, lanMask );
    tcm_doSystemAction("ralLan_doConfig", cmd);

    return TCMRET_SUCCESS;
}
