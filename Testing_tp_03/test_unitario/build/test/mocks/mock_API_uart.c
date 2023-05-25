/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_API_uart.h"

static const char* CMockString_pstring = "pstring";
static const char* CMockString_size = "size";
static const char* CMockString_uartInit = "uartInit";
static const char* CMockString_uartSendString = "uartSendString";
static const char* CMockString_uartSendStringSize = "uartSendStringSize";

typedef struct _CMOCK_uartInit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  bool_t ReturnVal;
  int CallOrder;

} CMOCK_uartInit_CALL_INSTANCE;

typedef struct _CMOCK_uartSendString_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint8_t* Expected_pstring;
  char ReturnThruPtr_pstring_Used;
  uint8_t* ReturnThruPtr_pstring_Val;
  size_t ReturnThruPtr_pstring_Size;
  char IgnoreArg_pstring;

} CMOCK_uartSendString_CALL_INSTANCE;

typedef struct _CMOCK_uartSendStringSize_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint8_t* Expected_pstring;
  uint16_t Expected_size;
  char ReturnThruPtr_pstring_Used;
  uint8_t* ReturnThruPtr_pstring_Val;
  size_t ReturnThruPtr_pstring_Size;
  char IgnoreArg_pstring;
  char IgnoreArg_size;

} CMOCK_uartSendStringSize_CALL_INSTANCE;

static struct mock_API_uartInstance
{
  char uartInit_IgnoreBool;
  bool_t uartInit_FinalReturn;
  char uartInit_CallbackBool;
  CMOCK_uartInit_CALLBACK uartInit_CallbackFunctionPointer;
  int uartInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE uartInit_CallInstance;
  char uartSendString_IgnoreBool;
  char uartSendString_CallbackBool;
  CMOCK_uartSendString_CALLBACK uartSendString_CallbackFunctionPointer;
  int uartSendString_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE uartSendString_CallInstance;
  char uartSendStringSize_IgnoreBool;
  char uartSendStringSize_CallbackBool;
  CMOCK_uartSendStringSize_CALLBACK uartSendStringSize_CallbackFunctionPointer;
  int uartSendStringSize_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE uartSendStringSize_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_API_uart_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.uartInit_CallInstance;
  if (Mock.uartInit_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_uartInit);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.uartInit_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.uartSendString_CallInstance;
  if (Mock.uartSendString_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_uartSendString);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.uartSendString_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.uartSendStringSize_CallInstance;
  if (Mock.uartSendStringSize_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_uartSendStringSize);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.uartSendStringSize_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_API_uart_Init(void)
{
  mock_API_uart_Destroy();
}

void mock_API_uart_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

bool_t uartInit(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_uartInit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_uartInit);
  cmock_call_instance = (CMOCK_uartInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.uartInit_CallInstance);
  Mock.uartInit_CallInstance = CMock_Guts_MemNext(Mock.uartInit_CallInstance);
  if (Mock.uartInit_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.uartInit_FinalReturn;
    Mock.uartInit_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.uartInit_CallbackBool &&
      Mock.uartInit_CallbackFunctionPointer != NULL)
  {
    bool_t cmock_cb_ret = Mock.uartInit_CallbackFunctionPointer(Mock.uartInit_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.uartInit_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.uartInit_CallbackFunctionPointer(Mock.uartInit_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void uartInit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uartInit_CALL_INSTANCE));
  CMOCK_uartInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uartInit_CallInstance = CMock_Guts_MemChain(Mock.uartInit_CallInstance, cmock_guts_index);
  Mock.uartInit_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.uartInit_IgnoreBool = (char)1;
}

void uartInit_CMockStopIgnore(void)
{
  if(Mock.uartInit_IgnoreBool)
    Mock.uartInit_CallInstance = CMock_Guts_MemNext(Mock.uartInit_CallInstance);
  Mock.uartInit_IgnoreBool = (char)0;
}

void uartInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uartInit_CALL_INSTANCE));
  CMOCK_uartInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uartInit_CallInstance = CMock_Guts_MemChain(Mock.uartInit_CallInstance, cmock_guts_index);
  Mock.uartInit_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void uartInit_AddCallback(CMOCK_uartInit_CALLBACK Callback)
{
  Mock.uartInit_IgnoreBool = (char)0;
  Mock.uartInit_CallbackBool = (char)1;
  Mock.uartInit_CallbackFunctionPointer = Callback;
}

void uartInit_Stub(CMOCK_uartInit_CALLBACK Callback)
{
  Mock.uartInit_IgnoreBool = (char)0;
  Mock.uartInit_CallbackBool = (char)0;
  Mock.uartInit_CallbackFunctionPointer = Callback;
}

void uartSendString(uint8_t* pstring)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_uartSendString_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_uartSendString);
  cmock_call_instance = (CMOCK_uartSendString_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.uartSendString_CallInstance);
  Mock.uartSendString_CallInstance = CMock_Guts_MemNext(Mock.uartSendString_CallInstance);
  if (Mock.uartSendString_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.uartSendString_CallbackBool &&
      Mock.uartSendString_CallbackFunctionPointer != NULL)
  {
    Mock.uartSendString_CallbackFunctionPointer(pstring, Mock.uartSendString_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_pstring)
  {
    UNITY_SET_DETAILS(CMockString_uartSendString,CMockString_pstring);
    if (cmock_call_instance->Expected_pstring == NULL)
      { UNITY_TEST_ASSERT_NULL(pstring, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_pstring, pstring, 1, cmock_line, CMockStringMismatch); }
  }
  if (Mock.uartSendString_CallbackFunctionPointer != NULL)
  {
    Mock.uartSendString_CallbackFunctionPointer(pstring, Mock.uartSendString_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_pstring_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(pstring, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)pstring, (void*)cmock_call_instance->ReturnThruPtr_pstring_Val,
      cmock_call_instance->ReturnThruPtr_pstring_Size);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_uartSendString(CMOCK_uartSendString_CALL_INSTANCE* cmock_call_instance, uint8_t* pstring);
void CMockExpectParameters_uartSendString(CMOCK_uartSendString_CALL_INSTANCE* cmock_call_instance, uint8_t* pstring)
{
  cmock_call_instance->Expected_pstring = pstring;
  cmock_call_instance->IgnoreArg_pstring = 0;
  cmock_call_instance->ReturnThruPtr_pstring_Used = 0;
}

void uartSendString_CMockIgnore(void)
{
  Mock.uartSendString_IgnoreBool = (char)1;
}

void uartSendString_CMockStopIgnore(void)
{
  Mock.uartSendString_IgnoreBool = (char)0;
}

void uartSendString_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t* pstring)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uartSendString_CALL_INSTANCE));
  CMOCK_uartSendString_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendString_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uartSendString_CallInstance = CMock_Guts_MemChain(Mock.uartSendString_CallInstance, cmock_guts_index);
  Mock.uartSendString_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_uartSendString(cmock_call_instance, pstring);
}

void uartSendString_AddCallback(CMOCK_uartSendString_CALLBACK Callback)
{
  Mock.uartSendString_IgnoreBool = (char)0;
  Mock.uartSendString_CallbackBool = (char)1;
  Mock.uartSendString_CallbackFunctionPointer = Callback;
}

void uartSendString_Stub(CMOCK_uartSendString_CALLBACK Callback)
{
  Mock.uartSendString_IgnoreBool = (char)0;
  Mock.uartSendString_CallbackBool = (char)0;
  Mock.uartSendString_CallbackFunctionPointer = Callback;
}

void uartSendString_CMockReturnMemThruPtr_pstring(UNITY_LINE_TYPE cmock_line, uint8_t* pstring, size_t cmock_size)
{
  CMOCK_uartSendString_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendString_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.uartSendString_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_pstring_Used = 1;
  cmock_call_instance->ReturnThruPtr_pstring_Val = pstring;
  cmock_call_instance->ReturnThruPtr_pstring_Size = cmock_size;
}

void uartSendString_CMockIgnoreArg_pstring(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_uartSendString_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendString_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.uartSendString_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pstring = 1;
}

void uartSendStringSize(uint8_t* pstring, uint16_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_uartSendStringSize);
  cmock_call_instance = (CMOCK_uartSendStringSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.uartSendStringSize_CallInstance);
  Mock.uartSendStringSize_CallInstance = CMock_Guts_MemNext(Mock.uartSendStringSize_CallInstance);
  if (Mock.uartSendStringSize_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.uartSendStringSize_CallbackBool &&
      Mock.uartSendStringSize_CallbackFunctionPointer != NULL)
  {
    Mock.uartSendStringSize_CallbackFunctionPointer(pstring, size, Mock.uartSendStringSize_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_pstring)
  {
    UNITY_SET_DETAILS(CMockString_uartSendStringSize,CMockString_pstring);
    if (cmock_call_instance->Expected_pstring == NULL)
      { UNITY_TEST_ASSERT_NULL(pstring, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_pstring, pstring, 1, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_uartSendStringSize,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_size, size, cmock_line, CMockStringMismatch);
  }
  if (Mock.uartSendStringSize_CallbackFunctionPointer != NULL)
  {
    Mock.uartSendStringSize_CallbackFunctionPointer(pstring, size, Mock.uartSendStringSize_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_pstring_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(pstring, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)pstring, (void*)cmock_call_instance->ReturnThruPtr_pstring_Val,
      cmock_call_instance->ReturnThruPtr_pstring_Size);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_uartSendStringSize(CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance, uint8_t* pstring, uint16_t size);
void CMockExpectParameters_uartSendStringSize(CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance, uint8_t* pstring, uint16_t size)
{
  cmock_call_instance->Expected_pstring = pstring;
  cmock_call_instance->IgnoreArg_pstring = 0;
  cmock_call_instance->ReturnThruPtr_pstring_Used = 0;
  cmock_call_instance->Expected_size = size;
  cmock_call_instance->IgnoreArg_size = 0;
}

void uartSendStringSize_CMockIgnore(void)
{
  Mock.uartSendStringSize_IgnoreBool = (char)1;
}

void uartSendStringSize_CMockStopIgnore(void)
{
  Mock.uartSendStringSize_IgnoreBool = (char)0;
}

void uartSendStringSize_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t* pstring, uint16_t size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uartSendStringSize_CALL_INSTANCE));
  CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendStringSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uartSendStringSize_CallInstance = CMock_Guts_MemChain(Mock.uartSendStringSize_CallInstance, cmock_guts_index);
  Mock.uartSendStringSize_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_uartSendStringSize(cmock_call_instance, pstring, size);
}

void uartSendStringSize_AddCallback(CMOCK_uartSendStringSize_CALLBACK Callback)
{
  Mock.uartSendStringSize_IgnoreBool = (char)0;
  Mock.uartSendStringSize_CallbackBool = (char)1;
  Mock.uartSendStringSize_CallbackFunctionPointer = Callback;
}

void uartSendStringSize_Stub(CMOCK_uartSendStringSize_CALLBACK Callback)
{
  Mock.uartSendStringSize_IgnoreBool = (char)0;
  Mock.uartSendStringSize_CallbackBool = (char)0;
  Mock.uartSendStringSize_CallbackFunctionPointer = Callback;
}

void uartSendStringSize_CMockReturnMemThruPtr_pstring(UNITY_LINE_TYPE cmock_line, uint8_t* pstring, size_t cmock_size)
{
  CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendStringSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.uartSendStringSize_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_pstring_Used = 1;
  cmock_call_instance->ReturnThruPtr_pstring_Val = pstring;
  cmock_call_instance->ReturnThruPtr_pstring_Size = cmock_size;
}

void uartSendStringSize_CMockIgnoreArg_pstring(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendStringSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.uartSendStringSize_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pstring = 1;
}

void uartSendStringSize_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_uartSendStringSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_uartSendStringSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.uartSendStringSize_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}
