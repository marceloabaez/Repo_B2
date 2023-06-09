/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_API_RTC_port.h"

static const char* CMockString_I2C_Read = "I2C_Read";
static const char* CMockString_I2C_Write = "I2C_Write";
static const char* CMockString_i2c_add = "i2c_add";
static const char* CMockString_mem_add = "mem_add";
static const char* CMockString_size = "size";

typedef struct _CMOCK_I2C_Read_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint16_t Expected_i2c_add;
  uint16_t Expected_mem_add;
  uint16_t Expected_size;
  char IgnoreArg_i2c_add;
  char IgnoreArg_mem_add;
  char IgnoreArg_size;

} CMOCK_I2C_Read_CALL_INSTANCE;

typedef struct _CMOCK_I2C_Write_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint16_t Expected_i2c_add;
  uint16_t Expected_mem_add;
  uint16_t Expected_size;
  char IgnoreArg_i2c_add;
  char IgnoreArg_mem_add;
  char IgnoreArg_size;

} CMOCK_I2C_Write_CALL_INSTANCE;

static struct mock_API_RTC_portInstance
{
  char I2C_Read_IgnoreBool;
  char I2C_Read_CallbackBool;
  CMOCK_I2C_Read_CALLBACK I2C_Read_CallbackFunctionPointer;
  int I2C_Read_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE I2C_Read_CallInstance;
  char I2C_Write_IgnoreBool;
  char I2C_Write_CallbackBool;
  CMOCK_I2C_Write_CALLBACK I2C_Write_CallbackFunctionPointer;
  int I2C_Write_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE I2C_Write_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_API_RTC_port_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.I2C_Read_CallInstance;
  if (Mock.I2C_Read_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_I2C_Read);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.I2C_Read_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.I2C_Write_CallInstance;
  if (Mock.I2C_Write_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_I2C_Write);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.I2C_Write_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_API_RTC_port_Init(void)
{
  mock_API_RTC_port_Destroy();
}

void mock_API_RTC_port_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void I2C_Read(uint16_t i2c_add, uint16_t mem_add, uint16_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_I2C_Read);
  cmock_call_instance = (CMOCK_I2C_Read_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.I2C_Read_CallInstance);
  Mock.I2C_Read_CallInstance = CMock_Guts_MemNext(Mock.I2C_Read_CallInstance);
  if (Mock.I2C_Read_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.I2C_Read_CallbackBool &&
      Mock.I2C_Read_CallbackFunctionPointer != NULL)
  {
    Mock.I2C_Read_CallbackFunctionPointer(i2c_add, mem_add, size, Mock.I2C_Read_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_i2c_add)
  {
    UNITY_SET_DETAILS(CMockString_I2C_Read,CMockString_i2c_add);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_i2c_add, i2c_add, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_mem_add)
  {
    UNITY_SET_DETAILS(CMockString_I2C_Read,CMockString_mem_add);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_mem_add, mem_add, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_I2C_Read,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_size, size, cmock_line, CMockStringMismatch);
  }
  if (Mock.I2C_Read_CallbackFunctionPointer != NULL)
  {
    Mock.I2C_Read_CallbackFunctionPointer(i2c_add, mem_add, size, Mock.I2C_Read_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_I2C_Read(CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance, uint16_t i2c_add, uint16_t mem_add, uint16_t size);
void CMockExpectParameters_I2C_Read(CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance, uint16_t i2c_add, uint16_t mem_add, uint16_t size)
{
  cmock_call_instance->Expected_i2c_add = i2c_add;
  cmock_call_instance->IgnoreArg_i2c_add = 0;
  cmock_call_instance->Expected_mem_add = mem_add;
  cmock_call_instance->IgnoreArg_mem_add = 0;
  cmock_call_instance->Expected_size = size;
  cmock_call_instance->IgnoreArg_size = 0;
}

void I2C_Read_CMockIgnore(void)
{
  Mock.I2C_Read_IgnoreBool = (char)1;
}

void I2C_Read_CMockStopIgnore(void)
{
  Mock.I2C_Read_IgnoreBool = (char)0;
}

void I2C_Read_CMockExpect(UNITY_LINE_TYPE cmock_line, uint16_t i2c_add, uint16_t mem_add, uint16_t size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_I2C_Read_CALL_INSTANCE));
  CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Read_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.I2C_Read_CallInstance = CMock_Guts_MemChain(Mock.I2C_Read_CallInstance, cmock_guts_index);
  Mock.I2C_Read_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_I2C_Read(cmock_call_instance, i2c_add, mem_add, size);
}

void I2C_Read_AddCallback(CMOCK_I2C_Read_CALLBACK Callback)
{
  Mock.I2C_Read_IgnoreBool = (char)0;
  Mock.I2C_Read_CallbackBool = (char)1;
  Mock.I2C_Read_CallbackFunctionPointer = Callback;
}

void I2C_Read_Stub(CMOCK_I2C_Read_CALLBACK Callback)
{
  Mock.I2C_Read_IgnoreBool = (char)0;
  Mock.I2C_Read_CallbackBool = (char)0;
  Mock.I2C_Read_CallbackFunctionPointer = Callback;
}

void I2C_Read_CMockIgnoreArg_i2c_add(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Read_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.I2C_Read_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_i2c_add = 1;
}

void I2C_Read_CMockIgnoreArg_mem_add(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Read_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.I2C_Read_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_mem_add = 1;
}

void I2C_Read_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_I2C_Read_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Read_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.I2C_Read_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}

void I2C_Write(uint16_t i2c_add, uint16_t mem_add, uint16_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_I2C_Write);
  cmock_call_instance = (CMOCK_I2C_Write_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.I2C_Write_CallInstance);
  Mock.I2C_Write_CallInstance = CMock_Guts_MemNext(Mock.I2C_Write_CallInstance);
  if (Mock.I2C_Write_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.I2C_Write_CallbackBool &&
      Mock.I2C_Write_CallbackFunctionPointer != NULL)
  {
    Mock.I2C_Write_CallbackFunctionPointer(i2c_add, mem_add, size, Mock.I2C_Write_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_i2c_add)
  {
    UNITY_SET_DETAILS(CMockString_I2C_Write,CMockString_i2c_add);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_i2c_add, i2c_add, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_mem_add)
  {
    UNITY_SET_DETAILS(CMockString_I2C_Write,CMockString_mem_add);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_mem_add, mem_add, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_I2C_Write,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_size, size, cmock_line, CMockStringMismatch);
  }
  if (Mock.I2C_Write_CallbackFunctionPointer != NULL)
  {
    Mock.I2C_Write_CallbackFunctionPointer(i2c_add, mem_add, size, Mock.I2C_Write_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_I2C_Write(CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance, uint16_t i2c_add, uint16_t mem_add, uint16_t size);
void CMockExpectParameters_I2C_Write(CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance, uint16_t i2c_add, uint16_t mem_add, uint16_t size)
{
  cmock_call_instance->Expected_i2c_add = i2c_add;
  cmock_call_instance->IgnoreArg_i2c_add = 0;
  cmock_call_instance->Expected_mem_add = mem_add;
  cmock_call_instance->IgnoreArg_mem_add = 0;
  cmock_call_instance->Expected_size = size;
  cmock_call_instance->IgnoreArg_size = 0;
}

void I2C_Write_CMockIgnore(void)
{
  Mock.I2C_Write_IgnoreBool = (char)1;
}

void I2C_Write_CMockStopIgnore(void)
{
  Mock.I2C_Write_IgnoreBool = (char)0;
}

void I2C_Write_CMockExpect(UNITY_LINE_TYPE cmock_line, uint16_t i2c_add, uint16_t mem_add, uint16_t size)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_I2C_Write_CALL_INSTANCE));
  CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Write_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.I2C_Write_CallInstance = CMock_Guts_MemChain(Mock.I2C_Write_CallInstance, cmock_guts_index);
  Mock.I2C_Write_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_I2C_Write(cmock_call_instance, i2c_add, mem_add, size);
}

void I2C_Write_AddCallback(CMOCK_I2C_Write_CALLBACK Callback)
{
  Mock.I2C_Write_IgnoreBool = (char)0;
  Mock.I2C_Write_CallbackBool = (char)1;
  Mock.I2C_Write_CallbackFunctionPointer = Callback;
}

void I2C_Write_Stub(CMOCK_I2C_Write_CALLBACK Callback)
{
  Mock.I2C_Write_IgnoreBool = (char)0;
  Mock.I2C_Write_CallbackBool = (char)0;
  Mock.I2C_Write_CallbackFunctionPointer = Callback;
}

void I2C_Write_CMockIgnoreArg_i2c_add(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Write_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.I2C_Write_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_i2c_add = 1;
}

void I2C_Write_CMockIgnoreArg_mem_add(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Write_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.I2C_Write_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_mem_add = 1;
}

void I2C_Write_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_I2C_Write_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_Write_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.I2C_Write_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}

