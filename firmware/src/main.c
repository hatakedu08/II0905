/**
 * TP II0905 
 *
 * Nom binôme : Dumont
 *
 * Version :
 *
 */



#define MY_CHANNEL 11


/************************ HEADERS ****************************************/
#include "VT100.h"
#include "system.h"
#include "system_config.h"
#include "miwi/miwi_api.h"


/************************** PROTOTYPES ************************************/





/************************** VARIABLES ************************************/
        
extern API_UINT16_UNION                 myPANID;        						// mon PANID
extern uint8_t                          myLongAddress[MY_ADDRESS_LENGTH];		// mon adresse IEEE
extern API_UINT16_UNION                 myShortAddress;                     	// mon adresse logique
extern ACTIVE_SCAN_RESULT               ActiveScanResults[ACTIVE_SCAN_RESULT_SIZE];		// table des actives scan



extern RECEIVED_MESSAGE  rxMessage;




void main (void)
{
    SYSTEM_Initialize();
    uartInitialize();
    erase();
    //_uartPrint("yo les gens");
    uint8_t connect;
    MiApp_ProtocolInit(false);
    MiApp_SetChannel(MY_CHANNEL);
    //MiApp_connectionMode(ENABLE_ALL_CONN); //pour créer la connection
    //MiApp_StartConnection(START_CONN_DIRECT,0,0);
    connect =MiApp_SearchConnection(10,0x1L<<MY_CHANNEL);
    if (connect != 0){
        _uartPrint("connecte"); 
    }
    MiApp_EstablishConnection(0,CONN_MODE_DIRECT);
    MiApp_FlushTx();
    MiApp_WriteData('a');
    if (MiApp_BroadcastPacket(0) ==1){
        _uartPrint(" envoyé "); 
    }
    Nop(); 
    
    //renvoie qq chose de différent de zero si quelqu'un coonecté
    //if (connect == 0){
    //         MiApp_StartConnection(Mode,ScanDuration,ChannelMap,DestAddr)
    //}
    while (1);
}
/*
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */




