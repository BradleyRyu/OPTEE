#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* OPTEE includes */
#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>
#include <ta_server_side.h>
#include <ta_client_side.h>

#include "lwip/def.h"
#include "lwip/ip_addr.h"
#include "lwip/init.h"
#include "lwip/tcp.h"
#include "lwip/tcpip.h"
#include "lwipopts.h"
#include "tcpecho_raw.h"
#include "lwip/ip.h"
#include "lwip/timeouts.h"
#include "lwip/netif.h"
#include "netif/ethernet.h"

#define ONBOARD 	0
//static struct netif loop_netif;
//static struct tcp_pcb *client_pcb = NULL;
//static err_t client_connected(void *arg, struct tcp_pcb *tpcb, err_t err);
//static err_t client_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
//static char *data_to_send = NULL;



typedef enum {
    STATE_DISCONNECTED,
    STATE_CONNECTING,
    STATE_CONNECTED,
    STATE_ERROR
} connection_state_t;


typedef struct {
    struct tcp_pcb *pcb;
    connection_state_t state;
} connection_t;

struct netif my_netif;

connection_t server = { .pcb = NULL, .state = STATE_DISCONNECTED };


ip_addr_t server_ip;


static err_t my_netif_init(struct netif *netif) {

   netif->hwaddr_len = 6;

#if ONBOARD

   netif->hwaddr[0] = 0x00;
   netif->hwaddr[0] = 0x04;
   netif->hwaddr[0] = 0x9F;
   netif->hwaddr[0] = 0x07;
   netif->hwaddr[0] = 0x57;
   netif->hwaddr[0] = 0x65;
#else
   netif->hwaddr[0] = 0x52;
   netif->hwaddr[0] = 0x54;
   netif->hwaddr[0] = 0x00;
   netif->hwaddr[0] = 0x12;
   netif->hwaddr[0] = 0x34;
   netif->hwaddr[0] = 0x56;
#endif

   netif->mtu = 1500;

   netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

}



static err_t server_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {

    IMSG("starting point of server_recv()");

    if (err != ERR_OK) {
        printf("Receive error\n");
        return err;
    }



/*
    err_t write_err = tcp_write(tpcb, p->payload, p->len, 0);
    if (write_err != ERR_OK) {
        printf("Failed to write echo data\n");
        return write_err;
    }
*/

    if( p == NULL ) {
       tcp_close(tpcb);
       return ERR_OK;
    }



    tcp_recved(tpcb, p->tot_len);
    IMSG("Received packet: %d bytes, %s", p->tot_len, (char *)p->payload);
    pbuf_free(p);

    IMSG("end of server_recv()");

    return ERR_OK;

}



// Dosen't Call

static err_t tcp_accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err) {

   printf("Server accept callback function\n");

    //if (err != ERR_OK) {
    //    printf("Accept failed\n");
    //    return err;
    //}

    //client.pcb = newpcb;
    //client.state = STATE_CONNECTED;
    //server.state = STATE_CONNECTED;

    tcp_recv(newpcb, server_recv);
    return ERR_OK;

}


/*

static err_t client_connected(void *arg, struct tcp_pcb *tpcb, err_t err) {
  if (err != ERR_OK) {
    IMSG("Client Connection failed");
    client.state = STATE_ERROR;
    return err;
  }

  IMSG("Connected to server");
  client.state = STATE_CONNECTED;

  char *message = "Hello from Secure World!";
  err = tcp_write(tpcb, message, strlen(message), TCP_WRITE_FLAG_COPY);
  if (err != ERR_OK) {
    IMSG("Failed to send message");
  } else {
    IMSG("Message has been sent to server");
  }

  return ERR_OK;

}

*/

/*

void connect_to_server() {
    IMSG("In connect_to_server()");

    //client.pcb = tcp_new();
    //if(client.pcb == NULL) {
    //    IMSG("Failed to create client.pcb");
    //    return ;
    //}

    IMSG("Attempting to connect server at 127.0.0.1:7");

    //err_t err = tcp_connect(client.pcb, &server_ip, 7, client_connected);
    //printf("ERRNO: %d\n", err);
    //if (err != ERR_OK) {
    //    printf("Failed to connect to server: %d\n", err);
    //    client.state = STATE_ERROR;
    //} else {
    //    client.state = STATE_CONNECTING;
    //    printf("Connecting to server...\n");
    //}
    //IMSG("End of connect_to_server()");

}
*/

void event_loop(void) {
    
    printf("I'm in event_loop()\n");
    printf("server_state: %d\n", server.state);

    while (server.state != STATE_CONNECTED && server.state != STATE_ERROR) {
        sys_check_timeouts(); // lwIP timeouts handling

        if (server.state == STATE_ERROR) {
            printf("Connection failed\n");
            break;
        }

        printf("Waiting for accept\n");
        TEE_Wait(1000); // 1 sec waiting
    }

    if (server.state == STATE_CONNECTED) {
        printf("Connection successful\n");
        // Additional tasks after successful connection
    }
}	

/*

void event_loop() {



    printf("I'm in event_loop()\n");

    printf("server_state: %d\n", server.state);


    if (client.state == STATE_CONNECTING) {

        printf("Trying to Connect..\n");

        IMSG("Before Accept");

        tcp_accept(server.pcb, server_accept);

        IMSG("After Accept");



    }



    while (client.state != STATE_CONNECTED && client.state != STATE_ERROR) {

        sys_check_timeouts(); // lwIP 타임아웃 처리



        if (client.state == STATE_ERROR) {

            printf("Connection failed\n");

            break;

        }

        if (client.state == STATE_CONNECTING && server.state == STATE_CONNECTING) {

            printf("Trying to Connect. client.state is %d, server.state is %d\n", client.state, server.state);

       tcp_accept(server.pcb, server_accept);

       

       tcp_accept(server.pcb, server_accept);

       if(server.state == STATE_CONNECTED) {

          printf("Ready to send data, server.state == STATE_CONNECTED\n");

      // 연결 성공 후 추가 작업 수행

           char *message = "Hello from Secure World!";

           err_t err = tcp_write(client.pcb, message, strlen(message), TCP_WRITE_FLAG_COPY);

           if (err != ERR_OK) {

                  printf("Failed to send message\n");

           } else {

                  printf("Message sent to server\n");

           }

       }       

        }



        printf("Waiting for accept\n");

        TEE_Wait(1000); // 1 sec waiting

    }



    if (client.state == STATE_CONNECTED) {

        printf("Connection successful\n");

        // 연결 성공 후 추가 작업 수행



    }



}

*/

/*

static err_t server_connected(void *arg, struct tcp_pcb *tpcb, err_t err) {

    IMSG("starting point of server_connected()");

    if (err != ERR_OK) {

        printf("Connection failed\n");

        client.state = STATE_ERROR;

        return err;

    }



    printf("Connected to server\n");

    printf("client.state = %d\n", client.state);

    tcp_recv(tpcb, server_recv);



    IMSG("end of server_connected()");

    

    return ERR_OK;

}

*/



static err_t tcp_client_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
  if (err != ERR_OK) {
    IMSG("Receive error");
    return err;
  }

  if (p == NULL) {
    IMSG("Connection closed by server");
    tcp_close(tpcb);
    return ERR_OK;
  }

  IMSG("Received packet: %d bytes, %s", p->len, (char *)p->payload);

  tcp_recved(tpcb, p->tot_len);

  pbuf_free(p);

  return ERR_OK;
}

/*

static err_t client_connected(void *arg, struct tcp_pcb *tpcb, err_t err) {

  if (err != ERR_OK) {

    IMSG("Client Connection failed");

    client.state = STATE_ERROR;

    return err;

  }





  IMSG("Connected to server");

  client.state = STATE_CONNECTED;



  char *message = "Hello from Secure World!";

  err = tcp_write(tpcb, message, strlen(message), TCP_WRITE_FLAG_COPY);

  if (err != ERR_OK) {

    IMSG("Failed to send message");

  } else {

    IMSG("Message has been sent to server");

  }



  return ERR_OK;

}

*/



/*****************************************************************

 *          OPTEE setting

 *****************************************************************/


TEE_Result TA_CreateEntryPoint(void) {

   DMSG("has been called");
   
   IMSG("Starting lwIP Initializing\n");
   lwip_init();
   IMSG("Initialized lwIP\n");
   
   IMSG("Starting configuring Network Interface\n");
   ip4_addr_t ipaddr, netmask, gw;
   IP4_ADDR(&ipaddr, 127, 0, 0, 1);
   IP4_ADDR(&netmask, 255, 0, 0, 0);
   IP4_ADDR(&gw, 127, 0, 0, 1);
   netif_add(&my_netif, &ipaddr, &netmask, &gw, NULL, netif_loopif_init, ip_input);
   netif_set_default(&my_netif);
   netif_set_up(&my_netif);


   IP4_ADDR(&server_ip, 127, 0, 0, 1); 
   
   /* NEW */
   server.pcb = tcp_new();

   /* BIND */
   err_t err = tcp_bind(server.pcb, &server_ip, 7);

   if( err != ERR_OK ) {
      printf("Failed to bind server socket\n");
      return TEE_ERROR_GENERIC;
   }

   IMSG("server.pcb bound");

   return TEE_SUCCESS;
}



void TA_DestroyEntryPoint(void) {

   printf("\n\n%d\n\n", netif_is_up(&my_netif));

   DMSG("has been called");

}



TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types,
                TEE_Param __maybe_unused params[4], void __maybe_unused **sess_ctx) {

   uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE,
					      TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);

   DMSG("has been called");

   if ( param_types != exp_param_types ) {
      return TEE_ERROR_BAD_PARAMETERS;
   }

   (void)&params;
   (void)&sess_ctx;

   IMSG("Hello lwIP!\n");

   return TEE_SUCCESS;

}



void TA_CloseSessionEntryPoint(void __maybe_unused *sess_ctx) {

   (void)&sess_ctx;

   IMSG("BYE lwIP!\n");

}



static TEE_Result my_init(uint32_t param_types, TEE_Param params[4]) {

   uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                   TEE_PARAM_TYPE_NONE,
                                                   TEE_PARAM_TYPE_NONE,
                                                   TEE_PARAM_TYPE_NONE);

   DMSG("has been called");

   if( param_types != exp_param_types ) {
      return TEE_ERROR_BAD_PARAMETERS;
   }

/*
   int arr[4] = {4, 3, 2, 1};
   int* pArr;

   pArr = (int *)mem_malloc(sizeof(int) * 4);
   if(pArr == NULL) {
   	printf("mem_malloc error\n");
   }

   for(int i = 0; i < 4; i++) {
   	pArr[i] = arr[i];
   }

   printf("malloc test\n");

   for(int i = 0; i < 4; i++) {
   	printf("%d \n", pArr[i]);
   }

   mem_free(pArr);

   printf("end of mem_malloc test\n");
*/

   char *fromREE = (char *)params[0].memref.buffer;
   
   IMSG("got [%s] from Normal World", fromREE);

   IMSG("Before Listening");
    server.pcb = tcp_listen(server.pcb);

    if(server.pcb == NULL) {
      printf("server.pcb = tcp_listen(server.pcb) went wrong\n");
        return TEE_ERROR_GENERIC;
   }

    IMSG("After Listening");
    IMSG("open session to client TA for setting up tcp_accept");

   TEE_Result res;
   TEE_TASessionHandle session = TEE_HANDLE_NULL;
   TEE_UUID uuid = { 0x59b49e72, 0xa721, 0x49a4, \
                { 0x8d, 0x21, 0x70, 0x80, 0x11, 0xce, 0xc4, 0x99} };

   /* Able to open session to client TA */

   if ( session == TEE_HANDLE_NULL ) {
      IMSG("server TA: TEE_OpenTASession for client");
      uint32_t my_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);

      res = TEE_OpenTASession(&uuid, TEE_TIMEOUT_INFINITE, my_param_types, params, &session, NULL);

      if ( res != TEE_SUCCESS ) {
         IMSG("Failed to open TA session for client");
         tcp_close(server.pcb);
         return res;
      }

      IMSG("Server gonna start initilizing Client by TA2TA Protocol");
      
      res = TEE_InvokeTACommand(session, TEE_TIMEOUT_INFINITE, TA_CLIENT_INIT, my_param_types, params, NULL);

      if ( res != TEE_SUCCESS ) {
         IMSG("Failed to TEE_InvokeTACommand while initializing client");
         TEE_CloseTASession(session);
         tcp_close(server.pcb);
         return res;

      }

      res = TEE_InvokeTACommand(session, TEE_TIMEOUT_INFINITE, TA_CLIENT_CONNECT, my_param_types, params, NULL);

      if ( res != TEE_SUCCESS ) {
            IMSG("Failed to TEE_InvokeTACommand while trying to connect client to server");
            TEE_CloseTASession(session);
            tcp_close(server.pcb);
            return res;

        }
   }

      printf("TA Client connection with Server\n");

      //tcp_accept(server.pcb, tcp_accept_callback);
      
      event_loop();

   TEE_Wait(500);
   TEE_CloseTASession(session);
   return TEE_SUCCESS;

}



TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *sess_ctx, uint32_t cmd_id,
                        uint32_t param_types, TEE_Param params[4])

{
        (void)&sess_ctx; /* Unused parameter */

        switch (cmd_id) {
        case TA_LWIP_INIT:
                return my_init(param_types, params);
        default:
                return TEE_ERROR_BAD_PARAMETERS;
        }
}







/* This function is only required to prevent arch.h including stdio.h
 * (which it does if LWIP_PLATFORM_ASSERT is undefined)
 */

void lwip_example_app_platform_assert(const char *msg, int line, const char *file)
{
  printf("Assertion \"%s\" failed at line %d in %s\n", msg, line, file);
  //fflush(NULL);
  abort();
}

/*

static err_t client_connected(void *arg, struct tcp_pcb *tpcb, err_t err) {

    if (err != ERR_OK) {

        EMSG("Connection failed");

        return err;

    }



    err = tcp_write(tpcb, data_to_send, strlen(data_to_send), TCP_WRITE_FLAG_COPY);

    if (err != ERR_OK) {

        EMSG("Failed to write data");

        return err;

    }



    err = tcp_output(tpcb);

    if (err != ERR_OK) {

        EMSG("Failed to send data");

        return err;

    }



    tcp_recv(tpcb, client_recv);

    return ERR_OK;

}



static err_t client_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {

    if (err != ERR_OK || p == NULL) {

        EMSG("Failed to receive data or connection closed");

        tcp_close(tpcb);

        return err;

    }



    char *received_data = (char *)malloc(p->len + 1);

    memcpy(received_data, p->payload, p->len);

    received_data[p->len] = '\0';



    IMSG("Received: %s", received_data);



    free(received_data);

    pbuf_free(p);

    tcp_close(tpcb);

    return ERR_OK;
}

*/


