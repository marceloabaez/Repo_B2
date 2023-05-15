/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsInit(void);
extern void test_prender_un_led(void);
extern void test_prender_y_apagar_un_led(void);
extern void test_prender_y_apagar_varios_led(void);
extern void test_encender_todos_los_leds(void);
extern void test_apagar_todos_los_leds(void);
extern void test_valores_limite_bajos(void);
extern void test_valores_limite_altos(void);
extern void test_valores_limite_tipos_incorrectos(void);
extern void test_valores_limite_tipos_incorrectos_2(void);
extern void test_valores_limite_tipos_incorrectos_3(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Setup (stub)=====*/
void setUp(void) {}

/*=======Teardown (stub)=====*/
void tearDown(void) {}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_LedsInit, "test_LedsInit", 19);
  run_test(test_prender_un_led, "test_prender_un_led", 26);
  run_test(test_prender_y_apagar_un_led, "test_prender_y_apagar_un_led", 34);
  run_test(test_prender_y_apagar_varios_led, "test_prender_y_apagar_varios_led", 44);
  run_test(test_encender_todos_los_leds, "test_encender_todos_los_leds", 55);
  run_test(test_apagar_todos_los_leds, "test_apagar_todos_los_leds", 63);
  run_test(test_valores_limite_bajos, "test_valores_limite_bajos", 72);
  run_test(test_valores_limite_altos, "test_valores_limite_altos", 83);
  run_test(test_valores_limite_tipos_incorrectos, "test_valores_limite_tipos_incorrectos", 92);
  run_test(test_valores_limite_tipos_incorrectos_2, "test_valores_limite_tipos_incorrectos_2", 101);
  run_test(test_valores_limite_tipos_incorrectos_3, "test_valores_limite_tipos_incorrectos_3", 113);

  return UnityEnd();
}
