#include "rsc2/include/Rsc2CApi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

/**************************************************
* rsctool argument description
* -h                show help info
* -l                connect to local host
* -r [host_ip]      connect to remote host
* -s [--signal]
*       -info       list all the available signal
        -assert     assert the signal
        -dessert    dessert the signal
        -rename     rename
        -status     show the status of this signal
**************************************************/

int main(int argc, char *argv[]){
    Rsc2_Host *host = NULL;
    Rsc2_Box *box = NULL;
    Rsc2_Signal *buttonPower = NULL;
    Rsc2_Signal *buttonAcAOut = NULL;
    Rsc2_Signal *buttonAcBOut = NULL;
    Rsc2_Signal *jumperMfgMode = NULL;
    Rsc2_Signal *ledStatusGreen = NULL;
    Rsc2_Signal *ledPower = NULL;
    int num = 0;
    char error[128] = {0};

    if(argc != 2){
        printf("invalid parameter number\n");
        return -1;
    }

    if(strncmp(argv[1], "on", strlen("on")) != 0
    && strncmp(argv[1], "off", strlen("off")) != 0){
        printf("invalid argument 1, only on or off is supported.\n");
        return -1;
    }

    Rsc2_Init();
    printf("rsc2 init done\n");

    host = Rsc2_ConnectToHost("localhost");
    if(host == NULL){
        Rsc2_GetLastErrorMessage(error, 128);
        printf ("unable to connect to host: %s\n", error);
        return -1;
    }

    num = Rsc2_GetNumBoxes(host);
    if(num == 0){
        printf("no rsc2 connected to the host\n");
        return -1;
    }else
        printf("%d rsc2 connected tot host\n", num);

    box = Rsc2_GetBox(host, 0);

    buttonPower = Rsc2_GetSignal(box, RSC2_ID_FPBUT_PWR);
    jumperMfgMode = Rsc2_GetSignal(box, RSC2_ID_JMP_MFG_MODE);
    ledStatusGreen = Rsc2_GetSignal(box, RSC2_ID_LED_STATUS_GREEN);
    ledPower = Rsc2_GetSignal(box, RSC2_ID_LED_PWR);

    buttonAcAOut = Rsc2_GetSignal(box, RSC2_ID_AC_1);
    buttonAcBOut = Rsc2_GetSignal(box, RSC2_ID_AC_2);

    if (strncmp(argv[1], "on", strlen("on")) == 0){
        printf("press down ac a switch\n");
        if (Rsc2_SetSigAssertionState(buttonAcAOut, RSC2_AC_ON)){
            Rsc2_GetLastErrorMessage(error, 128);
            printf ("press button failed: %s\n", error);
            return -1;
        }
        Sleep(1);
        printf("press down ac b switch\n");
        if (Rsc2_SetSigAssertionState(buttonAcBOut, RSC2_AC_ON)){
            Rsc2_GetLastErrorMessage(error, 128);
            printf ("unable to connect to host: %s\n", error);
            return -1;
        }
        Sleep(1);
    }else if(strncmp(argv[1], "off", strlen("off")) == 0){
        printf("press down ac a switch\n");
        if (Rsc2_SetSigAssertionState(buttonAcAOut, RSC2_AC_OFF)){
            Rsc2_GetLastErrorMessage(error, 128);
            printf ("press button failed: %s\n", error);
            return -1;
        }
        Sleep(1);
        printf("press down ac b switch\q:Q:q!n");
        if (Rsc2_SetSigAssertionState(buttonAcBOut, RSC2_AC_OFF)){
            Rsc2_GetLastErrorMessage(error, 128);
            printf ("unable to connect to host: %s\n", error);
            return -1;
        }
        Sleep(1);
    }

    return 0;

}
