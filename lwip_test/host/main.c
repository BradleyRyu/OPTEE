/* Header files for OP-TEE */
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

/* OP-TEE TEE client API */
#include <tee_client_api.h>

/* for the UUID (found in the TA's header file) */
#include <ta_server_side.h>

void* invoke_server(void *arg) {
	TEEC_Context ctx;
	TEEC_Session sess;
	TEEC_Operation op;
	TEEC_Result res;
	TEEC_UUID uuid = TA_LWIP_TEST_UUID;
	
	uint32_t err_origin;

        /* Initialize a context connecting us to the TEE */
        res = TEEC_InitializeContext(NULL, &ctx);
        if( res != TEEC_SUCCESS )
                errx(1, "TEEC_InitilizeContext failed with code 0x%x", res);

        /* Open a session to the "lwip_test" TA, the TA will execute tcpecho. */
        res = TEEC_OpenSession(&ctx, &sess, &uuid, TEEC_LOGIN_PUBLIC,
                               NULL, NULL, &err_origin);
        if( res != TEEC_SUCCESS )
                errx(1, "TEEC_OpenSession failed with code 0x%x origin 0x%x", res, err_origin);

        /* Execute app in the TA by invoking it, in this case we're running tcpecho app */
        /* The value of command ID part and how the parameters are interpreted is 
         * part of the interface provided by the TA. */

/*
        TEEC_SharedMemory shm;
        shm.size = 30;
        shm.flags = TEEC_MEM_INPUT | TEEC_MEM_OUTPUT;
        res = TEEC_AllocateSharedMemory(&ctx, &shm);
        if( res != TEEC_SUCCESS ) {
                printf("TEEC_AllocateSharedMemory failed with code 0x%x\n", res);
                TEEC_CloseSession(&sess);
                TEEC_FinalizeContext(&ctx);
                return 1;
        }

        printf("Enter a string: ");

        if( fgets((char *)shm.buffer, 30, stdin) == NULL ) {
                printf("Error reading input\n");
                TEEC_ReleaseSharedMemory(&shm);
                TEEC_CloseSession(&sess);
                TEEC_FinalizeContext(&ctx);
                return 1;
        }

        int len = strlen((char *)shm.buffer);
        if( len > 0 && ((char *)shm.buffer)[len - 1] == '\n' ) {
                ((char *)shm.buffer)[len - 1] = '\0';
        }
*/
        /* Clear the TEEC_Operation struct */
        memset(&op, 0, sizeof(op));
        op.paramTypes = TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE,
                                         TEEC_NONE, TEEC_NONE);
        //op.params[0].memref.parent = &shm;


        printf("Invoking TA to run tcpecho app with command ID%d\n", TA_LWIP_INIT);
        res = TEEC_InvokeCommand(&sess, TA_LWIP_INIT, &op, &err_origin);

        if( res != TEEC_SUCCESS )
                errx(1, "TEEC_InvokeCommand failed with code 0x%x origin 0x%x", res, err_origin);

        printf("Completed tcpecho app in Secure World! Congrats!!\n");

        printf("Requesting TEEC_CloseSession..\n");
        TEEC_CloseSession(&sess);

        printf("Requesting TEEC_FinalizeContext..\n");
        TEEC_FinalizeContext(&ctx);
 	
	return NULL;
}

void* invoke_client(void *arg) {
	TEEC_Result res;
	TEEC_Context ctx;
	TEEC_Session sess;
	TEEC_Operation op;
	TEEC_UUID uuid = { 0x59b49e72, 0xa721, 0x49a4, \
                { 0x8d, 0x21, 0x70, 0x80, 0x11, 0xce, 0xc4, 0x99} };
	uint32_t err_origin;
	
	/* Initialize a context connecting us to the TEE */
	res = TEEC_InitializeContext(NULL, &ctx);
	if( res != TEEC_SUCCESS )
		errx(1, "TEEC_InitilizeContext failed with code 0x%x", res);

	/* Open a session to the "lwip_test" TA, the TA will execute tcpecho. */
	res = TEEC_OpenSession(&ctx, &sess, &uuid, TEEC_LOGIN_PUBLIC,
			       NULL, NULL, &err_origin);
	if( res != TEEC_SUCCESS ) 
		errx(1, "TEEC_OpenSession failed with code 0x%x origin 0x%x", res, err_origin);

	/* Execute app in the TA by invoking it, in this case we're running tcpecho app */
	/* The value of command ID part and how the parameters are interpreted is 
	 * part of the interface provided by the TA. */

	/* Clear the TEEC_Operation struct */
	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE,
					 TEEC_NONE, TEEC_NONE);
	//op.params[0].memref.parent = &shm;
	

	printf("Invoking TA to run tcpecho app with command ID%d\n", 0);
	res = TEEC_InvokeCommand(&sess, 0, &op, &err_origin);	

	if( res != TEEC_SUCCESS )
		errx(1, "TEEC_InvokeCommand failed with code 0x%x origin 0x%x", res, err_origin);

	printf("Completed tcpecho app in Secure World! Congrats!!\n");
	
	printf("Requesting TEEC_CloseSession..\n");
	TEEC_CloseSession(&sess);
	
	printf("Requesting TEEC_FinalizeContext..\n");
	TEEC_FinalizeContext(&ctx);

	return NULL;
}


int main() {
    pthread_t thread1, thread2;

    // Create threads to invoke TA1 and TA2
    pthread_create(&thread1, NULL, invoke_server, NULL);

    sleep(3);

    pthread_create(&thread2, NULL, invoke_client, NULL);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

/*
int main(void) {
	TEEC_Result res;
	TEEC_Context ctx;
	TEEC_Session sess;
	TEEC_Operation op;
	TEEC_UUID uuid = TA_LWIP_TEST_UUID;
	uint32_t err_origin;

	//Initialize a context connecting us to the TEE 
	res = TEEC_InitializeContext(NULL, &ctx);
	if( res != TEEC_SUCCESS )
		errx(1, "TEEC_InitilizeContext failed with code 0x%x", res);

	// Open a session to the "lwip_test" TA, the TA will execute tcpecho. 
	res = TEEC_OpenSession(&ctx, &sess, &uuid, TEEC_LOGIN_PUBLIC,
			       NULL, NULL, &err_origin);
	if( res != TEEC_SUCCESS ) 
		errx(1, "TEEC_OpenSession failed with code 0x%x origin 0x%x", res, err_origin);

	// Execute app in the TA by invoking it, in this case we're running tcpecho app 
	// The value of command ID part and how the parameters are interpreted is 
	// part of the interface provided by the TA. 


	TEEC_SharedMemory shm;
	shm.size = 30;
	shm.flags = TEEC_MEM_INPUT | TEEC_MEM_OUTPUT;
	res = TEEC_AllocateSharedMemory(&ctx, &shm);
	if( res != TEEC_SUCCESS ) {
		printf("TEEC_AllocateSharedMemory failed with code 0x%x\n", res);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return 1;
	}

	printf("Enter a string: ");
	
	if( fgets((char *)shm.buffer, 30, stdin) == NULL ) {
		printf("Error reading input\n");
		TEEC_ReleaseSharedMemory(&shm);
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return 1;
	}

	int len = strlen((char *)shm.buffer);
	if( len > 0 && ((char *)shm.buffer)[len - 1] == '\n' ) {
		((char *)shm.buffer)[len - 1] = '\0';
	}

	//Clear the TEEC_Operation struct
	memset(&op, 0, sizeof(op));
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_PARTIAL_INPUT, TEEC_NONE,
					 TEEC_NONE, TEEC_NONE);
	op.params[0].memref.parent = &shm;
	

	printf("Invoking TA to run tcpecho app with command ID%d\n", TA_LWIP_INIT);
	res = TEEC_InvokeCommand(&sess, TA_LWIP_INIT, &op, &err_origin);	

	if( res != TEEC_SUCCESS )
		errx(1, "TEEC_InvokeCommand failed with code 0x%x origin 0x%x", res, err_origin);

	printf("Completed tcpecho app in Secure World! Congrats!!\n");
	
	printf("Requesting TEEC_CloseSession..\n");
	TEEC_CloseSession(&sess);
	
	printf("Requesting TEEC_FinalizeContext..\n");
	TEEC_FinalizeContext(&ctx);

	return 0;
}*/
