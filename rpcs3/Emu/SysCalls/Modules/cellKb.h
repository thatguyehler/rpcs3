#pragma once

namespace vm { using namespace ps3; }

enum CELL_KB_ERROR_CODE
{
	CELL_KB_ERROR_FATAL = 0x80121001,
	CELL_KB_ERROR_INVALID_PARAMETER = 0x80121002,
	CELL_KB_ERROR_ALREADY_INITIALIZED = 0x80121003,
	CELL_KB_ERROR_UNINITIALIZED = 0x80121004,
	CELL_KB_ERROR_RESOURCE_ALLOCATION_FAILED = 0x80121005,
	CELL_KB_ERROR_READ_FAILED = 0x80121006,
	CELL_KB_ERROR_NO_DEVICE = 0x80121007,
	CELL_KB_ERROR_SYS_SETTING_FAILED = 0x80121008,
};

static const u32 CELL_KB_MAX_KEYBOARDS = 127;

struct CellKbInfo
{
	be_t<u32> max_connect;
	be_t<u32> now_connect;
	be_t<u32> info;
	u8 status[CELL_KB_MAX_KEYBOARDS];
};

static const u32 CELL_KB_MAX_KEYCODES = 62;

struct CellKbData
{
	be_t<u32> led;
	be_t<u32> mkey;
	be_t<s32> len;
	be_t<u16> keycode[CELL_KB_MAX_KEYCODES];
};

struct CellKbConfig
{
	be_t<u32> arrange;
	be_t<u32> read_mode;
	be_t<u32> code_type;
};
