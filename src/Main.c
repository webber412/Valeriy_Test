
#include "TestConfig.h"

#include "Basic.h"
#include "Automated.h"
#include "Console.h"

#if(TEST_INT_DTCM == TEST_ON)
# include "TestIntDtcMaster.h"
#endif
#if(TEST_INT_DTCBRIDGE == TEST_ON)
# include "TestIntDtcBridge.h"
#endif
#if(TEST_INT_TIMERS == TEST_ON)
# include "TestIntTimers.h"
#endif
#if(TEST_INT_J1939W == TEST_ON)
# include "TestIntj1939w.h"
#endif
#if(TEST_UNIT_DTCM == TEST_ON)
# include "TestDtcMaster.h"
#endif
#if(TEST_UNIT_TIMERS == TEST_ON)
# include "TestTimers.h"
#endif
#if(TEST_UNIT_DTCBRIDGE == TEST_ON)
# include "TestDtcBridge.h"
#endif
#if(TEST_UNIT_J1939W == TEST_ON)
# include "Testj1939w.h"
#endif

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* Add tests */
#if(TEST_INT_DTCM == TEST_ON)
   CU_ErrorCode TestInDtcMaster_retVal = TestInDtcMaster_AddTests();
   if(CUE_SUCCESS != TestInDtcMaster_retVal)
   {
	   printf("\nError while running TestInDtcMaster_AddTests()");
	   return TestInDtcMaster_retVal;
   }
#endif

#if(TEST_INT_DTCBRIDGE == TEST_ON)
   CU_ErrorCode TestIntDtcBridge_retVal = TestIntDtcBridge_AddTests();
   if(CUE_SUCCESS != TestIntDtcBridge_retVal)
   {
	   printf("\nError while running TestInDtcBridge_AddTests()");
	   return TestIntDtcBridge_retVal;
   }
#endif

#if(TEST_INT_TIMERS == TEST_ON)
   CU_ErrorCode TestIntTimers_retVal = TestIntTimers_AddTests();
   if(CUE_SUCCESS != TestIntTimers_retVal)
   {
	   printf("\nError while running TestInDtcBridge_AddTests()");
	   return TestIntTimers_retVal;
   }
#endif

#if(TEST_INT_J1939W == TEST_ON)
   CU_ErrorCode TestIntJ1939w_retVal = TestIntJ1939w_AddTests();
   if(CUE_SUCCESS != TestIntJ1939w_retVal)
   {
       printf("\nError while running TestIntJ1939w_AddTests()");
       return TestIntJ1939w_retVal;
   }
#endif

#if(TEST_UNIT_DTCM == TEST_ON)
   CU_ErrorCode TestDtcMaster_retVal = TestDtcMaster_AddTests();
   if(CUE_SUCCESS != TestDtcMaster_retVal)
   {
	   printf("\nError while running TestDtcMaster_AddTests()");
	   return TestDtcMaster_retVal;
   }
#endif

#if(TEST_UNIT_TIMERS == TEST_ON)
   CU_ErrorCode TestTimers_retVal = TestTimers_AddTests();
   if(CUE_SUCCESS != TestTimers_retVal)
   {
	   printf("\nError while running TestDtcMaster_AddTests()");
	   return TestTimers_retVal;
   }
#endif

#if(TEST_UNIT_DTCBRIDGE == TEST_ON)
   CU_ErrorCode TestDtcBridge_retVal = TestDtcBridge_AddTests();
   if(CUE_SUCCESS != TestDtcBridge_retVal)
   {
       printf("\nError while running TestDtcMaster_AddTests()");
       return TestDtcBridge_retVal;
   }
#endif

#if(TEST_UNIT_J1939W == TEST_ON)
   CU_ErrorCode TestJ1939w_retVal = TestJ1939w_AddTests();
   if(CUE_SUCCESS != TestJ1939w_retVal)
   {
       printf("\nError while running TestJ1939w_AddTests()");
       return TestJ1939w_retVal;
   }
#endif
   /* Run Tests */

#if(TEST_RUN_TYPE == TEST_RUN_TYPE_AUTOMATED)
   /* Run tests in automated mode and generate results in xml file */
   CU_automated_run_tests();
#elif(TEST_RUN_TYPE == TEST_RUN_TYPE_BASIC)
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
#elif(TEST_RUN_TYPE == TEST_RUN_TYPE_CONSOLE)
   /* Run tests using console interactive mode */
   CU_console_run_tests();
#endif

   CU_cleanup_registry();
   return CU_get_error();
}
