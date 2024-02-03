#pragma once
#include "../base/base.h"

void process_sw_upload_init();
void process_sw_upload_new(u32 command_param, u8* pBuffer, int length);

bool process_sw_upload_is_started();
void process_sw_upload_check_timeout(u32 uTimeNow);